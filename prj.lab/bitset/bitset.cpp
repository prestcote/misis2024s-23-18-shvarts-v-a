#include <bitset/bitset.hpp>

#include <stdexcept>
#include <iostream>



int32_t BitSet::GetSize() const noexcept {
  return size_;
}

void BitSet::Resize(int32_t size) {
  //size_ = size;
  if (size <= 0) {
    throw std::runtime_error("invalid iuze");
  }
  else if (size < size_) {
    for (int i = size + 1; i < size_; i++) {
      Set(i, false);
    }
    set_.resize((size + 31) / 32, 0);
    size_ = size;
  }
  else if (size > size_) {
    set_.resize((size + 31) / 32, 0);
    size_ = size;
  }
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

BitSet::BitSet(const std::int32_t size) : size_(size) {
  if (size < 0) {
    throw std::runtime_error("invalid size");
  }
  set_.resize((size_ + 31) / 32, 0);
}

BitSet BitSet::operator~() const {
  BitSet b(*this);
  for (int i = 0; i < set_.size(); i++) {
    b.set_[i] = ~(b.set_[i]);
  }
  return b; 
}

BitSet& BitSet::operator&=(const BitSet& rhs) {
  if (size_ == rhs.size_) {
    for (int i = 0; i < set_.size(); i++) {
      set_[i] = (set_[i] & rhs.set_[i]);
    }
  }
  else {
    throw std::logic_error("bitsets with different sizes");
  }
  return *this;
}

BitSet& BitSet::operator|=(const BitSet& rhs) {
  if (size_ == rhs.size_) {
    for (int i = 0; i < set_.size(); i++) {
      set_[i] = (set_[i] | rhs.set_[i]);
    }
  }
  else {
    throw std::logic_error("bitsets with different sizes");
  }
  return *this;
}

BitSet& BitSet::operator^=(const BitSet& rhs) {
  if (size_ == rhs.size_) {
    for(int i = 0; i < set_.size(); i++) {
      set_[i] = (set_[i] ^ rhs.set_[i]);
    }
  }
  else {
    throw std::logic_error("bitsets with different sizes");
  }
  return *this;
}

BitSet operator&(const BitSet& lhs, const BitSet& rhs) {
  BitSet b(lhs);
  b &= rhs;
  return b;
}

BitSet operator|(const BitSet& lhs, const BitSet& rhs) {
  BitSet b(lhs);
  b |= rhs;
  return b;
}

BitSet operator^(const BitSet& lhs, const BitSet& rhs) {
  BitSet b(lhs);
  b ^= rhs;
  return b;
}

void BitSet::Fill(const bool val) noexcept {
  for (size_t i = 0; i < set_.size(); i++) {
    if (val) {
      set_[i] = (~0);
    }
    else {
      set_[i] = 0;
    }
  }
}


bool BitSet::Get(const int32_t idx) const {
  if (idx >= size_ || idx < 0) {
    throw std::logic_error("invalid index");
  }
  else {
    return set_[idx / 32] & (1 << idx % 32);
  }
}


void BitSet::Set(const int32_t idx, const bool value) {
  if (idx < 0 || idx >= size_) {
    throw std::logic_error("invalid index");
  }
  else {
    if (value) {
      set_[idx / 32] |= (1 << (idx % 32));
    }
    else {
      set_[idx / 32] &= ~(1 << (idx % 32));
    }
  }
}

void BitSet::Print() {
  if (size_ != 0) {
    for (int i = 0; i < set_.size(); i++) {
      std::cout << set_[i];
    }
    std::cout << std::endl;
  }
  else {
    std::cout << "empty";
  }
}




                                      // DOWN WITH THE SHIP