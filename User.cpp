//header files

#include<iostream>
#include <cstdlib>
#include <string>
#include<fstream>
#include <vector>
#include <sstream>
#include "User.h"


User::User()
{

}


//Adding new Student to file
void User::add_User()
{
	User user;
	//std::string new_username, new_password, usertype;
    std::ofstream fout("User.txt",std::ios_base::app);    //open or read login data file

    //Get data from user 
    std::cout << "Enter username: ";
    std::cin >> user.username;
    std::cout << "Enter password: ";
    std::cin >> user.password;
	std::cout << "Enter usertype: ";
	std::cin >> user.usertype;
	std::cout << "Enter emailid: ";
	std::cin >> user.emailid;

    fout << user.username << "\t" << user.password << "\t" << user.usertype << "\t" << user.emailid << std::endl;    // writing data into file 
    fout.close();

}

void User::delete_User()
{
	std::string username;
	std::string line;
	std::ifstream fin("User.txt");    //open or read Student data file
	std::ofstream temp("temp.txt");

	std::cout << "Enter username to delete: ";
	std::cin >> username;


	while (getline(fin, line))
	{
		if (!(line.find(username) != std::string::npos))
		{
			temp << line << std::endl;
		}

	}
	// closing output file
	fin.close();

	// closing input file
	temp.close();

	// remove the original file
	remove("User.txt");

	rename("temp.txt", "User.txt");

}


void User::find_User() {

	std::ifstream fin("User.txt");    //open or read Student data file

	std::string line;
	std::string user_data;
	std::cout << "Enter username to find: ";
	std::cin >> user_data;

	while (getline(fin, line))
	{
		if ((line.find(user_data) != std::string::npos))
		{
			std::cout << line << std::endl;
			break;
		}

	}
	// closing output file
	fin.close();


}

void User::display_User()
{
	std::ifstream fin("User.txt");    //open or read Student data file

	std::string line;

	User user;

	std::cout << " Username\t"  << "Usertype\t" << "Email Id\t" << std::endl;

	while (std::getline(fin, line)) {
		std::istringstream issLine(line);
		issLine >> user.username >> user.password >> user.usertype >> user.emailid;
		std::cout << user.username << "\t" << user.usertype << "\t" << user.emailid << std::endl;


	}
}


// Function to check user credentials
int User::find_Password(std::string u_name)
{
	std::ifstream fin("User.txt", std::ios_base::app);

	while (!fin.eof())
	{
		std::string f_username, f_password;
		fin >> f_username >> f_password;


		if (u_name == f_username)
		{
			std::cout << "Your password is : " << f_password << std::endl;
			return 0;
		}

		std::cout << "Username not found! Please register. ";
		return 0;

	}


}
 
int User::forgot()
{
	std::string username, new_password;

	//Get data from user 
	std::cout << "Enter your username: ";
	std::cin >> username;

	return find_Password(username);

}
