#include "data/dataset.h"
#include "gtest/gtest.h"
#include "operator/csv_table_load_op.h"
#include "operator/csv_table_store_op.h"
#include "operator/join_op.h"
#include "planner/pisi_planner.h"
TEST(PISIPlanner, JoinPlan) {
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

  auto planner = PISIPlanner(2);
  auto new_plan = planner.GeneratePISIPlan(join_op);
  EXPECT_EQ(new_plan->GetOperatorType(), GATHER);
  auto csv_storer =
      std::make_shared<CSVTableStoreOperator>("../data/store.csv");
  csv_storer->AddFromOperator(new_plan);
  EXPECT_EQ(csv_storer->Validate(), true);
  csv_storer->Execute();
}
