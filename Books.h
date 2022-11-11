#pragma once


//header files

#include<iostream>
#include <cstdlib>
#include <string>
#include<fstream>
#include <vector>

class Books
{
private:
	std::string bookno;
	std::string book_tile;
	std::string author_name;
	std::string category;

public:


	Books();	//Constructor
	 
	std::vector<Books> load_Data();
 
	void add_Book();	//Add new Book

	void delete_Book();		//Delete a Book
	void display_Book();	//Display Book List
	void find_Book();		//Find a Book


};

