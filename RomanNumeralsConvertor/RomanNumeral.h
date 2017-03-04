#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_
#include<string>
using namespace std;

class RomanNumeral
{
public:
	//constructor and destructors
	RomanNumeral(); 
	RomanNumeral(string Roman); // for cases like RomanNumeral r2("MCMXLIX")
	RomanNumeral(int value); // for cases like RomanNumeral r1(53)
	~RomanNumeral();

	//accessor functions declaration to access private variables/fucntions
	void todecimal();
	void toroman();
	string getroman();
	int getdecimal();
	
	//overloaded function declaration
		friend RomanNumeral operator+( const RomanNumeral& lhs, const RomanNumeral& rhs);
		friend RomanNumeral operator-( const RomanNumeral& lhs, const RomanNumeral& rhs);
		friend RomanNumeral operator*(const RomanNumeral& lhs, const RomanNumeral& rhs);
		friend RomanNumeral operator/( const RomanNumeral& lhs, const RomanNumeral& rhs);
		friend  bool operator==(const RomanNumeral lhs, const RomanNumeral rhs);
		friend  bool operator!=(const RomanNumeral lhs, const RomanNumeral rhs);
		friend ostream& operator <<(ostream& outs, RomanNumeral& rhs);
		friend istream& operator >>(istream& ins,  RomanNumeral& rhs);
		
		
	/***** Complete this class. *****/

private:
	string Roman;      // Roman numeral as a string
	int    decimal;    // decimal value of the Roman numeral

	void toRoman();    // calculate string from decimal value
	void toDecimal();  // calculate decimal value from string
};

#endif /* ROMANNUMERAL_H_ */