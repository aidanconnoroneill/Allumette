#include "operator/csv_table_load_op.h"
const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string& s) {
  size_t start = s.find_first_not_of(WHITESPACE);
  return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string& s) {
  size_t end = s.find_last_not_of(WHITESPACE);
  return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string& s) { return rtrim(ltrim(s)); }

std::unique_ptr<AbstractDataset> CSVTableLoadOperator::Execute() {
  csv::CSVReader reader(path_);
  std::vector<Row> rows;
  for (auto& row : reader) {  // Input iterator
    std::vector<Value> vals;

    for (size_t i = 0; i < schema_.columns_.size(); ++i) {
      switch (schema_.columns_[i].type_) {
        case ValueType::INT: {
          vals.push_back(Value::CreateIntegerValue(row[i].get<int32_t>()));
        } break;
        case ValueType::FLOAT: {
          vals.push_back(Value::CreateFloatValue(row[i].get<float>()));
        } break;
        case ValueType::STRING: {
          vals.push_back(
              Value::CreateStringValue(trim(row[i].get<std::string>())));
        }
        default:
          break;
      }
    }
    Row temp_row(std::move(vals));
    rows.push_back(temp_row);
  }

  auto schema = schema_;

  auto table = std::make_unique<Table>(std::move(schema), std::move(rows),
                                       "basic table");
  return table;
}

bool CSVTableLoadOperator::Validate() { return true; }