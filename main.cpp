#include <iostream>
#include <vector>
#include <fstream>
#include "Teacher.h"
#include "Student.h"
#include "Human.h"
#include "Mark.h"
using namespace std;

void InterfaceAverageTeacher(vector<Teacher>& interfaceTeacher);
void InterfacePrintAllStudent(vector<Student>& interfaceStudent);
void InterfaceFinalStudent(vector<Student>& interfaceStudent, vector<Teacher>& interfaceTeacher);

void Interface(vector<Student>& interfaceStudent, vector<Teacher>& interfaceTeacher)
{
	while (1)
	{
		short choice;
		cout << "Choose an appropriate option:\n";
		cout << "1 - Check average mark given by a teacher\n";
		cout << "2 - Print all marks of a student\n";
		cout << "3 - Check final mark of a student\n";
		cout << "4 - Exit\n";
		cin >> choice; 
		while (true)
		{
			if (choice <= 0 || choice > 4)
			{
				cout << "Enter valid number! Try again." << endl;
				cin.clear();
				while (cin.get() != '\n');
				cin >> choice;
			}
			else { break; }
		}
		switch (choice)
		{
		case 1:
			InterfaceAverageTeacher(interfaceTeacher);
			break;
		case 2:
			InterfacePrintAllStudent(interfaceStudent);
			break;
		case 3:
			InterfaceFinalStudent(interfaceStudent, interfaceTeacher);
			break;
		case 4:
			exit(0);
		}
	}
}

void InterfaceAverageTeacher(vector<Teacher>& interfaceTeacher)
{
	for (size_t i = 0; i < interfaceTeacher.size(); i++)
	{
		cout << "Enter " << i+1 << " to see average mark of " << interfaceTeacher[i].short_info();
	}
	short choicecase1;
	cin >> choicecase1;
	while (true)
	{
		if (choicecase1 <= 0 || choicecase1 > interfaceTeacher.size())
		{
			cout << "Enter valid number! Try again.";
			cin.clear();
			while (cin.get() != '\n');
			cin >> choicecase1;
		}
		else { break; }
	}
	for (size_t i = 0; i < interfaceTeacher.size(); i++)
	{
		if (i + 1 == choicecase1) 
		{
			interfaceTeacher[i].count_avg_mark();
			interfaceTeacher[i].print_avg_mark();
			cout << endl;
		}
	}
}

void InterfacePrintAllStudent(vector<Student>& interfaceStudent)
{
	vector<string> grades; 
	short a = 0;
	grades.push_back(interfaceStudent[0].GetGrade());
	for (size_t i = 0; i < interfaceStudent.size(); i++)
	{	
		if (interfaceStudent[i].GetGrade() != grades[a]) 
		{
			grades.push_back(interfaceStudent[i].GetGrade());
			a++;
		}
	}
	cout << "In which grade does required student is studiyng?\n";
	for (size_t i = 0; i < grades.size(); i++)
	{
		cout << "Enter " << i + 1 << " if in " << grades[i] << endl;
	}
	short choicecase2;
	cin >> choicecase2;
	while (true)
	{
		if (choicecase2 <= 0 || choicecase2 > grades.size())
		{
			cout << "Enter valid number! Try again." << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin >> choicecase2;
		}
		else { break; }
	}
	short startstudent = 0, minicounter = 0; bool notfound = true;
	while (notfound && minicounter < interfaceStudent.size())
	{
		if (grades[choicecase2 - 1] == interfaceStudent[minicounter].GetGrade())
		{
			startstudent = minicounter;
			notfound = false;
		}
		minicounter++;
	}
	short willneedlater = startstudent;
	short counter = 0;
	while (startstudent < interfaceStudent.size() && interfaceStudent[startstudent].GetGrade() == grades[choicecase2 - 1] )
	{
		counter++; startstudent++;
		cout << "Enter " << counter << " if you want to see all the marks of " << interfaceStudent[startstudent-1].GetName() << endl;
		
	}
	short studentchoice;
	cin >> studentchoice;
	while (true)
	{
		if (studentchoice <= 0 || studentchoice > counter)
		{
			cout << "Enter valid number! Try again." << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin >> studentchoice;
		}
		else { break; }
	}
	interfaceStudent[studentchoice+willneedlater-1].print_marks();
}

