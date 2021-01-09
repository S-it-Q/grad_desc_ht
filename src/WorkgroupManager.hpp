//
// Created by Etheon on 2021-01-08.
//

#ifndef GRAD_DESC_HT_WORKGROUPMANAGER_HPP
#define GRAD_DESC_HT_WORKGROUPMANAGER_HPP

#include <CL/cl.hpp>
#include <stdexcept>
#include <vector>

struct Workgroup {
    Workgroup(const cl::NDRange &global = cl::NDRange(1, 1, 1),
              const cl::NDRange &local = cl::NDRange(1, 1, 1),
              const cl::NDRange &offset = cl::NullRange) noexcept(false) {
        try {
            if (global[0] < 1 || global[1] < 1 || global[2] < 1) {
                throw std::runtime_error("Each number of NDRange should be more than 1.");
            }
            if (local[0] < 1 || local[1] < 1 || local[2] < 1) {
                throw std::runtime_error("Each number of NDRange should be more than 1.");
            }
            if (offset[0] < 0 || offset[1] < 0 || offset[2] < 0) {
                throw std::runtime_error("Each number of NDRange offset should be more than 0.");
            }

            _offset = offset;
            _global = global;
            _local = local;
        }
        catch (const std::runtime_error &err) {
            throw err;
        }
    }

    cl::NDRange _global;
    cl::NDRange _local;
    cl::NDRange _offset;
};

class WorkgroupManager {
public:
    WorkgroupManager(std::vector<size_t> &preferredWorkSize, cl::NDRange &totalGlobalNDRange) noexcept(false);

private:
    void dispense() noexcept(false);

private:
    std::vector<float> _dispenseRates;
    std::vector<Workgroup> _workgroups;
    std::vector<int> _preferredWorkSize;
    cl::NDRange _totalGlobalNDRange;
    int _numDevices;
};


#endif //GRAD_DESC_HT_WORKGROUPMANAGER_HPP
