#pragma once
#ifndef BITSET_BITSET_HPP
#define BITSET_BITSET_HPP

#include <vector>

class BitSet {
public:
  Bitset() = default;
  ~Bitset() = default;
  Bitset(const BitSet&) = default;
  Bitset(BitSet&&) = default;

  BitSet& operator=(const BitSet&) = default;
  BitSet& operator=(BitSet&&) = default;

  int32_t GetSize() const noexcept;
  void Resize(const int32_t);
  bool Get(const int32_t);
  void Set(const int32_t, const bool);

  BitSet& operator&(const BitSet&) = default;
  BitSet& operator|(const BitSet&) = default;
  BitSet& operator~(const BitSet&) = default;
  BitSet& operator^(const BitSet&) = default;

  void Fill(const bool);

private:
  size_ = 0;
  std::vector <uint32_t> set;

};

#endif