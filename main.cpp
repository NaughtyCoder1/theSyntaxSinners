#include<iostream>
#include<chrono>
#include<cmath>
#include<random>
#include<thread>
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

int sumofPeople = 0; //keeping track of the rest of M/2 people.

void timerIncrement(Gate *gate , int size , int people)
{
    int y = getRandomNumber(1,5);
    sumofPeople+=y;
    cout<<"Sum of people is: "<<sumofPeople<<endl;
    if(sumofPeople<people)
    {
        int x = getRandomNumber(0,size-1);
        cout<<endl<<"The number of person alloted are: "<<y<<"And gate alloted is: "<<x+1<<endl;
        gate[x].person += y;
         cout<<"The total person now are: "<<gate[x].person<<endl;
        updateTotalTime(gate , gate[x].person , x);
        cout<<"Updated time after increment is: "<<gate[x].total_time;
        cout<<endl;
    }
    else if(sumofPeople == people)
    {
        cout<<"The rest of half of the people are also alloted."<<endl;
        return;
    }
    else
    {
        int extra;
        extra = sumofPeople - people;
        int x = getRandomNumber(0,size-1);
        cout<<"The gate alloted is: "<<x<<"To "<<extra<<"People"<<endl;
        gate[x].person +=extra;
        cout<<"The total person now are: "<<gate[x].person<<endl;
        updateTotalTime(gate , gate[x].person , x);
    }
    this_thread::sleep_for(chrono::minutes(1));
}

void allocateTime(Gate gate[] , int size)
{
    for(int i = 0 ; i<size ; i++)
    {
        int p = getRandomNumber(1,2);
        cout<<"Time for processing per person is: "<<p<<endl;
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
            gate[i].person = max(0,gate[i].person-=2); // if 1 minute is take for 1 person than in  5 minutes 5 person will be processed
        }
      else
        {
             gate[i].person = max(0,gate[i].person-= 1); // if 5 minute is taken to process , then 1 will be processed in 5 minutes
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
        this_thread::sleep_for(chrono::minutes(1)); // function calling not activated 5 minutes
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

int getMaxTimedGate(Gate* gates[],int N){
    int gate = 0;
    int max_time = gates[0]->processing_time;
    for(int i=1;i<N;i++){
        if(EntryTimeCalculator(gates[i])>max_time){
            max_time = EntryTimeCalculator(gates[i]);
            gate = i;
        }
    }
    return gate+1;
}

int getMinTimedGate(Gate* gates[],int N){
    int gate = 0;
    int min_time = gates[0]->processing_time;
    for(int i=1;i<N;i++){
        if(EntryTimeCalculator(gates[i])<min_time){
            min_time = EntryTimeCalculator(gates[i]);
            gate = i;
        }
    }
    return gate+1;
}

int EntryTimeCalculator(Gate* G){       //Time for last person in the queue to enter the stadium
    return (G->person*G->processing_time);
}

void switching(Gate* from,Gate* to,int switchers){
    from->person -= switchers;
    to->person += switchers;
    cout<<"Switching done successfully\n";
}

void suggestSwitch(Gate* gates[],int N){
    int gate1 = getMaxTimedGate(gates, N);
    int gate2 = getMinTimedGate(gates, N);
    int t1 = EntryTimeCalculator(gates[gate1]);
    int t2 = EntryTimeCalculator(gates[gate2]);
    int timeDiff = t1-t2;
    if(timeDiff >= 10){
        int group ;
        for(int i=0;i<N;i++){
            cout<<"People at Gate "<<i+1<<" are : "<<gates[i]->person<<"\t";
            cout<<EntryTimeCalculator(gates[i])<<" minutes\n";
        }
        cout<<" people from Gate "<<gate1<<" should switch to Gate "<<gate2<<" to get Quicker Entry."<<endl;
        cout<<"Anyone At Gate "<<gate1<<" is willing to Switch?(1/0) : \t";
        int x;
        cin>>x;
        if(x == 1){
            cout<<"How many NUmber of People Wants to Switch : ";
            int z;
            cin>>z;
            switching(gates[gate1],gates[gate2],z);
        }
        else{
            cout<<"They will regret.\n";
        }
    }
    else{
        for(int i=0;i<N;i++){
            cout<<"People at Gate "<<i+1<<" are : "<<gates[i]->person<<"\t";
            cout<<EntryTimeCalculator(gates[i])<<" minutes\n";
        }
        cout<<"No switching is required.\n";
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
       if(sumofPeople!=M/2)
       {

       thread t1([&](){timerIncrement(gate , N , M/2);});
       t1.join();
       }
       else
       {
           continue;
       }
       thread t2([&](){timerDecrement(gate,N);});
       t2.join();
    }
    return 0;
}

