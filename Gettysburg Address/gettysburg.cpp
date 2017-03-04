//Complete the following file:

//gettysburg.cpp


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

const string INPUT_FILE_NAME = "GettysburgAddress.txt";

int main()
{
    string line;
    int line_count = 0,i;
    int character_count = 0;
    int word_count = 0;
    int lower_count = 0;
    int upper_count = 0;
    int space_count = 0;
    int punctuation_count = 0;
    string word;
    char ch;

    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    cout << "Statistics for file " << INPUT_FILE_NAME << ":" << endl;
    cout << endl;

        while (getline(input,line))
        { 
          for(i=0;i<line.length();i++) {
          character_count++;
          if (isupper(line[i])) {
              upper_count++;
          } else if (islower(line[i])){
              lower_count++;
          } else if (isspace(line[i])){
              space_count++;
              if (line[i-1]!=',' && line[i-1]!= '.')
              word_count++;
        
          } else if (line[i]==',' || line[i]== '.' || line[i]== '-'){
              punctuation_count++;
              if(line[i-1] != '-')
              word_count++;
          }
      } 
line_count++;
if (line[i-1]!=',' && line[i-1]!= '.' && i!=0)
              word_count++;

}
 
    
    cout << "Lines: " << line_count << endl;
    cout << "Characters: " << character_count << endl;
    cout << "Words: " << word_count << endl;
    cout << "Lower-case letters: " << lower_count << endl;
    cout << "Upper-case letters: " << upper_count << endl;
    cout << "Spaces: " << space_count << endl;
    cout << "Punctuation marks: " << punctuation_count << endl;
}

 
Submit
