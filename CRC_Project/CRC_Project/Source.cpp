#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
using namespace std ;

void Read_from_file(string& Message ,string& Divisor)
{
	ifstream ip ("input.txt");
	ip>> Message;
	ip>> Divisor ;
}
string alter (string message , int bit_no)
{
	if(bit_no <=message.length())
	{
		if(message[bit_no - 1] == '0')
			message[bit_no - 1] = '1';
		else 
			message[bit_no - 1] = '0';
	}
	return message;
}

void main()
{
	string Message ,Divisor ;

	// testing reading from file and alter functions
	int n;
	Read_from_file(Message ,Divisor);
	cout << Message <<endl << Divisor <<endl ;
	cout << "enter bit no to be changed \n";
	cin >> n;
	cout << alter(Message ,n) <<endl;

	
	system("pause");
}