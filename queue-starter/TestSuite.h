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
	bool isEmptyTest, peekFrontTest, dequeueTest;

	bool isEmptyTest1(Queue& q);
	bool isEmptyTest2(Queue& q);
	bool isEmptyTest3(Queue& q);

	bool peekFrontTest1(Queue& q);
	bool peekFrontTest2(Queue& q);
	bool peekFrontTest3(Queue& q);

	bool dequeueTest1(Queue& q);
	bool dequeueTest2(Queue& q);
	bool dequeueTest3(Queue& q);
	bool dequeueTest4(Queue& q);

	public:

	/**
	*	@post Creates an empty queue
	*/
	TestSuite();

	void runTests();

	void TestIsEmpty();

	void TestPeekFront();

	void TestDequeue();
};

#endif
