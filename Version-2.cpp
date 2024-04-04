//assuming entry time for all the gates will be same

#include<bits/stdc++.h>
using namespace std;

const int capacity=20000;  // max capacity of stadium

class Gate{
    public:
    int size;
    int P;     // time(in min) for any person to enter through the gate
};

int getRandomNumber(int minRange, int maxRange) {
    return minRange + rand() % (maxRange - minRange + 1); // generates a random number within a certain range
}

void Random_Assign(Gate* gates[],int people,int N){  
    int counter = 0;
    for(int i=0;i<N;i++){
        cout<<"Enter initial number of people at Gate "<<(i+1)<<": ";
        cin>>gates[i]->size;
        counter = counter + gates[i]->size;
        if(counter == people){
            cout<<"Random assignment of half people done successfully.\n";
            for(int j=(i+1);j<N;j++){
                gates[j]->size = 0;
            }
            break;
        }
        else if(counter > people){
            int extra = (counter - people);
            gates[i]->size = gates[i]->size - extra;
            cout<<"There are only "<<gates[i]->size<<" people left for random assignment which are assigned to Gate "<<(i+1);
            for(int j=(i+1);j<N;j++){
                gates[j]->size = 0;
            }
            cout<<"\nRandom assignment of half people done successfully.\n";
            break;
        }
        else{
            continue;
        }
    }
    if(counter < people){
        int remaining = (people - counter);
        cout<<"There are "<<remaining<<" people still left, so they are assigned to Gate "<<N<<endl;
        gates[N-1]->size = gates[N-1]->size + remaining;
        cout<<"Random assignment of half people done successfully.\n";
    }
}

void allocateTime(Gate *gate[] , int size)
{
    for(int i = 0 ; i<size ; i++)
    {
        int p = 1;
        cout<<"Time for processing per person for gate: "<<i+1<<" is"<<p<<endl;
        gate[i]->P = p; // gate processing time gets alloacted randomly between 1 and 5 minutes , including both
    }

}

int EntryTimeCalculator(Gate* G){       //Time for last person in the queue to enter the stadium
    return (G->size*G->P);
}

int getMaxTimedGate(Gate* gates[],int N){
    int gate = 0;
    int max_time = EntryTimeCalculator(gates[0]);
    for(int i=1;i<N;i++){
        int current_time = EntryTimeCalculator(gates[i]);
        if(current_time>max_time){
            max_time = EntryTimeCalculator(gates[i]);
            gate = i;
        }
    }
    return gate+1;
}

int getMinTimedGate(Gate* gates[],int N){
    int gate = 0;
    int min_time = EntryTimeCalculator(gates[0]);
    for(int i=1;i<N;i++){
        int current_time = EntryTimeCalculator(gates[i]);
        if(current_time<min_time){
            min_time = EntryTimeCalculator(gates[i]);
            gate = i;
        }
    }
    return gate+1;
}

void switching(Gate* from,Gate* to,int switchers){
    from->size -= switchers;
    to->size += switchers;
    cout<<"Switching done successfully\n";
}

int suggestSwitch(Gate* gates[],int N){
    cout <<endl;
    int gate1 = getMaxTimedGate(gates, N);
    int gate2 = getMinTimedGate(gates, N);
    cout<<"Gate which consists Max People : "<<gate1<<"\tGate which consists Min People : "<<gate2<<endl;
    int t1 = gates[gate1-1]->P*gates[gate1-1]->size;
    int t2 = gates[gate2-1]->P*gates[gate2-1]->size;
    int timeDiff = t1-t2;
    if(timeDiff >= 10){
        cout<<"Time Difference : "<<timeDiff<<endl;
        int extra_people = timeDiff/gates[gate1-1]->P;
        int group = extra_people/2;
        cout<<"Group : "<<group<<endl;
        for(int i=0;i<N;i++){
            cout<<"People at Gate "<<i+1<<" are : "<<gates[i]->size<<"\t";
            cout<<EntryTimeCalculator(gates[i])<<" minutes\n";
        }
        cout<<group<<" people from Gate "<<gate1<<" should switch to Gate "<<gate2<<" to get Quicker Entry."<<endl;
        cout<<"Anyone At Gate "<<gate1<<" is willing to Switch?(1/0) : \t";
        int x;
        cin>>x;
        if(x == 1){
            cout<<"How many Number of People Wants to Switch : ";
            int z;
            cin>>z;
            switching(gates[gate1-1],gates[gate2-1],z);
        }
        else{
            cout<<"They will regret.\n";
        }
        return 0;
    }
    else{
        for(int i=0;i<N;i++){
            cout<<"People at Gate "<<i+1<<" are : "<<gates[i]->size<<"\t";
            cout<<EntryTimeCalculator(gates[i])<<" minutes\n";
        }
        cout<<"No switching is required.\n";
        return -1;
    }
}

int checker=0;

void Increment(Gate *gates[],int people,int N){    // people = M/2 (half of the total people)
    if(checker<people){
        int tempEntered = getRandomNumber(2,10);
        int tempGate = getRandomNumber(0,N-1);
        gates[tempGate]->size += tempEntered;
        checker += tempEntered;
        if(checker > people){
            int extra = checker-people;
            gates[tempGate]->size -= extra;
            checker = people;
            cout<<"Rest of the half people are entered.\n";
            return;
        }
        cout<<tempEntered<<" people entered in gate "<<tempGate+1<<endl;
    }
    else if(checker == people){
        cout<<"Rest of the half people are entered.\n";
        return;
    }
}

void QueueManager(Gate* gates[],int people,int N){
    while(checker != people){
        Increment(gates, people, N);
        suggestSwitch(gates,N);
    }
    while(checker == people && suggestSwitch(gates,N)!=-1){
        suggestSwitch(gates,N);
    }
};

int main(){
    int M,N;
    cout<<"Enter total number of entry gates: ";
    cin>>N;
    Gate* gates[N];
    for(int i=0;i<N;i++) {
        gates[i] = new Gate();
    }
    cout<<"Enter total number of people to be entered in the stadium: ";
    cin>>M;
    for(int i=0;i<N;i++){
        gates[i]->P = getRandomNumber(1,2);
    }

    allocateTime(gates,N);

    if(M>capacity){
        cout<<"Number of people are greater than the stadium capacity.\n";
        return 0;
    }
    else{
       if(M%2 == 0){
            Random_Assign(gates,M/2,N);
            QueueManager(gates,M/2,N);
        }
        else{
            Random_Assign(gates,(M+1)/2,N);
            QueueManager(gates,(M+1)/2,N);
        }
        return 0; 
    }
}