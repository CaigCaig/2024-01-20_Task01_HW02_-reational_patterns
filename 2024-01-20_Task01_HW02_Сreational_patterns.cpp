#include <iostream>
#include "sql_query_builder.h"

using namespace std;

typedef pair <string, string> Str_Pair;

void SendQuery(const SqlSelectQuery& e) {
	cout << e.query << endl;
}

int main() {
	map<string, string> where;
	vector<string> columns;
	where.insert(Str_Pair( "id", "42"));
	where.insert(Str_Pair("name", "John"));
	where.insert(Str_Pair("city", "New-Vasuki"));
	columns.push_back("name");
	columns.push_back("phone");
	columns.push_back("address");
	SqlSelectQueryBuilder query_builder;
	query_builder.AddColumn(columns);
	query_builder.AddFrom("students");
	query_builder.AddWhere(where);

	//static_assert(query_builder.BuildQuery(), "SELECT name, phone FROM students WHERE id=42 AND name=John;");
	SendQuery(query_builder.BuildQuery());
	system("pause");
}