#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

const char chr[] = "0123456789!@#$%^&*()_+-=;:.,?<>`~/|\abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ--==__++";
int length = sizeof(chr)-1;
int n, choosed;
bool done = false;

void RandomPass()
{
	cout << "Password Length : ";
	cin >> n;
	srand(time(0));
	ofstream myfile;
	ifstream checkfile;
	if(checkfile)
	myfile.open("password.txt");
	for(int i = 0; i < n; i++)
	myfile << chr[rand() % length];
	myfile << "\n";
	myfile.close();
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
		else if(CrackTime < 2592000)cout << "Cracking time = " << CrackTime/3600 << " Days (175.000.000 MIPS)" << 
		endl;
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
	}
	return 0;
}
