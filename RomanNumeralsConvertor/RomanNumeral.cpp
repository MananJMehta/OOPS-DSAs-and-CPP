#include<iostream>
#include <string>
#include <fstream>
#include "RomanNumeral.h"
using namespace std;
/**
* Default constructor.
*/
//Contructor Definitions
RomanNumeral::RomanNumeral() : Roman(""), decimal(0)
{
}

RomanNumeral::RomanNumeral(string roman)
{
	Roman = roman;
	toDecimal();
}
RomanNumeral::RomanNumeral(int value)
{
	decimal = value;
	toRoman();
}


//Accessor functions definition
void RomanNumeral::todecimal() 
{
	toDecimal(); 
}
void RomanNumeral::toroman() 
{
	toRoman();
}
string RomanNumeral::getroman()
{
	return this->Roman;
}
int RomanNumeral::getdecimal()
{
	return this->decimal;
}


//operator "+" overloading definition
RomanNumeral operator+( const RomanNumeral& lhs, const RomanNumeral& rhs)
{
	RomanNumeral value;
	value.decimal = lhs.decimal + rhs.decimal;
	value.toRoman();
	return value;
	
}
//operator "-" overloading definition
RomanNumeral operator-(const RomanNumeral& lhs, const RomanNumeral& rhs)
{
	RomanNumeral value;
	value.decimal = lhs.decimal - rhs.decimal;
	value.toRoman();
	return value;
	
}
//operator "*" overloading definition
RomanNumeral operator*(const RomanNumeral& lhs,const RomanNumeral& rhs)
{
	RomanNumeral value;
	value.decimal = lhs.decimal * rhs.decimal;
	value.toRoman();
	return value;
}
//operator "/" overloading definition
RomanNumeral operator/(const RomanNumeral& lhs,const RomanNumeral& rhs)
{
	RomanNumeral value;
	value.decimal = lhs.decimal / rhs.decimal;
	value.toRoman();
	return value;
}


//operator "==" overloading definition
bool operator==(const RomanNumeral lhs, const RomanNumeral rhs)
{
	bool x=0;
	if (lhs.decimal == rhs.decimal)
		x = 1;
	return x;
}
//operator "!=" overloading definition
bool operator!=(const RomanNumeral lhs, const RomanNumeral rhs)
{
	bool x;
	if (lhs.decimal != rhs.decimal)
		x = 1;
	return x;
}


//operator "<<" overloading definition
ostream& operator <<(ostream& outs, RomanNumeral& rhs)
{
	outs << "["<<rhs.decimal << ":" << rhs.Roman << "]" <<" " ;
	return outs;
}
//operator ">>" overloading definition
istream& operator >>(istream& ins, RomanNumeral& rhs)
{
	
	ins >> rhs.Roman;
	rhs.toDecimal();
	return ins;
}



//To Convert from Decimal to Roman
void RomanNumeral::toRoman()
{
	int a = this->decimal;
	string str;
	int thousand = a / 1000;
	a = a % 1000;
	int hundred = a / 100;
	a = a % 100;
	int ten = a / 10;
	a = a % 10;
	int unit = a;

	if (thousand != 0)
	{
		for (int i = 0; i<thousand; i++)
			str.append("M");
	}
	if (hundred != 0)
	{
		if (hundred >= 4)
		{
			if (hundred == 9)
				str.append("CM");
			else if (hundred == 4)
				str.append("CD");
			else if (hundred>4)
			{
				int x = hundred % 5;
				str.append("D");
				for (int i = 0; i<x; i++)
					str.append("C");
			}
		}
		else
        {
			for (int i = 0; i<hundred; i++)
				str.append("C");
		}
	}
	if (ten != 0)
	{
		if (ten >= 4)
		{
			if (ten == 9)
				str.append("XC");
			else if (ten == 4)
				str.append("XL");
			else if (ten>4)
			{
				int x = ten % 5;
				str.append("L");
				for (int i = 0; i<x; i++)
					str.append("X");
			}
		}
		else
        {
			for (int i = 0; i<ten; i++)
				str.append("X");
		}
	}
	if (unit != 0)
	{
		if (unit >= 4)
		{
			if (unit == 9)
				str.append("IX");
			else if (unit == 4)
				str.append("IV");
			else if (unit>4)
			{
				int x = unit % 5;
				str.append("V");
				for (int i = 0; i<x; i++)
					str.append("I");
			}
		}
		else
        {
			for (int i = 0; i<unit; i++)
				str.append("I");
		}
	}
	this->Roman = str;
}
//To Convert from Roman to Decimal
void RomanNumeral::toDecimal()
{
	int result = 0;
	string number = this->Roman;
	const int length = number.length();
	
	
	for (int i = 0; i < length; ++i)
	{
		if (number[i] == 'I' && i != length - 1)
		{
			if (number[i + 1] == 'X') 
			{ 
				result += 9;
				++i;
			} 
			else if (number[i + 1] == 'V')
			{
                result += 4;
                ++i;
			} 
			else
            {
				result += 1;
			}
		}
		else if (number[i] == 'X' && i != length - 1)
		{
			if (number[i + 1] == 'C') 
			{ 
				result += 90;
				++i; 
			} 
			else if (number[i + 1] == 'L') 
			{ 
				result += 40;
                ++i;
			} 
			else 
			{ 
				result += 10;
			}
		}
		else if (number[i] == 'C' && i != length - 1)
		{
			if (number[i + 1] == 'M') 
			{ 
				result += 900;
				++i;
			} 
			else if (number[i + 1] == 'D') 
			{ 
				result += 400;
				++i;
			} 
			else 
			{
				result += 100;
			}
		}
		else if (number[i] == 'I')
		{ 
			result += 1; 
		}	
		else if (number[i] == 'X')
		{ 
			result += 10;
		}		
		else if (number[i] == 'C')
		{ 
			result += 100;
		}	
		else if (number[i] == 'M')
		{ 
			result += 1000;
		}
		else if (number[i] == 'D')
		{
			result += 500;
		}
		else if (number[i] == 'L')
		{
			result += 50;
		}
		else if (number[i] == 'V')
		{
			result += 5;
		}
	}
	this->decimal = result;
}
 
 
 //Destructor Definition
RomanNumeral::~RomanNumeral()
{
	// Empty body
} 
