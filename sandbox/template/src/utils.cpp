#include "utils.hpp"
#include <climits>
#include <cstddef>
#include <iostream>
#include <stdexcept>

namespace utils {

// IntArray::IntArray() : data_(nullptr), size_(0), bar("Bar"), foo() {
//   std::cout << "IntArray::IntArray()\n";
// }

IntArray::IntArray(int size) : foo(size), bar("Bar") {
  std::cout << "IntArray::IntArray(int size = " << size << ")\n ";
  data_ = new int[size];
  size_ = size;
}

IntArray::IntArray(int num, int size) {
  std::cout << "IntArray::IntArray(int num = " << num << "int size " << size
            << ")\n";
  data_ = new int[size];
  size_ = size;
  for (int i = 0; i < size; ++i) {
    data_[i] = num;
  }
}

IntArray::~IntArray() {
  Clear();
  std::cout << "IntArray::~IntArray()\n";
}

int IntArray::GetSize() const { return size_; }

bool IntArray::IsEmpty() const { return !size_; }

int &IntArray::operator[](int index) {
  if (index < 0)
    throw std::out_of_range("index is negative");
  if (index >= size_)
    throw std::out_of_range("index is too big");
  return data_[index];
}

void IntArray::Clear() {
  delete[] data_;
  data_ = nullptr;
  size_ = 0;
}

} // namespace utils
