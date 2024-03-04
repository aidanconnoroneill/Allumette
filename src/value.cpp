#include "data/value.h"

template <>
int32_t Value::Get<int32_t>() {
  return union_value_.int32_val_;
}

template <>
float Value::Get<float>() {
  return union_value_.float_val_;
}

template <>
std::string Value::Get<std::string>() {
  return string_value_;
}