#ifndef OOP_L5_TESTALL_H
#define OOP_L5_TESTALL_H

#include "../Test/TestDomain.h"
#include "../Test/TestRepo.h"
#include "TestController.h"

/**
 * the function that holds all the other test function from all the other components
 */
void testAll() {
    testDomain();
    testRepo();
    testController();
}
#endif //OOP_L5_TESTALL_H
