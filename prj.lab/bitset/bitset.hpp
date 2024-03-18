#pragma once
#ifndef BITSET_BITSET_HPP
#define BITSET_BITSET_HPP

#include <vector>

class BitSet {
public:
  BitSet() = default;
  ~BitSet() = default;
  BitSet(const BitSet&) = default;
  BitSet(BitSet&&) = default;

  BitSet& operator=(const BitSet&) = default;
  BitSet& operator=(BitSet&&) = default;

  int32_t GetSize() const noexcept;
  void Resize(const int32_t);
  bool Get(const int32_t);
  void Set(const int32_t, const bool);

  BitSet& operator&(const BitSet&);
  BitSet& operator|(const BitSet&);
  BitSet& operator~();
  BitSet& operator^(const BitSet&);

  void Fill(const bool);

private:
  uint32_t size_ = 0;
  std::vector <uint32_t> set;

};

#endif