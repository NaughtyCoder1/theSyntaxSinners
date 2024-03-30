#include<iostream>
#include<chrono>
#include<thread>
#include<cmath>
#include<random>
using namespace std;


int getRandomNumber(int minRange, int maxRange) {
    return minRange + rand() % (maxRange - minRange + 1); // generates a random number within a certain range
}



struct Gate
{
    int person = 0;
    int processing_time;//processing time per person
    int total_time; //total time to process all the person in a gate
};

void randomAssign(Gate gate[] , int people , int size) //people = M/2 of the size
{
    int counter = 0; // tracks the number of people assigned to the gate
    int i = 0; // used in loop
    for(i = 0 ; i<size ; i++)
    {
      cout<<"Enter the initial number of people at Gate-"<<i+1<<": ";
      cin>>gate[i].person;
      counter+=gate[i].person;
      if(counter == people)
      {
          cout<<"Random Assignment of half people done successfully."<<endl;
          for(int j = i+1 ; j<size ; j++)
          {
              gate[j].person = 0;
          }
          break;
      }
      else if(counter > people) // if extra allocation is done in a gate than M/2
      {
          int extra = counter - people;
          gate[i].person -= extra;
          cout<<"There are only "<<gate[i].person<<" people left for random assignment which are assinged to Gate "<<i+1;
          for(int j = i+1 ; j<size ; j++)
          {
              gate[j].person = 0;
          }
          cout<<"Random Assignment of half people done successfully."<<endl;
          break;
      }
      else
      {
        continue;
      }
    }
    if(counter < people) // if assignment is less than M/2
    {
        int remaining = people - counter;
        gate[size - 1].person += remaining;
        cout<<"There are "<<remaining<<" people still left, they are assigned to the gate "<<size<<endl;
        cout<<"Random Assignment of half people done successfully."<<endl;
    }
    return;
}

void updateTotalTime(Gate gate[] , int person , int i) // updates total time
{
    gate[i].total_time = gate[i].processing_time*person;
}

void decrement(Gate gate[] , int size) // decrements the number of people in the Queue
{
    for(int i = 0 ; i<size ; i++)
{


    if(gate[i].processing_time<5)
      {
        if(gate[i].processing_time==1)
        {
            gate[i].person = max(0,gate[i].person-=5); // if 1 minute is take for 1 person than in  5 minutes 5 person will be processed
        }
        else
        {int temp = gate[i].processing_time%5; // from random function number will be between 1 and 5 so same logic
        gate[i].person = max(0,gate[i].person-=temp);}

      }
      else
        {
             gate[i].person = max(0,gate[i].person-= 1); // if 5 minute is taken to process , then 1 will be processed in 5 minutes
        }

}

}

void allocateTime(Gate gate[] , int size)
{
    for(int i = 0 ; i<size ; i++)
    {
        int p = getRandomNumber(1,5);
        cout<<p<<" ";
        gate[i].processing_time = p; // gate processing time gets alloacted randomly between 1 and 5 minutes , including both
        gate[i].total_time = gate[i].processing_time * gate[i].person;
    }

}



int main()
{
    int M; // number of people
    int N; // number of gates;
    cout<<"Enter the number of the gates: ";
    cin>>N;

    Gate gate[N];
    cout<<"Enter the total number of people: ";
    cin>>M;


    allocateTime(gate , N);

    if(M%2 == 0)
    {
       randomAssign(gate , M/2 , N);
    }
    else
    {
        randomAssign(gate , (M+1)/2 , N);
    }
    while(true)
    {
        decrement(gate , N);
        cout<<"Update Queue: ";
        for(int i = 0 ; i<N ; i++)
        {
            cout<<"Person Left: "<<gate[i].person<<" ";
            updateTotalTime(gate , gate[i].person , i);
            cout<<"Updated time is: "<<gate[i].total_time<<endl;
        }
        cout<<endl;
        this_thread::sleep_for(chrono::seconds(1)); // function calling not activated 5 minutes

    }
    return 0;
}

