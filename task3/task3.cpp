#include "include/json.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;
using nlohmann::json;

void solution(string file1, string file2, string file3);
void json_filler(const map<int, string> &values, json &tests_json);

int main(int argc, char *argv[]) {

  string file1, file2, file3;

  // По аналогии со 2 заданием будем смотреть, были ли переданы пути в argv,
  // иначе запросим ввод изнутри программы.

  if (argc == 4) {
    file1 = argv[1];
    file2 = argv[2];
    file2 = argv[3];
  } else {
    cin >> file1 >> file2 >> file3;
  }

  solution(file1, file2, file3);
}

void json_filler(const map<int, string> &values, json &tests_json) {
  for (auto &entity : tests_json) {
    if (entity.contains("value")) {
      entity["value"] = values.find(entity["id"])->second;
    }
    if (entity.contains("values")) {
      json_filler(values, entity["values"]);
    }
  }
}

void solution(string file1, string file2, string file3) {
  map<int, string> values;

  ifstream values_in(file1);
  json values_json = json::parse(values_in);
  values_in.close();

  if (values_json.contains("values") && values_json["values"].is_array()) {
    for (auto &entity : values_json["values"]) {
      if (entity.contains("id") && entity.contains("value")) {
        values.insert(std::pair(entity["id"], entity["value"]));
      }
    }
  }

  ifstream tests_in(file2);
  json tests_json = json::parse(tests_in);
  tests_in.close();

  if (tests_json.contains("tests")) {
    json_filler(values, tests_json["tests"]);
  }

  ofstream report_out(file3);
  report_out << std::setw(2) << tests_json << std::endl;
  report_out.close();
}
