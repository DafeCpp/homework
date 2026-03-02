/*
#include <iostream>
#include <stdexcept>

class Array {
  // template < typename T, int Size> class Array {
 public:
  Array(int size) : size_(size), data_(new int(size)) {}
  ~Array() { delete[] data_; }  // деструктор

  int Size() { return size_; }
  int operator{}(int index) { return data_[index]; }
  int operator()(int index) {
    if (index < 0 || index >= size_) {
      throw std::out_of_range("oor");
    }
    return data_[index];
  }

 private:
  const int *data_;
  const int size_;
}

int main(){
  Array a(10);
  std::cout << "first: " << a[0];

  return 0;
}
*/