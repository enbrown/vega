#pragma once

#include "vega/types.h"
#include <stdint.h>
#include <string>

namespace vega {
  // Should overload with different arguments for different types
  template <typename T>
  std::string to_string(const T& t);

  template<>
  std::string to_string<std::string>(const std::string& s);
  template<>
  std::string to_string<float>(const float& f);
  template<>
  std::string to_string<double>(const double& d);
  template<>
  std::string to_string<int8_t>(const int8_t& i);
  template<>
  std::string to_string<int16_t>(const int16_t& i);
  template<>
  std::string to_string<int32_t>(const int32_t& i);
  template<>
  std::string to_string<uint8_t>(const uint8_t& u);
  template<>
  std::string to_string<uint16_t>(const uint16_t& u);
  template<>
  std::string to_string<uint32_t>(const uint32_t& u);
  template<>
  std::string to_string<Byte>(const Byte& byte);
  template<>
  std::string to_string<Word>(const Word& word);
  template<>
  std::string to_string<Long>(const Long& l);

  template <typename T>
  T from_string(const std::string& s);

  template<>
  std::string from_string(const std::string& s);
  template<>
  float from_string(const std::string& s);
  template<>
  double from_string(const std::string& s);
  template<>
  int8_t from_string(const std::string& s);
  template<>
  int16_t from_string(const std::string& s);
  template<>
  int32_t from_string(const std::string& s);
  template<>
  uint8_t from_string(const std::string& s);
  template<>
  uint16_t from_string(const std::string& s);
  template<>
  uint32_t from_string(const std::string& s);
  template<>
  Byte from_string(const std::string& s);
  template<>
  Word from_string(const std::string& s);
  template<>
  Long from_string(const std::string& s);
}

#include "vega/string_impl.h"
