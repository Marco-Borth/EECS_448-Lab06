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
	bool isEmptyTest, peekFrontTest;

	bool isEmptyTest1(Queue& q);
	bool isEmptyTest2(Queue& q);

	public:

	/**
	*	@post Creates an empty queue
	*/
	TestSuite();

	void runTests();

	void TestIsEmpty();

	void TestPeekFront();

	bool peekFrontTest1(Queue& q);
	bool peekFrontTest2(Queue& q);
	bool peekFrontTest3(Queue& q);
	bool peekFrontTest4(Queue& q);
	
	void test7(Queue& q);
	void test8(Queue& q);
	void test9(Queue& q);
	void test10(Queue& q);
};

#endif
