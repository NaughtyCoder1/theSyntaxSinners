// Assuming that the code is being used by some entry manager and not by the people which are entering

#include<iostream>
#include<cstdlib>

using namespace std;
const int MaxCapacity = 10000;     // fixing a maximum amount of people for the stadium

class Gate{
    public:
    int size;
    float entryTime;
    Gate(){}
    Gate(float time){
        size = 0;
        entryTime = time;        //processing time(in minutes) for any person to enter the stadium through a gate
    }
};

int getRandomNumber(int min, int max){              // to generate a random number
    return min + rand()%(max - min + 1);
}

void Random_Assign(Gate* gates,int people,int N){   // to randomly assign first half of the people manually by the user
    int counter = 0;
                                    
    for(int i=0;i<N;i++){           // to keep track on number of people assigned randomly
        cout<<"Enter initial number of people at Gate "<<(i+1)<<": ";
        cin>>gates[i].size;
        counter += gates[i].size;

        if(counter == people){

            cout<<"Random assignment of half people done successfully.\n";
            break;
        }
        else if(counter > people){                  // if extra people entered randomly then they are removed
            
            int extra = (counter - people);
            gates[i].size -= extra;
            cout<<"There are only "<<gates[i].size<<" people left for random assignment which are assigned to Gate "<<(i+1);
            cout<<"\nRandom assignment of half people done successfully.\n";
            break;
        }
        else{
            continue;
        }
    } 
    if(counter < people){              // after assigning random number of people at each gate if still some people are left

        int remaining = (people - counter);
        cout<<"There are "<<remaining<<" people still left, And they are assigned to Gate "<<N<<endl;
        gates[N-1].size += remaining;
        cout<<"Random assignment of half people done successfully.\n";
    }
}

float calculateEntryTime(Gate &gates){    
    return gates.size*gates.entryTime;
}

int getMinIndex(Gate* gates,int N){     // to get index of the gate which gives entry in minimum time
    int minIndex = 0;
    float minTime = calculateEntryTime(gates[0]);

    for(int i=1;i<N;i++){
        if(calculateEntryTime(gates[i]) < minTime){
            minTime = calculateEntryTime(gates[i]);
            minIndex = i;
        }
    }
    return minIndex;
}

int getMaxIndex(Gate* gates,int N){      // to get index of the gate which gives entry in maximum time
    int maxIndex = 0;
    float maxTime = calculateEntryTime(gates[0]);

    for(int i=1;i<N;i++){
        if(calculateEntryTime(gates[i]) > maxTime){
            maxTime = calculateEntryTime(gates[i]);
            maxIndex = i;
        }
    }
    return maxIndex;
}

void switching(Gate* from,Gate* to,int switchers){     

    from->size -= switchers;
    to->size += switchers;
    cout<<"Switching Done Successfully.\n";
}

int suggestSwitch(Gate* gates,int N){             // to suggest that how many people should switch from which gate to which gate

    int MaxIndex = getMaxIndex(gates,N);
    int MinIndex = getMinIndex(gates,N);
    float TimeDiff = calculateEntryTime(gates[MaxIndex]) - calculateEntryTime(gates[MinIndex]);

    if(TimeDiff >= 10){    // switching is required only if there is significant time difference between two gates

        cout<<endl;
        for(int i=0;i<N;i++){
            cout<<"Gate "<<i+1<<" will take "<<calculateEntryTime(gates[i])<<" minutes.\n";
        }
        cout<<endl;

        int should_switch = TimeDiff/(2*gates[MaxIndex].entryTime);
        cout <<should_switch<< " people from Gate "<<MaxIndex+1<<" can Switch to Gate "<<MinIndex+1<<" for quicker entry.\n";

        int choice;
        cout<<"\nDoes anyone at Gate "<<MaxIndex+1<<" willing to switch? (Enter 1 if yes/ 0 if no): ";  // If people wants to switch then only switching will be done
        cin>>choice;

        if(choice == 1){

            int switchers;
            cout<<"How many people are ready to switch: ";
            cin>>switchers;

            if(switchers <= should_switch || switchers <= should_switch+5){   // switching will be done in these conditions only
                                                                                
                switching(&gates[MaxIndex],&gates[MinIndex],switchers);
            }
            else{

                cout<<"Not possible to switch "<<switchers<<" people to Gate "<<MinIndex+1<<endl;
                cout<<"Aroud 5 people more than "<<should_switch<<" can be allowed.\n";
            }
        }
        else{

            cout<<"They will regret.\n";
        }
        return 1;
    }
    else{

        for(int i=0;i<N;i++){
            cout<<"Gate "<<i+1<<" will take "<<calculateEntryTime(gates[i])<<" minutes.\n";
        }

        cout<<"\nNo switching is required.\n"<<endl;
        return -1;
    }
}

