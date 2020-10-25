#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
//#include <ctype.h>


using namespace std;

const char chr[] = "0123456789!@#$%^&*()_+-=;:.,?<>`~/|\abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ--==__++";
const char str[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int length1 = sizeof(chr)-1;
int length2 = sizeof(str)-1;
int n, choosed;
bool done = false;

void RandomPin()
{
	cout << "Pin length : (normal = 4) ";
	cin >> n;
	
}

void RandomPass()
{
	cout << "Password Length : ";
	cin >> n;
	cout << "Choose characters" << endl;
	cout << "1. With symbols" << endl << "2. Without symbols" << endl;
	int chara;
	cin >> chara;
	cout << "Choose method" << endl;
	cout << "1. On Console" << endl;
	cout << "2. On password.txt file" << endl;
	switch(chara)
	{
		case 1:
			cin >> choosed;
			switch(choosed)
			{
			case 1:
				srand(time(0));
				for(int i = 0; i < n; i++)
				{
					cout << chr[rand() % length1];
				}
				cout << endl;
				break;
			case 2:
				srand(time(0));
				ifstream checkfile;
				ofstream myfile;
				if(checkfile)
				myfile.open("password.txt");
				for(int i = 0; i < n; i++)
				myfile << chr[rand() % length1];
				myfile << "\n";
				myfile.close();
				break;
			}
			break;
		case 2:
			cin >> choosed;
			switch(choosed)
			{
			case 1:
				srand(time(0));
				for(int i = 0; i < n; i++)
				{
					cout << str[rand() % length2];
				}
				cout << endl;
				break;
			case 2:
				srand(time(0));
				ifstream checkfile;
				ofstream myfile;
				if(checkfile)
				myfile.open("password.txt");
				for(int i = 0; i < n; i++)
				myfile << str[rand() % length2];
				myfile << "\n";
				myfile.close();
				break;
			}
			break;
	}
}

void SecurePass()
{
	string Password;
	cin >> Password;
	ifstream secure("commonpassword.txt");
	if(secure.is_open())
	{
		string line;
		while(getline(secure	, line))
		{
			if(Password == line.c_str())
			{
				cout << "INSTANTLY!!! Your password is on the top 100.000 most used password according to Wikipedia!" << endl;
				done = true;
				break;
			}
		}
	}
	if(!done)
	{
		cout << "Size = " << Password.length() << endl;
		double CrackTime = pow(76,Password.length())/175000000000000;
		if(CrackTime < 60)cout << "Cracking time = " << CrackTime << " Seconds (175.000.000 MIPS)" << endl;
		else if(CrackTime < 3600)cout << "Cracking time = " << CrackTime/60 << " Minutes (175.000.000 MIPS)" << endl;
		else if(CrackTime < 86400)cout << "Cracking time = " << CrackTime/3600 << " Hours (175.000.000 MIPS)" << endl;
		else if(CrackTime < 2592000)cout << "Cracking time = " << CrackTime/86400 << " Days (175.000.000 MIPS)" << endl;
		else if(CrackTime < 2592000*12)cout << "Cracking time = " << CrackTime/2592000 << " Months (175.000.000 MIPS)" << endl;
	}
}

int main()
{
	cout << "Welcome to Password Utilites 2.0" << endl;
	cout << "Choose action" << endl;
	cout << "1. How secure is my password (1)" << endl;
	cout << "2. Random password generator (2)" << endl;
	cin >> choosed;
	switch (choosed)
	{
		case 1:
			SecurePass();
			break;
		case 2:
			RandomPass();
			break;
		case 3:
			
			break;
	}
	return 0;
}
