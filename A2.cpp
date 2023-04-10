#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <Windows.h>
#include <string>

using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);


//function declaration
string upper(string);
void Main_Menu(string);
void CinemaManagement(int);
void AdministratorMenu(int);
//structure declaration
struct mapping_seats
{
	int hall;
	int data;
	int row[50];
	int column[50];
}unavailable[50];
//Main Menu
int main()
{
	bool decision = true;
	int selection;
	do
	{
		system("cls");
		Main_Menu("MAIN");
		cout << "\t\t\tPlease input your selection >>> ";
		cin >> selection;
		switch (selection)
		{
		case(1)://Movie details
		{
			break;
		}
		case(2)://f&d
		{
			break;
		}
		case(3)://purchase now
		{
			break;
		}
		case(4)://membership details
		{
			break;
		}
		case(5)://administrator menu
		{
			AdministratorMenu(5);
			break;
		}
		case(6)://exit
		{
			decision = false;
			break;
		}
		default://reinput
		{
			cout << "\t\t\tInvalid input found" << endl;

			break;
		}
		}
	} while (decision);


	system("pause");
	return 0;
}
//change string to uppercase
string upper(string uppercase)
{
	for (int i = 0; i < uppercase.size(); i++)
		uppercase[i] = toupper(uppercase[i]);
	return uppercase;
}
//Administrator Menu (havent implement employee function)
void AdministratorMenu(int option)
{
	//login menu
	system("cls");
	string admin_id, password;
	bool decision = true, access = true;
	int selection;
	do
	{
		cout << "\n\n\n\t\t\tPlease input your ADMIN ID >>>";
		cin >> admin_id;
		cout << "\t\t\tPlease input your password >>>";
		cin >> password;
		access = false;
	} while (access);

	system("cls");
	do {
		cout << "<1> Movie management" << endl;
		cout << "<1> Food & Beverages management" << endl;
		cout << "<1> Membership Management" << endl;
		cout << "<1> Employee management" << endl;

		cout << "\t\t\tPlease input your selection >>> ";
		cin >> selection;
		switch (selection)
		{
		case(1)://Movie management
		{
			CinemaManagement(selection);
			break;
		}
		case(2)://F&B management
		{
			break;
		}
		case(3)://Membership management
		{
			break;
		}
		case(4)://edit hall spaces
		{
			break;
		}
		case(5)://exit
		{
			decision = false;
			break;
		}
		default://reinput
		{
			cout << "\t\t\tInvalid input found" << endl;
			break;
		}
		}
	} while (decision);
}
//Cinema Management
void CinemaManagement(int option)
{
	system("cls");
	int selection;
	bool decision = true;
	do
	{
		cout << "<1> Add movies " << endl;
		cout << "<2> Modify movies " << endl;
		cout << "<3> Delete movies " << endl;
		cout << "<4> Cinema Hall modification " << endl;
		cout << "<5> Exit " << endl;
		cout << "\t\t\tPlease input your selection >>> ";
		cin >> selection;
		switch (selection)
		{
		case(1)://Add movie
		{

			break;
		}
		case(2)://Modify Movie
		{
			break;
		}
		case(3)://Delete Movie
		{
			break;
		}
		case(4)://Cinema Hall Modification
		{
			break;
		}
		case(5)://exit
		{
			decision = false;
			break;
		}
		default://reinput
		{
			cout << "\t\t\tInvalid input found" << endl;
			break;
		}
		}
	} while (decision);
}



void Main_Menu(string Name)
{
	int i = 142, j = 48;
	//system("Color 30");
	cout << "\n\n\n\t\t\t" << string(121, char(61)) << "\n";
	cout << "\t\t\t=" << right << setw(121) << "=\n";
	cout << "\t\t\t=" << string(4, ' ') << string(20, char(126)) << string(20, ' ') << string(25, char(126)) << string(25, ' ') << string(19, char(126)) << string(5, ' ') << " = \n";
	cout << "\t\t\t=" << string(4, ' ') << "[";
	//SetConsoleTextAttribute(console, i);
	cout << " 1. Movie Details ";
	//SetConsoleTextAttribute(console, j);
	cout << "]" << string(20, ' ') << "[";
	//SetConsoleTextAttribute(console, i);
	cout << " 2. Food and Beverages ";
	//(console, j);
	cout << "]" << string(25, ' ') << "[";
	//SetConsoleTextAttribute(console, i);
	cout << " 3. Purchase Now ";
	//SetConsoleTextAttribute(console, j);
	cout << "]" << string(5, ' ') << " = \n";
	cout << "\t\t\t=" << string(4, ' ') << string(20, char(126)) << string(20, ' ') << string(25, char(126)) << string(25, ' ') << string(19, char(126)) << string(5, ' ') << " = \n";
	cout << "\t\t\t=" << right << setw(121) << "=\n";
	cout << "\t\t\t=" << string(24, ' ') << string(22, char(95)) << string(23, ' ') << string(25, char(95)) << string(24, ' ') << " = \n";
	cout << "\t\t\t=" << string(24, ' ') << "[";
	//SetConsoleTextAttribute(console, i);
	cout << " 4. Membership Page ";
	//SetConsoleTextAttribute(console, j);
	cout << "]" << string(23, ' ') << "[";
	//SetConsoleTextAttribute(console, i);
	cout << " 5. Administrator Page ";
	//SetConsoleTextAttribute(console, j);
	cout << "]" << string(24, ' ') << " = \n";
	cout << "\t\t\t=" << string(24, ' ') << string(20, char(126)) << string(25, ' ') << string(25, char(126)) << string(24, ' ') << " = \n";
	cout << "\t\t\t=" << right << setw(121) << "=\n";
	cout << "\t\t\t=" << string(50, ' ') << string(14, char(126)) << string(54, ' ') << " = \n";
	cout << "\t\t\t=" << string(50, ' ') << "[";
	//SetConsoleTextAttribute(console, i);
	cout << " 5.   EXIT  ";
	//SetConsoleTextAttribute(console, j);
	cout << "]" << string(54, ' ') << " = \n";
	cout << "\t\t\t=" << string(50, ' ') << string(14, char(126)) << string(54, ' ') << " = \n";
	cout << "\t\t\t" << string(121, char(61)) << "\n";

}