void InterfaceFinalStudent(vector<Student>& interfaceStudent, vector<Teacher>& interfaceTeacher)
{
	vector<string> subjects; //adding all the subjects to a single vector
	short a = 0;
	subjects.push_back(interfaceTeacher[0].GetSubject());
	for (size_t i = 0; i < interfaceTeacher.size(); i++)
	{
		if (interfaceTeacher[i].GetSubject() != subjects[a])
		{
			subjects.push_back(interfaceTeacher[i].GetSubject());
			a++;
		}
	}
	cout << "Which subject are you interested in?\n"; // make a choice from vector
	for (size_t i = 0; i < subjects.size(); i++)
	{
		cout << "Enter " << i + 1 << " if you want " << subjects[i] << endl;
	}
	short subjectchoice;
	cin >> subjectchoice;
	while (true)
	{
		if (subjectchoice <= 0 || subjectchoice > subjects.size())
		{
			cout << "Enter valid number! Try again." << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin >> subjectchoice;
		}
		else { break; }
	}
	vector<string> grades; // adding all the grades to a single vector
	a = 0;
	grades.push_back(interfaceStudent[0].GetGrade());
	for (size_t i = 0; i < interfaceStudent.size(); i++)
	{
		if (interfaceStudent[i].GetGrade() != grades[a])
		{
			grades.push_back(interfaceStudent[i].GetGrade());
			a++;
		}
	}
	cout << "In which grade does required student is studiyng?\n"; // make a choice from vector
	for (size_t i = 0; i < grades.size(); i++)
	{
		cout << "Enter " << i + 1 << " if in " << grades[i] << endl;
	}
	short choicecase2;
	cin >> choicecase2;
	while (true)
	{
		if (choicecase2 <= 0 || choicecase2 > grades.size())
		{
			cout << "Enter valid number! Try again." << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin >> choicecase2;
		}
		else { break; }
	}
	short startstudent = 0, minicounter = 0; bool notfound = true; // finding first student's id basing on grade
	while (notfound && minicounter < interfaceStudent.size())
	{
		if (grades[choicecase2 - 1] == interfaceStudent[minicounter].GetGrade())
		{
			startstudent = minicounter;
			notfound = false;
		}
		minicounter++;
	}
	short willneedlater = startstudent;
	short counter = 0;
	while (startstudent < interfaceStudent.size() && interfaceStudent[startstudent].GetGrade() == grades[choicecase2 - 1]) // output all students from chosen grade
	{
		counter++; startstudent++;
		cout << "Enter " << counter << " if you want to see all the marks of " << interfaceStudent[startstudent - 1].GetName() << endl; // choose one from list

	}
	short studentchoice;
	cin >> studentchoice;
	while (true)
	{
		if (studentchoice <= 0 || studentchoice > counter)
		{
			cout << "Enter valid number! Try again." << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin >> studentchoice;
		}
		else { break; }
	}
	interfaceStudent[studentchoice + willneedlater - 1].count_final_mark(subjects[subjectchoice-1]); // output needed info about  student (id of student + choice made by user)
	interfaceStudent[studentchoice + willneedlater - 1].print_final_mark(subjects[subjectchoice - 1]);
}

