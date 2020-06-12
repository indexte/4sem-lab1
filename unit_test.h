/**
 * @file unit_test.h
 *
 */

#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include "sqlite_storage.h"
#include "text.h"
#include "section.h"
#define CONSOLE_OUTPUT true // set to false to get rid of the annoying gebug messages

struct test{
    bool passed;
    std::string function;
};
typedef struct test Test;

class UnitTest{
private:
    SqliteStorage *storage;
    std::vector<Test> tests;

public:
    UnitTest();
    ~UnitTest();

    void test();
};

#endif // UNIT_TEST_H
