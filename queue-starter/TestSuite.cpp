#include "TestSuite.h"

TestSuite::TestSuite()
{
  isEmptyTest = false;
  peekFrontTest = false;
  dequeueTest = false;
  runTests();
}

void TestSuite::runTests()
{
  TestIsEmpty();
  TestPeekFront();
  TestDequeue();
}

void TestSuite::TestIsEmpty()
{
  cout << "Method Test 1: isEmpty()\n\n";
  if(isEmptyTest1(qMaster) && isEmptyTest2(qMaster) && isEmptyTest3(qMaster))
  {
    isEmptyTest = true;
  }
  cout << "\n";
}

bool TestSuite::isEmptyTest1(Queue& q)
{
  cout << "\tisEmpty() Test 1: Newly created Queue is empty: ";
	if(q.isEmpty()) {
		cout << "PASSED\n";
    return true;
	} else {
		cout << "FAILED\n";
    return false;
	}
}

bool TestSuite::isEmptyTest2(Queue& q)
{
  cout << "\tisEmpty() Test 2: Enqueing a value makes the Queue not empty: ";
  q.enqueue(5);
  if(!q.isEmpty()) {
		cout << "PASSED\n";
    return true;
	} else {
		cout << "FAILED\n";
    return false;
	}
}

bool TestSuite::isEmptyTest3(Queue& q)
{
  cout << "\tisEmpty() Test 3: Enqueing two or more values makes the Queue not empty: ";
  q.enqueue(5);
  q.enqueue(12);
  if(!q.isEmpty()) {
		cout << "PASSED\n";
    return true;
	} else {
		cout << "FAILED\n";
    return false;
	}
}

void TestSuite::TestPeekFront()
{
  cout << "Method Test 2: peekFront()\n\n";
  if(peekFrontTest1(qMaster) && peekFrontTest2(qMaster) && peekFrontTest3(qMaster))
  {
    peekFrontTest = true;
  }
  cout << "\n";
}

bool TestSuite::peekFrontTest1(Queue& q)
{
  cout << "\tpeekFront() Test 1: Enqueue 5 on empty queue then peekFront returns 5: ";
  q.enqueue(5);
  if(q.peekFront() == 5) {
		cout << "PASSED\n";
    return true;
	} else {
		cout << "FAILED\n";
    return false;
	}
}

bool TestSuite::peekFrontTest2(Queue& q)
{
  cout << "\tpeekFront() Test 2: Enqueue 5, then 12, on empty queue then peekFront returns 5: ";
  q.enqueue(5);
  q.enqueue(12);
  if(q.peekFront() == 5) {
		cout << "PASSED\n";
    return true;
	} else {
		cout << "FAILED\n";
    return false;
	}
}

bool TestSuite::peekFrontTest3(Queue& q)
{
  cout << "\tpeekFront() Test 3: peekFront on empty queue throws an error: ";
  try {
    q.peekFront();
    cout << "FAILED\n";
    return false;
  }
  catch (std::runtime_error& e) {
    cout << "PASSED\n";
    return true;
  }
}

void TestSuite::TestDequeue()
{
  cout << "Method Test 3: dequeue()\n\n";
  if(dequeueTest1(qMaster) && dequeueTest2(qMaster) && dequeueTest3(qMaster) && dequeueTest4(qMaster))
  {
    dequeueTest = true;
  }
  cout << "\n";
}

bool TestSuite::dequeueTest1(Queue& q)
{
  cout << "\tdequeue() Test 1: Enqueuing a value, then dequeuing, makes the Queue not empty: ";
  q.enqueue(5);
  q.dequeue();
	if(q.isEmpty()) {
		cout << "PASSED\n";
    return true;
	} else {
		cout << "FAILED\n";
    return false;
	}
}

bool TestSuite::dequeueTest2(Queue& q)
{
  cout << "\tdequeue() Test 2: On empty queue, Enqueue 5, then 12, then dequeue, peekFront returns 12: ";
  q.enqueue(5);
  q.enqueue(12);
  q.dequeue();
  if(q.peekFront() == 12) {
		cout << "PASSED\n";
    return true;
	} else {
		cout << "FAILED\n";
    return false;
	}
}

bool TestSuite::dequeueTest3(Queue& q)
{
  cout << "\tdequeue() Test 3: dequeue on empty queue throws an error: ";
  try {
    q.dequeue();
    cout << "FAILED\n";
    return false;
  }
  catch (std::runtime_error& e) {
    cout << "PASSED\n";
    return true;
  }
}

bool TestSuite::dequeueTest4(Queue& q)
{
  cout << "\tdequeue() Test 4: On empty queue, Enqueue 5, then 12, then 21, then dequeue twice, peekFront returns 12: ";
  q.enqueue(5);
  q.enqueue(12);
  q.enqueue(21);
  if(q.peekFront() == 21) {
		cout << "PASSED\n";
    return true;
	} else {
		cout << "FAILED\n";
    return false;
	}
}
