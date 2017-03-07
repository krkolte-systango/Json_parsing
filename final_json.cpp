// final_json.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#include <string>
#include "json11.h"
using namespace json11;

int main()
{

	Json my_json = Json::object{
		{ "Name", "Kapil" },
		{ "Student", true },
		{ "Score", Json::array { 89, 78, 84,8.2 } },
	};

	// we r getting value here

	string json_str = my_json.dump();
	cout << json_str << endl;


	//For Integer Values

	class Point {
	public:
		int key;
		int value;
		Point(int key, int value) : key(key), value(value) {}
		Json to_json() const { return Json::array { key , value }; }
	};

	//For String Values


	class str {
	public:
		string key;
		string value;
		str(string key, string value) : key(key), value(value) {}
		Json to_json() const { return Json::array { key, value }; }
	};

	vector<Point> points = { { 45, 2 },{ 24, 20 },{ 23, 200 } };
	string points_json = Json(points).dump();

	cout << "\n" << points_json<<endl;

	vector<str> str1 = { { "name", "kapil" },{ "surname", "Kolte" } };
	string str_json = Json(str1).dump();
	cout << "\n" <<str_json << endl;

	Json json = Json::array { Json::object{ { "kapil", "systango" }, {"kolte","Acro"} },
		                      Json::object{ { "rahul", "info" },{ "jain","Acro" } }};
	string str = json[1]["rahul"].string_value();


	cout << "\n" << str << endl;


	system("Pause");

    return 0;
}

