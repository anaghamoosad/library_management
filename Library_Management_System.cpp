
#include<iostream>
#include <cstdlib>
#include <string>
#include<fstream> 
#include "Books.h"
#include "User.h"
#include "Student.h"
 

// Function to check user credentials
int check_Credentials(std::string u_name,std::string p_word,int login_option)
{
    std::ifstream fin;
    if (login_option == 1)
    {
        fin.open("login_details.txt");
    }

    if (login_option == 2)
    {
        fin.open("User.txt");
    }
        

    while (!fin.eof())
    {
        std::string f_username, f_password;
        fin >> f_username >> f_password;

 
        if (u_name == f_username)
        {            
                if (p_word == f_password)
                {
                    std::cout << "Login Successful!" <<std::endl;                   

                    return 1;
                }

            std::cout << "Wrong Password!" << std::endl;
            return 0;
            
        }

        std::cout << "Wrong Username!" << std::endl;
        return 0;

    }


}



//Function to login user
int login_user(int login_option)
{
 
    std::string username, password; 

    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;

    //check  username and password
    return check_Credentials(username, password, login_option);
   
 
}


/*//Function to register new user
int register_user()
{
    std::string new_username, new_password ;
    std::ofstream fout("login_details.txt");    //open or read login data file

    //Get data from user 
    std::cout << "Enter your username: ";
    std::cin >> new_username;
    std::cout << "Enter your password: ";
    std::cin >> new_password;

    fout << new_username << "\t" << new_password;    // writing data into file 
    fout.close();

    return 0;
} */





//Function to Book user
void Books_Menu()
{
    Books book;
    int book_option;
    std::cout << "************************ Welcome for Library Management System ****************\n";
    std::cout << "                           Books Menu\n";
    std::cout << "1. Add a new Book" << std::endl;;
    std::cout << "2. Delete a Book" << std::endl;
    std::cout << "3. Display a Book" << std::endl;
    std::cout << "4. Find a Book" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Please select an option to continue: ";
    std::cin >> book_option;

    switch (book_option)
    {
    case 1:
        book.add_Book();    
        break;
    case 2:
        book.delete_Book();
        break;
    case 3:
        book.display_Book();
        break;
    case 4:
        book.find_Book();
        break;
    case 5:
        exit(0);
    default:
        std::cout << "Sorry! you entered invalid option. Please try again." << std::endl;
        exit(0);
        system("cls");

    }

}



void user_Menu()
{
    User user;
    int user_option;
    std::cout << "************************ Welcome for Library Management System ****************\n";
    std::cout << "                           User Menu\n";
    std::cout << "1. Add a new User" << std::endl;;
    std::cout << "2. Delete a User" << std::endl;
    std::cout << "3. Display all User" << std::endl;
    std::cout << "4. Find a User" << std::endl;
    std::cout << "5. Forgot Password for Username" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Please select an option to continue: ";
    std::cin >> user_option;

    switch (user_option)
    {
    case 1:
        user.add_User();
        break;
    case 2:
        user.delete_User();
        break;
    case 3:
        user.display_User();
        break;
    case 4:
        user.find_User();
        break;
    case 5:
        user.forgot();
        break;
    case 6:
        exit(0);
    default:
        std::cout << "Sorry! you entered invalid option. Please try again." << std::endl;
        exit(0);
        system("cls");

    }

}


void student_Menu()
{
    Student student;
    int student_user;
    std::cout << "************************ Welcome for Library Management System ****************\n";
    std::cout << "                           Student Menu\n";
    std::cout << "1. Add a new Student" << std::endl;;
    std::cout << "2. Delete a Student" << std::endl;
    std::cout << "3. Display all Student" << std::endl;
    std::cout << "4. Find a Student" << std::endl;
    std::cout << "5. Lend a Book" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Please select an option to continue: ";
    std::cin >> student_user;

    switch (student_user)
    {
    case 1:
        student.add_Student();      
        break;
    case 2:
        student.delete_Student();
        break;
    case 3:
        student.display_All_Students();
        break;
    case 4:
        student.find_Student();
        break;
    case 5:
        student.lend_Book();
        break;
    case 6:
        exit(0);
    default:
        std::cout << "Sorry! you entered invalid option. Please try again." << std::endl;
        exit(0);
        system("cls");

    }

}




//Function to Book user
void librarian_Menu()
{
    int librarian_menu;
    Books book;
    Student student;
    std::cout << "************************ Welcome for Library Management System ****************\n";
    std::cout << "                           Admin Menu\n";
    std::cout << "1. Find a Student" << std::endl;
    std::cout << "2. Display all Student" << std::endl;
    std::cout << "3. Lend a Book" << std::endl;
    std::cout << "4. Display a Book" << std::endl;
    std::cout << "5. Find a Book" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Please select an option to continue: ";
    std::cin >> librarian_menu;

    switch (librarian_menu)
    {
    case 1:

        student.find_Student();
        break;
    case 2:
        student.display_All_Students();
        break;
    case 3:
        student.lend_Book();
        break;
    case 4:
        book.display_Book();
        break;
    case 5:
        book.find_Book();
        break;
    case 6:
        exit(0);
    default:
        std::cout << "Sorry! you entered invalid option. Please try again." << std::endl;
        exit(0);
        system("cls");

    }

    char choice;
    std::cout << "Do you want to continue? (Y/N): ";
    std::cin >> choice;
    if (tolower(choice) == 'y')
    {
        system("cls");
        librarian_Menu();
    }
    else
    {
        exit(0);
    }


}



//Function to Book user
void admin_Menu()
{
    int admin_option;
    std::cout << "************************ Welcome for Library Management System ****************\n";
    std::cout << "                           Admin Menu\n";
    std::cout << "1. User Menu" << std::endl;;
    std::cout << "2. Student Menu" << std::endl;
    std::cout << "3. Book Menu" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Please select an option to continue: ";
    std::cin >> admin_option;

    switch (admin_option)
    {
    case 1:
        user_Menu();
        break;
    case 2:
        student_Menu();
        break;
    case 3:
        Books_Menu();
        break;
    case 4:
        exit(0);
    default:
        std::cout << "Sorry! you entered invalid option. Please try again." << std::endl;
        exit(0);
        system("cls");

    }

    char choice;
    std::cout << "Do you want to continue? (Y/N): ";
    std::cin >> choice;

    if (tolower(choice) == 'y')
    {
        system("cls");
        admin_Menu();
    }
    else
    {
        exit(0);
    }

}


int main()
{
    int login_option;
    std::cout << "************************ Welcome for Library Management System ****************\n";
    std::cout << "                           Login Page\n";
    std::cout << "Login As" << std::endl;;
    std::cout << "1. Admin" << std::endl;
    std::cout << "2. Librarian" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Please select an option to continue: ";
    std::cin >> login_option;

    switch (login_option)
    {

    case 1: 

        if (login_user(login_option))
        {
            system("cls");
            admin_Menu();
        }
        else
        {
            std::cout << "Please try again! Press any button to continue..."<< std::endl;
            char option;
            std::cin >> option;
            system("cls");
            main();
        }
               

        break;
    

    case 2: 
        
        if (login_user(login_option))
        {
            librarian_Menu();
        }
        else
        {
            std::cout << "Please try again! Press any button to continue..." << std::endl;
            char option;
            std::cin >> option;
            system("cls");
            main();
        }

       
        break;

    case 3:
        exit(0);

    default:       
    
        std::cout << "Sorry! you entered invalid option. Please try again." << std::endl;
        exit(0);
        system("cls");

    }
}