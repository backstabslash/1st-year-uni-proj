#include <iostream>
#include <vector>
#include <fstream>
#include "Teacher.h"
#include "Student.h"
#include "Human.h"
#include "Mark.h"
using namespace std;

enum type_of_mark {
	HOME = 1,
	TEST = 2,
	INDEPENDENT = 3,
	EXAM = 4
};

void Interface(vector<Student> interfaceStudent, vector<Teacher> interfaceTeacher)
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
			cout << "What teacher do you need?\n";
			cout << "1 - Radeva Olga Stepanovna, English\n";
			cout << "2 - Nazarov Vladimir Grigorievich, Physics\n";
			cout << "3 - Trofimov Vladislav Sergeevich, History\n";
			short choicecase1;
			cin >> choicecase1;
			while (true)
			{
				if (choicecase1 <= 0 || choicecase1 > 3)
				{
					cout << "Enter valid number! Try again." << endl;
					cin.clear();
					while (cin.get() != '\n');
					cin >> choicecase1;
				}
				else { break; }
			}
			if (choicecase1 == 1)
			{
				for (size_t i = 0; i < interfaceTeacher.size(); i++) {
					if (interfaceTeacher[i].GetName() == "Radeva Olga Stepanovna") 
					{
						interfaceTeacher[i].avg_mark(); cout << endl;
					}
				}
			}
			else if (choicecase1 == 2)
			{
				for (size_t i = 0; i < interfaceTeacher.size(); i++) {
					if (interfaceTeacher[i].GetName() == "Nazarov Vladimir Grigorievich") 
					{
						interfaceTeacher[i].avg_mark(); cout << endl;
					}
				}
			}
			else
			{
				for (size_t i = 0; i < interfaceTeacher.size(); i++) {
					if (interfaceTeacher[i].GetName() == "Trofimov Vladislav Sergeevich")
					{
						interfaceTeacher[i].avg_mark(); cout << endl;
					}
				}
			}
			break;
		case 2:
			cout << "In which grade does required student is studiyng?\n";
			cout << "1 - 11-A\n" << "2 - 11-B\n";
			short choicecase2;
			cin >> choicecase2;
			while (true)
			{
				if (choicecase2 <= 0 || choicecase2 > 2)
				{
					cout << "Enter valid number! Try again." << endl;
					cin.clear();
					while (cin.get() != '\n');
					cin >> choicecase2;
				}
				else { break; }
			}
			if (choicecase2 == 1) 
			{
				short studentchoice, counter = 1;
				for (size_t i = 0; i < interfaceStudent.size(); i++)
				{
					if (interfaceStudent[i].GetGrade() == "11-A")
					{
						cout << "Enter " << counter << " if you want to see marks of " << interfaceStudent[i].GetName() << '\n';
						counter++;
					}
				}
				cin >> studentchoice;
				while (true)
				{
					if (studentchoice <= 0 || studentchoice > counter-1)
					{
						cout << "Enter valid number! Try again." << endl;
						cin.clear();
						while (cin.get() != '\n');
						cin >> studentchoice;
					}
					else { break; }
				}
				short minicounter = 1;
				for (size_t i = 0; i < interfaceStudent.size(); i++)
				{
					if (interfaceStudent[i].GetGrade() == "11-A") 
					{
						if (minicounter == studentchoice)
						{
							interfaceStudent[i].print_marks();
						}
						minicounter++;
					}
				}
			}
			else
			{
				int studentchoice, counter2 = 1;
				for (size_t i = 0; i < interfaceStudent.size(); i++)
				{
					if (interfaceStudent[i].GetGrade() == "11-B") {
						cout << "Enter " << counter2 << " if you want to see marks of " << interfaceStudent[i].GetName() << '\n';
						counter2++;
					}
				}
				cin >> studentchoice;
				while (true)
				{
					if (studentchoice <= 0 || studentchoice > counter2-1)
					{
						cout << "Enter valid number! Try again." << endl;
						cin.clear();
						while (cin.get() != '\n');
						cin >> studentchoice;
					}
					else { break; }
				}
				short minicounter = 1;
				for (size_t i = 0; i < interfaceStudent.size(); i++)
				{
					if (interfaceStudent[i].GetGrade() == "11-B") 
					{
						if (minicounter == studentchoice) 
						{
							interfaceStudent[i].print_marks();
						}
						minicounter++;
					}
				}
			}
			break;
		case 3:
			cout << "Which subject are you interested in?\n";
			cout << "1 - English\n" << "2 - Physics\n" << "3 - History\n";
			short subjectchoice;
			cin >> subjectchoice;
			while (true)
			{
				if (subjectchoice <= 0 || subjectchoice > 3)
				{
					cout << "Enter valid number! Try again." << endl;
					cin.clear();
					while (cin.get() != '\n');
					cin >> subjectchoice;
				}
				else { break; }
			}
			cout << "In which grade does required student is studiyng?\n";
			cout << "1 - 11-A\n" << "2 - 11-B\n";
			cin >> choicecase2;
			while (true)
			{
				if (choicecase2 <= 0 || choicecase2 > 2)
				{
					cout << "Enter valid number! Try again." << endl;
					cin.clear();
					while (cin.get() != '\n');
					cin >> choicecase2;
				}
				else { break; }
			}
			if (choicecase2 == 1)
			{
				short studentchoice, counter = 1;
				for (size_t i = 0; i < interfaceStudent.size(); i++)
				{
					if (interfaceStudent[i].GetGrade() == "11-A") 
					{
						cout << "Enter " << counter << " if you want to see the final mark of " << interfaceStudent[i].GetName() << '\n';
						counter++;
					}
				}
				cin >> studentchoice;
				while (true)
				{
					if (studentchoice <= 0 || studentchoice > counter - 1)
					{
						cout << "Enter valid number! Try again." << endl;
						cin.clear();
						while (cin.get() != '\n');
						cin >> studentchoice;
					}
					else { break; }
				}
				short minicounter = 1;
				for (size_t i = 0; i < interfaceStudent.size(); i++)
				{
					if (interfaceStudent[i].GetGrade() == "11-A") 
					{
						if (minicounter == studentchoice) {
							if (subjectchoice == 1) 
							{
								interfaceStudent[i].final_mark("English"); cout << endl;
							}
							else if (subjectchoice == 2) 
							{
								interfaceStudent[i].final_mark("Physics"); cout << endl;
							}
							else { interfaceStudent[i].final_mark("History"); cout << endl; }
						}
						minicounter++;
					}
				}
			}
			else
			{
				short studentchoice, counter2 = 1;
				for (size_t i = 0; i < interfaceStudent.size(); i++)
				{
					if (interfaceStudent[i].GetGrade() == "11-B") 
					{
						cout << "Enter " << counter2 << " if you want to see the final mark of " << interfaceStudent[i].GetName() << '\n';
						counter2++;
					}
				}
				cin >> studentchoice;
				while (true)
				{
					if (studentchoice <= 0 || studentchoice > counter2 - 1)
					{
						cout << "Enter valid number! Try again." << endl;
						cin.clear();
						while (cin.get() != '\n');
						cin >> studentchoice;
					}
					else { break; }
				}
				short minicounter = 1;
				for (size_t i = 0; i < interfaceStudent.size(); i++)
				{
					if (interfaceStudent[i].GetGrade() == "11-B")
					{
						if (minicounter == studentchoice)
						{
							if (subjectchoice == 1) {
								interfaceStudent[i].final_mark("English"); cout << endl;
							}
							else if (subjectchoice == 2) 
							{
								interfaceStudent[i].final_mark("Physics"); cout << endl;
							}
							else { interfaceStudent[i].final_mark("History"); cout << endl; }
						}
						minicounter++;
					}
				}
			}
			break;
		case 4:
			exit(0);
		}
	}
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
	tcOlgaR.add_new_mark(stVasB, 1, 10);
	tcOlgaR.add_new_mark(stVasB, 1, 9);
	tcOlgaR.add_new_mark(stVasB, 2, 12);
	tcOlgaR.add_new_mark(stVasB, 3, 8);
	tcOlgaR.add_new_mark(stVasB, 3, 10);
	tcOlgaR.add_new_mark(stVasB, 4, 9);

	tcVladN.add_student(stVasB);
	tcVladN.add_new_mark(stVasB, 1, 10);
	tcVladN.add_new_mark(stVasB, 1, 7);
	tcVladN.add_new_mark(stVasB, 2, 11);
	tcVladN.add_new_mark(stVasB, 3, 8);
	tcVladN.add_new_mark(stVasB, 3, 10);
	tcVladN.add_new_mark(stVasB, 4, 9);

	tcVladT.add_student(stVasB);
	tcVladT.add_new_mark(stVasB, 1, 5);
	tcVladT.add_new_mark(stVasB, 1, 9);
	tcVladT.add_new_mark(stVasB, 2, 11);
	tcVladT.add_new_mark(stVasB, 3, 8);
	tcVladT.add_new_mark(stVasB, 3, 10);
	tcVladT.add_new_mark(stVasB, 4, 9);
	// 2/10
	tcOlgaR.add_student(stPetrM);
	tcOlgaR.add_new_mark(stPetrM, 1, 10);
	tcOlgaR.add_new_mark(stPetrM, 1, 9);
	tcOlgaR.add_new_mark(stPetrM, 2, 4);
	tcOlgaR.add_new_mark(stPetrM, 3, 8);
	tcOlgaR.add_new_mark(stPetrM, 3, 10);
	tcOlgaR.add_new_mark(stPetrM, 4, 9);

	tcVladN.add_student(stPetrM);
	tcVladN.add_new_mark(stPetrM, 1, 10);
	tcVladN.add_new_mark(stPetrM, 1, 9);
	tcVladN.add_new_mark(stPetrM, 2, 11);
	tcVladN.add_new_mark(stPetrM, 3, 8);
	tcVladN.add_new_mark(stPetrM, 3, 5);
	tcVladN.add_new_mark(stPetrM, 4, 9);

	tcVladT.add_student(stPetrM);
	tcVladT.add_new_mark(stPetrM, 1, 10);
	tcVladT.add_new_mark(stPetrM, 1, 9);
	tcVladT.add_new_mark(stPetrM, 2, 7);
	tcVladT.add_new_mark(stPetrM, 3, 8);
	tcVladT.add_new_mark(stPetrM, 3, 10);
	tcVladT.add_new_mark(stPetrM, 4, 9);
	// 3/10
	tcOlgaR.add_student(stDmiS);
	tcOlgaR.add_new_mark(stDmiS, 1, 10);
	tcOlgaR.add_new_mark(stDmiS, 1, 9);
	tcOlgaR.add_new_mark(stDmiS, 2, 11);
	tcOlgaR.add_new_mark(stDmiS, 3, 8);
	tcOlgaR.add_new_mark(stDmiS, 3, 5);
	tcOlgaR.add_new_mark(stDmiS, 4, 9);

	tcVladN.add_student(stDmiS);
	tcVladN.add_new_mark(stDmiS, 1, 2);
	tcVladN.add_new_mark(stDmiS, 1, 9);
	tcVladN.add_new_mark(stDmiS, 2, 11);
	tcVladN.add_new_mark(stDmiS, 3, 8);
	tcVladN.add_new_mark(stDmiS, 3, 10);
	tcVladN.add_new_mark(stDmiS, 4, 9);

	tcVladT.add_student(stDmiS);
	tcVladT.add_new_mark(stDmiS, 1, 10);
	tcVladT.add_new_mark(stDmiS, 1, 9);
	tcVladT.add_new_mark(stDmiS, 2, 11);
	tcVladT.add_new_mark(stDmiS, 3, 4);
	tcVladT.add_new_mark(stDmiS, 3, 10);
	tcVladT.add_new_mark(stDmiS, 4, 9);
	// 4/10
	tcOlgaR.add_student(stVladS);
	tcOlgaR.add_new_mark(stVladS, 1, 11);
	tcOlgaR.add_new_mark(stVladS, 1, 9);
	tcOlgaR.add_new_mark(stVladS, 2, 11);
	tcOlgaR.add_new_mark(stVladS, 3, 8);
	tcOlgaR.add_new_mark(stVladS, 3, 10);
	tcOlgaR.add_new_mark(stVladS, 4, 9);

	tcVladN.add_student(stVladS);
	tcVladN.add_new_mark(stVladS, 1, 10);
	tcVladN.add_new_mark(stVladS, 1, 9);
	tcVladN.add_new_mark(stVladS, 2, 11);
	tcVladN.add_new_mark(stVladS, 3, 12);
	tcVladN.add_new_mark(stVladS, 3, 10);
	tcVladN.add_new_mark(stVladS, 4, 9);

	tcVladT.add_student(stVladS);
	tcVladT.add_new_mark(stVladS, 1, 10);
	tcVladT.add_new_mark(stVladS, 1, 9);
	tcVladT.add_new_mark(stVladS, 2, 11);
	tcVladT.add_new_mark(stVladS, 3, 8);
	tcVladT.add_new_mark(stVladS, 3, 10);
	tcVladT.add_new_mark(stVladS, 4, 9);
	// 5/10
	tcOlgaR.add_student(stNikG);
	tcOlgaR.add_new_mark(stNikG, 1, 11);
	tcOlgaR.add_new_mark(stNikG, 1, 9);
	tcOlgaR.add_new_mark(stNikG, 2, 11);
	tcOlgaR.add_new_mark(stNikG, 3, 8);
	tcOlgaR.add_new_mark(stNikG, 3, 10);
	tcOlgaR.add_new_mark(stNikG, 4, 7);

	tcVladN.add_student(stNikG);
	tcVladN.add_new_mark(stNikG, 1, 10);
	tcVladN.add_new_mark(stNikG, 1, 12);
	tcVladN.add_new_mark(stNikG, 2, 11);
	tcVladN.add_new_mark(stNikG, 3, 8);
	tcVladN.add_new_mark(stNikG, 3, 10);
	tcVladN.add_new_mark(stNikG, 4, 9);

	tcVladT.add_student(stNikG);
	tcVladT.add_new_mark(stNikG, 1, 10);
	tcVladT.add_new_mark(stNikG, 1, 9);
	tcVladT.add_new_mark(stNikG, 2, 11);
	tcVladT.add_new_mark(stNikG, 3, 8);
	tcVladT.add_new_mark(stNikG, 3, 10);
	tcVladT.add_new_mark(stNikG, 4, 6);
	// 6/10 
	tcOlgaR.add_student(stMaksK);
	tcOlgaR.add_new_mark(stMaksK, 1, 10);
	tcOlgaR.add_new_mark(stMaksK, 1, 9);
	tcOlgaR.add_new_mark(stMaksK, 2, 11);
	tcOlgaR.add_new_mark(stMaksK, 3, 8);
	tcOlgaR.add_new_mark(stMaksK, 3, 2);
	tcOlgaR.add_new_mark(stMaksK, 4, 9);

	tcVladN.add_student(stMaksK);
	tcVladN.add_new_mark(stMaksK, 1, 10);
	tcVladN.add_new_mark(stMaksK, 1, 9);
	tcVladN.add_new_mark(stMaksK, 2, 11);
	tcVladN.add_new_mark(stMaksK, 3, 3);
	tcVladN.add_new_mark(stMaksK, 3, 10);
	tcVladN.add_new_mark(stMaksK, 4, 9);

	tcVladT.add_student(stMaksK);
	tcVladT.add_new_mark(stMaksK, 1, 10);
	tcVladT.add_new_mark(stMaksK, 1, 9);
	tcVladT.add_new_mark(stMaksK, 2, 4);
	tcVladT.add_new_mark(stMaksK, 3, 8);
	tcVladT.add_new_mark(stMaksK, 3, 10);
	tcVladT.add_new_mark(stMaksK, 4, 9);
	// 7/10
	tcOlgaR.add_student(stIliaZ);
	tcOlgaR.add_new_mark(stIliaZ, 1, 2);
	tcOlgaR.add_new_mark(stIliaZ, 1, 9);
	tcOlgaR.add_new_mark(stIliaZ, 2, 11);
	tcOlgaR.add_new_mark(stIliaZ, 3, 8);
	tcOlgaR.add_new_mark(stIliaZ, 3, 11);
	tcOlgaR.add_new_mark(stIliaZ, 4, 9);

	tcVladN.add_student(stIliaZ);
	tcVladN.add_new_mark(stIliaZ, 1, 10);
	tcVladN.add_new_mark(stIliaZ, 1, 9);
	tcVladN.add_new_mark(stIliaZ, 2, 12);
	tcVladN.add_new_mark(stIliaZ, 3, 8);
	tcVladN.add_new_mark(stIliaZ, 3, 10);
	tcVladN.add_new_mark(stIliaZ, 4, 3);

	tcVladT.add_student(stIliaZ);
	tcVladT.add_new_mark(stIliaZ, 1, 10);
	tcVladT.add_new_mark(stIliaZ, 1, 9);
	tcVladT.add_new_mark(stIliaZ, 2, 11);
	tcVladT.add_new_mark(stIliaZ, 3, 8);
	tcVladT.add_new_mark(stIliaZ, 3, 10);
	tcVladT.add_new_mark(stIliaZ, 4, 9);
	// 8/10 
	tcOlgaR.add_student(stStepR);
	tcOlgaR.add_new_mark(stStepR, 1, 12);
	tcOlgaR.add_new_mark(stStepR, 1, 9);
	tcOlgaR.add_new_mark(stStepR, 2, 11);
	tcOlgaR.add_new_mark(stStepR, 3, 8);
	tcOlgaR.add_new_mark(stStepR, 3, 4);
	tcOlgaR.add_new_mark(stStepR, 4, 9);

	tcVladN.add_student(stStepR);
	tcVladN.add_new_mark(stStepR, 1, 10);
	tcVladN.add_new_mark(stStepR, 1, 9);
	tcVladN.add_new_mark(stStepR, 2, 5);
	tcVladN.add_new_mark(stStepR, 3, 8);
	tcVladN.add_new_mark(stStepR, 3, 10);
	tcVladN.add_new_mark(stStepR, 4, 12);

	tcVladT.add_student(stStepR);
	tcVladT.add_new_mark(stStepR, 1, 12);
	tcVladT.add_new_mark(stStepR, 1, 9);
	tcVladT.add_new_mark(stStepR, 2, 11);
	tcVladT.add_new_mark(stStepR, 3, 8);
	tcVladT.add_new_mark(stStepR, 3, 4);
	tcVladT.add_new_mark(stStepR, 4, 9);
	// 9/10
	tcOlgaR.add_student(stAnasF);
	tcOlgaR.add_new_mark(stAnasF, 1, 10);
	tcOlgaR.add_new_mark(stAnasF, 1, 9);
	tcOlgaR.add_new_mark(stAnasF, 2, 11);
	tcOlgaR.add_new_mark(stAnasF, 3, 12);
	tcOlgaR.add_new_mark(stAnasF, 3, 10);
	tcOlgaR.add_new_mark(stAnasF, 4, 9);

	tcVladN.add_student(stAnasF);
	tcVladN.add_new_mark(stAnasF, 1, 10);
	tcVladN.add_new_mark(stAnasF, 1, 9);
	tcVladN.add_new_mark(stAnasF, 2, 11);
	tcVladN.add_new_mark(stAnasF, 3, 8);
	tcVladN.add_new_mark(stAnasF, 3, 4);
	tcVladN.add_new_mark(stAnasF, 4, 9);

	tcVladT.add_student(stAnasF);
	tcVladT.add_new_mark(stAnasF, 1, 10);
	tcVladT.add_new_mark(stAnasF, 1, 9);
	tcVladT.add_new_mark(stAnasF, 2, 11);
	tcVladT.add_new_mark(stAnasF, 3, 8);
	tcVladT.add_new_mark(stAnasF, 3, 10);
	tcVladT.add_new_mark(stAnasF, 4, 9);
	// 10/10 
	tcOlgaR.add_student(stSofS);
	tcOlgaR.add_new_mark(stSofS, 1, 10);
	tcOlgaR.add_new_mark(stSofS, 1, 9);
	tcOlgaR.add_new_mark(stSofS, 2, 11);
	tcOlgaR.add_new_mark(stSofS, 3, 8);
	tcOlgaR.add_new_mark(stSofS, 3, 10);
	tcOlgaR.add_new_mark(stSofS, 4, 9);

	tcVladN.add_student(stSofS);
	tcVladN.add_new_mark(stSofS, 1, 10);
	tcVladN.add_new_mark(stSofS, 1, 9);
	tcVladN.add_new_mark(stSofS, 2, 11);
	tcVladN.add_new_mark(stSofS, 3, 8);
	tcVladN.add_new_mark(stSofS, 3, 10);
	tcVladN.add_new_mark(stSofS, 4, 9);

	tcVladT.add_student(stSofS);
	tcVladT.add_new_mark(stSofS, 1, 10);
	tcVladT.add_new_mark(stSofS, 1, 9);
	tcVladT.add_new_mark(stSofS, 2, 11);
	tcVladT.add_new_mark(stSofS, 3, 8);
	tcVladT.add_new_mark(stSofS, 3, 10);
	tcVladT.add_new_mark(stSofS, 4, 9);
	// 1/10 11-B
	tcOlgaR.add_student(stTimS);
	tcOlgaR.add_new_mark(stTimS, 1, 10);
	tcOlgaR.add_new_mark(stTimS, 1, 9);
	tcOlgaR.add_new_mark(stTimS, 2, 4);
	tcOlgaR.add_new_mark(stTimS, 3, 8);
	tcOlgaR.add_new_mark(stTimS, 3, 10);
	tcOlgaR.add_new_mark(stTimS, 4, 9);

	tcVladN.add_student(stTimS);
	tcVladN.add_new_mark(stTimS, 1, 10);
	tcVladN.add_new_mark(stTimS, 1, 9);
	tcVladN.add_new_mark(stTimS, 2, 11);
	tcVladN.add_new_mark(stTimS, 3, 8);
	tcVladN.add_new_mark(stTimS, 3, 3);
	tcVladN.add_new_mark(stTimS, 4, 9);

	tcVladT.add_student(stTimS);
	tcVladT.add_new_mark(stTimS, 1, 10);
	tcVladT.add_new_mark(stTimS, 1, 9);
	tcVladT.add_new_mark(stTimS, 2, 11);
	tcVladT.add_new_mark(stTimS, 3, 8);
	tcVladT.add_new_mark(stTimS, 3, 2);
	tcVladT.add_new_mark(stTimS, 4, 9);
	// 2/10
	tcOlgaR.add_student(stIvanS);
	tcOlgaR.add_new_mark(stIvanS, 1, 12);
	tcOlgaR.add_new_mark(stIvanS, 1, 12);
	tcOlgaR.add_new_mark(stIvanS, 2, 11);
	tcOlgaR.add_new_mark(stIvanS, 3, 8);
	tcOlgaR.add_new_mark(stIvanS, 3, 10);
	tcOlgaR.add_new_mark(stIvanS, 4, 9);

	tcVladN.add_student(stIvanS);
	tcVladN.add_new_mark(stIvanS, 1, 10);
	tcVladN.add_new_mark(stIvanS, 1, 12);
	tcVladN.add_new_mark(stIvanS, 2, 11);
	tcVladN.add_new_mark(stIvanS, 3, 8);
	tcVladN.add_new_mark(stIvanS, 3, 10);
	tcVladN.add_new_mark(stIvanS, 4, 9);

	tcVladT.add_student(stIvanS);
	tcVladT.add_new_mark(stIvanS, 1, 10);
	tcVladT.add_new_mark(stIvanS, 1, 9);
	tcVladT.add_new_mark(stIvanS, 2, 11);
	tcVladT.add_new_mark(stIvanS, 3, 8);
	tcVladT.add_new_mark(stIvanS, 3, 10);
	tcVladT.add_new_mark(stIvanS, 4, 9);
	// 3/10
	tcOlgaR.add_student(stVladK);
	tcOlgaR.add_new_mark(stVladK, 1, 10);
	tcOlgaR.add_new_mark(stVladK, 1, 12);
	tcOlgaR.add_new_mark(stVladK, 2, 11);
	tcOlgaR.add_new_mark(stVladK, 3, 8);
	tcOlgaR.add_new_mark(stVladK, 3, 10);
	tcOlgaR.add_new_mark(stVladK, 4, 9);

	tcVladN.add_student(stVladK);
	tcVladN.add_new_mark(stVladK, 1, 10);
	tcVladN.add_new_mark(stVladK, 1, 9);
	tcVladN.add_new_mark(stVladK, 2, 4);
	tcVladN.add_new_mark(stVladK, 3, 8);
	tcVladN.add_new_mark(stVladK, 3, 10);
	tcVladN.add_new_mark(stVladK, 4, 9);

	tcVladT.add_student(stVladK);
	tcVladT.add_new_mark(stVladK, 1, 10);
	tcVladT.add_new_mark(stVladK, 1, 9);
	tcVladT.add_new_mark(stVladK, 2, 3);
	tcVladT.add_new_mark(stVladK, 3, 8);
	tcVladT.add_new_mark(stVladK, 3, 10);
	tcVladT.add_new_mark(stVladK, 4, 9);
	// 4/10
	tcOlgaR.add_student(stVladM);
	tcOlgaR.add_new_mark(stVladM, 1, 10);
	tcOlgaR.add_new_mark(stVladM, 1, 9);
	tcOlgaR.add_new_mark(stVladM, 2, 11);
	tcOlgaR.add_new_mark(stVladM, 3, 8);
	tcOlgaR.add_new_mark(stVladM, 3, 2);
	tcOlgaR.add_new_mark(stVladM, 4, 9);

	tcVladN.add_student(stVladM);
	tcVladN.add_new_mark(stVladM, 1, 10);
	tcVladN.add_new_mark(stVladM, 1, 9);
	tcVladN.add_new_mark(stVladM, 2, 11);
	tcVladN.add_new_mark(stVladM, 3, 8);
	tcVladN.add_new_mark(stVladM, 3, 11);
	tcVladN.add_new_mark(stVladM, 4, 9);

	tcVladT.add_student(stVladM);
	tcVladT.add_new_mark(stVladM, 1, 10);
	tcVladT.add_new_mark(stVladM, 1, 9);
	tcVladT.add_new_mark(stVladM, 2, 11);
	tcVladT.add_new_mark(stVladM, 3, 8);
	tcVladT.add_new_mark(stVladM, 3, 10);
	tcVladT.add_new_mark(stVladM, 4, 9);
	// 5/10
	tcOlgaR.add_student(stAndrF);
	tcOlgaR.add_new_mark(stAndrF, 1, 10);
	tcOlgaR.add_new_mark(stAndrF, 1, 9);
	tcOlgaR.add_new_mark(stAndrF, 2, 11);
	tcOlgaR.add_new_mark(stAndrF, 3, 8);
	tcOlgaR.add_new_mark(stAndrF, 3, 12);
	tcOlgaR.add_new_mark(stAndrF, 4, 9);

	tcVladN.add_student(stAndrF);
	tcVladN.add_new_mark(stAndrF, 1, 10);
	tcVladN.add_new_mark(stAndrF, 1, 9);
	tcVladN.add_new_mark(stAndrF, 2, 11);
	tcVladN.add_new_mark(stAndrF, 3, 8);
	tcVladN.add_new_mark(stAndrF, 3, 10);
	tcVladN.add_new_mark(stAndrF, 4, 9);

	tcVladT.add_student(stAndrF);
	tcVladT.add_new_mark(stAndrF, 1, 10);
	tcVladT.add_new_mark(stAndrF, 1, 9);
	tcVladT.add_new_mark(stAndrF, 2, 11);
	tcVladT.add_new_mark(stAndrF, 3, 8);
	tcVladT.add_new_mark(stAndrF, 3, 12);
	tcVladT.add_new_mark(stAndrF, 4, 9);
	// 6/10 
	tcOlgaR.add_student(stAndrO);
	tcOlgaR.add_new_mark(stAndrO, 1, 11);
	tcOlgaR.add_new_mark(stAndrO, 1, 9);
	tcOlgaR.add_new_mark(stAndrO, 2, 11);
	tcOlgaR.add_new_mark(stAndrO, 3, 11);
	tcOlgaR.add_new_mark(stAndrO, 3, 11);
	tcOlgaR.add_new_mark(stAndrO, 4, 9);

	tcVladN.add_student(stAndrO);
	tcVladN.add_new_mark(stAndrO, 1, 10);
	tcVladN.add_new_mark(stAndrO, 1, 9);
	tcVladN.add_new_mark(stAndrO, 2, 11);
	tcVladN.add_new_mark(stAndrO, 3, 8);
	tcVladN.add_new_mark(stAndrO, 3, 10);
	tcVladN.add_new_mark(stAndrO, 4, 9);

	tcVladT.add_student(stAndrO);
	tcVladT.add_new_mark(stAndrO, 1, 10);
	tcVladT.add_new_mark(stAndrO, 1, 9);
	tcVladT.add_new_mark(stAndrO, 2, 11);
	tcVladT.add_new_mark(stAndrO, 3, 8);
	tcVladT.add_new_mark(stAndrO, 3, 10);
	tcVladT.add_new_mark(stAndrO, 4, 9);
	// 7/10
	tcOlgaR.add_student(stNikV);
	tcOlgaR.add_new_mark(stNikV, 1, 10);
	tcOlgaR.add_new_mark(stNikV, 1, 9);
	tcOlgaR.add_new_mark(stNikV, 2, 11);
	tcOlgaR.add_new_mark(stNikV, 3, 8);
	tcOlgaR.add_new_mark(stNikV, 3, 10);
	tcOlgaR.add_new_mark(stNikV, 4, 9);

	tcVladN.add_student(stNikV);
	tcVladN.add_new_mark(stNikV, 1, 10);
	tcVladN.add_new_mark(stNikV, 1, 9);
	tcVladN.add_new_mark(stNikV, 2, 11);
	tcVladN.add_new_mark(stNikV, 3, 8);
	tcVladN.add_new_mark(stNikV, 3, 10);
	tcVladN.add_new_mark(stNikV, 4, 9);

	tcVladT.add_student(stNikV);
	tcVladT.add_new_mark(stNikV, 1, 10);
	tcVladT.add_new_mark(stNikV, 1, 9);
	tcVladT.add_new_mark(stNikV, 2, 11);
	tcVladT.add_new_mark(stNikV, 3, 8);
	tcVladT.add_new_mark(stNikV, 3, 10);
	tcVladT.add_new_mark(stNikV, 4, 9);
	// 8/10 
	tcOlgaR.add_student(stAlexE);
	tcOlgaR.add_new_mark(stAlexE, 1, 10);
	tcOlgaR.add_new_mark(stAlexE, 1, 9);
	tcOlgaR.add_new_mark(stAlexE, 2, 11);
	tcOlgaR.add_new_mark(stAlexE, 3, 12);
	tcOlgaR.add_new_mark(stAlexE, 3, 10);
	tcOlgaR.add_new_mark(stAlexE, 4, 12);

	tcVladN.add_student(stAlexE);
	tcVladN.add_new_mark(stAlexE, 1, 10);
	tcVladN.add_new_mark(stAlexE, 1, 9);
	tcVladN.add_new_mark(stAlexE, 2, 11);
	tcVladN.add_new_mark(stAlexE, 3, 4);
	tcVladN.add_new_mark(stAlexE, 3, 10);
	tcVladN.add_new_mark(stAlexE, 4, 9);

	tcVladT.add_student(stAlexE);
	tcVladT.add_new_mark(stAlexE, 1, 10);
	tcVladT.add_new_mark(stAlexE, 1, 9);
	tcVladT.add_new_mark(stAlexE, 2, 11);
	tcVladT.add_new_mark(stAlexE, 3, 8);
	tcVladT.add_new_mark(stAlexE, 3, 7);
	tcVladT.add_new_mark(stAlexE, 4, 9);
	// 9/10
	tcOlgaR.add_student(stDarB);
	tcOlgaR.add_new_mark(stDarB, 1, 10);
	tcOlgaR.add_new_mark(stDarB, 1, 9);
	tcOlgaR.add_new_mark(stDarB, 2, 2);
	tcOlgaR.add_new_mark(stDarB, 3, 8);
	tcOlgaR.add_new_mark(stDarB, 3, 10);
	tcOlgaR.add_new_mark(stDarB, 4, 9);

	tcVladN.add_student(stDarB);
	tcVladN.add_new_mark(stDarB, 1, 10);
	tcVladN.add_new_mark(stDarB, 1, 9);
	tcVladN.add_new_mark(stDarB, 2, 3);
	tcVladN.add_new_mark(stDarB, 3, 8);
	tcVladN.add_new_mark(stDarB, 3, 10);
	tcVladN.add_new_mark(stDarB, 4, 9);

	tcVladT.add_student(stDarB);
	tcVladT.add_new_mark(stDarB, 1, 10);
	tcVladT.add_new_mark(stDarB, 1, 9);
	tcVladT.add_new_mark(stDarB, 2, 4);
	tcVladT.add_new_mark(stDarB, 3, 8);
	tcVladT.add_new_mark(stDarB, 3, 10);
	tcVladT.add_new_mark(stDarB, 4, 9);
	// 10/10 
	tcOlgaR.add_student(stSvetO);
	tcOlgaR.add_new_mark(stSvetO, 1, 10);
	tcOlgaR.add_new_mark(stSvetO, 1, 9);
	tcOlgaR.add_new_mark(stSvetO, 2, 2);
	tcOlgaR.add_new_mark(stSvetO, 3, 8);
	tcOlgaR.add_new_mark(stSvetO, 3, 10);
	tcOlgaR.add_new_mark(stSvetO, 4, 9);

	tcVladN.add_student(stSvetO);
	tcVladN.add_new_mark(stSvetO, 1, 10);
	tcVladN.add_new_mark(stSvetO, 1, 11);
	tcVladN.add_new_mark(stSvetO, 2, 11);
	tcVladN.add_new_mark(stSvetO, 3, 8);
	tcVladN.add_new_mark(stSvetO, 3, 11);
	tcVladN.add_new_mark(stSvetO, 4, 11);

	tcVladT.add_student(stSvetO);
	tcVladT.add_new_mark(stSvetO, 1, 10);
	tcVladT.add_new_mark(stSvetO, 1, 9);
	tcVladT.add_new_mark(stSvetO, 2, 11);
	tcVladT.add_new_mark(stSvetO, 3, 12);
	tcVladT.add_new_mark(stSvetO, 3, 10);
	tcVladT.add_new_mark(stSvetO, 4, 9);

	// For menu / Menu
	// Add students and teachers to a suitable vectors for manipulations in menu
	vector<Student> forInterfaceStudent =
	{ stVasB, stPetrM, stDmiS, stVladS, stNikG, stMaksK, stIliaZ, stStepR, stAnasF, stSofS,
	stTimS, stIvanS, stVladK, stVladM, stAndrF, stAndrO, stNikV, stAlexE, stDarB, stSvetO };
	vector<Teacher> forInterfaceTeacher = { tcOlgaR, tcVladN, tcVladT };
	Interface(forInterfaceStudent, forInterfaceTeacher);

	return 0;
}