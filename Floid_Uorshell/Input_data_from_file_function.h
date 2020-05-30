#pragma once
#include<string>
#include <fstream>
#include"List.h"
void InputDataFromFile(List<string>* data, string path) {//file input
	ifstream file(path);
	if (file.is_open()) {
		file.close();
		file.open(path);
	}
	else
		throw exception("File is  missing!");
	while (!file.eof()) {
		string s1;
		getline(file, s1);
		data->push_back(s1);
	}
}