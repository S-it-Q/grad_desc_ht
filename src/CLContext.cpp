//
// Created by Etheon on 2021-01-04.
//

#include "CLContext.hpp"

#include <stdexcept>

CLContext::CLContext()
    noexcept(false)
{
    try {
        std::vector<cl::Platform> platforms = _findAllPlatforms();
        _devices = _findAllDevices(platforms);
        _context = cl::Context(_devices);
    }
    catch (const cl::Error& err) {
        throw err;
    }
    catch (const std::runtime_error& err) {
        throw err;
    }
}

CLContext::~CLContext()
{

}

std::vector<cl::Platform>
CLContext::_findAllPlatforms()
    noexcept(false)
{
    std::vector<cl::Platform> platforms;
    try {
        cl::Platform::get(&platforms);
        if (platforms.size() == 0) {
            throw std::runtime_error("Platform size 0");
        }
    }
    catch (const cl::Error& err) {
        throw err;
    }
    catch (const std::runtime_error& err) {
        throw err;
    }

    return platforms;
}

std::vector<cl::Device>
CLContext::_findAllDevices(const std::vector<cl::Platform>& platforms)
    noexcept(false)
{
    std::vector<cl::Device> devices;
    try {
        for (const cl::Platform& platform : platforms) {
            std::vector<cl::Device> tempDevices;
            platform.getDevices(CL_DEVICE_TYPE_GPU, &tempDevices);
            devices.insert(devices.end(), tempDevices.begin(), tempDevices.end());
        }
    }
    catch (const cl::Error& err) {
        throw err;
    }
    catch (const std::runtime_error& err) {
        throw err;
    }

    return devices;
}
