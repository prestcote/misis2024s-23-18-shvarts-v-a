#pragma once
#ifndef BITSET_BITSET_HPP
#define BITSET_BITSET_HPP

#include <cstdint>
#include <iosfwd>
#include <vector>

class BitSet {
public:
  BitSet() = default;
  BitSet(const int32_t size);
  ~BitSet() = default;
  BitSet(const BitSet&);
  BitSet(BitSet&&) noexcept;

  BitSet& operator=(const BitSet&);
  BitSet& operator=(BitSet&&) noexcept;

  int32_t GetSize() const noexcept;
  void Resize(const int32_t size);
  bool Get(const int32_t idx) const;
  void Set(const int32_t idx, const bool value);
  void Fill(const bool val) noexcept;

  uint32_t Size() const noexcept {
    return size_;
  }

  bool operator==(const BitSet& rhs) const noexcept;
  bool operator!=(const BitSet& rhs) const noexcept;

  BitSet& operator&=(const BitSet&) ;
  BitSet& operator|=(const BitSet&);
  BitSet operator~() const;
  BitSet& operator^=(const BitSet&);

  void Print(); //attempt ig

  class BitSetAccess {
  private:
    uint32_t idx_;
    BitSet& bitset_; 
  public:
    BitSetAccess(uint32_t idx, BitSet& bitset) : idx_(idx), bitset_(bitset) {};
    BitSetAccess& operator=(bool v) {
      bitset_.Set(idx_, v);
      return *this;
    }
    operator bool() const {
      return bitset_.Get(idx_);
    }
    
  };
  
  BitSetAccess operator[](const uint32_t index) {
    return BitSetAccess(index, *this);
  } 

  // ? operator[](const int32_t) - what can return
  // why not bool....???????? 
  // ok get it ig
// std::ostream& WriteTxt(std::ostream&)
// std::ostream& WriteBinary(std::ostream&)
// std::istream& ReadTxt(std::istream&)
// std::istream& RaadBinary(std::istream&)

private:
  uint32_t size_ = 0;
  std::vector <uint32_t> set_;
};

BitSet operator&(const BitSet& lhs, const BitSet& rhs);
BitSet operator|(const BitSet& lhs, const BitSet& rhs);
BitSet operator^(const BitSet& lhs, const BitSet& rhs);

#endif