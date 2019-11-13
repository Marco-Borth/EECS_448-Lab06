#include "TestSuite.h"

TestSuite::TestSuite()
{
  runTests();
}

void TestSuite::runTests()
{
  test1(qMaster);
  test2(qMaster);
  test3(qMaster);
  test4(qMaster);
  test5(qMaster);
}

void TestSuite::test1(Queue& q)
{
  cout << "Test 1: Newly created Queue is empty: ";
	if(q.isEmpty()) {
		cout << "PASSED\n";
	} else {
		cout << "FAILED\n";
	}
}

void TestSuite::test2(Queue& q)
{
  cout << "Test 2: Enqueing a value makes the Queue not empty: ";
  q.enqueue(5);
  if(!q.isEmpty()) {
		cout << "PASSED\n";
	} else {
		cout << "FAILED\n";
	}
}

void TestSuite::test3(Queue& q)
{
  cout << "Test 3: Enqueue 5 on empty queue then peekFront returns 5: ";
  q.enqueue(5);
  if(q.peekFront() == 5) {
		cout << "PASSED\n";
	} else {
		cout << "FAILED\n";
	}
}

void TestSuite::test4(Queue& q)
{
  cout << "Test 4: Enqueue 12 on empty queue then peekFront returns 12: ";
  q.enqueue(12);
  if(q.peekFront() == 12) {
		cout << "PASSED\n";
	} else {
		cout << "FAILED\n";
	}
}

void TestSuite::test5(Queue& q)
{
  cout << "Test 5: Enqueue 5, then 12, on empty queue then peekFront returns 5: ";
  q.enqueue(5);
  q.enqueue(12);
  if(q.peekFront() == 5) {
		cout << "PASSED\n";
	} else {
		cout << "FAILED\n";
	}
}
