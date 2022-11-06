
/*


*/


#include<iostream>
#include <cstdlib>
#include <string>
#include<fstream> 
#include "Books.h"
 

// Function to check user credentials
int check_Credentials(std::string u_name,std::string p_word)
{
    std::ifstream fin("login_details.txt");

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

        std::cout << "Wrong Username!";
        return 0;

    }


}

// Function to check user credentials
int find_Password(std::string u_name)
{
    std::ifstream fin("login_details.txt");

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


//Function to login user
int login_user()
{
 
    std::string username, password; 

    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;

    //check  username and password
    return check_Credentials(username, password);
   
 
}


//Function to register new user
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
}

//Function to register new user
int forgot()
{
    std::string username, new_password; 

    //Get data from user 
    std::cout << "Enter your username: ";
    std::cin >> username;

    return find_Password(username);

}



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

int main()
{
    int login_option;
    std::cout << "************************ Welcome for Library Management System ****************\n";
    std::cout << "                           Login Page\n";
    std::cout << "1. Login" << std::endl;;
    std::cout << "2. Register New User" << std::endl;
    std::cout << "3. Forgot Password" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Please select an option to continue: ";
    std::cin >> login_option;

    switch (login_option)
    {
    case 1:
        char choice;
    
        if (login_user())
        {
            Books_Menu();
            std::cout << "Do you want to continue? (Y/N): ";
            std::cin >> choice;
            if (tolower(choice) == 'y')
            {
                system("cls");
                Books_Menu();
            }
            else
            {
                exit(0);
            }
          
        }

     
        std::cin >> choice;
        std::cout << "Login Unsucessful! Do you want to try again! (Y/N): ";
        std::cin >> choice;

        if (tolower(choice) == 'y')
        {
            system("cls");
            main();

        }
        else
        {
            exit(0);
        }

        
       
               

    case 2:
        register_user();
        std::cout << "Registration Successful! Please Login." << std::endl;
        login_user();
        break;

    case 3:
        forgot(); 
        break;

    case 4:
        exit(0);

    default:
        std::cout << "Sorry! you entered invalid login_option. Please try again." << std::endl;
        system("cls");
        main();

    }
     
} 