#include <memory>

#include "data/dataset.h"
#include "gtest/gtest.h"
#include "operator/csv_table_load_op.h"
#include "operator/csv_table_store_op.h"

TEST(CSVTest, LoadTable) {
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
}

TEST(CSVTest, StoreTable) {
  Schema schema(std::vector<ColumnInfo>{{ValueType::INT, "id"},
                                        {ValueType::STRING, "name"},
                                        {ValueType::FLOAT, "salary"}});

  auto csv_loader = std::make_shared<CSVTableLoadOperator>("../data/demo.csv",
                                                           std::move(schema));
  auto csv_storer =
      std::make_shared<CSVTableStoreOperator>("../data/store.csv");
  csv_storer->AddFromOperator(csv_loader);
  csv_storer->Validate();
  csv_storer->Execute();
}
