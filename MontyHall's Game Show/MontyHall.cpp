#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>

using namespace std;
typedef int Door;

const int SIMULATION_COUNT = 100;

void simulate(int sequence, int& win1, int& win2);
Door hideCar();
Door openDoor(Door firstChoiceDoor, Door carBehindDoor);
Door makeFirstChoice();
Door makeSecondChoice(Door firstDoor, Door openedDoor);
Door randomDoor();


int main()
{
    int win1 = 0, win2 = 0; // Win1 is if the first choice is right and Win2 is if changing your choice in the second round is true

    srand(time(NULL));  // seed the random number generator
    
    // Run the simulations.
    for (int i = 1; i <= SIMULATION_COUNT; i++)
    simulate(i, win1, win2);

    cout << endl;
    cout << setw(4) << win1 << " wins if stay with the first choice" << endl;
    cout << setw(4) << win2 << " wins if switch to the second choice" << endl;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    cout << endl;
    cout << "Win ratio of switch over stay: ";
    cout << static_cast<double>(win2)/win1 << endl;
    return 0;
}


Door randomDoor()
{
    int a= rand() %3 + 1;
    return a;    
}

Door hideCar()
{
    int a=randomDoor();
    return a;
}
Door makeFirstChoice()
{
    int b=randomDoor();
    return b;
}
Door openDoor(Door firstChoiceDoor, Door carBehindDoor)
{
   int c;
   do
   c=randomDoor();
   while(c==firstChoiceDoor || c==carBehindDoor);
   return c;
}

Door makeSecondChoice(Door firstDoor, Door openedDoor)
{
    int d;
    do
    d=randomDoor();    
    while( d==openedDoor);
    
    return d;
}

void simulate(int sequence, int& win1, int& win2)
{
    int a= hideCar();
    cout<<"Car Is Behind Door Number "<<a<<endl;
    int b= makeFirstChoice();
    cout<<"Your First Choice is Door Number "<<b<<endl;
    int c= openDoor(b,a);
     cout<<"Monty Opens Door Number "<<c<<endl;
    int d= makeSecondChoice( b, c);
     cout<<"Your Second Choice is Door Number "<<d<<endl;
    if (a==d && a==b)
    {
        ++win1;
        cout<<"First Choice Win"<<endl;
    }
    else if( d==a && b!=d)
    {
        ++win2;
        cout<<"Second Choice Wins"<<endl;
    }
    else 
    cout<<"Sorry You lost"<<endl;
    cout<<endl;
    cout<<endl;
}

