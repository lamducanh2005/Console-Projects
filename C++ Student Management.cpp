// Student Management System

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>
using namespace std;

class Student {
public:
	string id;
	string name;
	string course;
	string birthday;

	Student(string id, string name, string course, string birthday) {
		this->id = id;
		this->name = name;
		this->course = course;
		this->birthday = birthday;
	}
};

class StudentManagement {
public:
	vector<Student> studentList;

	StudentManagement() {
		fstream file("student.txt");
		string id, name, course, birthday, empty;

		do {
			getline(file, id);
			getline(file, name);
			getline(file, course);
			getline(file, birthday);

		} while (getline(file, empty));

		Student s(id, name, course, birthday);
		studentList.push_back(s);
		file.close();
	}

	void menu() {
		int choice;
		do {
			cout << "STUDENT MANAGEMENT SYSTEM" << endl;
			cout << "\t1. Add student" << endl;
			cout << "\t2. Edit student" << endl;
			cout << "\t3. Delete student" << endl;
			cout << "\t4. Show student" << endl;
			cout << "\t0. Save and exit" << endl;
			cout << "Your choice: ";
			cin >> choice;
			cin.ignore();

			if (choice == 1)
				addStudent();
			else if (choice == 2)
				editStudent();
			else if (choice == 3)
				deleteStudent();
			else if (choice == 4)
				showStudent();
			else if (choice == 0)
				exitProgram();
			break;
		} while (true);
	}


	void addStudent() {
		string id, name, course, birthday;
		cout << "Enter student id: "; getline(cin, id);
		cout << "Enter student name: "; getline(cin, name);
		cout << "Enter student course: "; getline(cin, course);
		cout << "Enter student birthday: "; getline(cin, birthday);

		Student s(id, name, course, birthday);
		studentList.push_back(s);

		fstream file("student.txt", ios::app);
		file << id << endl << name << endl << course << endl << birthday << endl;
		file.close();

		int choice;
		cout << "Add student successfully!" << endl;
	}


	void editStudent() {
		string id;
		cout << "Enter student id: "; getline(cin, id);

	}


	void deleteStudent() {
		string id;
		cout << "Enter student id: "; getline(cin, id);
		for (auto s : studentList) {
			if (s.id == id) {
				studentList.erase(studentList.begin());
				break;
			}
		}
	}


	void showStudent() {
		string id;
		cout << "Enter student id: "; getline(cin, id);
		for (auto s : studentList) {
			if (s.id == id) {
				cout << "Student id: " << s.id << endl;
				cout << "Student name: " << s.name << endl;
				cout << "Student course: " << s.course << endl;
				cout << "Student birthday: " << s.birthday << endl;
				break;
			}
		}

	}


	void exitProgram() {
		
	}
};

int main() {
	StudentManagement sm;
	sm.menu();
	return 0;
}