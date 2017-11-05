#pragma once


#include<iostream>
#include<string>
using namespace std;

class Student {
public:
	string sName;
	int sScore;

	//重载运算符<
	bool operator<(const Student &otherStudent) {
		return sScore != otherStudent.sScore ? sScore< otherStudent.sScore : sName<otherStudent.sName;
	}
	//重载输出运算符<<
	friend ostream&operator<<(ostream&os, const Student&student) {
		os << "Student:" << student.sName << "　" << student.sScore << endl;
		return os;
	}
	/*bool operator<(const Student&otherStudent) {
		return score != otherStudent.score ?
			score>otherStudent.score:name < otherStudent.name;
	}*/

};