#include "sql_query_builder.h"

SqlSelectQuery SqlSelectQueryBuilder::BuildQuery() noexcept {
	string comma = ", ";
	string str_and = " AND ";
	sql_select_query.query = "SELECT ";
	if (sql_select_query.columns.size()) {
		for (const auto& i : sql_select_query.columns) { sql_select_query.query += i + comma; }
		sql_select_query.query.erase(sql_select_query.query.length() - comma.length(), comma.length());
	}
	else sql_select_query.query += "*";
	sql_select_query.query += " FROM " + sql_select_query.from + " WHERE ";
	for (const auto& i : sql_select_query.where) { sql_select_query.query += i.first + "=" + i.second + str_and; }
	sql_select_query.query.erase(sql_select_query.query.length() - str_and.length(), str_and.length());
	sql_select_query.query += ";";
	return sql_select_query;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const vector<string>& columns) noexcept {
	for (const auto& i : columns) { sql_select_query.columns.push_back(i); }
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const string& from) noexcept {
	sql_select_query.from = from;
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const map<string, string>& kv) noexcept {
//SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& key, const std::string& value) {
	sql_select_query.where = kv;
	return *this;
}

/*

Расширьте класс из предыдущего задания методом

SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;
С помощью которого можно будет добавить в запрос сразу несколько условий.

Расширьте класс из предыдущего задания методом

SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept;
С помощью этого метода можно добавить в запрос сразу несколько полей, по которым он будет строиться вместо одного, как в базовом варианте.


*/