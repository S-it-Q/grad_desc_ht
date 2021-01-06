#define __CL_ENABLE_EXCEPTIONS

#if defined(__APPLE__) || defined(__MACOSX)
#include <OpenCL/cl.hpp>
#else
#include <CL/cl.hpp>
#endif

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

string getSource(const string& filePath)
{
    ifstream srcFile(filePath, ios_base::in | ios_base::ate);
    if (srcFile.fail()) {
        throw std::runtime_error("File open error");
    }

    int srcLength = srcFile.tellg();
    srcFile.seekg(0, srcFile.beg);

    //char* buffer = new char[srcLength];
    string src;
    src.resize(srcLength);
    srcFile.read(&src[0], srcLength);
    srcFile.close();

    return src;
}

int main(int argc, char* argv[])
{
    try {
        // Setup CL Context
        std::vector<cl::Platform> platforms;
        cl::Platform::get(&platforms);
        if (platforms.size() == 0) {
            throw cl::Error(-1, "Platform size 0");
        }

        cl::Context context(CL_DEVICE_TYPE_GPU);
        std::vector<cl::Device> devices;
        for (cl::Platform& platform : platforms) {
            std::vector<cl::Device> tempDevice;
            platform.getDevices(CL_DEVICE_TYPE_GPU, &tempDevice);
            devices.insert(devices.end(), tempDevice.begin(), tempDevice.end());
        }

        std::vector<cl::CommandQueue> queues;
        cl_command_queue_properties properties = CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE
                                                 | CL_QUEUE_PROFILING_ENABLE;

        queues.reserve(devices.size());

        for (cl::Device& device: devices) {
            queues.push_back(cl::CommandQueue(context, device, properties));
        }

        // Setup Sobel kernel
        string sobelSrc = getSource("../src/CL/Sobel.cl");
        cl::Program::Sources sobelSource(1, std::make_pair(sobelSrc.c_str(), sobelSrc.length()));
        cl::Program sobelProgram = cl::Program(context, sobelSource);
        sobelProgram.build(devices);

        cl::Kernel sobelKernel(sobelProgram, "sobel");

        // Run kernel
        std::vector<cl::Event> helloEvent(queues.size());
        for (int i = 0; i < queues.size(); ++i) {
            queues[i].enqueueNDRangeKernel(sobelKernel, cl::NullRange, cl::NDRange(4, 4), cl::NullRange, nullptr, &helloEvent[i]);
        }
        cl::WaitForEvents(helloEvent);
    }
    catch (const cl::Error& err) {
        cerr << "CL Error Code: " << err.err() << ", CL Error: " << err.what() << endl;
    }
    catch (const runtime_error& err) {
        cerr << "Runtime Error: " << err.what() << endl;
    }

    return EXIT_SUCCESS;
}
