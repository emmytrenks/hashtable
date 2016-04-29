#include "hashtable.hpp"

int main(int argc, char **argv) {
  Hashtable<int> test(10);
  test.insert(5);
  return 0;
}
