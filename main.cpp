/**
 * @file main.cpp
 *
 * @brief This file is the entry point to program.
 *
 */

#include "mainwindow.h"
#include "unit_test.h"
#include <QApplication>
#define TESTS_INCLUDED true

void test();

int main(int argc, char *argv[])
{
    if(TESTS_INCLUDED)
        test();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

void test() {
    UnitTest test;
    test.test();
}
