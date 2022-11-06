/* 

Login page for library management systems

*/

#include<iostream>
#include <cstdlib>

int main()
{
int login_option;
std::cout<<"************************ Welcome for Library Management System ****************\n";
std::cout<<"                           Login Page\n";
std::cout<<"1. Login\n";
std::cout<<"2. Register New User\n";
std::cout<<"3. Forgot Username or Password\n";
std::cout<<"4. Exit\n";
std::cout<<"Please select an option to continue: ";
std::cin>>login_option;

switch (login_option)
{
    case 1: 
            //login_user();
            std::cout<<"case 1:\n ";      
            break;

    case 2: 
            //register_user();
            std::cout<<"case 2:\n ";
            break;

    case 3: 
            //forgot();
            std::cout<<"case 3:\n ";
            break;

    case 4:
            std::cout<<"case 4:\n ";
            exit(0);
    
    default:
            std::cout<<"Sorry! you entered invalid login_option\n. Please try again.\n";
            system("cls");
            main();


}



}

 