int checker = 0;                                          // to keep track on rest half of the people entered

void Increment(Gate* gates,int halfpeople,int N){         // remaining half people entering in the gates
    if(checker < halfpeople){
        int Entered = getRandomNumber(4,12);
        int gateIndex = getRandomNumber(0,N-1);
        gates[gateIndex].size += Entered;                // random number of people entering into random number of gate
        checker += Entered;                              // updating checker
        if(checker > halfpeople){                        // removing people if extra people entered raandomly 
            int extra = checker - halfpeople;
            gates[gateIndex].size -= extra;
            checker = halfpeople;
            cout<<"Rest of the half people are entered in the gates.\n";
            return;
        }
        cout<<Entered<<" people entered in Gate "<<gateIndex+1<<endl;
    }
    else if(checker == halfpeople){
        cout<<"Rest of the half people are entered in the gates.\n";
        return;
    }
}

void EntryManager(Gate* gates,int halfpeople,int N){    // to manage the increment and suggest switch function 
    while(checker != halfpeople){
        Increment(gates,halfpeople,N);
        suggestSwitch(gates,N);
    }                                                  
    while(checker == halfpeople && suggestSwitch(gates,N) != -1){      // suggesting switching after all the people entered into gates
        suggestSwitch(gates,N);
    }
}

int main(){
    int Totalpeople,Totalgates;
    cout<<"Enter total number of people to be entered in the stadium: ";
    cin>>Totalpeople;

    if(Totalpeople > MaxCapacity){

        cout<<"Insufficient Stadium Capacity!!\n";
        return 0;
    }

    else{

        cout<<"Enter total number of entry gates available in the stadium: ";
        cin>>Totalgates;

        Gate* gates = new Gate[Totalgates];

        int response;
        float processingTime;
        cout<<"Processing time for each entry gate is similar(enter 1) or different(enter 0)? : ";
        cin>>response;

        if(response == 1){

            cout<<"Enter processing time(in minutes): ";
                cin>>processingTime;

            if(processingTime <= 0){
                cout<<"Invalid Input!\nTry again.\n";
                cout<<"Enter processing time(in minutes): ";
                cin>>processingTime;
            }

            for(int i=0;i<Totalgates;i++){
                gates[i] = Gate(processingTime);
            }

        }
        else{

            for(int i=0;i<Totalgates;i++){
                cout<<"Enter processing time for Gate "<<i+1<<" (in minutes): ";
                cin>>processingTime;
                gates[i] = Gate(processingTime);
            }
        }

        if(Totalpeople % 2 == 0){

            Random_Assign(gates, Totalpeople/2, Totalgates);
            suggestSwitch(gates,Totalgates);
            EntryManager(gates, Totalpeople/2, Totalgates);
        }
        else{

            Random_Assign(gates, (Totalpeople+1)/2, Totalgates);
            suggestSwitch(gates,Totalgates);
            EntryManager(gates, (Totalpeople+1)/2, Totalgates);
        }

        cout<<"THANK YOU.\n";
        return 0;
    }
}
