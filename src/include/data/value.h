#pragma once
#include <cassert>
#include <cstdint>
#include <functional>
#include <stdexcept>
#include <utility>
#include <vector>
enum ValueType { INT = 0, FLOAT = 1, DOUBLE = 2, STRING = 3 };

// The basic value class for our system.
class Value {
 public:
  Value(const Value& value) {
    type_ = value.type_;
    union_value_ = value.union_value_;
    string_value_ = value.string_value_;
  }
  Value(Value&& value) {
    type_ = value.type_;
    union_value_ = value.union_value_;
    string_value_ = std::move(value.string_value_);
  }
  static Value CreateFloatValue(float val) { return Value(val); }
  static Value CreateIntegerValue(int32_t val) { return Value(val); }
  static Value CreateStringValue(std::string val) { return Value(val); }
  ValueType GetValueType() { return this->type_; }
  std::string ToString() {
    switch (type_) {
      case INT:
        return std::to_string(union_value_.int32_val_);
      case FLOAT:
        return std::to_string(union_value_.float_val_);
      case STRING:
        return string_value_;
      default:
        throw std::runtime_error("Unable to get string value");
    }
  }
  Value(int32_t val) {
    union_value_.int32_val_ = val;
    type_ = ValueType::INT;
  }

  Value(std::string val) {
    string_value_ = std::move(val);
    type_ = ValueType::STRING;
  }

  size_t HashValue() {
    switch (type_) {
      case INT:
        return std::hash<int32_t>()(union_value_.int32_val_);
      case FLOAT:
        return std::hash<float>()(union_value_.float_val_);
      case STRING:
        return std::hash<std::string>()(string_value_);
      default:
        throw std::runtime_error("Unable to get hash value");
    }
  }

  Value& operator=(const Value& value) = default;
  // Comparing two value, will be useful in all kinds of operator.
  bool operator==(const Value& rhs) {
    switch (rhs.type_) {
      case INT: {
        assert(this->type_ == INT);
        return this->union_value_.int32_val_ == rhs.union_value_.int32_val_;
      }
      case FLOAT: {
        assert(this->type_ == FLOAT);
        return this->union_value_.float_val_ == rhs.union_value_.float_val_;
      }
      case STRING: {
        assert(this->type_ == STRING);
        return this->string_value_ == rhs.string_value_;
      }
      default:
        throw std::runtime_error("Unable compare two values");
    }
  }

  template <class T>
  T Get();

 private:
  Value(float val) {
    union_value_.float_val_ = val;
    type_ = ValueType::FLOAT;
  }

  union {
    float float_val_;
    int32_t int32_val_;
  } union_value_;
  std::string string_value_;
  ValueType type_;
};

// Each row contains multiple values.
// Table is Dataset<Row>
class Row {
 public:
  Row(std::vector<Value>&& values) : values_(values) {}
  Row(Row&& row) { values_ = std::move(row.values_); }
  Row(const Row& row) { values_ = row.values_; }
  Row& operator=(const Row& row) {
    values_ = row.values_;
    return *this;
  }
  Value& GetColumnByIdx(size_t idx) { return values_[idx]; }
  void AppendRow(const Row& row) {
    for (auto& val : row.values_) {
      values_.push_back(val);
    }
  }

 private:
  std::vector<Value> values_;
};
