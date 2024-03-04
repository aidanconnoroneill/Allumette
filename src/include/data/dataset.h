#pragma once
#include <cassert>
#include <string>
#include <vector>

#include "value.h"
// Enum is used to coverting AbstractDataset pointer into specific dataset.
// For example, when type == DatasetType::TABLE. We could covert a
// abstractdataset pointer into a table pointer.
enum DatasetType { INVALID = -1, TABLE = 0 };

class AbstractDataset {
 public:
  AbstractDataset(std::string&& name, DatasetType type)
      : name_(name), type_(type) {}

  std::string GetName() { return name_; }

  DatasetType Type() { return type_; }

 private:
  std::string name_;
  DatasetType type_;
};
