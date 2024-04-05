#include <iostream>
#include <cstdlib>

using namespace std;
const int STADIUM_CAPACITY = 20000;

class Gate {
public:
    int size;
    int entryTime; // time (in minutes) for any person to enter through the gate
    Gate(){}
    Gate(int time) : size(0), entryTime(time) {}
};

int getRandomNumber(int minRange, int maxRange) {
    return minRange + rand() % (maxRange - minRange + 1);
}

void Random_Assign(Gate* gates,int people,int N){  
    int counter = 0;
    for(int i=0;i<N;i++){
        cout<<"Enter initial number of people at Gate "<<(i+1)<<": ";
        cin>>gates[i].size;
        counter = counter + gates[i].size;
        if(counter == people){
            cout<<"Random assignment of half people done successfully.\n";
            for(int j=(i+1);j<N;j++){
                gates[j].size = 0;
            }
            break;
        }
        else if(counter > people){
            int extra = (counter - people);
            gates[i].size -= extra;
            cout<<"There are only "<<gates[i].size<<" people left for random assignment which are assigned to Gate "<<(i+1);
            for(int j=(i+1);j<N;j++){
                gates[j].size = 0;
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
        gates[N-1].size += remaining;
        cout<<"Random assignment of half people done successfully.\n";
    }
}

int calculateEntryTime(const Gate& gate) {
    return gate.size * gate.entryTime;
}

int getMaxTimedGate(Gate* gates, int N) {
    int maxTime = calculateEntryTime(gates[0]);
    int maxGate = 0;
    for (int i = 1; i < N; ++i) {
        int currentTime = calculateEntryTime(gates[i]);
        if (currentTime > maxTime) {
            maxTime = currentTime;
            maxGate = i;
        }
    }
    return maxGate;
}

int getMinTimedGate(Gate* gates, int N) {
    int minTime = calculateEntryTime(gates[0]);
    int minGate = 0;
    for (int i = 1; i < N; ++i) {
        int currentTime = calculateEntryTime(gates[i]);
        if (currentTime < minTime) {
            minTime = currentTime;
            minGate = i;
        }
    }
    return minGate;
}

void switching(Gate *from,Gate *to,int switchers){
    from->size -= switchers;
    to->size += switchers;
    cout<<"Switching done successfully\n";
}

int suggestSwitch(Gate* gates,int N){
    int maxGate = getMaxTimedGate(gates, N);
    int minGate = getMinTimedGate(gates, N);
    int t1 = gates[maxGate].entryTime*gates[maxGate].size;
    int t2 = gates[minGate].entryTime*gates[minGate].size;
    int timeDifference = t1-t2;
    if(timeDifference >= 10){
        for(int i=0;i<N;i++){
            cout<<"Gate "<<i+1<<" will take "<<calculateEntryTime(gates[i])<<" minutes."<<endl;
        }
        int extra_people = timeDifference/gates[maxGate].entryTime;
        int should_switch = extra_people / 2;
        cout <<should_switch<< " People from Gate " << maxGate + 1 << " can Switch to Gate " << minGate + 1 << " for quicker entry." << std::endl;
        cout << "Is anyone at Gate " << maxGate + 1 << " willing to Switch? (Enter 1 for yes/0 for no) : \t";
        int response;
        cin >> response;
        if(response == 1){
            int switchers;
            cout << "How many people want to switch: ";
            cin >> switchers;
           if(switchers <= should_switch || switchers < should_switch + 5){
                switching(&gates[maxGate],&gates[minGate],switchers);
            }
            else{
                cout<<"It is not Possible to Switch "<<switchers<<" People."<<endl;
                cout<<"Approximately "<<should_switch<<" people can be Allowed to Gate."<<endl;
            }
        }
        else{
            cout<<"They will regret.\n";
        }
        return 0;
    }
    else{
        for(int i=0;i<N;i++){
            cout<<"People at Gate "<<i+1<<" are : "<<gates[i].size<<"\t";
            cout<<calculateEntryTime(gates[i])<<" minutes\n";
        }
        cout<<"No switching is required.\n";
        return -1;
    }
}

int checker=0;     // to keep a track on how many number of people entered in the stadium

void Increment(Gate *gates,int people,int N){    // people = M/2 (half of the total people)
    if(checker<people){
        int tempEntered = getRandomNumber(2,10);   // random number of people entering the stadium at a time
        int tempGate = getRandomNumber(0,N-1);    // random gate at which they will go
        gates[tempGate].size += tempEntered;
        checker += tempEntered;                   // updating size of gates and checker
        if(checker > people){                     // if more people entered than the expected total then further entry is prohibited 
            int extra = checker-people;
            gates[tempGate].size -= extra;
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

void QueueManager(Gate* gates,int people,int N){
    while(checker != people){
        Increment(gates, people, N);
        suggestSwitch(gates,N);
    }
    while(checker == people && suggestSwitch(gates,N)!=-1){
        suggestSwitch(gates,N);
    }
};

int main() {

    int numGates, totalPeople;
    cout << "Enter the total number of entry gates: ";
    cin >> numGates;

    Gate* gates = new Gate[numGates];
    int processingTime;
        int choice;
        cout<<"Processing time for each entry gate is similar(enter 1) or different(enter 0): ";
        cin>>choice;
        if(choice == 1){
            cout<<"Enter processing time: ";
            cin>>processingTime;
            if(processingTime <= 0){
                cout<<"Invalid Input!\nTry again.\n";
                cout<<"Enter processing time: ";
                cin>>processingTime;
            }
            for(int i=0;i<numGates;i++){
                gates[i] = Gate(processingTime);
            }
        }
        else{
            for(int i=0;i<numGates;i++){
                cout<< "Enter the processing time for Gate "<< i+1 << " (in minutes): ";
                cin>>processingTime;
                gates[i] = Gate(processingTime);
            }
        }

    cout << "Enter the total number of people to be entered in the stadium: ";
    cin >> totalPeople;

    if (totalPeople > STADIUM_CAPACITY) {
        cout << "Number of people exceeds stadium capacity." << endl;
        delete[] gates;
        return 0;
    }
    else{
        if(totalPeople%2 == 0){
            Random_Assign(gates, totalPeople/2, numGates);
            suggestSwitch(gates,numGates);
            QueueManager(gates, totalPeople/2, numGates);
        }
        else{
            Random_Assign(gates, (totalPeople+1)/2, numGates);
            suggestSwitch(gates,numGates);
            QueueManager(gates, (totalPeople+1)/2, numGates);
        }
    }
    cout<<"Thank you.\n";
    delete[] gates;
    return 0;
}


