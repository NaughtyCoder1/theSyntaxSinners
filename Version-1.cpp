#include<iostream>
#include<chrono>
#include<cmath>
#include<random>
#include<thread>
using namespace std;


int getRandomNumber(int minRange, int maxRange) {
    return minRange + rand() % (maxRange - minRange + 1);
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

int sumofPeople = 0; //keeping track of the rest of M/2 people.
int temp = 0;

void timerIncrement(Gate *gate , int size , int people)
{
    if(sumofPeople == people)
    {
        cout<<"The rest of half of the people are also alloted."<<endl;
        return;
    }
    int y = getRandomNumber(5,10); // number of people
    int x = getRandomNumber(0,size-1); // gate number
    sumofPeople+=y;
    if(sumofPeople<people)
    {
        temp=sumofPeople;
        cout<<endl<<"The number of person alloted are: "<<y<<" And gate alloted is: "<<x+1<<endl;
        gate[x].person += y;
        cout<<"The total person now are: "<<gate[x].person<<endl;
        updateTotalTime(gate , gate[x].person , x);
        cout<<"Updated time after increment is: "<<gate[x].total_time;
        cout<<endl<<endl;
    }
    else
    {
        int extra = 0;
        extra = people - temp;
        sumofPeople = people;
        int x = getRandomNumber(0,size-1);
        cout<<"The number of person alloted are: "<<extra<<" And gate alloted is: "<<x+1<<endl;
        gate[x].person +=extra;
        cout<<"The total person now are: "<<gate[x].person<<endl;
        updateTotalTime(gate , gate[x].person , x);
        cout<<"Updated time after increment is: "<<gate[x].total_time;
    }
    this_thread::sleep_for(chrono::milliseconds(10));
}

void allocateTime(Gate gate[] , int size)
{
    for(int i = 0 ; i<size ; i++)
    {
        int p = getRandomNumber(1,3);
        cout<<"Time for processing per person for gate: "<<i+1<<" is"<<p<<endl;
        gate[i].processing_time = p; // gate processing time gets alloacted randomly between 1 and 5 minutes , including both
        gate[i].total_time = gate[i].processing_time * gate[i].person;
    }

}

void decrement(Gate *gate, int size) // decrements the number of people in the Queue
{
    for(int i = 0 ; i<size ; i++)
   {
        if(gate[i].processing_time==1)
        {
            gate[i].person = max(0,gate[i].person-=3); // if 1 minute is take for 1 person than in  3 minutes 3 person will be processed
        }
      else
        {
             gate[i].person = max(0,gate[i].person-= 1); // if 2 or 3 minute is taken to process , then 1 will be processed in 3 minutes
        }

   }

}

void timerDecrement(Gate *gate , int size)
{
        decrement(gate , size);
        cout<<endl;
        for(int i = 0 ; i<size ; i++)
        {
            cout<<"Person Left on gate"<<i+1<<" : "<<gate[i].person<<" ";
            updateTotalTime(gate , gate[i].person , i);
            cout<<"  Updated time is: "<<gate[i].total_time<<endl;
        }
        cout<<endl;
        this_thread::sleep_for(chrono::milliseconds(10)); // function calling not activated 5 minutes
}


int allZero(Gate gate[] , int size)
{
    int sum = 0;
    for(int i = 0 ; i<size ; i++)
    {
        if(gate[i].person!= 0)
        {
            return 0;
        }
    }
    return 1;
}

int getMaxIndex(Gate gate[] , int size) //returns the index of the gate having the most processing time
{
    int index = 0;
    int maxTime = gate[0].total_time;
    for(int i = 0 ; i<size ; i++)
    {
        if(gate[i].total_time > maxTime)
        {
            maxTime = gate[i].total_time;
            index = i;
        }
    }
    return index;
}

int getMinIndex(Gate gate[], int size)
{
    int index = 0;
    int minTime = gate[0].total_time;
    for(int i = 0 ; i<size ; i++)
    {
        if(gate[i].total_time < minTime)
        {
            minTime = gate[i].total_time;
            index = i;
        }
    }
    return index;
}


void switchGate(Gate gate[] , int size , int person)
{
    int iteration = 0; // to keep track of iterations the loop is going in.
    int temp1 = getMaxIndex(gate,size) ; // to ensure switching done between two same gates.
    int temp2 = getMinIndex(gate,size); // to ensure no collison . temp2 = minIndex.
    cout<<"The gate with most time is: "<<temp1+1<<" and the gate with the least time is: "<<temp2+1<<endl;
    int temp3 = 0; //to ensure no collision. temp3 = maxIndex.
    int temp4 = temp1;
    int temp5 = temp2;
    int checker = 0;
    int choice = 0;
    cout<<"Are people interested in switching gates?(0/1) ";
    cin>>choice;
    if(choice == 1)
    {
    while(true)
    {
        int minIndex = getMinIndex(gate , size);
        int maxIndex = getMaxIndex(gate , size);
        int minTime = gate[minIndex].total_time;
        int maxTime = gate[maxIndex].total_time;


        if(temp1!=maxIndex)
        {
            cout<<"No need of switching"<<endl;
            break;
        }
        if(checker == 1)
        {
         checker = 0;
        if(temp2 == maxIndex && temp3 == minIndex)
        {
            cout<<"No need of switching."<<endl;
            break;
        }
        }

        if(gate[minIndex].person == 0)
        {
            int temp = gate[maxIndex].person/3;
            gate[maxIndex].person -=temp;
            gate[minIndex].person +=temp;
            updateTotalTime(gate,gate[maxIndex].person , maxIndex);
            updateTotalTime(gate,gate[minIndex].person , minIndex);

        }
        int threshold = maxTime - minTime;
        if(threshold<=4 || iteration >=10)
        {
           if(threshold <= 4)
           {
               cout<<"Switching Done successfully."<<endl;
           }
        }
        if(threshold >= 90)
        {
            gate[maxIndex].person -= 12;
            gate[minIndex].person += 12;
        }
        else if(threshold >= 45)
        {
            gate[maxIndex].person -= 9;
            gate[minIndex].person += 9;
        }
        else if(threshold>=30)
        {
            gate[maxIndex].person -= 7;
            gate[minIndex].person += 7;
        }
        else if(threshold>=24)
        {
            gate[maxIndex].person -= 6;
            gate[minIndex].person += 6;
        }
        else if(threshold>=18)
        {
            gate[maxIndex].person -= 4;
            gate[minIndex].person += 4;
        }
        else if(threshold >=9)
        {
            gate[maxIndex].person -= 2;
            gate[minIndex].person += 2;
        }
        else
        {
            gate[maxIndex].person--;
            gate[minIndex].person++;
        }
        if(gate[maxIndex].person/2  > gate[minIndex].person)
        {
            int temp = gate[maxIndex].person/4;
            gate[maxIndex].person -= temp;
            gate[minIndex].person += temp;
        }
        else if(gate[maxIndex].person/4 > gate[minIndex].person)
        {
            int temp = gate[maxIndex].person/8;
            gate[maxIndex].person -=temp;
            gate[minIndex].person +=temp;
        }

        updateTotalTime(gate , gate[maxIndex].person , maxIndex);
        updateTotalTime(gate , gate[minIndex].person , minIndex);
        iteration++;
        temp1 = maxIndex;
        temp2 = minIndex;
        temp3 = temp1;
        checker = 1;

    }
    cout<<"The person on the gate "<<temp4+1 <<" are "<<gate[temp4].person<<endl;
    cout<<"The person on the gate "<<temp5+1 <<" are "<<gate[temp5].person<<endl;

     cout<<"Switching Done successfully!!!"<<endl<<endl;
    }

   else
   {
       cout<<"They will regret.¯\(:/)/¯";
       return;
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
        thread t1([&](){timerIncrement(gate , N , M/2);});
        t1.join();
        thread t2([&](){timerDecrement(gate,N);});
        t2.join();
       if(sumofPeople>=M/2&&allZero(gate,N))
       {
           break;
       }

       switchGate(gate , N  , M/2);
    }
    cout<<endl<<endl<<"CODE successfully runned!!!!!";
    return 0;
}

