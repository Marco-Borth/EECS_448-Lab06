#include "TestSuite.h"

TestSuite::TestSuite()
{
  isEmptyTest = false;
  peekFrontTest = false;
  runTests();
}

void TestSuite::runTests()
{
  TestIsEmpty();
  TestPeekFront();
  test7(qMaster);
  test8(qMaster);
  test9(qMaster);
  test10(qMaster);
}

void TestSuite::TestIsEmpty()
{
  cout << "Method Test 1: isEmpty()\n\n";
  if(isEmptyTest1(qMaster) && isEmptyTest2(qMaster))
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

void TestSuite::test7(Queue& q)
{
  cout << "Test 7: Enqueuing a value, then dequeuing, makes the Queue not empty: ";
  q.enqueue(5);
  q.dequeue();
	if(q.isEmpty()) {
		cout << "PASSED\n";
	} else {
		cout << "FAILED\n";
	}
}

void TestSuite::test8(Queue& q)
{
  cout << "Test 8: On empty queue, Enqueue 5, then 12, then dequeue, peekFront returns 5: ";
  q.enqueue(5);
  q.enqueue(12);
  q.dequeue();
  if(q.peekFront() == 5) {
		cout << "PASSED\n";
	} else {
		cout << "FAILED\n";
	}
}

void TestSuite::test9(Queue& q)
{
  cout << "Test 9: dequeue on empty queue throws an error: ";
  try {
    q.dequeue();
    cout << "FAILED\n";
  }
  catch (std::runtime_error& e) {
    cout << "PASSED\n";
  }
}

void TestSuite::test10(Queue& q)
{
  cout << "Test 10: On empty queue, Enqueue 5, then 12, then dequeue twice, peekFront throws an error: ";
  try {
    q.enqueue(5);
    q.enqueue(12);
    q.dequeue();
    q.dequeue();
    q.peekFront();
    cout << "FAILED\n";
  }
  catch (std::runtime_error& e) {
    cout << "PASSED\n";
  }
}
