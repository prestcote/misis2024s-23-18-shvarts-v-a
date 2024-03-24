#pragma once
#ifndef BITSET_BITSET_HPP
#define BITSET_BITSET_HPP

#include <cstdint>
#include <iosfwd>
#include <vector>

class BitSet {
public:
  BitSet() = default; //
  BitSet(const std::int32_t size);
  ~BitSet() = default; 
  BitSet(const BitSet&); //
  BitSet(BitSet&&); //

  BitSet& operator=(const BitSet&); //
  BitSet& operator=(BitSet&&); //

  int32_t GetSize() const noexcept;
  void Resize(const int32_t size); //?
  bool Get(const int32_t idx) const;
  void Set(const int32_t idx, const bool value);
  void Fill(const bool val) noexcept;

  int32_t Size() const noexcept { return size_; } //

  bool operator==(const BitSet& rhs) const noexcept; //
  bool operator!=(const BitSet& rhs) const noexcept; //

  BitSet& operator&=(const BitSet&);
  BitSet& operator|=(const BitSet&);
  BitSet& operator~(); //
  BitSet& operator^=(const BitSet&);

  // ? operator[](const int32_t) - what can return
// std::ostream& WriteTxt(std::ostream&)
// std::ostream& WriteBinary(std::ostream&)
// std::istream& ReadTxt(std::istream&)
// std::istream& RaadBinary(std::istream&)

private:
  uint32_t size_ = 0;
  std::vector <uint32_t> set_;

};

BitSet& operator&(const BitSet&lhs, const BitSet& rhs);
BitSet& operator|(const BitSet& lhs, const BitSet& rhs);
BitSet& operator^(const BitSet& lhs, const BitSet& rhs);

#endif