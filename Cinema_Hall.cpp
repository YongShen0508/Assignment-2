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
void CinemaHall(int);
void AdministratorMenu(int);
void ReadCinemaHallRecord(int&);
void CinemaSeatPrinting(int);
void HallSeatPrinting(int, int, int);
bool AddCinemaHall(bool);
void ModifyCinemaHall(int&);
void DeleteCinemaHall(int&);
void LoadCinemaHallRecord(int&);
void AddCinemaSeat(int&);
void DeleteCinemaSeat(int&);
void ConfirmAddCinemaSeat(int, int, int);

//structure declaration


struct mapping_seats
{
	int hall; //cinema hall
	int data;	//a set of column and row = 1 data
	int row[70];	
	int column[70];
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
		case(2)://f&b
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

	do {
		system("cls");
		cout << "\n\n\t\t\t<1> Movie management" << endl;
		cout << "\t\t\t<1> Food & Beverages management" << endl;
		cout << "\t\t\t<1> Membership Management" << endl;
		cout << "\t\t\t<1> Employee management" << endl;

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
	int selection;
	bool decision = true;
	do
	{	
		system("cls");
		cout << "\t\t\t<1> Add movies " << endl;
		cout << "\t\t\t<2> Modify movies " << endl;
		cout << "\t\t\t<3> Delete movies " << endl;
		cout << "\t\t\t<4> Cinema Hall modification " << endl;
		cout << "\t\t\t<5> Exit " << endl;
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
			CinemaHall(selection);
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
//Cinema Hall Page
void CinemaHall(int option)
{
	int selection;
	bool decision = true;
	do
	{
		system("cls");
		int record = 0;
		bool result = false;
		ReadCinemaHallRecord(record);
		cout << "\n\n\n" << string(100, char(61)) << "\n\n\n";
		for (int w = 0; w < record; w++)
		{
			cout << "\n\n\t\t\t\t HALL " << unavailable[w].hall << "\n\n";
			CinemaSeatPrinting(w);
		}

		cout << string(100, char(61)) << "\n\n\n";
		cout << "\t\t\t<1> Add Cinema Hall" << endl;
		cout << "\t\t\t<2> Modify Cinema Hall space" << endl;
		cout << "\t\t\t<3> Delete Cinema Hall" << endl;
		cout << "\t\t\t<4> Exit" << endl;
		cout << "\t\t\tInput your selection >>> ";
		cin >> selection;

		switch (selection)
		{
		case(1)://Add cinema Hall
		{
			result = AddCinemaHall(result);
			if (result)
			{
				record++;
				unavailable[record - 1].hall = record;
				unavailable[record - 1].data = 0;
				unavailable[record - 1].row[0] = 0;
				unavailable[record - 1].column[0] = 0;
				LoadCinemaHallRecord(record);
			}
			break;
		}
		case(2)://Modify Cinema Seat
		{
			ModifyCinemaHall(record);
			break;
		}
		case(3)://Delete Cinema Hall
		{
			DeleteCinemaHall(record);
			break;
		}
		case(4)://exit
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
//read cinema hall seats
void ReadCinemaHallRecord(int& record)
{
	ifstream infile;
	infile.open("seatcontrol.txt");
	if (infile.fail())
	{
		cout << "unable to open the file";
	}
	else
	{
		int i = 0;
		while (!infile.eof())
		{
			infile >> unavailable[i].hall;
			infile >> unavailable[i].data;
			infile.ignore();
			if (unavailable[i].data > 0)
			{
				for (int j = 0; j < unavailable[i].data; j++)
					infile >> unavailable[i].row[j];
				for (int j = 0; j < unavailable[i].data; j++)
					infile >> unavailable[i].column[j];
			}
			else
			{
				infile >> unavailable[i].row[0];
				infile >> unavailable[i].column[0];
			}
			infile.ignore();
			i++;
			record++;
		}
	}
}
//save cinema hall record
void LoadCinemaHallRecord(int& record)
{
	ofstream outfile;
	outfile.open("seatcontrol.txt");
	for (int i = 0; i < record; i++)
	{
		outfile << unavailable[i].hall << endl;
		outfile << unavailable[i].data << endl;
		if (unavailable[i].data > 0)
		{
			for (int j = 0; j < unavailable[i].data; j++)
			{
				if (j > 0)
					outfile << " ";
				outfile << unavailable[i].row[j];
			}
			outfile << endl;
			for (int j = 0; j < unavailable[i].data; j++)
			{
				if (j > 0)
					outfile << " ";
				outfile << unavailable[i].column[j];
			}

		}
		else
		{
			outfile << unavailable[i].row[0] << endl;
			outfile << unavailable[i].column[0];
		}
		if (i != record - 1)
			outfile << endl;
	}
	outfile.close();
}
//print selected cinema seat mapping
void CinemaSeatPrinting(int w)
{

	for (int i = 0; i < 10; i++)
	{
		cout << "\t\t\t";
		cout << i;
		if (i == 0)
		{
			for (int j = 1; j < 15; j++)
			{
				if (j == 2 || j == 12)
					cout << setw(2) << j << " ";
				else
					cout << setw(2) << j;
			}
			cout << endl;
		}
		else
		{
			for (int j = 1; j < 3; j++)
			{
				HallSeatPrinting(w, i, j);
			}
			cout << " ";
			for (int j = 3; j < 13; j++)
			{
				HallSeatPrinting(w, i, j);
			}
			cout << " ";
			for (int j = 13; j < 15; j++)
			{
				HallSeatPrinting(w, i, j);
			}
			cout << endl;
		}

	}
}
//check availability of seat
void HallSeatPrinting(int w, int i, int j)
{
	int checking = 1;
	if (unavailable[w].data != 0)
	{
		for (int z = 0; z < unavailable[w].data; z++)
		{
			if (i == unavailable[w].row[z] && j == unavailable[w].column[z])
			{
				cout << setw(2) << "X";
				checking = 0;
			}
		}
	}
	if (checking)
		cout << setw(2) << "*";
}
//add cinema hall
bool AddCinemaHall(bool result) 
{
	char confirms;
	bool decision = true;
	do
	{
		cout << "Do you want to add a new cinema hall <Y>es or <N>o >>> ";
		cin >> confirms;
		confirms = toupper(confirms);
		if (confirms == 'Y' || confirms == 'N')
			decision = false;

	} while (decision);
	if (confirms == 'Y')
		return true;
	else
		return false;
}
void ModifyCinemaHall(int& record)
{
	int selection;
	bool decision = true;
	do {
		cout << "\t\t\t<1> Add Cinema Unavailable Seat" << endl;
		cout << "\t\t\t<2> Delete Cinema Unavailable Seat" << endl;
		cout << "\t\t\t<3> Exit" << endl;
		cout << "\t\t\tInput your selection >>> ";
		cin >> selection;
		switch (selection)
		{
		case(1)://	Add
		{
			AddCinemaSeat(record);
			break;
		}
		case(2)://Delete
		{
			DeleteCinemaSeat(record);
			break;
		}
		case(3)://Exit
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
void DeleteCinemaHall(int& record)
{
	int number;
	cout << "Please input the cinema hall number >>>";
	cin >> number;

	if (number > 0 && number <= record)
	{
		for (int i = 0; i < record; i++)
		{
			if (unavailable[i].hall == number)
			{
				for (int j = i; j < record; j++)
				{
					unavailable[j].hall = unavailable[j + 1].hall;
					unavailable[j].data = unavailable[j + 1].data;
					for (int z = 0; z < unavailable[j].data; z++)
					{
						unavailable[j + 1].row[z] = unavailable[j].row[z];
						unavailable[j + 1].column[z] = unavailable[j].column[z];
					}
				}
			}
		}
		cout << "R1 ";
		cout << record<<endl;
		record--;
		cout << "successfully deleted..." << endl;
		cout << record;
		LoadCinemaHallRecord(record);
	}
	else
		cout << "no cinema hall found" << endl;
}
void AddCinemaSeat(int& record)
{
	int number;
	char continued;
	cout << "\t\t\tInput the number of cinema hall >>>";
	cin >> number;
	if (number > 0 && number <= record)
	{
		bool decision = true;
		do {
			int row, column;
			CinemaSeatPrinting(number - 1);
			cout << "\t\t\tInput the row that you want to modify >>>";
			cin >> row;
			cout << "\t\t\tInput the column that you want to modify >>>";
			cin >> column;
			if (unavailable[number - 1].data > 0)
			{
				int found = 0;
				for (int i = 0; i < unavailable[number - 1].data; i++)
				{
					if (row > 10 || column > 14)
					{
						found++;
						cout << "\t\t\tplease ensure row and column within the range: 0 < row < 10 and 0 < column < 15" << endl;
						cout << "\t\t\tPlease reinput row and column" << endl;
						break;
					}
					else if (unavailable[number - 1].row[i] == row && unavailable[number - 1].column[i] == column)
					{
						found++;
						cout << "\t\t\tInput have found inside the system..." << endl;
						cout << "\t\t\tPlease reinput row and column" << endl;
						break;
					}
				}
				if (found == 0)
				{
					ConfirmAddCinemaSeat(number, row, column);
				}
				
			}
			else
				ConfirmAddCinemaSeat(number, row, column);
			LoadCinemaHallRecord(record);
			cout << "\t\t\tDo you want to continue <Y>es <N>o >>";
			cin >> continued;
			continued = toupper(continued);
			if (continued == 'N')
				decision = false;
		} while (decision);

	}
	else
		cout << "\t\t\tNo cinema hall found."<<endl;
}
void DeleteCinemaSeat(int& record)
{
	int number;
	cout << "\t\t\tPlease input the cinema hall number >>>";
	cin >> number;

	if (number > 0 && number <= record)
	{
		cout << "\n\n" << string(100, char(61)) << "\n\n";
		cout << "\t\t\tCinema hall " << number << endl;
		CinemaSeatPrinting(number - 1);
		bool decision = true;
		do {
			char continued;
			int row, column;
			cout << "\t\t\tInput the row of the seat >> ";
			cin >> row;
			cout << "\t\t\tInput the column of the seat >> ";
			cin >> column;
			int found = 0;
			for (int i = 0; i < unavailable[number - 1].data; i++)
			{
				if (row > 10 || column > 14)
				{
					cout << "\t\t\tplease ensure row and column within the range: 0 < row < 10 and 0 < column < 15" << endl;
					break;
				}
				else if (unavailable[number - 1].row[i] == row && unavailable[number - 1].column[i] == column)
				{
					found++;
					char confirms;
					cout << "\t\t\tAre you confirm delete row " << row << " and " << "column " << column << " <Y>es <N>o  >>";
					cin >> confirms;
					confirms = toupper(confirms);					
					if (confirms == 'Y')
					{
						for (int j = i; j < unavailable[number - 1].data; j++)
						{
							unavailable[number - 1].row[j] = unavailable[number - 1].row[j + 1];
							unavailable[number - 1].column[j] = unavailable[number - 1].column[j + 1];
						}
						unavailable[number - 1].data -= 1;
						LoadCinemaHallRecord(record);
					}
					else
					{
						cout << "\t\t\tConfirmation Unsuccessful" << endl;
						cout << "\t\t\tPlease reinput the row and column" << endl;
					}
					break;
				}

			}
			if (found == 0)
				cout << "\t\t\tNo data found in system" << endl;
			cout << "\t\t\tDo you want to continue <Y>es <N>o >>";
			cin >> continued;
			continued = toupper(continued);
			if (continued == 'N')
				decision = false;
		} while (decision);
	}
	else
		cout << "\t\t\tno cinema hall seat found" << endl;
}
void ConfirmAddCinemaSeat(int number, int row, int column)
{
	char confirms;
	cout << "Are you confirm add row " << row << " and " << "column " << column << " <Y>es <N>o  >>";
	cin >> confirms;
	confirms = toupper(confirms);
	if (confirms == 'Y')
	{
		cout << "confirmation successful" << endl;
		unavailable[number - 1].data += 1;
		unavailable[number - 1].row[unavailable[number - 1].data - 1] = row;
		unavailable[number - 1].column[unavailable[number - 1].data - 1] = column;
		cout << "succesfully added" << endl;
	}
	else
	{
		cout << "Confirmation Unsuccessful" << endl;
		cout << "Please reinput the row and column" << endl;
	}
}























void Main_Menu(string Name)
{
	int i=142, j=48;
	system("Color 30");
	cout << "\n\n\n\t\t\t" << string(121, char(61)) << "\n";
	cout << "\t\t\t=" << right << setw(121) << "=\n";
	cout << "\t\t\t=" << string(4, ' ') << string(20, char(126)) << string(20, ' ') << string(25, char(126)) << string(25, ' ') << string(19, char(126)) << string(5, ' ') << " = \n";
	cout << "\t\t\t=" << string(4, ' ') << "[";
	SetConsoleTextAttribute(console, i);
	cout << " 1. Movie Details ";
	SetConsoleTextAttribute(console, j);
	cout << "]" << string(20, ' ') << "[";
	SetConsoleTextAttribute(console, i);
	cout << " 2. Food and Beverages ";
	SetConsoleTextAttribute(console, j);
	cout << "]" << string(25, ' ') << "[";
	SetConsoleTextAttribute(console, i);
	cout << " 3. Purchase Now ";
	SetConsoleTextAttribute(console, j);
	cout << "]" << string(5, ' ') << " = \n";
	cout << "\t\t\t=" << string(4, ' ') << string(20, char(126)) << string(20, ' ') << string(25, char(126)) << string(25, ' ') << string(19, char(126)) << string(5, ' ') << " = \n";
	cout << "\t\t\t=" << right << setw(121) << "=\n";
	cout << "\t\t\t=" << string(24, ' ') << string(22, char(95)) << string(23, ' ') << string(25, char(95)) << string(24, ' ') << " = \n";
	cout << "\t\t\t=" << string(24, ' ') << "[";
	SetConsoleTextAttribute(console, i);
	cout << " 4. Membership Page ";
	SetConsoleTextAttribute(console, j);
	cout << "]" << string(23, ' ') << "[";
	SetConsoleTextAttribute(console, i);
	cout << " 5. Administrator Page ";
	SetConsoleTextAttribute(console, j);
	cout << "]" << string(24, ' ') << " = \n";
	cout << "\t\t\t=" << string(24, ' ') << string(20, char(126)) << string(25, ' ') << string(25, char(126)) << string(24, ' ') << " = \n";
	cout << "\t\t\t=" << right << setw(121) << "=\n";
	cout << "\t\t\t=" << string(50, ' ') << string(14, char(126)) << string(54, ' ') << " = \n";
	cout << "\t\t\t=" << string(50, ' ') << "[";
	SetConsoleTextAttribute(console, i);
	cout << " 5.   EXIT  ";
	SetConsoleTextAttribute(console, j);
	cout << "]" << string(54, ' ') << " = \n";
	cout << "\t\t\t=" << string(50, ' ') << string(14, char(126)) << string(54, ' ') << " = \n";
	cout << "\t\t\t" << string(121, char(61)) << "\n";
	
}
