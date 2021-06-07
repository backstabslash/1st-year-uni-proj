#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int home = 1;
const int control = 2;
const int solo = 3;
const int exam = 4;

class Human;
class Student;
class Teacher;

class Mark {
public:
	string subject;
	int type_of_mark;
	int mark;
	Mark() {}
	Mark(string subject, int type_of_mark, int mark) {
		this->subject = subject;
		this->type_of_mark = type_of_mark;
		this->mark = mark;
	}
};

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
public:
	string grade;
	vector<Mark> marks;
public:
	
	Student():Human() {
		grade = "Unknown";
	}
	Student(string full_name, int age, int height, string grade):Human(full_name, age, height) {
		this->grade = grade;
	}

	void final_mark(string subject) {
		
	}
	void print_marks() {

	}
};

class Teacher : public Human {
private:
	string subject;
	vector<Student*> students;
public:
	Teacher():Human() {
		subject = "Unknown";
	}
	Teacher(string full_name, int age, int height, string subject):Human(full_name, age, height) {
		this->subject = subject;
	}

	void add_new_mark(Student st, string subject, int type_of_mark, int mark) {
		Mark newmark(subject, type_of_mark, mark);
		st.marks.push_back(newmark);
	}
	void avg_mark() {

	}
	friend class Student;
};

int main() {
	return 0;
}