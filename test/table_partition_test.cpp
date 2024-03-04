#include "data/dataset.h"
#include "gtest/gtest.h"
#include "operator/csv_table_load_op.h"
#include "operator/table_partiton_op.h"

TEST(TablePartition, HashPartition) {
  auto access0 = std::make_shared<PartitionAccessOperator>(0);
  auto access1 = std::make_shared<PartitionAccessOperator>(1);
  auto access2 = std::make_shared<PartitionAccessOperator>(2);

  Schema schema(std::vector<ColumnInfo>{{ValueType::INT, "id"},
                                        {ValueType::STRING, "name"},
                                        {ValueType::FLOAT, "salary"}});
  auto csv_loader = std::make_shared<CSVTableLoadOperator>("../data/demo.csv",
                                                           std::move(schema));
  EXPECT_TRUE(csv_loader->Validate());
  auto data = csv_loader->Execute();
  EXPECT_EQ(data->Type(), DatasetType::TABLE);
  auto table = reinterpret_cast<Table*>(data.get());
  EXPECT_EQ(table->Size(), 3);

  auto partitioner = std::make_shared<HashTablePartitionOperator>(0, 3);

  partitioner->AddFromOperator(csv_loader);
  access0->AddFromOperator(partitioner);
  access1->AddFromOperator(partitioner);
  access2->AddFromOperator(partitioner);
  partitioner->Execute();
  EXPECT_EQ(access0->Validate(), true);
  EXPECT_EQ(access1->Validate(), true);
  EXPECT_EQ(access2->Validate(), true);

  auto part0 = access0->Execute();
  auto part1 = access1->Execute();
  auto part2 = access2->Execute();
  EXPECT_NE(part0, nullptr);
  EXPECT_NE(part1, nullptr);
  EXPECT_NE(part2, nullptr);

  EXPECT_EQ(part0->Type(), DatasetType::TABLE);
  EXPECT_EQ(part1->Type(), DatasetType::TABLE);
  EXPECT_EQ(part2->Type(), DatasetType::TABLE);

  auto table0 = reinterpret_cast<Table*>(part0.get());
  auto table1 = reinterpret_cast<Table*>(part1.get());
  auto table2 = reinterpret_cast<Table*>(part2.get());
  EXPECT_EQ(table0->Size(), 1);
  EXPECT_EQ(table1->Size(), 1);
  EXPECT_EQ(table2->Size(), 1);
}
