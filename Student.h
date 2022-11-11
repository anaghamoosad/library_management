
#ifndef HEADER_H
#define HEADER_H

//header files

#include<iostream>
#include <cstdlib>
#include <string>
#include<fstream>
#include <vector>

class Student
{
private:
	std::string studentno;
	std::string first_name;
	std::string last_name;
	int no_of_books;
 

public:


	Student();	//Constructor 

	void add_Student();	//Add new Student
	void delete_Student(std::string studentno="0");		//Delete a Student
	void display_All_Students();	//Display Student List
	void find_Student();		//Find a Student
	void lend_Book();	//Lend Book to student


};

//code
#endif 