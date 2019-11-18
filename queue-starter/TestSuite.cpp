#include "TestSuite.h"

TestSuite::TestSuite()
{
  isEmptyTest = false;
  peekFrontTest = false;
  dequeueTest = false;
  test1 = false;
  test2 = false;
  test3 = false;
  test4 = false;
  runTests();
}

void TestSuite::runTests()
{
  myfile.open ("buglist.txt");
  myfile << "Queue bug list:\n\n";

  bool errorHandlingPresent = true;
  bool peekCorrectFront = true;

  TestIsEmpty();
  if(!isEmptyTest) {
    myfile << "isEmpty Method is defective:\n\n";
    if(test1 == false) {
      myfile << "\tERROR: isEmpty() Test 1: Newly created Queue is NOT empty.\n";
    }

    if(test2 == false) {
      myfile << "\tERROR: isEmpty() Test 2: Enqueing a value makes the Queue still return as empty.\n";
    }

    if(test3 == false) {
      myfile << "\tERROR: isEmpty() Test 3: Enqueing two or more values makes the Queue still return as empty.\n";
    }
    myfile <<"\n";
  }

  TestPeekFront();
  if(!peekFrontTest) {
    myfile << "peekFront Method is defective:\n\n";
    if(test1 == false) {
      myfile << "\tERROR: peekFront() Test 1: peekFront does not return 5 when 5 is Enqueued.\n";
    }

    if(test2 == false) {
      myfile << "\tERROR: peekFront() Test 2: peekFront does not return 5 when 5 and 12 are Enqueued respectively, 5 should be the front of queue.\n";
      peekCorrectFront = false;
    }

    if(test3 == false) {
      myfile << "\tERROR: peekFront() Test 3: peekFront does not throw an error on an empty list.\n";
    }
    myfile <<"\n";
  }

  TestDequeue();
  if(!dequeueTest) {
    myfile << "dequeue Method is defective:\n\n";
    if(test1 == false) {
      myfile << "\tERROR: dequeue() Test 1: dequeue does not remove a single node entry at m_front.\n";
    }

    if(test2 == false) {
      myfile << "\tERROR: dequeue() Test 2: peekFront does not return 12 when 5 and 12 are Enqueued respectively, then 5, which is the front of queue, is dequeued.\n";
      peekCorrectFront = false;
    }

    if(test3 == false) {
      myfile << "\tERROR: dequeue() Test 3: dequeue does not throw an error on an empty list.\n";
      errorHandlingPresent = false;
    }

    if(test4 == false) {
      myfile << "\tERROR: dequeue() Test 4:peekFront does not return 21 when 5, 12, and 21 are Enqueued respectively, then 5 and 12 are dequeued.\n";
    }
    myfile <<"\n";
  }

  if(!peekCorrectFront) {
    myfile << "Possible error detected: Back of queue is returned as m_front of queue on identified methods.\n";
  }

  if(!errorHandlingPresent) {
    myfile << "Possible error detected: Lack of error handling for errors thrown on identified methods.\n";
  }

  if (isEmptyTest && peekFrontTest && dequeueTest) {
    cout << "no errors have been listed.";
  }

  myfile.close();

  if (!isEmptyTest || !peekFrontTest || !dequeueTest) {
    cout << "See 'buglist.txt' for list of errors.\n\n";
  } else {
    cout << "Queue Class Examination SUCCESSFUL.\n\n";
  }
}

void TestSuite::TestIsEmpty()
{
  cout << "Method Test 1: isEmpty()\n\n";
  test1 = isEmptyTest1(qMaster);
  test2 = isEmptyTest2(qMaster);
  test3 = isEmptyTest3(qMaster);
  if(test1 && test2 && test3)
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
  test1 = peekFrontTest1(qMaster);
  test2 = peekFrontTest2(qMaster);
  test3 = peekFrontTest3(qMaster);
  if(test1 && test2 && test3)
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
  test1 = dequeueTest1(qMaster);
  test2 = dequeueTest2(qMaster);
  test3 = dequeueTest3(qMaster);
  test4 = dequeueTest4(qMaster);
  if(test1 && test2 && test3 && test4)
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
  cout << "\tdequeue() Test 4: On empty queue, Enqueue 5, then 12, then 21, then dequeue twice, peekFront returns 21: ";
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
