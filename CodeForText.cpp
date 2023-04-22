
//declare text 2-D array as global array

string text[20][7];


//declare void function for text

void ReadTextRecord(int);






//define void function
void ReadTextRecord(int record)
{
	ifstream infile;
	infile.open("title.txt");
	if (infile.fail())
		cout << "unable to open the file" << endl;
	else
	{
		while (!infile.eof())
		{
			for (int i = 0; i < 19; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					getline(infile, text[i][j]);
				}
			}
		}
	}
}
