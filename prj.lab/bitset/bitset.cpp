#include <bitset/bitset.hpp>

#include <stdexcept>
#include <iostream>

int32_t BitSet::GetSize() const noexcept {
  return size_;
}

void BitSet::Resize(const int32_t size) {
  size_ = size;
  set_.resize(size, 0);
}

BitSet::BitSet(const BitSet& copy) {
  size_ = copy.size_;
  set_ = copy.set_;
}

BitSet::BitSet(BitSet&& copy) noexcept{
  size_ = copy.size_;
  copy.size_ = 0;
  set_ = std::move(copy.set_);
}

BitSet& BitSet::operator=(const BitSet& copy) {
  if (this != &copy) {
    size_ = copy.size_;
    set_ = copy.set_;
  }
  return *this;
}

BitSet& BitSet::operator=(BitSet&& copy) noexcept {
  if (this != &copy) {
    size_ = copy.size_;
    copy.size_ = 0;
    set_ = std::move(copy.set_);
  }
  return *this;
}

bool BitSet::operator==(const BitSet& rhs) const noexcept {
  return (size_ == rhs.size_ && set_ == rhs.set_);
}

bool BitSet::operator!=(const BitSet& rhs) const noexcept {
  return !(size_ == rhs.size_ && set_ == rhs.set_);
}

BitSet::BitSet(const std::int32_t size) {
  Resize(size);
}

BitSet& BitSet::operator~() {
  BitSet b(*this);
  for (int i = 0; i < size_; i++) {
    b.set_[i] = ~(set_[i]);
  }
  return b; 
}

BitSet& BitSet::operator&=(const BitSet& rhs) {
  if (size_ == rhs.size_) {
    for (int i = 0; i < size_; i++) {
      set_[i] = (set_[i] & rhs.set_[i]);
    }
  }
  else {
    throw std::exception("bitsets with different sizes");
  }
  return *this;
}

BitSet& BitSet::operator|=(const BitSet& rhs) {
  if (size_ == rhs.size_) {
    for (int i = 0; i < size_; i++) {
      set_[i] = (set_[i] | rhs.set_[i]);
    }
  }
  else {
    throw std::exception("bitsets with different sizes");
  }
  return *this;
}

BitSet& BitSet::operator^=(const BitSet& rhs) {
  if (size_ == rhs.size_) {
    for(int i = 0; i < size_; i++) {
      set_[i] = (set_[i] ^ rhs.set_[i]);
    }
  }
  else {
    throw std::exception("bitsets with different sizes");
  }
  return *this;
}

BitSet& BitSet::operator&(const BitSet& rhs) {
  BitSet b(*this);
  if (size_ == rhs.size_) {
    for (int i = 0; i < size_; i++) {
      b.set_[i] = (set_[i] & rhs.set_[i]);
    }
  }
  else {
    throw std::exception("bitsets with different sizes");
  }
  return b;
}

BitSet& BitSet::operator|(const BitSet& rhs) {
  BitSet b(*this);
  if (size_ == rhs.size_) {
    for (int i = 0; i < size_; i++) {
      b.set_[i] = (set_[i] | rhs.set_[i]);
    }
  }
  else {
    throw std::exception("bitsets with different sizes");
  }
  return b;
}

BitSet& BitSet::operator^(const BitSet& rhs) {
  BitSet b(*this);
  if (size_ == rhs.size_) {
    for (int i = 0; i < size_; i++) {
      b.set_[i] = (set_[i] ^ rhs.set_[i]);
    }
  }
  else {
    throw std::exception("bitsets with different sizes");
  }
  return b;
}

void BitSet::Fill(const bool val) noexcept {
  for (int i = 0; i < size_; i++) {
    set_[i] = val;
  }
}

bool BitSet::Get(const int32_t idx) const {
  if (idx > size_ - 1 || idx < 0) {
    throw std::logic_error("invalid index");
  }
  else {
    return set_[idx];
  }
}

void BitSet::Set(const int32_t idx, const bool value) {
  if (idx < 0 || idx > size_ - 1) {
    throw std::logic_error("invalid index");
  }
  else {
    set_[idx] = value;
  }
}

void BitSet::Print() {
  if (size_ != 0) {
    for (int i = 0; i < size_; i++) {
      std::cout << set_[i];
    }
    std::cout << std::endl;
  }
  else {
    std::cout << "empty";
  }
}