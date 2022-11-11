#pragma once

//header files

#include<iostream>
#include <cstdlib>
#include <string>
#include<fstream>

class User
{
private:
	std::string username;
	std::string password;
	std::string usertype;
	std::string emailid;

public:
	User();	//Constructor 

	void add_User();	//Add new Student
	void delete_User();		//Delete a Student
	void display_User();	//Display Student List
	void find_User();		//Find a Student
	int forgot();
	int find_Password(std::string u_name);


};

