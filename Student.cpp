//header files

#include<iostream>
#include <cstdlib>
#include <string>
#include<fstream>
#include <vector>
#include <sstream>
#include "Student.h"


Student::Student()
{
	 
}


//Adding new Student to file
void Student::add_Student()
{
	Student student;
	student.no_of_books = 0;
 
	std::ofstream fout("Student.txt", std::ios_base::app);    //open or read Student data file

	std::cout << "Enter Student number: ";
	std::cin >> student.studentno;

	std::cout << "Enter First Name: ";
	std::cin >> student.first_name;

	std::cout << "Enter Last Name: ";
	std::cin >> student.last_name;
 

	fout << student.studentno << "\t" << student.first_name << "\t" << student.last_name << "\t" <<  student.no_of_books << std::endl;    // writing data into file 

	std::cout << "Student added sucessfully!";

}

//Display all the Student 
void Student::display_All_Students()
{
	std::ifstream fin("Student.txt");    //open or read Student data file

	std::vector<Student> library_Student;

	std::string line;

	Student student;

	std::cout << " Student number\t" << "First Name\t" << "Last Name\t" << "No of Books Taken\t" << std::endl;

	while (std::getline(fin, line)) {
		std::istringstream issLine(line);
		issLine >> student.studentno >> student.first_name >> student.last_name >> student.no_of_books;
		std::cout << student.studentno << "\t" << student.first_name << "\t" << student.last_name << "\t" << student.no_of_books << std::endl;

		library_Student.push_back(student);

	}
}

void Student::delete_Student(std::string studentno)
{
	std::ifstream fin("Student.txt");    //open or read Student data file
	std::ofstream temp("temp.txt");

	std::vector<Student> library_Student;

	std::string line;
	//int studentno;
	if (studentno == "0")
	{
		std::cout << "Enter the Student no to delete: ";
		std::cin >> studentno;
	}
	
	while (getline(fin, line))
	{
		if (!(line.find(studentno) != std::string::npos))
		{
			temp << line << std::endl;
		}
		
	}
	// closing output file
	fin.close();

	// closing input file
	temp.close();

	// remove the original file
	int ret = std::rename("Student.txt", "Student1.txt");
	std::remove("Student1.txt");

	ret=std::rename("temp.txt", "Student.txt");

}
void Student::find_Student() {

	std::ifstream fin("Student.txt");    //open or read Student data file

	std::string line;
	std::string student_data;
	std::cout << "Enter the Book no to find: ";
	std::cin >> student_data;

	while (getline(fin, line))
	{
		if ((line.find(student_data) != std::string::npos))
		{
			std::cout << line << std::endl;
			break;
		}

	}
	// closing output file
	fin.close();


}

void Student::lend_Book() {

	std::ifstream fin("Student.txt");    //open or read Student data file
	std::string line;
	std::string student_data;
	Student student;
	std::cout << "Enter the Student no: ";
	std::cin >> student_data;

	while (getline(fin, line))
	{
		if ((line.find(student_data) != std::string::npos))
		{
			std::cout << line << std::endl;
			std::istringstream issLine(line);
			issLine >> student.studentno >> student.first_name >> student.last_name >> student.no_of_books;
			break;
		}
		std::cout << "Sorry student not found!" << std::endl;
	}
	fin.close();

	
	if (student.no_of_books < 3)
	{
		delete_Student(student.studentno);
		student.no_of_books++;
		std::ofstream fout("Student.txt", std::ios_base::app);
		fout << student.studentno << "\t" << student.first_name << "\t" << student.last_name << "\t" << student.no_of_books << std::endl;    // writing data into file 
		fout.close();
	}
	else
	{
		std::cout << "Sorry! You have taken the maximum amount of books!";
	}


	



}





