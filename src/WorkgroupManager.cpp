//
// Created by Etheon on 2021-01-09.
//

#include "WorkgroupManager.hpp"

#include <stdexcept>
#include <algorithm>

WorkgroupManager::WorkgroupManager(std::vector<size_t> &preferredWorkSize, cl::NDRange &totalGlobalNDRange)
    noexcept(false)
{
    _numDevices = preferredWorkSize.size();

    if (_numDevices <= 0) {
        throw std::runtime_error("Vector size must be more than 1.");
    }
    if (totalGlobalNDRange[0] < 1 || totalGlobalNDRange[1] < 1 || totalGlobalNDRange[2] < 1) {
        throw std::runtime_error("Each value of NDRange must be more than 1");
    }

    _dispenseRates.resize(_numDevices);
    _workgroups.resize(_numDevices);
    _preferredWorkSize.resize(_numDevices);

    std::copy(preferredWorkSize.begin(), preferredWorkSize.end(), _preferredWorkSize.begin());

    _totalGlobalNDRange = totalGlobalNDRange;
    for (float& rates : _dispenseRates) {
        rates = 1.0f / _numDevices;
    }
    dispense();
}

void
WorkgroupManager::dispense()
    noexcept(false)
{
    cl::NDRange sumNDRange = cl::NullRange;
    int gx = _totalGlobalNDRange[0];
    int gy = _totalGlobalNDRange[1];

    for (int i = 0; i < _numDevices; ++i) {
        int p = _preferredWorkSize[i];
        int y = gy * _dispenseRates[i];

        _workgroups[i]._local = cl::NDRange(p, 1, 1);
        _workgroups[i]._offset = sumNDRange;
        _workgroups[i]._global = cl::NDRange(((gx - 1) / p + 1) * p, y,1);

        sumNDRange = cl::NDRange(0, sumNDRange[1] + y, 0);
    }

    _workgroups[_numDevices - 1]._global = cl::NDRange(_workgroups[_numDevices - 1]._global[0],
                                                       _workgroups[_numDevices - 1]._global[1] + _totalGlobalNDRange[1] - sumNDRange[1],
                                                       1);
}
