#include "CLContext.hpp"

#include <iostream>
#include <memory>

using namespace std;

int
main(void) {
    try {
        unique_ptr<CLContext> context = make_unique<CLContext>();


    }
    catch (const cl::Error& err) {
        cerr << "Error: " << err.what() << endl;
    }

    return EXIT_SUCCESS;
}