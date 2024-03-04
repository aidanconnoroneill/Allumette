#include "data/dataset.h"
#include "gtest/gtest.h"
#include "operator/csv_table_load_op.h"
#include "operator/csv_table_store_op.h"
#include "operator/join_op.h"
TEST(JoinTest, LoopJoinTest) {
  Schema schema(std::vector<ColumnInfo>{{ValueType::INT, "id"},
                                        {ValueType::STRING, "name"},
                                        {ValueType::FLOAT, "salary"}});

  auto csv_loader = std::make_shared<CSVTableLoadOperator>("../data/demo.csv",
                                                           std::move(schema));

  Schema schema1(std::vector<ColumnInfo>{{ValueType::INT, "pid"},
                                         {ValueType::STRING, "project"}});

  auto csv_loader1 = std::make_shared<CSVTableLoadOperator>("../data/demo2.csv",
                                                            std::move(schema1));

  auto join_op = std::make_shared<LoopJoinOp>(0, 0);
  join_op->AddFromOperator(csv_loader);
  join_op->AddFromOperator(csv_loader1);
  auto csv_storer = std::make_shared<CSVTableStoreOperator>("../data/join.csv");
  csv_storer->AddFromOperator(join_op);
  csv_storer->Validate();
  csv_storer->Execute();
}