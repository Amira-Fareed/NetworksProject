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
string alter (string message)
{
	if(message.length()>0)
	{
		if(message[0] == '0')
			message[0] = '1';
		else 
			message[0] = '0';
	}
	return message;
}

void main()
{
	string Message ,Divisor ;

	// testing reading from file and alter functions
	/*
	Read_from_file(Message ,Divisor);
	cout << Message <<endl << Divisor <<endl ;
	cout << alter(Message) <<endl;

	*/
	system("pause");
}