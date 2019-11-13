#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <iostream>
#include <stdexcept>
#include "Queue.h"
using namespace std;

class TestSuite
{
	private:

	Queue qMaster;

	public:

	/**
	*	@post Creates an empty queue
	*/
	TestSuite();

	void runTests();
	void test1(Queue& q);
	void test2(Queue& q);
	void test3(Queue& q);
	void test4(Queue& q);
	void test5(Queue& q);
};

#endif