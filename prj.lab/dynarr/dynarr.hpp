#ifndef DYNARR_DYNARR_HPP
#define DYNARR_DYNARR_HPP
#include <cstddef>

class DynArr {
public:
  DynArr() = default; //default constructor 
  DynArr(const DynArr& to_copy); //copy constructor
  DynArr(DynArr&&) = default;
  DynArr(const std::ptrdiff_t size);  //by size
  ~DynArr(); //destructor
  DynArr& operator=(const DynArr& to_copy); //assignment
  DynArr& operator=(DynArr&&) = default;

  std::ptrdiff_t Size() const { return size_; } 
  std::ptrdiff_t Capacity() const { return capacity_; } 
  void Resize(const std::ptrdiff_t size); 
  float& operator[](const std::ptrdiff_t idx) const;

private:
  std::ptrdiff_t size_ = 0; // array size
  float * data_ = 0;          // element //ссылка на элемент
  std::ptrdiff_t capacity_ = 0; //assigned memory
};

#endif