int main() {

	// 11-A Students
	Student stVasB("Bragin Vasiliy Petrovich", 18, 180, "11-A");
	Student stPetrM("Maksimov Petr Pavlovich", 17, 182, "11-A");
	Student stDmiS("Sobolev Dmitriy Grigorievich", 17, 176, "11-A");
	Student stVladS("Suvorov Vladislav Viktorovich", 19, 182, "11-A");
	Student stNikG("Gavrilov Nikita Vladimirovich", 18, 178, "11-A");
	Student stMaksK("Kovalev Maksim Mykhailovich", 18, 177, "11-A");
	Student stIliaZ("Zaytcev Ilia Sergeevich", 18, 181, "11-A");
	Student stStepR("Rybakov Stepan Semenovich", 17, 180, "11-A");
	Student stAnasF("Fedoseeva Anastasia Petrovna", 18, 168, "11-A");
	Student stSofS("Sorokina Sofia Dmitrievna", 17, 172, "11-A");
	// 11-B Students
	Student stTimS("Striukov Tymofii Mykhailovich", 18, 180, "11-B");
	Student stIvanS("Shvergun Ivan Sergeevich", 17, 182, "11-B");
	Student stVladK("Klimov Vladislav Vladimirovich", 17, 176, "11-B");
	Student stVladM("Maslou Vladislav Timofeevich", 19, 182, "11-B");
	Student stAndrF("Fedorov Andrey Mykhailovich", 18, 178, "11-B");
	Student stAndrO("Orehov Andrey Andreevich", 18, 177, "11-B");
	Student stNikV("Kostin Nikita Vladislavovich", 18, 181, "11-B");
	Student stAlexE("Efremov Aleksandr Grigorievich", 17, 180, "11-B");
	Student stDarB("Bykova Daria Semenovna", 18, 168, "11-B");
	Student stSvetO("Orlova Svetlana Stepanovna", 17, 172, "11-B");
	// Teachers
	Teacher tcOlgaR("Radeva Olga Stepanovna", 43, 178, "English");
	Teacher tcVladN("Nazarov Vladimir Grigorievich", 45, 185, "Physics");
	Teacher tcVladT("Trofimov Vladislav Sergeevich", 51, 189, "History");
	// 1/10 11-A
	tcOlgaR.add_student(stVasB);
	tcOlgaR.add_new_mark(stVasB, HOME, 10);
	tcOlgaR.add_new_mark(stVasB, HOME, 9);
	tcOlgaR.add_new_mark(stVasB, TEST, 12);
	tcOlgaR.add_new_mark(stVasB, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stVasB, INDEPENDENT, 10);
	tcOlgaR.add_new_mark(stVasB, EXAM, 9);

	tcVladN.add_student(stVasB);
	tcVladN.add_new_mark(stVasB, HOME, 10);
	tcVladN.add_new_mark(stVasB, HOME, 7);
	tcVladN.add_new_mark(stVasB, TEST, 11);
	tcVladN.add_new_mark(stVasB, INDEPENDENT, 8);
	tcVladN.add_new_mark(stVasB, INDEPENDENT, 10);
	tcVladN.add_new_mark(stVasB, EXAM, 9);

	tcVladT.add_student(stVasB);
	tcVladT.add_new_mark(stVasB, HOME, 5);
	tcVladT.add_new_mark(stVasB, HOME, 9);
	tcVladT.add_new_mark(stVasB, TEST, 11);
	tcVladT.add_new_mark(stVasB, INDEPENDENT, 8);
	tcVladT.add_new_mark(stVasB, INDEPENDENT, 10);
	tcVladT.add_new_mark(stVasB, EXAM, 9);
	// 2/10
	tcOlgaR.add_student(stPetrM);
	tcOlgaR.add_new_mark(stPetrM, HOME, 10);
	tcOlgaR.add_new_mark(stPetrM, HOME, 9);
	tcOlgaR.add_new_mark(stPetrM, TEST, 4);
	tcOlgaR.add_new_mark(stPetrM, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stPetrM, INDEPENDENT, 10);
	tcOlgaR.add_new_mark(stPetrM, EXAM, 9);

	tcVladN.add_student(stPetrM);
	tcVladN.add_new_mark(stPetrM, HOME, 10);
	tcVladN.add_new_mark(stPetrM, HOME, 9);
	tcVladN.add_new_mark(stPetrM, TEST, 11);
	tcVladN.add_new_mark(stPetrM, INDEPENDENT, 8);
	tcVladN.add_new_mark(stPetrM, INDEPENDENT, 5);
	tcVladN.add_new_mark(stPetrM, EXAM, 9);

	tcVladT.add_student(stPetrM);
	tcVladT.add_new_mark(stPetrM, HOME, 10);
	tcVladT.add_new_mark(stPetrM, HOME, 9);
	tcVladT.add_new_mark(stPetrM, TEST, 7);
	tcVladT.add_new_mark(stPetrM, INDEPENDENT, 8);
	tcVladT.add_new_mark(stPetrM, INDEPENDENT, 10);
	tcVladT.add_new_mark(stPetrM, EXAM, 9);
	// 3/10
	tcOlgaR.add_student(stDmiS);
	tcOlgaR.add_new_mark(stDmiS, HOME, 10);
	tcOlgaR.add_new_mark(stDmiS, HOME, 9);
	tcOlgaR.add_new_mark(stDmiS, TEST, 11);
	tcOlgaR.add_new_mark(stDmiS, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stDmiS, INDEPENDENT, 5);
	tcOlgaR.add_new_mark(stDmiS, EXAM, 9);

	tcVladN.add_student(stDmiS);
	tcVladN.add_new_mark(stDmiS, HOME, 2);
	tcVladN.add_new_mark(stDmiS, HOME, 9);
	tcVladN.add_new_mark(stDmiS, TEST, 11);
	tcVladN.add_new_mark(stDmiS, INDEPENDENT, 8);
	tcVladN.add_new_mark(stDmiS, INDEPENDENT, 10);
	tcVladN.add_new_mark(stDmiS, EXAM, 9);

	tcVladT.add_student(stDmiS);
	tcVladT.add_new_mark(stDmiS, HOME, 10);
	tcVladT.add_new_mark(stDmiS, HOME, 9);
	tcVladT.add_new_mark(stDmiS, TEST, 11);
	tcVladT.add_new_mark(stDmiS, INDEPENDENT, 4);
	tcVladT.add_new_mark(stDmiS, INDEPENDENT, 10);
	tcVladT.add_new_mark(stDmiS, EXAM, 9);
	// 4/10
	tcOlgaR.add_student(stVladS);
	tcOlgaR.add_new_mark(stVladS, HOME, 11);
	tcOlgaR.add_new_mark(stVladS, HOME, 9);
	tcOlgaR.add_new_mark(stVladS, TEST, 11);
	tcOlgaR.add_new_mark(stVladS, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stVladS, INDEPENDENT, 10);
	tcOlgaR.add_new_mark(stVladS, EXAM, 9);

	tcVladN.add_student(stVladS);
	tcVladN.add_new_mark(stVladS, HOME, 10);
	tcVladN.add_new_mark(stVladS, HOME, 9);
	tcVladN.add_new_mark(stVladS, TEST, 11);
	tcVladN.add_new_mark(stVladS, INDEPENDENT, 12);
	tcVladN.add_new_mark(stVladS, INDEPENDENT, 10);
	tcVladN.add_new_mark(stVladS, EXAM, 9);

	tcVladT.add_student(stVladS);
	tcVladT.add_new_mark(stVladS, HOME, 10);
	tcVladT.add_new_mark(stVladS, HOME, 9);
	tcVladT.add_new_mark(stVladS, TEST, 11);
	tcVladT.add_new_mark(stVladS, INDEPENDENT, 8);
	tcVladT.add_new_mark(stVladS, INDEPENDENT, 10);
	tcVladT.add_new_mark(stVladS, EXAM, 9);
	// 5/10
	tcOlgaR.add_student(stNikG);
	tcOlgaR.add_new_mark(stNikG, HOME, 11);
	tcOlgaR.add_new_mark(stNikG, HOME, 9);
	tcOlgaR.add_new_mark(stNikG, TEST, 11);
	tcOlgaR.add_new_mark(stNikG, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stNikG, INDEPENDENT, 10);
	tcOlgaR.add_new_mark(stNikG, EXAM, 7);

	tcVladN.add_student(stNikG);
	tcVladN.add_new_mark(stNikG, HOME, 10);
	tcVladN.add_new_mark(stNikG, HOME, 12);
	tcVladN.add_new_mark(stNikG, TEST, 11);
	tcVladN.add_new_mark(stNikG, INDEPENDENT, 8);
	tcVladN.add_new_mark(stNikG, INDEPENDENT, 10);
	tcVladN.add_new_mark(stNikG, EXAM, 9);

	tcVladT.add_student(stNikG);
	tcVladT.add_new_mark(stNikG, HOME, 10);
	tcVladT.add_new_mark(stNikG, HOME, 9);
	tcVladT.add_new_mark(stNikG, TEST, 11);
	tcVladT.add_new_mark(stNikG, INDEPENDENT, 8);
	tcVladT.add_new_mark(stNikG, INDEPENDENT, 10);
	tcVladT.add_new_mark(stNikG, EXAM, 6);
	// 6/10 
	tcOlgaR.add_student(stMaksK);
	tcOlgaR.add_new_mark(stMaksK, HOME, 10);
	tcOlgaR.add_new_mark(stMaksK, HOME, 9);
	tcOlgaR.add_new_mark(stMaksK, TEST, 11);
	tcOlgaR.add_new_mark(stMaksK, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stMaksK, INDEPENDENT, 2);
	tcOlgaR.add_new_mark(stMaksK, EXAM, 9);

	tcVladN.add_student(stMaksK);
	tcVladN.add_new_mark(stMaksK, HOME, 10);
	tcVladN.add_new_mark(stMaksK, HOME, 9);
	tcVladN.add_new_mark(stMaksK, TEST, 11);
	tcVladN.add_new_mark(stMaksK, INDEPENDENT, 3);
	tcVladN.add_new_mark(stMaksK, INDEPENDENT, 10);
	tcVladN.add_new_mark(stMaksK, EXAM, 9);

	tcVladT.add_student(stMaksK);
	tcVladT.add_new_mark(stMaksK, HOME, 10);
	tcVladT.add_new_mark(stMaksK, HOME, 9);
	tcVladT.add_new_mark(stMaksK, TEST, 4);
	tcVladT.add_new_mark(stMaksK, INDEPENDENT, 8);
	tcVladT.add_new_mark(stMaksK, INDEPENDENT, 10);
	tcVladT.add_new_mark(stMaksK, EXAM, 9);
	// 7/10
	tcOlgaR.add_student(stIliaZ);
	tcOlgaR.add_new_mark(stIliaZ, HOME, 2);
	tcOlgaR.add_new_mark(stIliaZ, HOME, 9);
	tcOlgaR.add_new_mark(stIliaZ, TEST, 11);
	tcOlgaR.add_new_mark(stIliaZ, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stIliaZ, INDEPENDENT, 11);
	tcOlgaR.add_new_mark(stIliaZ, EXAM, 9);

	tcVladN.add_student(stIliaZ);
	tcVladN.add_new_mark(stIliaZ, HOME, 10);
	tcVladN.add_new_mark(stIliaZ, HOME, 9);
	tcVladN.add_new_mark(stIliaZ, TEST, 12);
	tcVladN.add_new_mark(stIliaZ, INDEPENDENT, 8);
	tcVladN.add_new_mark(stIliaZ, INDEPENDENT, 10);
	tcVladN.add_new_mark(stIliaZ, EXAM, 3);

	tcVladT.add_student(stIliaZ);
	tcVladT.add_new_mark(stIliaZ, HOME, 10);
	tcVladT.add_new_mark(stIliaZ, HOME, 9);
	tcVladT.add_new_mark(stIliaZ, TEST, 11);
	tcVladT.add_new_mark(stIliaZ, INDEPENDENT, 8);
	tcVladT.add_new_mark(stIliaZ, INDEPENDENT, 10);
	tcVladT.add_new_mark(stIliaZ, EXAM, 9);
	// 8/10 
	tcOlgaR.add_student(stStepR);
	tcOlgaR.add_new_mark(stStepR, HOME, 12);
	tcOlgaR.add_new_mark(stStepR, HOME, 9);
	tcOlgaR.add_new_mark(stStepR, TEST, 11);
	tcOlgaR.add_new_mark(stStepR, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stStepR, INDEPENDENT, 4);
	tcOlgaR.add_new_mark(stStepR, EXAM, 9);

	tcVladN.add_student(stStepR);
	tcVladN.add_new_mark(stStepR, HOME, 10);
	tcVladN.add_new_mark(stStepR, HOME, 9);
	tcVladN.add_new_mark(stStepR, TEST, 5);
	tcVladN.add_new_mark(stStepR, INDEPENDENT, 8);
	tcVladN.add_new_mark(stStepR, INDEPENDENT, 10);
	tcVladN.add_new_mark(stStepR, EXAM, 12);

	tcVladT.add_student(stStepR);
	tcVladT.add_new_mark(stStepR, HOME, 12);
	tcVladT.add_new_mark(stStepR, HOME, 9);
	tcVladT.add_new_mark(stStepR, TEST, 11);
	tcVladT.add_new_mark(stStepR, INDEPENDENT, 8);
	tcVladT.add_new_mark(stStepR, INDEPENDENT, 4);
	tcVladT.add_new_mark(stStepR, EXAM, 9);
	// 9/10
	tcOlgaR.add_student(stAnasF);
	tcOlgaR.add_new_mark(stAnasF, HOME, 10);
	tcOlgaR.add_new_mark(stAnasF, HOME, 9);
	tcOlgaR.add_new_mark(stAnasF, TEST, 11);
	tcOlgaR.add_new_mark(stAnasF, INDEPENDENT, 12);
	tcOlgaR.add_new_mark(stAnasF, INDEPENDENT, 10);
	tcOlgaR.add_new_mark(stAnasF, EXAM, 9);

	tcVladN.add_student(stAnasF);
	tcVladN.add_new_mark(stAnasF, HOME, 10);
	tcVladN.add_new_mark(stAnasF, HOME, 9);
	tcVladN.add_new_mark(stAnasF, TEST, 11);
	tcVladN.add_new_mark(stAnasF, INDEPENDENT, 8);
	tcVladN.add_new_mark(stAnasF, INDEPENDENT, 4);
	tcVladN.add_new_mark(stAnasF, EXAM, 9);

	tcVladT.add_student(stAnasF);
	tcVladT.add_new_mark(stAnasF, HOME, 10);
	tcVladT.add_new_mark(stAnasF, HOME, 9);
	tcVladT.add_new_mark(stAnasF, TEST, 11);
	tcVladT.add_new_mark(stAnasF, INDEPENDENT, 8);
	tcVladT.add_new_mark(stAnasF, INDEPENDENT, 10);
	tcVladT.add_new_mark(stAnasF, EXAM, 9);
	// 10/10 
	tcOlgaR.add_student(stSofS);
	tcOlgaR.add_new_mark(stSofS, HOME, 10);
	tcOlgaR.add_new_mark(stSofS, HOME, 9);
	tcOlgaR.add_new_mark(stSofS, TEST, 11);
	tcOlgaR.add_new_mark(stSofS, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stSofS, INDEPENDENT, 10);
	tcOlgaR.add_new_mark(stSofS, EXAM, 9);

	tcVladN.add_student(stSofS);
	tcVladN.add_new_mark(stSofS, HOME, 10);
	tcVladN.add_new_mark(stSofS, HOME, 9);
	tcVladN.add_new_mark(stSofS, TEST, 11);
	tcVladN.add_new_mark(stSofS, INDEPENDENT, 8);
	tcVladN.add_new_mark(stSofS, INDEPENDENT, 10);
	tcVladN.add_new_mark(stSofS, EXAM, 9);

	tcVladT.add_student(stSofS);
	tcVladT.add_new_mark(stSofS, HOME, 10);
	tcVladT.add_new_mark(stSofS, HOME, 9);
	tcVladT.add_new_mark(stSofS, TEST, 11);
	tcVladT.add_new_mark(stSofS, INDEPENDENT, 8);
	tcVladT.add_new_mark(stSofS, INDEPENDENT, 10);
	tcVladT.add_new_mark(stSofS, EXAM, 9);
	// 1/10 11-B
	tcOlgaR.add_student(stTimS);
	tcOlgaR.add_new_mark(stTimS, HOME, 10);
	tcOlgaR.add_new_mark(stTimS, HOME, 9);
	tcOlgaR.add_new_mark(stTimS, TEST, 4);
	tcOlgaR.add_new_mark(stTimS, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stTimS, INDEPENDENT, 10);
	tcOlgaR.add_new_mark(stTimS, EXAM, 9);

	tcVladN.add_student(stTimS);
	tcVladN.add_new_mark(stTimS, HOME, 10);
	tcVladN.add_new_mark(stTimS, HOME, 9);
	tcVladN.add_new_mark(stTimS, TEST, 11);
	tcVladN.add_new_mark(stTimS, INDEPENDENT, 8);
	tcVladN.add_new_mark(stTimS, INDEPENDENT, 3);
	tcVladN.add_new_mark(stTimS, EXAM, 9);

	tcVladT.add_student(stTimS);
	tcVladT.add_new_mark(stTimS, HOME, 10);
	tcVladT.add_new_mark(stTimS, HOME, 9);
	tcVladT.add_new_mark(stTimS, TEST, 11);
	tcVladT.add_new_mark(stTimS, INDEPENDENT, 8);
	tcVladT.add_new_mark(stTimS, INDEPENDENT, 2);
	tcVladT.add_new_mark(stTimS, EXAM, 9);
	// 2/10
	tcOlgaR.add_student(stIvanS);
	tcOlgaR.add_new_mark(stIvanS, HOME, 12);
	tcOlgaR.add_new_mark(stIvanS, HOME, 12);
	tcOlgaR.add_new_mark(stIvanS, TEST, 11);
	tcOlgaR.add_new_mark(stIvanS, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stIvanS, INDEPENDENT, 10);
	tcOlgaR.add_new_mark(stIvanS, EXAM, 9);

	tcVladN.add_student(stIvanS);
	tcVladN.add_new_mark(stIvanS, HOME, 10);
	tcVladN.add_new_mark(stIvanS, HOME, 12);
	tcVladN.add_new_mark(stIvanS, TEST, 11);
	tcVladN.add_new_mark(stIvanS, INDEPENDENT, 8);
	tcVladN.add_new_mark(stIvanS, INDEPENDENT, 10);
	tcVladN.add_new_mark(stIvanS, EXAM, 9);

	tcVladT.add_student(stIvanS);
	tcVladT.add_new_mark(stIvanS, HOME, 10);
	tcVladT.add_new_mark(stIvanS, HOME, 9);
	tcVladT.add_new_mark(stIvanS, TEST, 11);
	tcVladT.add_new_mark(stIvanS, INDEPENDENT, 8);
	tcVladT.add_new_mark(stIvanS, INDEPENDENT, 10);
	tcVladT.add_new_mark(stIvanS, EXAM, 9);
	// 3/10
	tcOlgaR.add_student(stVladK);
	tcOlgaR.add_new_mark(stVladK, HOME, 10);
	tcOlgaR.add_new_mark(stVladK, HOME, 12);
	tcOlgaR.add_new_mark(stVladK, TEST, 11);
	tcOlgaR.add_new_mark(stVladK, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stVladK, INDEPENDENT, 10);
	tcOlgaR.add_new_mark(stVladK, EXAM, 9);

	tcVladN.add_student(stVladK);
	tcVladN.add_new_mark(stVladK, HOME, 10);
	tcVladN.add_new_mark(stVladK, HOME, 9);
	tcVladN.add_new_mark(stVladK, TEST, 4);
	tcVladN.add_new_mark(stVladK, INDEPENDENT, 8);
	tcVladN.add_new_mark(stVladK, INDEPENDENT, 10);
	tcVladN.add_new_mark(stVladK, EXAM, 9);

	tcVladT.add_student(stVladK);
	tcVladT.add_new_mark(stVladK, HOME, 10);
	tcVladT.add_new_mark(stVladK, HOME, 9);
	tcVladT.add_new_mark(stVladK, TEST, 3);
	tcVladT.add_new_mark(stVladK, INDEPENDENT, 8);
	tcVladT.add_new_mark(stVladK, INDEPENDENT, 10);
	tcVladT.add_new_mark(stVladK, EXAM, 9);
	// 4/10
	tcOlgaR.add_student(stVladM);
	tcOlgaR.add_new_mark(stVladM, HOME, 10);
	tcOlgaR.add_new_mark(stVladM, HOME, 9);
	tcOlgaR.add_new_mark(stVladM, TEST, 11);
	tcOlgaR.add_new_mark(stVladM, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stVladM, INDEPENDENT, 2);
	tcOlgaR.add_new_mark(stVladM, EXAM, 9);

	tcVladN.add_student(stVladM);
	tcVladN.add_new_mark(stVladM, HOME, 10);
	tcVladN.add_new_mark(stVladM, HOME, 9);
	tcVladN.add_new_mark(stVladM, TEST, 11);
	tcVladN.add_new_mark(stVladM, INDEPENDENT, 8);
	tcVladN.add_new_mark(stVladM, INDEPENDENT, 11);
	tcVladN.add_new_mark(stVladM, EXAM, 9);

	tcVladT.add_student(stVladM);
	tcVladT.add_new_mark(stVladM, HOME, 10);
	tcVladT.add_new_mark(stVladM, HOME, 9);
	tcVladT.add_new_mark(stVladM, TEST, 11);
	tcVladT.add_new_mark(stVladM, INDEPENDENT, 8);
	tcVladT.add_new_mark(stVladM, INDEPENDENT, 10);
	tcVladT.add_new_mark(stVladM, EXAM, 9);
	// 5/10
	tcOlgaR.add_student(stAndrF);
	tcOlgaR.add_new_mark(stAndrF, HOME, 10);
	tcOlgaR.add_new_mark(stAndrF, HOME, 9);
	tcOlgaR.add_new_mark(stAndrF, TEST, 11);
	tcOlgaR.add_new_mark(stAndrF, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stAndrF, INDEPENDENT, 12);
	tcOlgaR.add_new_mark(stAndrF, EXAM, 9);

	tcVladN.add_student(stAndrF);
	tcVladN.add_new_mark(stAndrF, HOME, 10);
	tcVladN.add_new_mark(stAndrF, HOME, 9);
	tcVladN.add_new_mark(stAndrF, TEST, 11);
	tcVladN.add_new_mark(stAndrF, INDEPENDENT, 8);
	tcVladN.add_new_mark(stAndrF, INDEPENDENT, 10);
	tcVladN.add_new_mark(stAndrF, EXAM, 9);

	tcVladT.add_student(stAndrF);
	tcVladT.add_new_mark(stAndrF, HOME, 10);
	tcVladT.add_new_mark(stAndrF, HOME, 9);
	tcVladT.add_new_mark(stAndrF, TEST, 11);
	tcVladT.add_new_mark(stAndrF, INDEPENDENT, 8);
	tcVladT.add_new_mark(stAndrF, INDEPENDENT, 12);
	tcVladT.add_new_mark(stAndrF, EXAM, 9);
	// 6/10 
	tcOlgaR.add_student(stAndrO);
	tcOlgaR.add_new_mark(stAndrO, HOME, 11);
	tcOlgaR.add_new_mark(stAndrO, HOME, 9);
	tcOlgaR.add_new_mark(stAndrO, TEST, 11);
	tcOlgaR.add_new_mark(stAndrO, INDEPENDENT, 11);
	tcOlgaR.add_new_mark(stAndrO, INDEPENDENT, 11);
	tcOlgaR.add_new_mark(stAndrO, EXAM, 9);

	tcVladN.add_student(stAndrO);
	tcVladN.add_new_mark(stAndrO, HOME, 10);
	tcVladN.add_new_mark(stAndrO, HOME, 9);
	tcVladN.add_new_mark(stAndrO, TEST, 11);
	tcVladN.add_new_mark(stAndrO, INDEPENDENT, 8);
	tcVladN.add_new_mark(stAndrO, INDEPENDENT, 10);
	tcVladN.add_new_mark(stAndrO, EXAM, 9);

	tcVladT.add_student(stAndrO);
	tcVladT.add_new_mark(stAndrO, HOME, 10);
	tcVladT.add_new_mark(stAndrO, HOME, 9);
	tcVladT.add_new_mark(stAndrO, TEST, 11);
	tcVladT.add_new_mark(stAndrO, INDEPENDENT, 8);
	tcVladT.add_new_mark(stAndrO, INDEPENDENT, 10);
	tcVladT.add_new_mark(stAndrO, EXAM, 9);
	// 7/10
	tcOlgaR.add_student(stNikV);
	tcOlgaR.add_new_mark(stNikV, HOME, 10);
	tcOlgaR.add_new_mark(stNikV, HOME, 9);
	tcOlgaR.add_new_mark(stNikV, TEST, 11);
	tcOlgaR.add_new_mark(stNikV, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stNikV, INDEPENDENT, 10);
	tcOlgaR.add_new_mark(stNikV, EXAM, 9);

	tcVladN.add_student(stNikV);
	tcVladN.add_new_mark(stNikV, HOME, 10);
	tcVladN.add_new_mark(stNikV, HOME, 9);
	tcVladN.add_new_mark(stNikV, TEST, 11);
	tcVladN.add_new_mark(stNikV, INDEPENDENT, 8);
	tcVladN.add_new_mark(stNikV, INDEPENDENT, 10);
	tcVladN.add_new_mark(stNikV, EXAM, 9);

	tcVladT.add_student(stNikV);
	tcVladT.add_new_mark(stNikV, HOME, 10);
	tcVladT.add_new_mark(stNikV, HOME, 9);
	tcVladT.add_new_mark(stNikV, TEST, 11);
	tcVladT.add_new_mark(stNikV, INDEPENDENT, 8);
	tcVladT.add_new_mark(stNikV, INDEPENDENT, 10);
	tcVladT.add_new_mark(stNikV, EXAM, 9);
	// 8/10 
	tcOlgaR.add_student(stAlexE);
	tcOlgaR.add_new_mark(stAlexE, HOME, 10);
	tcOlgaR.add_new_mark(stAlexE, HOME, 9);
	tcOlgaR.add_new_mark(stAlexE, TEST, 11);
	tcOlgaR.add_new_mark(stAlexE, INDEPENDENT, 12);
	tcOlgaR.add_new_mark(stAlexE, INDEPENDENT, 10);
	tcOlgaR.add_new_mark(stAlexE, EXAM, 12);

	tcVladN.add_student(stAlexE);
	tcVladN.add_new_mark(stAlexE, HOME, 10);
	tcVladN.add_new_mark(stAlexE, HOME, 9);
	tcVladN.add_new_mark(stAlexE, TEST, 11);
	tcVladN.add_new_mark(stAlexE, INDEPENDENT, 4);
	tcVladN.add_new_mark(stAlexE, INDEPENDENT, 10);
	tcVladN.add_new_mark(stAlexE, EXAM, 9);

	tcVladT.add_student(stAlexE);
	tcVladT.add_new_mark(stAlexE, HOME, 10);
	tcVladT.add_new_mark(stAlexE, HOME, 9);
	tcVladT.add_new_mark(stAlexE, TEST, 11);
	tcVladT.add_new_mark(stAlexE, INDEPENDENT, 8);
	tcVladT.add_new_mark(stAlexE, INDEPENDENT, 7);
	tcVladT.add_new_mark(stAlexE, EXAM, 9);
	// 9/10
	tcOlgaR.add_student(stDarB);
	tcOlgaR.add_new_mark(stDarB, HOME, 10);
	tcOlgaR.add_new_mark(stDarB, HOME, 9);
	tcOlgaR.add_new_mark(stDarB, TEST, 2);
	tcOlgaR.add_new_mark(stDarB, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stDarB, INDEPENDENT, 10);
	tcOlgaR.add_new_mark(stDarB, EXAM, 9);

	tcVladN.add_student(stDarB);
	tcVladN.add_new_mark(stDarB, HOME, 10);
	tcVladN.add_new_mark(stDarB, HOME, 9);
	tcVladN.add_new_mark(stDarB, TEST, 3);
	tcVladN.add_new_mark(stDarB, INDEPENDENT, 8);
	tcVladN.add_new_mark(stDarB, INDEPENDENT, 10);
	tcVladN.add_new_mark(stDarB, EXAM, 9);

	tcVladT.add_student(stDarB);
	tcVladT.add_new_mark(stDarB, HOME, 10);
	tcVladT.add_new_mark(stDarB, HOME, 9);
	tcVladT.add_new_mark(stDarB, TEST, 4);
	tcVladT.add_new_mark(stDarB, INDEPENDENT, 8);
	tcVladT.add_new_mark(stDarB, INDEPENDENT, 10);
	tcVladT.add_new_mark(stDarB, EXAM, 9);
	// 10/10 
	tcOlgaR.add_student(stSvetO);
	tcOlgaR.add_new_mark(stSvetO, HOME, 10);
	tcOlgaR.add_new_mark(stSvetO, HOME, 9);
	tcOlgaR.add_new_mark(stSvetO, TEST, 2);
	tcOlgaR.add_new_mark(stSvetO, INDEPENDENT, 8);
	tcOlgaR.add_new_mark(stSvetO, INDEPENDENT, 10);
	tcOlgaR.add_new_mark(stSvetO, EXAM, 9);

	tcVladN.add_student(stSvetO);
	tcVladN.add_new_mark(stSvetO, HOME, 10);
	tcVladN.add_new_mark(stSvetO, HOME, 11);
	tcVladN.add_new_mark(stSvetO, TEST, 11);
	tcVladN.add_new_mark(stSvetO, INDEPENDENT, 8);
	tcVladN.add_new_mark(stSvetO, INDEPENDENT, 11);
	tcVladN.add_new_mark(stSvetO, EXAM, 11);

	tcVladT.add_student(stSvetO);
	tcVladT.add_new_mark(stSvetO, HOME, 10);
	tcVladT.add_new_mark(stSvetO, HOME, 9);
	tcVladT.add_new_mark(stSvetO, TEST, 11);
	tcVladT.add_new_mark(stSvetO, INDEPENDENT, 12);
	tcVladT.add_new_mark(stSvetO, INDEPENDENT, 10);
	tcVladT.add_new_mark(stSvetO, EXAM, 9);
	// For menu / Menu
	// Add students and teachers to a suitable vectors for manipulations in menu
	vector<Student> Students =
	{ stVasB, stPetrM, stDmiS, stVladS, stNikG, stMaksK, stIliaZ, stStepR, stAnasF, stSofS,
	stTimS, stIvanS, stVladK, stVladM, stAndrF, stAndrO, stNikV, stAlexE, stDarB, stSvetO };
	vector<Teacher> Teachers = { tcOlgaR, tcVladN, tcVladT };
	Interface(Students, Teachers);

	return 0;
}