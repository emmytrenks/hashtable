#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <vector>
#include <cmath>
#include <algorithm>

template<class T>
class Hashtable {
private:
  int count;
  std::vector<std::vector<T>> buckets;
public:
  Hashtable() : Hashtable(101) { }
  Hashtable(const int &buckets) : count(0) {
    this->buckets.resize(std::max(1, buckets));
  }

  void insert(const T t) {
    std::vector<T> &v = buckets[hash(t)];
    if (std::find(v.begin(), v.end(), t) != v.end()) return;
    v.push_back(t);
    if (++count > buckets.size()) rehash();
  }

  void remove(const T t) {
    std::vector<T> &v = buckets[hash(t)];
    auto pos = std::find(v.begin(), v.end(), t);
    if (pos == v.end()) return;
    v.erase(pos);
    --count;
  }

  int size() { return count; }

private:
  void rehash() {
    std::vector<T> temp;
    for (auto &v : buckets) for (auto t : v) temp.push_back(t);
    for (auto t : temp) remove(t);
    buckets.resize(buckets.size() * 2);
    for (auto t : temp) insert(t);
  }

  inline int hash(const T &t) { return t % buckets.size(); }
};

#endif
