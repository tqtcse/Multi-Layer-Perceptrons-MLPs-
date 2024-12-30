#include "unit_test.hpp"

map<string, bool (UNIT_TEST_Heap::*)()> UNIT_TEST_Heap::TESTS;

int maxHeapComparator(int *&lhs, int *&rhs)
{
  if (*lhs < *rhs)
  {
    return +1;
  }
  else if (*lhs > *rhs)
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

int minHeapComparator(int *&lhs, int *&rhs)
{
  if (*lhs < *rhs)
  {
    return -1;
  }
  else if (*lhs > *rhs)
  {
    return +1;
  }
  else
  {
    return 0;
  }
}
int a_minHeapComparator(int &lhs, int &rhs)
{
  if (lhs < rhs)
  {
    return -1;
  }
  else if (lhs > rhs)
  {
    return +1;
  }
  else
  {
    return 0;
  }
}
int a_maxHeapComparator(int &lhs, int &rhs)
{
  if (lhs > rhs)
  {
    return -1;
  }
  else if (lhs < rhs)
  {
    return +1;
  }
  else
  {
    return 0;
  }
}
string strInt(int *&str) { return to_string(*str); }

void deleteInt(int *a) { delete a; }
// TODO unit test new
bool UNIT_TEST_Heap::heap01()
{
  string name = "heap01";
  //! data ------------------------------------
  Heap<int> heap;

  //! expect ----------------------------------
  string expect = "size=0;empty=1;[]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap02()
{
  string name = "heap02";
  //! data ------------------------------------
  Heap<int> heap;
  Heap<int> copy(heap);

  //! expect ----------------------------------
  string expect = "size=0;empty=1;[]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << copy.size() << ";empty=" << copy.empty() << ";"
         << copy.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap03()
{
  string name = "heap03";
  //! data ------------------------------------
  Heap<int> heap;
  Heap<int> copy;

  copy = heap;

  //! expect ----------------------------------
  string expect = "size=0;empty=1;[]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << copy.size() << ";empty=" << copy.empty() << ";"
         << copy.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap04()
{
  string name = "heap04";
  //! data ------------------------------------
  Heap<int> heap;
  heap.push(4);
  heap.push(2);
  heap.push(1);

  //! expect ----------------------------------
  string expect = "size=3;empty=0;[1,4,2]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap05()
{
  string name = "heap05";
  //! data ------------------------------------
  Heap<int> heap;
  heap.push(4);
  heap.push(2);
  heap.push(1);
  heap.push(7);
  heap.push(3);
  heap.push(9);
  heap.push(10);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(12);
  heap.push(11);
  heap.push(14);
  heap.push(13);
  heap.push(15);
  //! expect ----------------------------------
  string expect = "size=15;empty=0;[1,3,2,6,4,9,10,7,8,5,12,11,14,13,15]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap06()
{
  string name = "heap06";
  //! data ------------------------------------
  Heap<int> heap;
  heap.push(4);
  heap.push(2);
  heap.push(1);

  //! expect ----------------------------------
  string expect = "size=3;empty=0;[1,4,2]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap07()
{
  string name = "heap07";
  //! data ------------------------------------
  Heap<int> heap;

  //! expect ----------------------------------
  string expect = "Caught exception: Calling to peek with the empty heap.";

  //! output ----------------------------------
  stringstream output;
  try
  {
    output << heap.pop();
  }
  catch (const underflow_error &e)
  {
    output << "Caught exception: " << e.what();
  }

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap08()
{
  string name = "heap08";
  stringstream output;
  //! data ------------------------------------
  Heap<int> heap;
  heap.push(4);
  output << heap.pop() << endl;

  //! expect ----------------------------------
  string expect =
      "4\n\
size=0;empty=1;[]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap09()
{
  string name = "heap09";
  stringstream output;
  //! data ------------------------------------
  Heap<int> heap;
  heap.push(4);
  heap.push(2);
  heap.push(1);
  heap.push(7);
  heap.push(3);
  heap.push(9);
  heap.push(10);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(12);
  heap.push(11);
  heap.push(14);
  heap.push(13);
  heap.push(15);

  output << heap.pop() << heap.pop() << heap.pop() << endl;

  //! expect ----------------------------------
  string expect =
      "123\n\
size=12;empty=0;[4,5,9,6,12,11,10,7,8,13,14,15]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap10()
{
  string name = "heap10";
  //! data ------------------------------------
  Heap<int> heap;

  //! expect ----------------------------------
  string expect = "Caught exception: Calling to peek with the empty heap.";

  //! output ----------------------------------
  stringstream output;
  try
  {
    output << heap.peek();
  }
  catch (const underflow_error &e)
  {
    output << "Caught exception: " << e.what();
  }

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap11()
{
  string name = "heap11";
  stringstream output;
  //! data ------------------------------------
  Heap<int> heap;
  heap.push(4);
  heap.push(2);
  heap.push(1);
  heap.push(7);
  heap.push(3);
  heap.push(9);
  heap.push(10);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(12);
  heap.push(11);
  heap.push(14);
  heap.push(13);
  heap.push(15);

  output << heap.peek() << heap.peek() << heap.peek() << endl;

  //! expect ----------------------------------
  string expect =
      "111\n\
size=15;empty=0;[1,3,2,6,4,9,10,7,8,5,12,11,14,13,15]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap12()
{
  string name = "heap12";
  //! data ------------------------------------
  Heap<int> heap;
  heap.push(4);
  heap.push(2);
  heap.push(1);
  heap.remove(2);

  //! expect ----------------------------------
  string expect = "size=2;empty=0;[1,4]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap13()
{
  string name = "heap13";
  //! data ------------------------------------
  Heap<int> heap;
  heap.push(4);
  heap.push(2);
  heap.push(1);
  heap.push(7);
  heap.push(3);
  heap.push(9);
  heap.push(10);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(12);
  heap.push(11);
  heap.push(14);
  heap.push(13);
  heap.push(15);

  heap.remove(11);
  heap.remove(20);
  heap.remove(15);

  //! expect ----------------------------------
  string expect = "size=13;empty=0;[1,3,2,6,4,9,10,7,8,5,12,13,14]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap14()
{
  string name = "heap14";
  //! data ------------------------------------
  Heap<int> heap;
  heap.push(4);
  heap.push(2);
  heap.push(1);

  //! expect ----------------------------------
  string expect = "True\nsize=3;empty=0;[1,4,2]";

  //! output ----------------------------------
  stringstream output;
  output << (heap.contains(2) ? "True" : "False") << endl;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap15()
{
  string name = "heap15";
  //! data ------------------------------------
  Heap<int> heap;
  heap.push(4);
  heap.push(2);
  heap.push(1);

  //! expect ----------------------------------
  string expect = "False\nsize=3;empty=0;[1,4,2]";

  //! output ----------------------------------
  stringstream output;
  output << (heap.contains(0) ? "True" : "False") << endl;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap16()
{
  string name = "heap16";
  //! data ------------------------------------
  Heap<int *> heap(maxHeapComparator, Heap<int *>::free);
  heap.push(new int(4));
  heap.push(new int(2));
  heap.push(new int(1));

  //! expect ----------------------------------
  string expect = "size=3;empty=0;[4,2,1]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap17()
{
  string name = "heap17";
  //! data ------------------------------------
  Heap<int *> heap(maxHeapComparator, Heap<int *>::free);
  heap.push(new int(4));
  heap.push(new int(2));
  heap.push(new int(1));
  heap.push(new int(8));
  heap.push(new int(6));
  heap.push(new int(9));
  heap.push(new int(12));
  heap.push(new int(7));
  heap.push(new int(5));
  heap.push(new int(3));
  heap.push(new int(10));
  heap.push(new int(14));
  heap.push(new int(15));
  heap.push(new int(11));
  heap.push(new int(13));
  heap.push(new int(16));
  heap.push(new int(18));
  heap.push(new int(17));

  Heap<int *> copy(heap);

  //! expect ----------------------------------
  string expect =
      "size=18;empty=0;[18,17,14,16,7,12,13,10,15,3,4,1,9,8,11,2,6,5]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << copy.size() << ";empty=" << copy.empty() << ";"
         << copy.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap18()
{
  string name = "heap18";
  //! data ------------------------------------
  Heap<int *> heap(maxHeapComparator, Heap<int *>::free);
  heap.push(new int(4));
  heap.push(new int(2));
  heap.push(new int(1));
  heap.push(new int(8));
  heap.push(new int(6));
  heap.push(new int(9));
  heap.push(new int(12));
  heap.push(new int(7));
  heap.push(new int(5));
  heap.push(new int(3));
  heap.push(new int(10));
  heap.push(new int(14));
  heap.push(new int(15));
  heap.push(new int(11));
  heap.push(new int(13));
  heap.push(new int(16));
  heap.push(new int(18));
  heap.push(new int(17));

  Heap<int *> copy;
  copy = heap;

  //! expect ----------------------------------
  string expect =
      "size=18;empty=0;[18,17,14,16,7,12,13,10,15,3,4,1,9,8,11,2,6,5]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << copy.size() << ";empty=" << copy.empty() << ";"
         << copy.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap19()
{
  string name = "heap19";
  stringstream output;
  //! data ------------------------------------
  Heap<int *> heap(maxHeapComparator, Heap<int *>::free);
  heap.push(new int(4));
  heap.push(new int(2));
  heap.push(new int(1));
  heap.push(new int(8));
  heap.push(new int(6));
  heap.push(new int(9));
  heap.push(new int(12));
  heap.push(new int(7));
  heap.push(new int(5));
  heap.push(new int(3));
  heap.push(new int(10));
  heap.push(new int(14));
  heap.push(new int(15));
  heap.push(new int(11));
  heap.push(new int(13));
  heap.push(new int(16));
  heap.push(new int(18));
  heap.push(new int(17));

  int *a = heap.pop();
  output << *a << endl;
  delete a;

  //! expect ----------------------------------
  string expect =
      "18\nsize=17;empty=0;[17,16,14,15,7,12,13,10,5,3,4,1,9,8,11,2,6]";

  //! output ----------------------------------

  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap20()
{
  string name = "heap20";
  stringstream output;
  //! data ------------------------------------
  Heap<int *> heap(maxHeapComparator, Heap<int *>::free);
  heap.push(new int(4));
  heap.push(new int(2));
  heap.push(new int(1));
  heap.push(new int(8));
  heap.push(new int(6));
  heap.push(new int(9));
  heap.push(new int(12));
  heap.push(new int(7));
  heap.push(new int(5));
  heap.push(new int(3));
  heap.push(new int(10));
  heap.push(new int(14));
  heap.push(new int(15));
  heap.push(new int(11));
  heap.push(new int(13));
  heap.push(new int(16));
  heap.push(new int(18));
  heap.push(new int(17));

  int *a = heap.pop();
  output << *a << endl;
  delete a;
  a = heap.pop();
  output << *a << endl;
  delete a;
  heap.clear();

  //! expect ----------------------------------
  string expect = "18\n17\nsize=0;empty=1;[]";

  //! output ----------------------------------

  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap21()
{
  string name = "heap21";
  //! data ------------------------------------
  Heap<int *> heap(minHeapComparator, Heap<int *>::free);
  heap.push(new int(4));
  heap.push(new int(2));
  heap.push(new int(1));
  heap.push(new int(8));
  heap.push(new int(6));
  heap.push(new int(9));
  heap.push(new int(12));
  heap.push(new int(7));
  heap.push(new int(5));
  heap.push(new int(3));
  heap.push(new int(10));
  heap.push(new int(14));
  heap.push(new int(15));
  heap.push(new int(11));
  heap.push(new int(13));
  heap.push(new int(16));
  heap.push(new int(18));
  heap.push(new int(17));

  Heap<int *> copy;
  copy = heap;

  //! expect ----------------------------------
  string expect =
      "size=18;empty=0;[1,3,2,5,4,9,11,8,7,6,10,14,15,12,13,16,18,17]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << copy.size() << ";empty=" << copy.empty() << ";"
         << copy.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap22()
{
  string name = "heap22";
  //! data ------------------------------------
  Heap<int *> heap(minHeapComparator, Heap<int *>::free);
  heap.push(new int(4));
  heap.push(new int(2));
  heap.push(new int(1));
  heap.push(new int(8));
  heap.push(new int(6));
  heap.push(new int(9));
  heap.push(new int(12));
  heap.push(new int(7));
  heap.push(new int(5));
  heap.push(new int(3));
  heap.push(new int(10));
  heap.push(new int(14));
  int *value = new int(15);
  heap.push(value);
  heap.push(new int(11));
  heap.push(new int(13));
  heap.push(new int(16));
  heap.push(new int(18));
  heap.push(new int(17));

  heap.remove(value, deleteInt);

  //! expect ----------------------------------
  string expect = "size=17;empty=0;[1,3,2,5,4,9,11,8,7,6,10,14,17,12,13,16,18]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap23()
{
  string name = "heap23";
  //! data ------------------------------------
  Heap<int *> heap(minHeapComparator, Heap<int *>::free);
  heap.push(new int(4));
  heap.push(new int(2));
  heap.push(new int(1));
  heap.push(new int(8));
  heap.push(new int(6));
  heap.push(new int(9));
  heap.push(new int(12));
  heap.push(new int(7));
  heap.push(new int(5));
  heap.push(new int(3));
  heap.push(new int(10));
  heap.push(new int(14));
  heap.push(new int(15));
  heap.push(new int(11));
  heap.push(new int(13));
  heap.push(new int(16));
  heap.push(new int(18));
  heap.push(new int(17));

  //! expect ----------------------------------
  string expect = "1 3 2 5 4 9 11 8 7 6 10 14 15 12 13 16 18 17 ";

  //! output ----------------------------------
  stringstream output;
  for (auto i : heap)
  {
    output << *i << " ";
  }

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap24()
{
  string name = "heap24";
  //! data ------------------------------------
  Heap<int *> heap(minHeapComparator, Heap<int *>::free);
  heap.push(new int(4));
  heap.push(new int(2));
  heap.push(new int(1));
  heap.push(new int(8));
  heap.push(new int(6));
  heap.push(new int(9));
  heap.push(new int(12));
  heap.push(new int(7));
  heap.push(new int(5));
  heap.push(new int(3));
  heap.push(new int(10));
  heap.push(new int(14));
  heap.push(new int(15));
  heap.push(new int(11));
  heap.push(new int(13));
  heap.push(new int(16));
  heap.push(new int(18));
  heap.push(new int(17));

  //! expect ----------------------------------
  string expect = "1 4 2 7 6 14 11 13 18 12 10 15 ";

  //! output ----------------------------------
  stringstream output;
  int index = 0;
  for (auto i = heap.begin(); i != heap.end(); ++i)
  {
    if (index % 2)
      i.remove(deleteInt);
    output << **i << " ";
    index += 1;
  }

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap25()
{
  string name = "heap25";
  //! data ------------------------------------
  int array[] = {1, 4, 2};
  Heap<int> heap;
  heap.heapify(array, 3);

  //! expect ----------------------------------
  string expect = "size=3;empty=0;[1,4,2]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap26()
{
  string name = "heap26";
  //! data ------------------------------------
  int array[] = {15, 3, 8, 1, 20, 9, 4, 5, 12, 6,
                 11, 10, 7, 14, 2, 13, 17, 18, 19, 16};
  Heap<int> heap;
  heap.heapify(array, 20);

  //! expect ----------------------------------
  string expect =
      "size=20;empty=0;[1,3,2,5,6,7,4,13,12,16,11,10,9,14,8,15,17,18,19,20]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap27()
{
  string name = "heap27";
  //! data ------------------------------------
  int array[] = {};
  Heap<int> heap;
  heap.heapify(array, 0);

  //! expect ----------------------------------
  string expect = "size=0;empty=1;[]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap28()
{
  string name = "heap28";
  //! data ------------------------------------
  int *array[] = {new int(15), new int(3), new int(8), new int(1),
                  new int(20), new int(9), new int(4), new int(5),
                  new int(12), new int(6), new int(11), new int(10),
                  new int(7), new int(14), new int(2), new int(13),
                  new int(17), new int(18), new int(19), new int(16)};
  Heap<int *> heap(maxHeapComparator, Heap<int *>::free);
  heap.heapify(array, 20);

  //! expect ----------------------------------
  string expect =
      "size=20;empty=0;[20,19,14,18,16,9,10,13,17,11,6,8,7,4,2,1,12,5,15,3]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap29()
{
  string name = "heap29";
  //! data ------------------------------------
  int *array[] = {};
  Heap<int *> heap(maxHeapComparator, Heap<int *>::free);
  heap.heapify(array, 0);

  //! expect ----------------------------------
  string expect = "size=0;empty=1;[]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap30()
{
  string name = "heap30";
  //! data ------------------------------------
  int *array[] = {new int(15), new int(3), new int(8), new int(1),
                  new int(20), new int(9), new int(4), new int(5),
                  new int(12), new int(6), new int(11), new int(10),
                  new int(7), new int(14), new int(2), new int(13),
                  new int(17), new int(18), new int(19), new int(16)};
  Heap<int *> heap(&minHeapComparator, Heap<int *>::free);
  heap.heapify(array, 20);

  //! expect ----------------------------------
  string expect =
      "size=20;empty=0;[1,3,2,5,6,7,4,13,12,16,11,10,9,14,8,15,17,18,19,20]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap31()
{
  string name = "heap31";
  //! data ------------------------------------
  Heap<double> heap;
  heap.push(4);
  heap.push(2);
  heap.push(1);
  heap.push(4);
  heap.push(2);
  heap.push(1);
  //! expect ----------------------------------
  string expect = "size=6;empty=0;[1,2,1,4,4,2]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap32()
{
  string name = "heap32";
  //! data ------------------------------------
  Heap<double> heap;
  heap.push(4);
  heap.push(2);
  heap.push(1);
  heap.push(4);
  heap.push(2);
  heap.push(1);
  heap.remove(2);
  heap.remove(1);
  heap.remove(4);
  heap.remove(5);
  Heap<double> heap1 = heap;
  heap1.clear();
  heap.clear();
  //! expect ----------------------------------
  string expect = "size=0;empty=1;[]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap33()
{
  string name = "heap33";
  //! data ------------------------------------
  Heap<double> heap;
  heap.push(4);
  heap.push(2);
  heap.push(1);
  heap.pop();
  heap.pop();
  heap.pop();

  //! expect ----------------------------------
  string expect = "Caught exception: Calling to peek with the empty heap.";

  //! output ----------------------------------
  stringstream output;
  try
  {
    output << heap.peek();
  }
  catch (const underflow_error &e)
  {
    output << "Caught exception: " << e.what();
  }

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap34()
{
  string name = "heap34";
  //! data ------------------------------------
  Heap<int *> heap(&maxHeapComparator, Heap<int *>::free);
  int *data = new int(5);
  int *data1 = new int(5);
  heap.push(data);
  heap.push(data1);
  heap.remove(data, &deleteInt);
  // delete a;

  //! expect ----------------------------------
  string expect = "size=1;empty=0;[5]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap35()
{
  string name = "heap35";
  stringstream output;
  //! data ------------------------------------
  Heap<int> heap(&a_maxHeapComparator);
  heap.push(4);
  heap.push(2);
  heap.push(1);
  heap.push(7);
  heap.push(3);
  heap.push(9);
  heap.push(10);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(12);
  heap.push(11);
  heap.push(14);
  heap.push(13);
  heap.push(15);

  output << heap.pop() << heap.pop() << heap.pop() << endl;

  //! expect ----------------------------------
  string expect =
      "151413\n\
size=12;empty=0;[12,10,11,6,8,9,7,2,4,3,5,1]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Heap::heap36()
{
  string name = "heap36";
  stringstream output;
  //! data ------------------------------------
  Heap<int> heap(&a_maxHeapComparator);
  heap.push(4);
  heap.push(2);
  heap.push(1);
  heap.push(7);
  heap.push(3);
  heap.push(9);
  heap.push(10);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(12);

  output << heap.pop() << heap.pop() << heap.pop() << heap.peek() << endl;
  heap = heap;
  heap.clear();
  //! expect ----------------------------------
  string expect =
      "121098\n\
size=0;empty=1;[]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Heap::heap37()
{
  string name = "heap37";
  stringstream output;
  //! data ------------------------------------
  Heap<int> heap(&a_maxHeapComparator);
  heap.push(4);
  heap.push(2);
  heap.push(1);
  heap.push(7);
  heap.push(3);
  heap.push(9);
  heap.push(10);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(12);
  heap.push(11);
  heap.push(14);
  heap.push(13);
  heap.push(15);

  output << heap.contains(15) << heap.contains(16) << endl;

  //! expect ----------------------------------
  string expect =
      "10\n\
size=15;empty=0;[15,10,14,6,8,11,13,2,4,3,5,1,9,7,12]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Heap::heap38()
{
  string name = "heap38";
  Heap<int *> heap(minHeapComparator, Heap<int *>::free);
  heap.push(new int(4));
  heap.push(new int(2));
  heap.push(new int(1));
  heap.push(new int(8));
  heap.push(new int(6));
  heap.push(new int(9));
  heap.push(new int(12));
  heap.push(new int(7));
  heap.push(new int(5));
  heap.push(new int(3));
  heap.push(new int(10));
  heap.push(new int(14));
  heap.push(new int(15));
  heap.push(new int(11));
  heap.push(new int(13));
  heap.push(new int(16));
  heap.push(new int(18));
  heap.push(new int(17));
  stringstream output;
  int a = 15;
  int b = -100;
  output << heap.contains(&a) << heap.contains(&b) << endl;
  heap.clear();
  heap.push(new int(5));
  //! expect ----------------------------------
  string expect =
      "10\n\
size=1;empty=0;[5]";
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(&strInt);

  //! output ----------------------------------

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Heap::heap39()
{
  string name = "heap39";
  Heap<int *> heap(maxHeapComparator, Heap<int *>::free);
  heap.push(new int(4));
  heap.push(new int(2));
  heap.push(new int(1));
  heap.push(new int(8));
  heap.push(new int(6));
  heap.push(new int(9));
  heap.push(new int(12));
  heap.push(new int(7));
  heap.push(new int(5));
  Heap<int *> copy(heap);
  heap.push(new int(14));
  heap.push(new int(100));
  int a = 100;
  heap.remove(&a, &deleteInt);

  //! expect ----------------------------------
  string expect =
      "size=9;empty=0;[12,7,9,6,4,1,8,2,5]";

  //! output ----------------------------------
  stringstream output;
  output << "size=" << copy.size() << ";empty=" << copy.empty() << ";"
         << copy.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Heap::heap40()
{
  string name = "heap40";
  stringstream output;
  //! data ------------------------------------
  Heap<int> heap(&a_minHeapComparator);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.clear();
  heap = heap;
  heap.push(11);
  heap.push(11);
  heap.push(14);

  //! expect ----------------------------------
  string expect =
      "size=3;empty=0;[11,11,14]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Heap::heap41()
{
  string name = "heap41";
  stringstream output;
  //! data ------------------------------------
  Heap<int> heap(&a_minHeapComparator);
  heap = heap;
  heap.push(11);
  heap.push(11);
  heap.push(14);
  output << heap.peek() << endl;
  heap.remove(11);
  output << heap.peek() << endl;
  heap.remove(14);
  output << heap.peek() << endl;
  heap.remove(11);

  //! expect ----------------------------------
  string expect =
      "11\n11\n11\nsize=0;empty=1;[]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Heap::heap42()
{
  string name = "heap42";
  stringstream output;
  //! data ------------------------------------
  Heap<int> heap(&a_minHeapComparator);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(11);
  heap.push(11);
  heap.push(14);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(11);
  heap.push(11);
  heap.push(14);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(11);
  heap.push(11);
  heap.push(14);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(11);
  heap.push(11);
  heap.push(14);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(11);
  heap.push(11);
  heap.push(14);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(11);
  heap.push(11);
  heap.push(14);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(11);
  heap.push(11);
  heap.push(14);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(11);
  heap.push(11);
  heap.push(14);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(11);
  heap.push(11);
  heap.push(14);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(11);
  heap.push(11);
  heap.push(14);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(11);
  heap.push(11);
  heap.push(14);

  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(11);
  heap.push(11);
  heap.push(14);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(11);
  heap.push(11);
  heap.push(14);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(11);
  heap.push(11);
  heap.push(14);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(11);
  heap.push(11);
  heap.push(14);
  heap.push(6);
  heap.push(8);
  heap.push(5);
  heap.push(11);
  heap.push(11);
  heap.push(14);

  //! expect ----------------------------------
  string expect =
      "size=96;empty=0;[5,5,5,5,5,5,5,5,5,5,5,5,6,6,5,6,6,5,6,6,5,6,5,6,6,11,6,8,11,6,6,11,8,8,11,8,6,8,6,8,11,8,6,11,8,8,11,14,14,14,8,14,11,14,8,11,8,11,11,14,14,8,6,11,11,14,11,11,11,11,11,14,14,14,8,11,11,14,8,11,11,11,11,14,14,11,8,11,11,14,11,11,11,11,11,14]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Heap::heap43()
{
  string name = "heap43";
  stringstream output;
  //! data ------------------------------------
  Heap<int> heap(&a_minHeapComparator);
  int *a = new int(5);
  heap.push(*a);
  Heap<int> heap1 = heap;
  delete a;
  //! expect ----------------------------------
  string expect =
      "size=1;empty=0;[5]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Heap::heap44()
{
  string name = "heap44";
  stringstream output;
  //! data ------------------------------------
  Heap<int *> heap(&minHeapComparator);
  int a = 5;
  int b = 7;
  int c = 15;
  heap.push(&a);
  heap.push(&b);
  heap.push(&c);

  //! expect ----------------------------------
  string expect =
      "size=3;empty=0;[5,7,15]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Heap::heap45()
{
  string name = "heap45";
  stringstream output;
  //! data ------------------------------------
  Heap<int *> heap(minHeapComparator);
  int a = 5;
  int b = 6;
  int c = 7;
  int d = 8;
  heap.push(&a);
  heap.push(&b);
  heap.push(&c);
  heap = heap;
  output << heap.contains(&a);
  heap.remove(&b);

  //! expect ----------------------------------
  string expect =
      "1size=2;empty=0;[5,7]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap46()
{
  string name = "heap46";
  stringstream output;
  //! data ------------------------------------
  Heap<int> heap(a_minHeapComparator);
  int *a = new int(5);
  heap.push(*a);
  heap.push(*a);
  heap.push(*a);
  heap.push(*a);
  heap.push(*a);
  heap.push(*a);
  delete a;

  //! expect ----------------------------------
  string expect =
      "size=6;empty=0;[5,5,5,5,5,5]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Heap::heap47()
{
  string name = "heap47";
  stringstream output;
  //! data ------------------------------------
  Heap<int> heap(a_minHeapComparator);
  int *a = new int(5);
  heap.push(*a);
  heap.push(*a);
  heap.push(*a);
  heap.push(*a);
  heap.push(*a);
  heap.push(*a);
  heap.remove(*a);
  Heap<int> heap1 = heap;
  delete a;

  //! expect ----------------------------------
  string expect =
      "size=5;empty=0;[5,5,5,5,5]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Heap::heap48()
{
  string name = "heap48";
  stringstream output;
  //! data ------------------------------------
  Heap<int *> heap(maxHeapComparator);
  int *a = new int(5);
  heap.push(a);
  heap.push(a);
  heap.push(a);
  heap.push(a);
  heap.push(a);
  heap.push(a);

  //! expect ----------------------------------
  string expect =
      "size=6;empty=0;[5,5,5,5,5,5]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString(&strInt);

  //! remove data -----------------------------
  delete a;
  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Heap::heap49()
{
  string name = "heap49";
  stringstream output;
  //! data ------------------------------------
  Heap<int *> heap(minHeapComparator, Heap<int *>::free);
  Heap<int *> heap1(minHeapComparator, Heap<int *>::free);

  heap.push(new int(5));
  heap.push(new int(19));
  heap = heap1;
  //! expect ----------------------------------
  string expect =
      "size=0;empty=1;[]";

  //! output ----------------------------------
  output << "size=" << heap.size() << ";empty=" << heap.empty() << ";"
         << heap.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Heap::heap50()
{
  string name = "heap50";
  Heap<int *> heap(minHeapComparator, Heap<int *>::free);
  Heap<int *> heap1(minHeapComparator, Heap<int *>::free);
  stringstream output;
  heap.push(new int(5));
  heap.push(new int(19));
  heap = heap1;
  Heap<int *> copy(heap1);
  //! expect ----------------------------------
  string expect =
      "size=0;empty=1;[]";

  //! output ----------------------------------
  output << "size=" << copy.size() << ";empty=" << copy.empty() << ";"
         << copy.toString(&strInt);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}