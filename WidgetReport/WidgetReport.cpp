#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

class WidgetReport //Class and Function Declaration, Function Definitions below
{
public:
	
	WidgetReport(ifstream& in);  
								 
	void printline(int a,int countdept,int countplant,int countstate);
	void readfile(ifstream& in);
	int getstate1();
	int getstate2();
	int getplant1();
	int getplant2();
	int getdept1();
	int getdept2();

private:
	ifstream& input;  // reference to the input stream
	int state1;
	int state2;
	int plant1;
	int plant2;
	int dept1;
	int dept2;
	int count1;
	int count2;
	int empid1;
	int empid2;
	string fname;
	string sname;
};

const string INPUT_FILE_NAME = "widgets.txt";

int main()
{
	string line;
	ifstream input;
	input.open(INPUT_FILE_NAME);
	if (input.fail())
	{
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
	}

	WidgetReport hello(input);
	hello.readfile(input);

	input.close();
	return 0;
}

void WidgetReport::readfile(ifstream& in)
{
	string s;

	int x = 0, y = 0;
	int countDT = 0;
	int countPT = 0;
	int countST = 0;
	int countT = 0;
	while (getline(input, s))
	{
		stringstream ss;
		

		if (x == 1)
		{

			ss << s;
			ss >> state2;
			ss >> plant2;
			ss >> dept2;
			ss >> empid2;
			ss >> fname;
			ss >> sname;
			ss >> count2;
			
			
			//control logic
			if (state2 == state1)
			{
				countST += count2;
				if (plant2 == plant1)
				{
					countPT += count2;
					if (dept2 == dept1)
					{
						countDT += count2;
						printline(1, 0, 0, 0);
					}
					else
					{
						
						printline(2, countDT, 0, 0);
						countDT = count2;
						printline(1, 0, 0, 0);
					}
				}
				else
				{
					
					printline(2, countDT, countPT, 0);
					countDT = count2;
					countPT = count2;
					printline(1, 0, 0, 0);
				}
			}
			else
			{
				
				printline(2,countDT,countPT,countST);
				countT = countST;
				countDT = count2;
				countPT = count2;
				countST = count2;
				printline(1,0,0,0);
			}
		
		
		state1 = state2;
		plant1 = plant2;
		dept1 = dept2;

	}
		else if (y == 1)
		{
			ss << s;
			ss >> state1;
			ss >> plant1;
			ss >> dept1;
			ss >> empid1;
			ss >> fname;
			ss >> sname;
			ss >> count1;
			cout <<setw(6)<< state1 <<  setw(6) << plant1 <<  setw(6) << dept1 <<  setw(6) << empid1 <<  setw(6) << count1 << "  "<<fname << " " << sname << endl;
			
			x = 1;
			countDT += count1;
			countPT += count1;
			countST += count1;
			
		}
		if (y == 0)
		{
			string Tstate, Tplant,Tdept, Tempid, Tname, Tcount; //title names;
			ss << s;
			ss >> Tstate;
			ss >> Tplant;
			ss >> Tdept;
			ss >> Tempid;
			ss >> Tname;
			ss >> Tcount;
			
			cout <<setw(6) <<Tstate<<setw(6)<<Tplant << setw(6) <<Tdept << setw(6)<<Tempid <<setw(6)<<Tcount <<setw(6)<<Tname << endl<<endl;
			y = 1;
		}
	}
	countT += countST;

	printline(2, countDT, countPT, countST);
	cout.width(30);
	cout << right << countT<<setw(13) << "  GRAND TOTAL " <<setw(6)<<" " << " ****" << endl << endl;
}

WidgetReport::WidgetReport(ifstream& in) :input(in)
{
	// line for line "translation"
	state1 = state2 = plant1 = plant2 = dept1 = dept2 = 0;

	}
void WidgetReport :: printline(int a, int countdept, int countplant, int countstate)
{
	if(a==1)
	cout << setw(6)<<state2 <<  setw(6) << plant2 <<  setw(6) << dept2 <<  setw(6) << empid2  << setw(6) << count2 << "  " << fname << " " << sname << endl;
	if (a == 2)
	{
		cout << endl;
		cout.width(30);
		cout << right << countdept <<setw(13)<< "  TOTAL FOR DEPT " << right <<setw(3)<<dept1 << " *" << endl;
		if (countplant != 0)
		{
			cout.width(30);
			cout << right << countplant << setw(13) << "  TOTAL FOR Plant " << right <<setw(2)<<plant1 << " **" << endl;
			if (countstate != 0)
			{
				cout.width(30);
				cout << right << countstate << setw(13) << "  TOTAL FOR STATE " << right<<setw(2) << state1 << " ***" << endl ;
			}
		}
		cout << endl;
	}
	
}
int WidgetReport::getstate1()
{
	return state1;
}
int WidgetReport::getstate2()
{
	return state2;
}

int WidgetReport::getplant1()
{
	return plant1;
}

int WidgetReport::getplant2()
{
	return plant2;
}

int WidgetReport::getdept1()
{
	return dept1;
}
int WidgetReport::getdept2()
{
	return dept2;
}
