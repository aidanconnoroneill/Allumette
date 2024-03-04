#include <fstream>
#include <iostream>
#include "data/dataset.h"
#include "gtest/gtest.h"
#include "operator/csv_table_load_op.h"
#include "operator/csv_table_store_op.h"
#include "operator/join_op.h"
#include "planner/pisi_planner.h"
#include "scheduler/scheduler.h"
using std::cout;
using std::endl;
using std::vector;
TEST(Scheduler, Schedule1Thread) {
  Schema schema_student(std::vector<ColumnInfo>{{ValueType::INT, "student_id"},
                                                {ValueType::STRING, "lastname"},
                                                {ValueType::STRING, "dept"},
                                                {ValueType::INT, "credits"}});

  Schema schema_instructor(
      std::vector<ColumnInfo>{{ValueType::INT, "instructor_id"},
                              {ValueType::STRING, "name"},
                              {ValueType::STRING, "dept"},
                              {ValueType::FLOAT, "salary"}});
  Schema schema_department(
      std::vector<ColumnInfo>{{ValueType::STRING, "name"},
                              {ValueType::STRING, "dept"},
                              {ValueType::FLOAT, "budget"}});

  auto student_csv = std::make_shared<CSVTableLoadOperator>(
      "../data/student.csv", std::move(schema_student));

  auto instructor_csv = std::make_shared<CSVTableLoadOperator>(
      "../data/instructor.csv", std::move(schema_instructor));

  auto dept_csv = std::make_shared<CSVTableLoadOperator>(
      "../data/department.csv", std::move(schema_department));
  EXPECT_EQ(student_csv->Validate(), true);
  EXPECT_EQ(instructor_csv->Validate(), true);
  EXPECT_EQ(dept_csv->Validate(), true);
  auto join_op = std::make_shared<LoopJoinOp>(2, 2);
  join_op->AddFromOperator(student_csv);
  join_op->AddFromOperator(instructor_csv);
  EXPECT_EQ(join_op->Validate(), true);
  auto join_op2 = std::make_shared<LoopJoinOp>(2, 0);

  join_op2->AddFromOperator(join_op);

  join_op2->AddFromOperator(dept_csv);
  EXPECT_EQ(join_op2->Validate(), true);
  auto final_result = join_op2->Execute();

  vector<std::unique_ptr<AbstractDataset>> vector_final_result;
  vector_final_result.push_back(std::move(final_result));

  auto gather_final = std::make_shared<TableGatherOp>();
  gather_final->GatherResult(vector_final_result);
  auto csv_storer =
      std::make_shared<CSVTableStoreOperator>("../data/result.csv");
  csv_storer->AddFromOperator(gather_final);
  EXPECT_EQ(csv_storer->Validate(), true);
  csv_storer->Execute();
  // For Scheduler
  Schema schema_student_sch(
      std::vector<ColumnInfo>{{ValueType::INT, "student_id"},
                              {ValueType::STRING, "lastname"},
                              {ValueType::STRING, "dept"},
                              {ValueType::INT, "credits"}});

  Schema schema_instructor_sch(
      std::vector<ColumnInfo>{{ValueType::INT, "instructor_id"},
                              {ValueType::STRING, "name"},
                              {ValueType::STRING, "dept"},
                              {ValueType::FLOAT, "salary"}});
  Schema schema_department_sch(
      std::vector<ColumnInfo>{{ValueType::STRING, "name"},
                              {ValueType::STRING, "dept"},
                              {ValueType::FLOAT, "budget"}});

  auto student_csv_sch = std::make_shared<CSVTableLoadOperator>(
      "../data/student.csv", std::move(schema_student_sch));

  auto instructor_csv_sch = std::make_shared<CSVTableLoadOperator>(
      "../data/instructor.csv", std::move(schema_instructor_sch));

  auto dept_csv_sch = std::make_shared<CSVTableLoadOperator>(
      "../data/department.csv", std::move(schema_department_sch));

  auto join_op_sch = std::make_shared<LoopJoinOp>(2, 2);
  join_op_sch->AddFromOperator(student_csv_sch);
  join_op_sch->AddFromOperator(instructor_csv_sch);
  auto join_op2_sch = std::make_shared<LoopJoinOp>(2, 0);

  join_op2_sch->AddFromOperator(join_op_sch);
  join_op2_sch->AddFromOperator(dept_csv_sch);
  auto csv_storer_sch =
      std::make_shared<CSVTableStoreOperator>("../data/result2.csv");
  csv_storer_sch->AddFromOperator(join_op2_sch);
  auto s = std::make_shared<Scheduler>();
  s->Schedule(1, csv_storer_sch);
  std::unordered_set<std::string> res1;
  std::unordered_set<std::string> res2;

  std::ifstream input_file("../data/result.csv");
  std::ifstream input_file2("../data/result2.csv");

  std::string line;
  while (!input_file.eof()) {
    std::getline(input_file, line);
    res1.insert(line);
  }
  while (!input_file2.eof()) {
    std::getline(input_file2, line);
    res2.insert(line);
  }
  for (std::string s1 : res1) {
    EXPECT_TRUE(res2.find(s1) != res2.end());
  }
  for (std::string s2 : res2) {
    EXPECT_TRUE(res1.find(s2) != res1.end());
  }
}
TEST(Scheduler, Schedule4Thread) {
  Schema schema_student(std::vector<ColumnInfo>{{ValueType::INT, "student_id"},
                                                {ValueType::STRING, "lastname"},
                                                {ValueType::STRING, "dept"},
                                                {ValueType::INT, "credits"}});

  Schema schema_instructor(
      std::vector<ColumnInfo>{{ValueType::INT, "instructor_id"},
                              {ValueType::STRING, "name"},
                              {ValueType::STRING, "dept"},
                              {ValueType::FLOAT, "salary"}});
  Schema schema_department(
      std::vector<ColumnInfo>{{ValueType::STRING, "name"},
                              {ValueType::STRING, "dept"},
                              {ValueType::FLOAT, "budget"}});

  auto student_csv = std::make_shared<CSVTableLoadOperator>(
      "../data/student.csv", std::move(schema_student));

  auto instructor_csv = std::make_shared<CSVTableLoadOperator>(
      "../data/instructor.csv", std::move(schema_instructor));

  auto dept_csv = std::make_shared<CSVTableLoadOperator>(
      "../data/department.csv", std::move(schema_department));
  EXPECT_EQ(student_csv->Validate(), true);
  EXPECT_EQ(instructor_csv->Validate(), true);
  EXPECT_EQ(dept_csv->Validate(), true);
  auto join_op = std::make_shared<LoopJoinOp>(2, 2);
  join_op->AddFromOperator(student_csv);
  join_op->AddFromOperator(instructor_csv);
  EXPECT_EQ(join_op->Validate(), true);
  auto join_op2 = std::make_shared<LoopJoinOp>(2, 0);

  join_op2->AddFromOperator(join_op);

  join_op2->AddFromOperator(dept_csv);
  EXPECT_EQ(join_op2->Validate(), true);
  auto final_result = join_op2->Execute();

  vector<std::unique_ptr<AbstractDataset>> vector_final_result;
  vector_final_result.push_back(std::move(final_result));

  auto gather_final = std::make_shared<TableGatherOp>();
  gather_final->GatherResult(vector_final_result);
  auto csv_storer =
      std::make_shared<CSVTableStoreOperator>("../data/result4.csv");
  csv_storer->AddFromOperator(gather_final);
  EXPECT_EQ(csv_storer->Validate(), true);
  // For Scheduler
  Schema schema_student_sch(
      std::vector<ColumnInfo>{{ValueType::INT, "student_id"},
                              {ValueType::STRING, "lastname"},
                              {ValueType::STRING, "dept"},
                              {ValueType::INT, "credits"}});

  Schema schema_instructor_sch(
      std::vector<ColumnInfo>{{ValueType::INT, "instructor_id"},
                              {ValueType::STRING, "name"},
                              {ValueType::STRING, "dept"},
                              {ValueType::FLOAT, "salary"}});
  Schema schema_department_sch(
      std::vector<ColumnInfo>{{ValueType::STRING, "name"},
                              {ValueType::STRING, "dept"},
                              {ValueType::FLOAT, "budget"}});

  auto student_csv_sch = std::make_shared<CSVTableLoadOperator>(
      "../data/student.csv", std::move(schema_student_sch));

  auto instructor_csv_sch = std::make_shared<CSVTableLoadOperator>(
      "../data/instructor.csv", std::move(schema_instructor_sch));

  auto dept_csv_sch = std::make_shared<CSVTableLoadOperator>(
      "../data/department.csv", std::move(schema_department_sch));

  auto join_op_sch = std::make_shared<LoopJoinOp>(2, 2);
  join_op_sch->AddFromOperator(student_csv_sch);
  join_op_sch->AddFromOperator(instructor_csv_sch);
  auto join_op2_sch = std::make_shared<LoopJoinOp>(2, 0);

  join_op2_sch->AddFromOperator(join_op_sch);
  join_op2_sch->AddFromOperator(dept_csv_sch);

  auto s = std::make_shared<Scheduler>();
  auto res = s->Schedule(2, join_op2_sch);
  csv_storer->Execute(std::move(res));
  std::unordered_set<std::string> res1;
  std::unordered_set<std::string> res2;
  //   csv_storer_sch->Execute(std::move(res));
  std::ifstream input_file("../data/result.csv");
  std::ifstream input_file2("../data/result4.csv");

  std::string line;
  while (!input_file.eof()) {
    std::getline(input_file, line);
    res1.insert(line);
  }
  while (!input_file2.eof()) {
    std::getline(input_file2, line);
    res2.insert(line);
  }
  for (std::string s1 : res1) {
    EXPECT_TRUE(res2.find(s1) != res2.end());
  }
  for (std::string s2 : res2) {
    EXPECT_TRUE(res1.find(s2) != res1.end());
  }
}