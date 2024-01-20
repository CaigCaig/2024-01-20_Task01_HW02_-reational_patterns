#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct SqlSelectQuery {
    vector<string> columns;
    string from;
    map<string, string> where;
    string query;
};

class SqlSelectQueryBuilder {
private:
    SqlSelectQuery sql_select_query;
public:
    explicit SqlSelectQueryBuilder() {};
    SqlSelectQuery BuildQuery() noexcept;
    SqlSelectQueryBuilder& AddColumn(const vector<string>& columns) noexcept;
    SqlSelectQueryBuilder& AddFrom(const string& from) noexcept;
    SqlSelectQueryBuilder& AddWhere(const map<string, string>& kv) noexcept;

};