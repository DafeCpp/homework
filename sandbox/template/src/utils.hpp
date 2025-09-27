#pragma once

#include <iostream>

namespace utils {

class Foo {
public:
  Foo() { std::cout << "Foo()\n"; }
  Foo(int) { std::cout << "Foo(int)\n"; }
  Foo(const std::string &s) { std::cout << s << "(string)\n"; }
  ~Foo() { std::cout << "~Foo()\n"; }
};

class IntArray {
public:
  IntArray() = delete;
  IntArray(int size);
  IntArray(int num, int size);
  ~IntArray();

  int GetSize() const;

  bool IsEmpty() const;

  void Resize(int size);

  int &operator[](int index);

  void Clear();

private:
  Foo foo;
  Foo bar;
  int *data_;
  int size_;
};

} // namespace utils