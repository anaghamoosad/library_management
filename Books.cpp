//header files

#include<iostream>
#include <cstdlib>
#include <string>
#include<fstream>
#include <vector>
#include <sstream>
#include "Books.h"
 

Books::Books()
{
	//load_Data();
}

std::vector<Books> Books::load_Data()
{
	std::ifstream fin("books.txt");    //open or read books data file

	std::vector<Books> library_books;

	std::string line;

	Books book;
	while (std::getline(fin, line)) {
		std::istringstream issLine(line);
		issLine >> book.bookno >> book.book_tile >> book.author_name >> book.category;
		std::cout << book.bookno << book.book_tile << book.author_name << book.category << std::endl;

		library_books.push_back(book);

	}
	return library_books;
}
 

//Adding new books to file
void Books::add_Book()
{
	Books book;
	std::vector<std::string> available_categories{ "Mathematics", "Computer Science", "Chemistry", "Language", "Physics" };
	std::ofstream fout("books.txt", std::ios_base::app);    //open or read books data file

	std::cout << "Enter book number: ";
	std::cin >> book.bookno;

	std::cout << "Enter book title: ";
	std::cin >> book.book_tile;

	std::cout << "Enter book author: ";
	std::cin >> book.author_name;

	std::cout << "Enter book category from the list: ";

	for (int i = 0; i < available_categories.size(); i++)
		std::cout << i+1<<". " << available_categories[i] << std::endl;

	std::cin >> book.category;

	fout << book.bookno << "\t" << book.book_tile << "\t" << book.author_name << "\t" << book.category << std::endl;    // writing data into file 

	std::cout << "Book added sucessfully!";

}
 
//Display all the books 
void Books::display_Book()
{
	std::ifstream fin("books.txt");    //open or read books data file

	std::vector<Books> library_books;

	std::string line;

	Books book;

	std::cout << "Book No\t" << "Title\t" <<"Author\t" << "Category\t" << std::endl;

	while (std::getline(fin, line)) {
		std::istringstream issLine(line);
		issLine >> book.bookno >> book.book_tile >> book.author_name >> book.category;
		std::cout << book.bookno << "\t" << book.book_tile << "\t" << book.author_name << "\t" << book.category << std::endl;

		library_books.push_back(book);

	}
}

void Books::delete_Book()
{
	std::ifstream fin("books.txt");    //open or read books data file
	std::ofstream temp("temp.txt");

	std::vector<Books> library_books;

	std::string line;
	std::string bookno;
	std::cout << "Enter the Book no to delete: ";
	std::cin >> bookno;

	while (getline(fin, line))
	{
		if (!(line.find(bookno) != std::string::npos))
		{
			temp << line << std::endl;
		}

		//line.replace(line.find(bookno), line.length(), "");
	

	}
	// closing output file
	fin.close();

	// closing input file
	temp.close();

	// remove the original file
	remove("books.txt");

	rename("temp.txt", "books.txt");

	
}
void Books::find_Book() {

	std::ifstream fin("books.txt");    //open or read books data file
	std::string line;
	std::string book_data;
	std::cout << "Enter the Book no to find: ";
	std::cin >> book_data;

	while (getline(fin, line))
	{
		if ((line.find(book_data) != std::string::npos))
		{
			std::cout << line << std::endl;
			break;
		}

	}
	// closing output file
	fin.close();


}


		


 