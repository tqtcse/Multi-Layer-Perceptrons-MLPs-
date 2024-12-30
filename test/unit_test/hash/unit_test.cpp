#include "unit_test.hpp"

map<string, bool (UNIT_TEST_Hash::*)()> UNIT_TEST_Hash::TESTS;

// TODO unit test new

void newINT_delete(int *value) { delete value; }
bool newINT_EQ(int *&a, int *&b) { return *a == *b; }
int newINT_keyHash(int *&key, int capacity) { return *key % capacity; }

int INT_keyHash(int &key, int capacity) { return key % capacity; }
int newString_keyHash(string *&key, int capacity)
{
  int hashValue = 0;
  for (char c : *key)
  {
    hashValue += static_cast<int>(c);
  }
  return hashValue % capacity;
}
int String_keyHash(string &key, int capacity)
{
  int hashValue = 0;
  for (char c : key)
  {
    hashValue += static_cast<int>(c);
  }
  return hashValue % capacity;
}
string newINT_toString(int *&key) { return "n_" + to_string(*key); }
string INT_toString(int &key) { return "n_" + to_string(key); }
bool newString_EQ(string *&a, string *&b) { return *a == *b; }
void newString_delete(string *value) { delete value; }
string newString_toString(string *&key) { return *key; }
bool UNIT_TEST_Hash::hash01()
{

  string name = "hash01";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash);

  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   10\n\
size:       0\n\
0   : \n\
1   : \n\
2   : \n\
3   : \n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;

  output << "\n"
         << hash.toString();

  //! remove data -----------------------------

  //! result ----------------------------------

  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash02()
{
  string name = "hash02";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash);
  xMap<int, string> copy(hash);
  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   10\n\
size:       0\n\
0   : \n\
1   : \n\
2   : \n\
3   : \n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  output << "\n"
         << copy.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash03()
{
  string name = "hash03";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash);
  xMap<int, string> copy(xMap<int, string>::intKeyHash);
  copy = hash;
  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   10\n\
size:       0\n\
0   : \n\
1   : \n\
2   : \n\
3   : \n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  output << "\n"
         << hash.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash04()
{
  string name = "hash04";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash);
  hash.put(1, "votien1");
  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   10\n\
