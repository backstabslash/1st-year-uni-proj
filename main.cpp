#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

enum type_of_mark {
	HOME = 1,
	CONTROL = 2,
	SOLO = 3,
	EXAM = 4
};

class Mark {
public:
	string subject;
	int type_of_mark;
	int mark;
	Mark(string subject, int type_of_mark, int mark) {
		this->subject = subject;
		this->type_of_mark = type_of_mark;
		this->mark = mark;
	}

	friend ostream& operator<<(ostream& os, Mark& mark) 
	{
		os  << "Subject is: " << mark.subject <<
			" Type of work is: " << mark.type_of_mark <<
			" Mark is " << mark.mark << endl;
		return os;
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
private:
	string grade;
	vector<Mark> marks;
public:

	Student():Human() {
		grade = "Unknown";
	}
	Student(string full_name, int age, int height, string grade) :Human(full_name, age, height) {
		this->grade = grade;
	}

	void final_mark(string subject)
	{
		int final_mark = 0;
		short a = 0;
		for (size_t i = 0; i < marks.size(); i++) {
			++a;
			if (marks[i].subject == subject) {
				final_mark += marks[i].mark;
			}
		}
		final_mark /= a;
		cout << "Student's " << this->full_name << " final mark is: " << final_mark << "." << endl;
	}
	void print_marks()
	{
		cout << "All marks that student " << this->full_name << " have: " << endl;
		for (size_t i = 0; i < marks.size(); i++) {
			cout << marks[i];
		}
		cout << endl;
	}

	friend class Teacher;
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

	void add_new_mark(Student& st, int type_of_mark, int mark) 
	{
		st.marks.push_back(Mark(this->subject, type_of_mark, mark));
	}
	void add_student(Student &st) 
	{
		Student* p = &st;
		students.push_back(p);
	}
	void avg_mark()
	{
		int quant = 0, sum = 0;
		for (int i = 0; i < students.size(); i++) {
			for (int j = 0; j < students[i]->marks.size(); j++) {
				if (students[i]->marks[j].subject == this->subject) {
					quant++;
					sum += students[i]->marks[j].mark;
				}
			}
		}
		cout << "Teacher's " << this->full_name << " average mark given is " << sum / quant << "." << endl;
	}
};

int main() {
	Student sttest("Tim", 19, 180, "11-B");
	Student sttest2("Tim2", 19, 180, "11-B");
	Teacher tctest("Nikita", 91, 181, "History");

	tctest.add_student(sttest);
	tctest.add_new_mark(sttest, 1, 11);
	tctest.add_new_mark(sttest, 2, 8);
	tctest.add_new_mark(sttest, 3, 10);
	tctest.add_new_mark(sttest, 4, 7);

	tctest.add_student(sttest2);
	tctest.add_new_mark(sttest2, 1, 11);
	tctest.add_new_mark(sttest2, 2, 8);
	tctest.add_new_mark(sttest2, 3, 5);
	tctest.add_new_mark(sttest2, 4, 8);

	sttest.print_marks();

	sttest.final_mark("History");
	tctest.avg_mark();

	return 0;
}