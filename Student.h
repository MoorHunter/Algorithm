#pragma once


#include<iostream>
#include<string>
using namespace std;

class Student {
public:
	string sName;
	int sScore;

	//���������<
	bool operator<(const Student &otherStudent) {
		return sScore != otherStudent.sScore ? sScore< otherStudent.sScore : sName<otherStudent.sName;
	}
	//������������<<
	friend ostream&operator<<(ostream&os, const Student&student) {
		os << "Student:" << student.sName << "��" << student.sScore << endl;
		return os;
	}
	/*bool operator<(const Student&otherStudent) {
		return score != otherStudent.score ?
			score>otherStudent.score:name < otherStudent.name;
	}*/

};