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
	bool isEmptyTest;

	public:

	/**
	*	@post Creates an empty queue
	*/
	TestSuite();

	void runTests();

	void TestIsEmpty();

	bool isEmptyTest1(Queue& q);
	bool isEmptyTest2(Queue& q);

	void test3(Queue& q);
	void test4(Queue& q);
	void test5(Queue& q);
	void test6(Queue& q);
	void test7(Queue& q);
	void test8(Queue& q);
	void test9(Queue& q);
	void test10(Queue& q);
};

#endif
