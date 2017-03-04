#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Names to search for.

const string MAKAR  = "Makar Alexeevich";
const string JOSEPH = "Joseph Bazdeev";
const string BORIS  = "Boris Drubetskoy";

const string INPUT_FILE_NAME = "WarAndPeace.txt";

int main()
{

    vector <string> names;
    names.push_back(MAKAR); //Add string to vector names
    names.push_back(JOSEPH);
    names.push_back(BORIS);
   
    
    cout<<setw(5)<<"LINE"<<setw(10)<<"POSITION"<<"  "<<setw(16)<<left<<"NAME"<<endl;
    
    int line_count=0;
    
    ifstream input;
    input.open(INPUT_FILE_NAME);
    
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    
    string line;
    int z=3;//Flag bit
    int x=0;//Flag Bit
    int i=0;//Flag Bit
    while (getline(input,line))
    { 
        if(z!=3)  //condition if name is split between lines
        {
            string temp1=names.at(z);
            int temp2=temp1.find(' ');
            string lastname= temp1.substr(temp2+1,(temp1.length()-2));
            
            int temp3=line.find(lastname);
            if(temp3!=string::npos)
            {
                if (temp3==0)
                {
                     cout<<line_count<<setw(10)<<right<<++x<<"  "<<setw(16)<<left<<names.at(z)<<endl; //Print
                     
                }
            } 
            x=0;
            z=3;
        }
        
        line_count++;
        
        for(i=0;i<3;i++) //check for each name in the line
        {
            int temp=line.find(names.at(i));
            if(temp!=string::npos)
           {
                cout<<line_count<<setw(10)<<right<<temp+1<<"  "<<setw(16)<<left<<names.at(i)<<endl;
                
                int temp1=line.find(names.at(i),temp+1);
                if(temp1!=string::npos)
                {
                    cout<<line_count<<setw(10)<<right<<temp1+1<<"  "<<setw(16)<<left<<names.at(i)<<endl;
                }
           }
            string temp1=names.at(i);
            int temp2=temp1.find(' ');
            string firstname= temp1.substr(0,temp2);
            int temp3=line.find(firstname,temp+1);
            if(temp3!=string::npos)
                {
                    z=i;
                    x=temp3;
                }
            }
        }
        
    
return 0;
}
