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

////////////////////////////////////////////// Medhat ///////////////////////////////////
string XOR(string a, string b)
{
	int a_size = a.length();
	int b_size = b.length();
	string zeros = "0000000000000";

	if (a_size < b_size)
		a = zeros.substr(0, b_size - a_size) + a;
	if (a_size > b_size)
		b = zeros.substr(0, a_size - b_size) + b;
	string c = a;
	for (int i = 0; i < a_size; i++)
	{
		if (a[i] == '0' && b[i] == '0')
			c[i] = '0';
		else if (a[i] == '1' && b[i] == '1')
			c[i] = '0';
		else
			c[i] = '1';
	}

	return c;
}

//function takes the message and polynomial to return the remainder 
string CRC_Division(string message, string polynomial)
{
	string zeros = "0000000000";
	string CRC = "";
	int P_length = polynomial.length();
	string messagePoly_str = message + zeros.substr(0, P_length - 1);
	int MK_length = messagePoly_str.length();
	string XOR_Out = polynomial;

	if (messagePoly_str[0] == '1')
		XOR_Out = XOR(messagePoly_str.substr(0, P_length), polynomial);
	else
		XOR_Out = messagePoly_str.substr(0, P_length);

	for (int i = P_length; i < MK_length; i++)
	{
		XOR_Out = XOR_Out.substr(1, XOR_Out.length() - 1) + messagePoly_str[i];
		if (XOR_Out[0] == '1')
			XOR_Out = XOR(XOR_Out, polynomial);
	}
	XOR_Out = XOR_Out.substr(1, XOR_Out.length() - 1);
	return XOR_Out;
}
//////////////////////////////////////////////////////////////////////////////////////////////
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
