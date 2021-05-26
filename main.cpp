#include <iostream>
#include <vector>
#include <map>
using namespace std;
//��� �����? ���(������ �������, ���(������ ��� ������, ������ ������ ������� ����)), ����� ���� ��������
class Human {
protected:
	string full_name;
	int age;
	int height;
public:
	Human() {
		full_name = "Unknown";
		age = 0;
		height = 0;
	}
	Human(string full_name, int age, int height) {
		this->full_name = full_name;
		this->age = age;
		this->height = height;
	}
};

class Student : public Human {
private:
	string grade;
	vector<Mark> marks;
public:
	Student():Human() {
		grade = "Unknown";
		marks = {};
	}
	Student(string grade, vector<Mark> marks):Human(full_name, age, height) {
		this->grade = grade;
	}

	void final_mark(string subject) {
		
	}
};

class Teacher : public Human {
private:
	string subject;
	vector<Student> students;
public:
	Teacher():Human() {
		subject = "Unknown";
		vector<Student> students = {};
	}
	Teacher(string subject, vector<Student> students):Human(full_name, age, height) {
		this->subject = subject;
		this->students = students;
	}
};

class Mark {
private:
	int homework;
	int test;
	int independent_work;
	int exam;
};

int main() {



	return 0;
}