size:       1\n\
0   : \n\
1   :  (1,votien1)\n\
2   : \n\
3   : \n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  output << "\n"
         << hash.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash05()
{
  string name = "hash05";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(2, "votien2");
  hash.put(10, "votien10");

  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   10\n\
size:       5\n\
0   :  (10,votien10)\n\
1   :  (1,votien1); (11,votien11); (21,votien21)\n\
2   :  (2,votien2)\n\
3   : \n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  output << "\n"
         << hash.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash06()
{
  string name = "hash06";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.6);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   15\n\
size:       7\n\
0   : \n\
1   :  (1,votien1); (31,votien31); (61,votien61)\n\
2   : \n\
3   : \n\
4   : \n\
5   : \n\
6   :  (21,votien21); (51,votien51)\n\
7   : \n\
8   : \n\
9   : \n\
10  : \n\
11  :  (11,votien11); (41,votien41)\n\
12  : \n\
13  : \n\
14  : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  output << "\n"
         << hash.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash07()
{
  string name = "hash07";
  //! data ------------------------------------
  xMap<int *, string> hash(&newINT_keyHash, 0.45, 0,
                           xMap<int *, string>::freeKey);

  hash.put(new int(1), "votien1");
  hash.put(new int(11), "votien11");
  hash.put(new int(3), "votien3");
  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   10\n\
size:       3\n\
0   : \n\
1   :  (n_1,votien1); (n_11,votien11)\n\
2   : \n\
3   :  (n_3,votien3)\n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  output << "\n"
         << hash.toString(&newINT_toString);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash08()
{
  string name = "hash08";
  stringstream output;
  //! data ------------------------------------
  xMap<int *, string> hash(&newINT_keyHash, 1, 0, xMap<int *, string>::freeKey,
                           &newINT_EQ);
  int *key, *value;
  string s;

  hash.put(new int(1), "votien1");
  hash.put(new int(11), "votien11");
  hash.put(new int(3), "votien3");

  key = new int(1);
  output << hash.put(key, "votien_1");
  delete key;

  hash.put(new int(21), "votien21");
  hash.put(new int(31), "votien31");
  hash.put(new int(41), "votien41");
  hash.put(new int(51), "votien51");

  key = new int(11);
  output << hash.put(key, "votien_11");
  delete key;

  xMap<int *, string> copy(&newINT_keyHash);
  copy = hash;

  //! expect ----------------------------------
  string expect =
      "votien1votien11\n\
==================================================\n\
capacity:   10\n\
size:       7\n\
0   : \n\
1   :  (n_1,votien_1); (n_11,votien_11); (n_21,votien21); (n_31,votien31); (n_41,votien41); (n_51,votien51)\n\
2   : \n\
3   :  (n_3,votien3)\n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

  //! output ----------------------------------
  output << "\n"
         << copy.toString(&newINT_toString);

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash09()
{
  string name = "hash09";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.6);

  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");

  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   15\n\
size:       9\n\
0   : \n\
1   :  (1,votien_1); (31,votien31); (61,votien61)\n\
2   :  (2,votien2)\n\
3   :  (3,votien3)\n\
4   : \n\
5   : \n\
6   :  (21,votien21); (51,votien51)\n\
7   : \n\
8   : \n\
9   : \n\
10  : \n\
11  :  (11,votien11); (41,votien41)\n\
12  : \n\
13  : \n\
14  : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  output << "\n"
         << hash.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash10()
{
  string name = "hash10";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.6);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");

  //! expect ----------------------------------
  string expect = "votien_1";

  //! output ----------------------------------
  stringstream output;
  try
  {
    output << hash.get(1);
  }
  catch (const KeyNotFound &e)
  {
    output << "Caught exception: " << e.what() << std::endl;
  }

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash11()
{
  string name = "hash11";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.6);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");

  //! expect ----------------------------------
  string expect = "Caught exception: key (0) is not found";

  //! output ----------------------------------
  stringstream output;
  try
  {
    output << hash.get(0);
  }
  catch (const KeyNotFound &e)
  {
    output << "Caught exception: " << e.what();
  }

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash12()
{
  string name = "hash12";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.6);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");

  //! expect ----------------------------------
  string expect =
      "votien_1\n\
==================================================\n\
capacity:   15\n\
size:       8\n\
0   : \n\
1   :  (31,votien31); (61,votien61)\n\
2   :  (2,votien2)\n\
3   :  (3,votien3)\n\
4   : \n\
5   : \n\
6   :  (21,votien21); (51,votien51)\n\
7   : \n\
8   : \n\
9   : \n\
10  : \n\
11  :  (11,votien11); (41,votien41)\n\
12  : \n\
13  : \n\
14  : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  try
  {
    output << hash.remove(1) << endl;
  }
  catch (const KeyNotFound &e)
  {
    output << "Caught exception: " << e.what();
  }
  output << hash.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash13()
{
  string name = "hash13";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.6);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");

  //! expect ----------------------------------
  string expect =
      "Caught exception: key (0) is not found\n\
==================================================\n\
capacity:   15\n\
size:       9\n\
0   : \n\
1   :  (1,votien_1); (31,votien31); (61,votien61)\n\
2   :  (2,votien2)\n\
3   :  (3,votien3)\n\
4   : \n\
5   : \n\
6   :  (21,votien21); (51,votien51)\n\
7   : \n\
8   : \n\
9   : \n\
10  : \n\
11  :  (11,votien11); (41,votien41)\n\
12  : \n\
13  : \n\
14  : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  try
  {
    output << hash.remove(0) << endl;
  }
  catch (const KeyNotFound &e)
  {
    output << "Caught exception: " << e.what() << std::endl;
  }
  output << hash.toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash14()
{
  string name = "hash14";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.6);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");

  //! expect ----------------------------------
  string expect = "True";

  //! output ----------------------------------
  stringstream output;
  output << (hash.containsKey(51) ? "True" : "False");

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash15()
{
  string name = "hash15";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.6);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");

  //! expect ----------------------------------
  string expect = "False";

  //! output ----------------------------------
  stringstream output;
  output << (hash.containsKey(71) ? "True" : "False");

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash16()
{
  string name = "hash16";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.6);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");

  //! expect ----------------------------------
  string expect = "False";

  //! output ----------------------------------
  stringstream output;
  output << (hash.containsKey(22) ? "True" : "False");

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash17()
{
  string name = "hash17";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.6);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");

  //! expect ----------------------------------
  string expect = "True";

  //! output ----------------------------------
  stringstream output;
  output << (hash.containsValue("votien_1") ? "True" : "False");

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash18()
{
  string name = "hash18";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.6);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");

  //! expect ----------------------------------
  string expect = "False";

  //! output ----------------------------------
  stringstream output;
  output << (hash.containsValue("votien_2") ? "True" : "False");

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash19()
{
  string name = "hash19";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.6);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");

  //! expect ----------------------------------
  string expect = "False";

  //! output ----------------------------------
  stringstream output;
  output << (hash.containsValue("votien_71") ? "True" : "False");

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash20()
{
  string name = "hash20";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.6);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");

  //! expect ----------------------------------
  string expect = "[1, 31, 61, 2, 3, 21, 51, 11, 41]";

  //! output ----------------------------------
  stringstream output;
  output << hash.keys().toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash21()
{
  string name = "hash21";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.6);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");

  //! expect ----------------------------------
  string expect =
      "[votien_1, votien31, votien61, votien2, votien3, votien21, votien51, "
      "votien11, votien41]";

  //! output ----------------------------------
  stringstream output;
  output << hash.values().toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash22()
{
  string name = "hash22";

  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.6);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");

  //! expect ----------------------------------
  string expect = "[0, 3, 1, 1, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0]";

  //! output ----------------------------------
  stringstream output;
  output << hash.clashes().toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash23()
{
  string name = "hash23";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.5);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");

  //! expect ----------------------------------
  string expect =
      "0\n\
[1, 2, 3, 51, 31, 11, 61, 41, 21]\n\
[votien_1, votien2, votien3, votien51, votien31, votien11, votien61, votien41, votien21]\n\
[0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1]";

  //! output ----------------------------------
  stringstream output;
  output << hash.empty() << endl;
  output << hash.keys().toString() << endl;
  output << hash.values().toString() << endl;
  output << hash.clashes().toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash24()
{
  string name = "hash24";
  //! data ------------------------------------
  xMap<int, string> hash(xMap<int, string>::intKeyHash, 0.5);
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");
  hash.clear();
  //! expect ----------------------------------
  string expect =
      "1\n\
[]\n\
[]\n\
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]";

  //! output ----------------------------------
  stringstream output;
  output << hash.empty() << endl;
  output << hash.keys().toString() << endl;
  output << hash.values().toString() << endl;
  output << hash.clashes().toString();

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash25()
{
  string name = "hash25";
  //! data ------------------------------------
  xMap<int *, int *> hash(&newINT_keyHash, 1, &newINT_EQ,
                          xMap<int *, int *>::freeKey, &newINT_EQ,
                          xMap<int *, int *>::freeValue);
  int *key1 = new int(1);
  int *key11 = new int(11);
  int *key21 = new int(21);
  int *key31 = new int(31);
  int *key41 = new int(41);
  int *key51 = new int(51);
  int *key61 = new int(61);
  int *key2 = new int(2);
  int *key3 = new int(1);

  int *value1 = new int(100);
  int *value11 = new int(200);
  int *value21 = new int(300);
  int *value31 = new int(400);
  int *value41 = new int(500);
  int *value51 = new int(600);
  int *value61 = new int(700);
  int *value2 = new int(800);
  int *value3 = new int(900);

  hash.put(key1, value1);
  hash.put(key11, value11);
  hash.put(key21, value21);
  hash.put(key31, value31);
  hash.put(key41, value41);
  hash.put(key51, value51);
  hash.put(key61, value61);
  hash.put(key2, value2);
  hash.put(key3, value3);

  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   10\n\
size:       8\n\
0   : \n\
1   :  (n_1,n_900); (n_11,n_200); (n_21,n_300); (n_31,n_400); (n_41,n_500); (n_51,n_600); (n_61,n_700)\n\
2   :  (n_2,n_800)\n\
3   : \n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  output << "\n"
         << hash.toString(&newINT_toString, &newINT_toString);

  //! remove data -----------------------------
  delete value1;
  delete key3;

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash26()
{
  string name = "hash26";
  //! data ------------------------------------
  xMap<int *, int *> hash(&newINT_keyHash, 1, &newINT_EQ,
                          xMap<int *, int *>::freeKey, &newINT_EQ,
                          xMap<int *, int *>::freeValue);
  int *key1 = new int(1);
  int *key11 = new int(11);
  int *key21 = new int(21);
  int *key31 = new int(31);
  int *key41 = new int(41);
  int *key51 = new int(51);
  int *key61 = new int(61);
  int *key2 = new int(2);
  int *key3 = new int(1);

  int *value1 = new int(100);
  int *value11 = new int(200);
  int *value21 = new int(300);
  int *value31 = new int(400);
  int *value41 = new int(500);
  int *value51 = new int(600);
  int *value61 = new int(700);
  int *value2 = new int(800);
  int *value3 = new int(900);

  hash.put(key1, value1);
  hash.put(key11, value11);
  hash.put(key21, value21);
  hash.put(key31, value31);
  hash.put(key41, value41);
  hash.put(key51, value51);
  hash.put(key61, value61);
  hash.put(key2, value2);
  hash.put(key3, value3);

  hash.remove(key61, &newINT_delete);

  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   10\n\
size:       7\n\
0   : \n\
1   :  (n_1,n_900); (n_11,n_200); (n_21,n_300); (n_31,n_400); (n_41,n_500); (n_51,n_600)\n\
2   :  (n_2,n_800)\n\
3   : \n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  output << "\n"
         << hash.toString(&newINT_toString, &newINT_toString);

  //! remove data -----------------------------
  delete value1;
  delete key3;
  delete value61;

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash27()
{
  string name = "hash27";
  //! data ------------------------------------
  xMap<int *, int *> hash(&newINT_keyHash, 1, &newINT_EQ,
                          xMap<int *, int *>::freeKey, &newINT_EQ,
                          xMap<int *, int *>::freeValue);
  int *key1 = new int(1);
  int *key11 = new int(11);
  int *key21 = new int(21);
  int *key31 = new int(31);
  int *key41 = new int(41);
  int *key51 = new int(51);
  int *key61 = new int(61);
  int *key2 = new int(2);
  int *key3 = new int(1);

  int *value1 = new int(100);
  int *value11 = new int(200);
  int *value21 = new int(300);
  int *value31 = new int(400);
  int *value41 = new int(500);
  int *value51 = new int(600);
  int *value61 = new int(700);
  int *value2 = new int(800);
  int *value3 = new int(900);

  hash.put(key1, value1);
  hash.put(key11, value11);
  hash.put(key21, value21);
  hash.put(key31, value31);
  hash.put(key41, value41);
  hash.put(key51, value51);
  hash.put(key61, value61);
  hash.put(key2, value2);
  hash.put(key3, value3);

  hash.remove(key61, &newINT_delete);
  hash.remove(key31, value31, &newINT_delete, &newINT_delete);

  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   10\n\
size:       6\n\
0   : \n\
1   :  (n_1,n_900); (n_11,n_200); (n_21,n_300); (n_41,n_500); (n_51,n_600)\n\
2   :  (n_2,n_800)\n\
3   : \n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  output << "\n"
         << hash.toString(&newINT_toString, &newINT_toString);

  //! remove data -----------------------------
  delete value1;
  delete key3;
  delete value61;

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash28()
{
  string name = "hash28";
  //! data ------------------------------------
  xMap<int *, int *> hash(&newINT_keyHash, 1, &newINT_EQ,
                          xMap<int *, int *>::freeKey, &newINT_EQ,
                          xMap<int *, int *>::freeValue);
  int *key1 = new int(1);
  int *key11 = new int(11);
  int *key21 = new int(21);
  int *key31 = new int(31);
  int *key41 = new int(41);
  int *key51 = new int(51);
  int *key61 = new int(61);
  int *key2 = new int(2);
  int *key3 = new int(1);

  int *value1 = new int(100);
  int *value11 = new int(200);
  int *value21 = new int(300);
  int *value31 = new int(400);
  int *value41 = new int(500);
  int *value51 = new int(600);
  int *value61 = new int(700);
  int *value2 = new int(800);
  int *value3 = new int(900);

  hash.put(key1, value1);
  hash.put(key11, value11);
  hash.put(key21, value21);
  hash.put(key31, value31);
  hash.put(key41, value41);
  hash.put(key51, value51);
  hash.put(key61, value61);
  hash.put(key2, value2);
  hash.put(key3, value3);

  hash.remove(key61, &newINT_delete);
  hash.remove(key31, value31, &newINT_delete, &newINT_delete);
  xMap<int *, int *> copy(&newINT_keyHash);

  copy = hash;

  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   10\n\
size:       6\n\
0   : \n\
1   :  (n_1,n_900); (n_11,n_200); (n_21,n_300); (n_41,n_500); (n_51,n_600)\n\
2   :  (n_2,n_800)\n\
3   : \n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  output << "\n"
         << copy.toString(&newINT_toString, &newINT_toString);

  //! remove data -----------------------------
  delete value1;
  delete key3;
  delete value61;

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash29()
{
  string name = "hash29";
  //! data ------------------------------------
  xMap<int *, int *> hash(&newINT_keyHash, 1, &newINT_EQ,
                          xMap<int *, int *>::freeKey, &newINT_EQ,
                          xMap<int *, int *>::freeValue);
  int *key1 = new int(1);
  int *key11 = new int(11);
  int *key21 = new int(21);
  int *key31 = new int(31);
  int *key41 = new int(41);
  int *key51 = new int(51);
  int *key61 = new int(61);
  int *key2 = new int(2);
  int *key3 = new int(1);

  int *value1 = new int(100);
  int *value11 = new int(200);
  int *value21 = new int(300);
  int *value31 = new int(400);
  int *value41 = new int(500);
  int *value51 = new int(600);
  int *value61 = new int(700);
  int *value2 = new int(800);
  int *value3 = new int(900);

  hash.put(key1, value1);
  hash.put(key11, value11);
  hash.put(key21, value21);
  hash.put(key31, value31);
  hash.put(key41, value41);
  hash.put(key51, value51);
  hash.put(key61, value61);
  hash.put(key2, value2);
  hash.put(key3, value3);

  hash.remove(key61, &newINT_delete);
  hash.remove(key31, value31, &newINT_delete, &newINT_delete);
  xMap<int *, int *> copy = hash;

  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   10\n\
size:       6\n\
0   : \n\
1   :  (n_1,n_900); (n_11,n_200); (n_21,n_300); (n_41,n_500); (n_51,n_600)\n\
2   :  (n_2,n_800)\n\
3   : \n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  output << "\n"
         << copy.toString(&newINT_toString, &newINT_toString);

  //! remove data -----------------------------
  delete value1;
  delete key3;
  delete value61;

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash30()
{
  string name = "hash30";
  //! data ------------------------------------
  xMap<int *, int *> hash(&newINT_keyHash, 1, &newINT_EQ,
                          xMap<int *, int *>::freeKey, &newINT_EQ,
                          xMap<int *, int *>::freeValue);
  int *key1 = new int(1);
  int *key11 = new int(11);
  int *key21 = new int(21);
  int *key31 = new int(31);
  int *key41 = new int(41);
  int *key51 = new int(51);
  int *key61 = new int(61);
  int *key2 = new int(2);
  int *key3 = new int(1);

  int *value1 = new int(100);
  int *value11 = new int(200);
  int *value21 = new int(300);
  int *value31 = new int(400);
  int *value41 = new int(500);
  int *value51 = new int(600);
  int *value61 = new int(700);
  int *value2 = new int(800);
  int *value3 = new int(900);

  hash.put(key1, value1);
  hash.put(key11, value11);
  hash.put(key21, value21);
  hash.put(key31, value31);
  hash.put(key41, value41);
  hash.put(key51, value51);
  hash.put(key61, value61);
  hash.put(key2, value2);
  hash.put(key3, value3);

  hash.remove(key61, &newINT_delete);
  hash.remove(key31, value31, &newINT_delete, &newINT_delete);
  xMap<int *, int *> copy = hash;
  copy.clear();

  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   10\n\
size:       0\n\
0   : \n\
1   : \n\
2   : \n\
3   : \n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  hash.clear();
  output << "\n"
         << hash.toString(&newINT_toString, &newINT_toString);
  //! remove data -----------------------------
  delete value1;
  delete key3;
  delete value61;

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Hash::hash31()
{
  string name = "hash31";
  //! data ------------------------------------

  xMap<string *, string> hash(&newString_keyHash, 0.2, nullptr, nullptr, &newString_EQ,
                              xMap<string *, string>::freeKey);

  string *key1 = new string("key1");
  string *key11 = new string("key11");
  string *key113 = new string("key113");
  string *key1133 = new string("key1133");
  string *key111 = new string("key111");
  string *key1111 = new string("key1111");
  string *key11311 = new string("key11311");

  hash.put(key1, "value1");
  hash.put(key11, "value11");
  hash.put(key113, "value113");
  hash.put(key111, "value111");
  hash.put(key1133, "value1133");
  hash.put(key11311, "value11311");
  hash.put(key1111, "value113");

  //! expect ----------------------------------
  string expect =
      "no find delete\n\
==================================================\n\
capacity:   49\n\
size:       7\n\
0   : \n\
1   : \n\
2   : \n\
3   : \n\
4   : \n\
5   : \n\
6   : \n\
7   : \n\
8   : \n\
9   : \n\
10  : \n\
11  : \n\
12  : \n\
13  : \n\
14  : \n\
15  : \n\
16  : \n\
17  : \n\
18  : \n\
19  : \n\
20  : \n\
21  : \n\
22  : \n\
23  : \n\
24  : \n\
25  : \n\
26  : \n\
27  : \n\
28  : \n\
29  : \n\
30  : \n\
31  : \n\
32  : \n\
33  : \n\
34  : \n\
35  :  (key111,value111); (key1,value1); (key1111,value113); (key11,value11)\n\
36  : \n\
37  :  (key11311,value11311); (key113,value113)\n\
38  : \n\
39  :  (key1133,value1133)\n\
40  : \n\
41  : \n\
42  : \n\
43  : \n\
44  : \n\
45  : \n\
46  : \n\
47  : \n\
48  : \n\
==================================================\n";

  //! output ----------------------------------
  stringstream output;
  string *a = new string("a");
  try
  {

    hash.remove(a, nullptr); // Thử xóa một khóa không tồn tại
  }
  catch (const KeyNotFound &)
  {
    output << "no find delete";
  }
  delete a;
  output << "\n"
         << hash.toString(&newString_toString, nullptr);

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Hash::hash32()
{
  string name = "hash32";
  //! data ------------------------------------

  xMap<string *, string> hash(&newString_keyHash, 0.9, nullptr, nullptr, &newString_EQ,
                              xMap<string *, string>::freeKey);

  string *key1 = new string("key1");
  string *key11 = new string("key11");

  stringstream output;
  hash.put(key1, "value1");
  hash.put(key11, "value11");
  hash.put(key11, "value1");
  output << (bool)hash.remove(key11, "value1", &newString_delete) << "size :" << hash.size();

  //! expect ----------------------------------
  string expect = "1size :1";

  //! output ----------------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash33()
{
  string name = "hash33";
  //! data ------------------------------------

  xMap<string *, int *> hash(&newString_keyHash, 0.9, &newINT_EQ, xMap<string *, int *>::freeValue, &newString_EQ,
                             xMap<string *, int *>::freeKey);
  stringstream output;
  string *key0 = new string("key0");
  string *key11 = new string("key11");

  hash.put(key0, new int(0));
  hash.put(key11, new int(11));
  //! hash2
  xMap<string *, int *> hash2(&newString_keyHash, 0.8, &newINT_EQ, xMap<string *, int *>::freeValue, &newString_EQ,
                              xMap<string *, int *>::freeKey);
  string *key20 = new string("key0");
  string *key211 = new string("key11");
  hash2.put(key20, new int(01));
  hash2.put(key211, new int(11));
  hash2 = hash;
  //! get
  output << *(hash2.get(key0));
  //! expect ----------------------------------
  string expect = "0";

  //! output ----------------------------------
  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
bool UNIT_TEST_Hash::hash34()
{
  string name = "hash34";
  //! data ------------------------------------

  xMap<string *, int *> hash(&newString_keyHash, 0.1, &newINT_EQ, xMap<string *, int *>::freeValue, &newString_EQ,
                             xMap<string *, int *>::freeKey);
  stringstream output;
  string *key0 = new string("key0");
  string *key11 = new string("key11");
  string *keya = new string("keya");
  hash.put(key0, new int(0));
  hash.put(key11, new int(11));
  hash.put(keya, new int(11));
  //! hash2
  xMap<string *, int *> hash2(&newString_keyHash, 0.1, &newINT_EQ, xMap<string *, int *>::freeValue, &newString_EQ,
                              xMap<string *, int *>::freeKey);
  string *key20 = new string("key0");
  string *key211 = new string("key11");

  hash2.put(key20, new int(01));
  hash2.put(key211, new int(11));
  hash2 = hash;
  xMap<string *, int *> hash3 = hash2;
  output << "size: " << hash3.size() << "; capacity: " << hash3.getCapacity() << endl;
  //! expect ----------------------------------
  string expect = "size: 3; capacity: 22\n";

  //! output ----------------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash35()
{
  string name = "hash35";
  //! data ------------------------------------

  xMap<string *, int *> hash(&newString_keyHash, 0.6, &newINT_EQ, xMap<string *, int *>::freeValue, &newString_EQ,
                             xMap<string *, int *>::freeKey);

  string *key0 = new string("key0");
  string *key1 = new string("key1");
  string *key2 = new string("key2");
  string *key3 = new string("key3");
  string *key4 = new string("key4");
  string *key5 = new string("key5");
  string *key6 = new string("key6");
  string *key7 = new string("key7");
  string *key8 = new string("key8");
  string *key9 = new string("key9");
  string *key10 = new string("key10");
  hash.put(key1, new int(0));
  hash.put(key2, new int(0));
  hash.put(key3, new int(0));
  hash.put(key4, new int(0));
  hash.put(key5, new int(0));
  hash.put(key6, new int(0));
  hash.put(key7, new int(0));
  hash.put(key8, new int(0));
  hash.put(key9, new int(0));
  hash.put(key10, new int(0));
  hash.put(key0, new int(0));
  //! hash2

  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   22\n\
size:       11\n\
0   : \n\
1   : \n\
2   : \n\
3   :  (key0,n_0)\n\
4   :  (key1,n_0)\n\
5   :  (key2,n_0)\n\
6   :  (key3,n_0)\n\
7   :  (key4,n_0)\n\
8   :  (key10,n_0); (key5,n_0)\n\
9   :  (key6,n_0)\n\
10  :  (key7,n_0)\n\
11  :  (key8,n_0)\n\
12  :  (key9,n_0)\n\
13  : \n\
14  : \n\
15  : \n\
16  : \n\
17  : \n\
18  : \n\
19  : \n\
20  : \n\
21  : \n\
==================================================\n\nkey: [key0 key1 key2 key3 key4 key10 key5 key6 key7 key8 key9 ]\nvalue: [0 0 0 0 0 0 0 0 0 0 0 ]\n";

  //! output ----------------------------------
  stringstream output;
  output << "\n"
         << hash.toString(&newString_toString, &newINT_toString) << "\n";
  output << "key: [";
  for (auto it : hash.keys())
    output << *it << " ";
  output << "";
  output << "]\n";

  output << "value: [";
  for (auto it : hash.values())
    output << *it << " ";
  output << "";
  output << "]\n";

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash36()
{
  string name = "hash36";
  //! data ------------------------------------

  xMap<string, int *> hash(&String_keyHash, 0.6, &newINT_EQ, xMap<string, int *>::freeValue, nullptr, nullptr);

  hash.put("key1", new int(0));
  hash.put("key2", new int(0));
  hash.put("key3", new int(0));
  hash.put("key4", new int(0));
  hash.put("key5", new int(0));
  hash.put("key6", new int(0));
  hash.put("key7", new int(0));
  hash.put("key8", new int(0));
  hash.put("key9", new int(0));
  hash.put("key10", new int(0));
  hash.put("key11", new int(0));
  hash.put("key12", new int(0));

  //! hash2

  //! expect ----------------------------------
  string expect =
      "\n\
==================================================\n\
capacity:   22\n\
size:       12\n\
0   : \n\
1   : \n\
2   : \n\
3   : \n\
4   :  (key1,n_0)\n\
5   :  (key2,n_0)\n\
6   :  (key3,n_0)\n\
7   :  (key4,n_0)\n\
8   :  (key10,n_0); (key5,n_0)\n\
9   :  (key6,n_0); (key11,n_0)\n\
10  :  (key7,n_0); (key12,n_0)\n\
11  :  (key8,n_0)\n\
12  :  (key9,n_0)\n\
13  : \n\
14  : \n\
15  : \n\
16  : \n\
17  : \n\
18  : \n\
19  : \n\
20  : \n\
21  : \n\
==================================================\n\nkey: [key1 key2 key3 key4 key10 key5 key6 key11 key7 key12 key8 key9 ]\nvalue: [0 0 0 0 0 0 0 0 0 0 0 0 ]\n";

  //! output ----------------------------------
  stringstream output;
  output << "\n"
         << hash.toString(nullptr, &newINT_toString) << "\n";
  output << "key: [";
  for (auto it : hash.keys())
    output << it << " ";
  output << "";
  output << "]\n";

  output << "value: [";
  for (auto it : hash.values())
    output << *it << " ";
  output << "";
  output << "]\n";

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash37()
{
  string name = "hash37";
  //! data ------------------------------------

  xMap<string, int *> hash(&String_keyHash, 0.6, &newINT_EQ, xMap<string, int *>::freeValue, nullptr, nullptr);

  hash.put("key1", new int(0));
  hash.put("key2", new int(0));
  hash.put("key3", new int(0));
  hash.put("key4", new int(0));
  hash.put("key5", new int(9));
  hash.put("key6", new int(0));
  hash.put("key7", new int(0));
  hash.put("key8", new int(12));
  hash.put("key9", new int(0));
  hash.put("key10", new int(0));
  hash.put("key11", new int(10));
  hash.put("key12", new int(0));

  //! hash2
  xMap<string, int *> hash2 = hash;

  //! expect ----------------------------------
  string expect = "1\n1\n1\n0\n";

  //! output ----------------------------------
  stringstream output;
  output << hash2.containsKey("key1") << endl;
  output << hash2.containsKey("key12") << endl;
  int *tmp = new int(10);
  int *tmp1 = new int(1);
  output << hash2.containsValue(tmp) << endl;
  output << hash2.containsValue(tmp1) << endl;
  delete tmp;
  delete tmp1;
  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash38()
{
  string name = "hash38";
  //! data ------------------------------------

  xMap<string, int *> hash(&String_keyHash, 0.2, &newINT_EQ, xMap<string, int *>::freeValue, nullptr, nullptr);

  hash.put("key1", new int(0));
  hash.put("key2", new int(0));
  hash.put("key3", new int(0));
  hash.put("key4", new int(0));
  hash.put("key5", new int(9));
  hash.put("key6", new int(0));
  hash.put("key7", new int(0));
  hash.put("key8", new int(12));
  hash.put("key9", new int(0));
  hash.put("key10", new int(0));
  hash.put("key11", new int(10));
  hash.put("key12", new int(0));

  //! hash2
  xMap<string, int *> hash2 = hash;
  //! operator =
  hash2 = hash2;

  //! expect ----------------------------------
  string expect = "1\n1\n1\n0\nsize : 12\n";

  //! output ----------------------------------
  stringstream output;
  output << hash2.containsKey("key1") << endl;
  output << hash2.containsKey("key12") << endl;
  int *tmp = new int(10);
  int *tmp1 = new int(-1);
  output << hash2.containsValue(tmp) << endl;
  output << hash2.containsValue(tmp1) << endl;
  output << "size : " << hash2.size() << endl;
  delete tmp;
  delete tmp1;
  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash39()
{
  string name = "hash39";
  //! data ------------------------------------

  xMap<string, int *> hash(&String_keyHash, 0.2, &newINT_EQ, nullptr, nullptr, nullptr);
  stringstream output;
  int *temp = new int(0);
  int *temp1 = new int(10);
  hash.put("key1", temp);
  hash.put("key2", temp);
  hash.put("key3", temp);
  hash.put("key4", temp);
  hash.put("key5", temp);
  hash.put("key6", temp);
  hash.put("key7", temp);
  hash.put("key8", temp);
  hash.put("key9", temp);
  hash.put("key10", temp);
  output << "put : " << *(hash.put("key10", temp1));
  hash.put("key11", temp);
  hash.put("key12", temp);
  output << "put : " << *(hash.put("key12", temp1));

  //! hash2

  //! expect ----------------------------------
  string expect = "put : 0put : 0";

  //! output ----------------------------------
  delete temp1;
  delete temp;
  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash40()
{
  string name = "hash40";
  //! data ------------------------------------

  xMap<string *, int *> hash(&newString_keyHash, 0.2, &newINT_EQ, nullptr, &newString_EQ, nullptr);
  stringstream output;
  int *temp = new int(0);
  int *temp1 = new int(10);
  string *str = new string("abc");
  string *str1 = new string("xyz");
  string *str3 = new string("hrm");

  hash.put(str1, temp);
  output << "put : " << *(hash.put(str1, temp1));
  hash.put(str1, temp);
  hash.put(str3, temp);
  output << "put : " << *(hash.put(str, temp1));

  //! hash2

  //! expect ----------------------------------
  string expect = "put : 0put : 10";

  //! output ----------------------------------
  delete temp1;
  delete temp;
  delete str3;
  delete str1;
  delete str;
  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash41()
{
  string name = "hash41";
  //! data ------------------------------------

  xMap<string, int> hash(&String_keyHash, 0.2, nullptr, nullptr, nullptr, nullptr);
  stringstream output;
  int *temp = new int(0);
  int *temp1 = new int(10);
  string *str = new string("abc");
  string *str1 = new string("xyz");
  string *str3 = new string("hrm");

  hash.put(*str1, *temp);
  output << "put : " << hash.put(*str1, *temp1);
  hash.put(*str1, *temp);
  hash.put(*str3, *temp);
  output << "put : " << hash.put(*str, *temp1);

  //! expect ----------------------------------
  string expect = "put : 0put : 10";

  //! output ----------------------------------
  delete temp1;
  delete temp;
  delete str3;
  delete str1;
  delete str;
  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash42()
{
  string name = "hash42";
  //! data ------------------------------------

  xMap<string, int> hash(&String_keyHash, 0.2, nullptr, nullptr, nullptr, nullptr);
  stringstream output;
  int *temp = new int(0);
  int *temp1 = new int(10);
  string *str = new string("abc");
  string *str1 = new string("xyz");
  string *str3 = new string("hrm");

  hash.put(*str1, *temp);
  hash.put(*str1, *temp1);
  hash.put(*str1, *temp);
  hash.put(*str3, *temp);
  hash.put(*str, *temp1);

  //! expect ----------------------------------
  string expect = "containskey : 1\ncontainsvalue : 1\nsize : 3\nremove : 10\n";

  //! output ----------------------------------
  output << "containskey : " << hash.containsKey("abc") << endl;
  output << "containsvalue : " << hash.containsValue(0) << endl;
  output << "size : " << hash.size() << endl;
  output << "remove : " << hash.remove("abc") << endl;

  delete temp1;
  delete temp;
  delete str3;
  delete str1;
  delete str;
  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash43()
{
  string name = "hash43";
  //! data ------------------------------------

  xMap<int, string> hash(&INT_keyHash, 0.2, nullptr, nullptr, nullptr, nullptr);
  stringstream output;
  int *temp = new int(0);
  int *temp1 = new int(10);
  string *str = new string("abc");
  string *str1 = new string("xyz");
  string *str3 = new string("hrm");

  hash.put(*temp, *str);
  hash.put(*temp1, *str1);
  hash.put(*temp, *str3);

  //! expect ----------------------------------
  string expect = "containskey : 1\ncontainsvalue : 0\nsize : 2\nremove : hrm\n";

  //! output ----------------------------------
  output << "containskey : " << hash.containsKey(0) << endl;
  output << "containsvalue : " << hash.containsValue("abc") << endl;
  output << "size : " << hash.size() << endl;
  output << "remove : " << hash.remove(0) << endl;

  delete temp1;
  delete temp;
  delete str3;
  delete str1;
  delete str;
  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash44()
{
  string name = "hash44";
  //! data ------------------------------------

  xMap<int, string> hash(&INT_keyHash, 0.2, nullptr, nullptr, nullptr, nullptr);
  stringstream output;

  hash.put(1, "*str");
  hash.put(10, "*str1");
  hash.put(20, "*str3");
  hash.put(30, "*str3");
  hash.put(40, "*str3");
  hash.put(50, "*str3");
  hash.put(60, "votien3");
  hash.put(70, "votien3");
  hash.put(80, "votien3");
  hash.put(100, "votien");

  //! expect ----------------------------------
  string expect = "containskey : 0\ncontainsvalue : 0\nsize : 10\nno find delete\n";

  //! output ----------------------------------
  output << "containskey : " << hash.containsKey(0) << endl;
  output << "containsvalue : " << hash.containsValue("abc") << endl;
  output << "size : " << hash.size() << endl;
  try
  {

    hash.remove(0);
  }
  catch (const KeyNotFound &)
  {
    output << "no find delete\n";
  }

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash45()
{
  string name = "hash45";
  //! data ------------------------------------

  xMap<int, string> hash(&INT_keyHash, 0.2, nullptr, nullptr, nullptr, nullptr);
  stringstream output;

  hash.put(1, "*str");
  hash.put(10, "*str1");
  hash.put(20, "*str3");
  hash.put(30, "*str3");
  hash.put(40, "*str3");
  hash.put(50, "*str3");
  hash.put(60, "votien60");
  hash.put(70, "votien70");
  hash.put(80, "votien80");
  hash.put(100, "votien100");
  hash.put(1000, "votien100");
  hash.put(10001, "votien1001");

  //! expect ----------------------------------
  string expect = "keys : [10001, 1, 80, 10, 20, 100, 30, 40, 50, 1000, 60, 70]\nvalues : [votien1001, *str, votien80, *str1, *str3, votien100, *str3, *str3, *str3, votien100, votien60, votien70]\nclashes : [1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0]\n";

  //! output ----------------------------------
  output << "keys : " << hash.keys().toString() << endl;
  output << "values : " << hash.values().toString() << endl;
  output << "clashes : " << hash.clashes().toString() << endl;

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}


bool UNIT_TEST_Hash::hash46()
{
  string name = "hash46";
  //! data ------------------------------------

  xMap<int, string> hash(&INT_keyHash, 0.2, nullptr, nullptr, nullptr, nullptr);
  stringstream output;

  output<<"empty: "<<hash.empty()<<endl;
  output<<"clashes"<<hash.clashes().toString()<<endl;
  hash.put(10,"votien");
  hash.put(0,"votien0");
  hash.put(0,"5");
  output<<"empty: "<<hash.empty()<<endl;
  hash.clear();
  output<<"size : "<<hash.size();

  //! expect ----------------------------------
  string expect = "empty: 1\nclashes[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]\nempty: 0\nsize : 0";

 

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}


bool UNIT_TEST_Hash::hash47()
{
  string name = "hash47";
  //! data ------------------------------------

  xMap<int, string> hash(&INT_keyHash, 0.2, nullptr, nullptr, nullptr, nullptr);
  stringstream output;

  output<<"empty: "<<hash.empty()<<endl;
  output<<"clashes"<<hash.clashes().toString()<<endl;
  output<<"size"<<hash.size()<<endl;
  hash.put(1, "votien1");
  hash.put(11, "votien11");
  hash.put(21, "votien21");
  hash.put(31, "votien31");
  hash.put(41, "votien41");
  hash.put(51, "votien51");
  hash.put(61, "votien61");
  hash.put(2, "votien2");
  hash.put(3, "votien3");
  hash.put(1, "votien_1");
  output<<"empty: "<<hash.empty()<<endl;
  hash.clear();
  hash = hash;
  xMap<int, string> hash2 = hash;
  output<<"size : "<<hash2.size()<<endl;
  output<<"Capacity : "<<hash2.getCapacity()<<endl;

  //! expect ----------------------------------
  string expect = "empty: 1\nclashes[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]\nsize0\nempty: 0\nsize : 0\nCapacity : 10\n";

 

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}


bool UNIT_TEST_Hash::hash48()
{
  string name = "hash48";
  //! data ------------------------------------

  xMap<int*, string> hash(&newINT_keyHash, 0.2, nullptr, nullptr, &newINT_EQ, xMap<int *, string>::freeKey);
  stringstream output;

 
  int *key1 = new int(1);
  int *key11 = new int(11);
  int *key21 = new int(21);
  int *key31 = new int(31);
  int *key41 = new int(41);
  int *key51 = new int(51);
  int *key61 = new int(61);
  int *key2 = new int(2);
  int *key3 = new int(1);


  hash.put(key1, "value1");
  hash.put(key11, "value11");
  hash.put(key21, "value21");
  hash.put(key31, "value31");
  hash.put(key41, "value41");
  hash.put(key51, "value51");
  hash.put(key61, "value61");
  hash.put(key2, "value2");
  hash.put(key3, "value3");
 
  output << "values : " << hash.values().toString() << endl;
  delete key3;
  hash.remove(key1,"value1",&newINT_delete,nullptr);
  //! expect ----------------------------------
  string expect = "values : [value3, value51, value2, value11, value61, value21, value31, value41]\n";

 

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}


bool UNIT_TEST_Hash::hash49()
{
  string name = "hash49";
  //! data ------------------------------------

  xMap<int*, string> hash(&newINT_keyHash, 0.2, nullptr, nullptr, &newINT_EQ, xMap<int *, string>::freeKey);
  stringstream output;

 
  int *key1 = new int(1);
  int *key11 = new int(11);
  int *key21 = new int(21);
  int *key31 = new int(31);
  int *key41 = new int(41);
  int *key51 = new int(51);
  int *key61 = new int(61);
  int *key2 = new int(2);
  int *key3 = new int(1);


  hash.put(key1, "value1");
  hash.put(key11, "value11");
  hash.put(key21, "value21");
  hash.put(key31, "value31");
  hash.put(key41, "value41");
  hash.put(key51, "value51");
  hash.put(key61, "value61");
  hash.put(key2, "value2");
  hash.put(key3, "value3");
 
  output << "values : " << hash.values().toString() << endl;
  delete key3;
  //! remove
  hash.remove(key1,"value3",nullptr,nullptr);
  delete key1;
  //! expect ----------------------------------
  string expect = "values : [value3, value51, value2, value11, value61, value21, value31, value41]\n";

 

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}

bool UNIT_TEST_Hash::hash50()
{
  string name = "hash50";
  //! data ------------------------------------

  xMap<int, int*> hash(&INT_keyHash, 0.2, &newINT_EQ, xMap<int , int *>::freeValue, nullptr, nullptr);
  stringstream output;

 int *value1 = new int(100);
  int *value11 = new int(200);
  int *value21 = new int(300);
  int *value31 = new int(400);
  int *value41 = new int(500);
  int *value51 = new int(600);
  int *value61 = new int(700);
  int *value2 = new int(800);
  int *value3 = new int(900);

  hash.put(2, value1);
  hash.put(3, value11);
  hash.put(4, value21);
  hash.put(5, value31);
  hash.put(6, value41);
  hash.put(7, value51);
  hash.put(8, value61);
  hash.put(8, value2);
  hash.put(9, value3);
 delete value61;
  output << "key : " << hash.keys().toString() << endl;
  
   hash.remove(9,value3,nullptr,&newINT_delete);
  //! expect ----------------------------------
  string expect = "key : [2, 3, 4, 5, 6, 7, 8, 9]\n";

 

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}