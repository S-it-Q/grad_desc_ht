//
// Created by Etheon on 2021-01-04.
//

#ifndef GRAD_DESC_HT_CLCONTEXT_HPP
#define GRAD_DESC_HT_CLCONTEXT_HPP

#define __CL_ENABLE_EXCEPTIONS

#if defined(__APPLE__) || defined(__MACOSX)
#include <OpenCL/cl.hpp>
#else
#include <CL/cl.hpp>
#endif

#include <vector>

class CLContext {
public:
    CLContext() noexcept(false);
    ~CLContext();

private:
    std::vector<cl::Platform> _findAllPlatforms() noexcept(false);
    std::vector<cl::Device> _findAllDevices(const std::vector<cl::Platform>& platforms) noexcept(false);

private:
    cl::Context _context;
    std::vector<cl::Device> _devices;
};
4
#endif //GRAD_DESC_HT_CLCONTEXT_HPP
