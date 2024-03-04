#include "data/dataset.h"
#include "data/table.h"
#include "gtest/gtest.h"

TEST(DemoTest, Demo1) {
  Row row1 = Row(std::vector<Value>{Value::CreateIntegerValue(1),
                                    Value::CreateIntegerValue(2)});
  Row row2 = Row(std::vector<Value>{Value::CreateIntegerValue(3),
                                    Value::CreateIntegerValue(4)});
  auto rows = std::vector<Row>{std::move(row1), std::move(row2)};
  auto schema = Schema(std::vector<ColumnInfo>{
      ColumnInfo(ValueType::INT, "a"), ColumnInfo(ValueType::INT, "b")});
  auto table = Table(std::move(schema), std::move(rows), "basic table");
  EXPECT_EQ(table.Size(), 2);
}
