#include <iostream>
#include <cstdlib>
#include <ctime>

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

int getMaxTimedGate(Gate* gates, int numGates) {
    int maxTime = calculateEntryTime(gates[0]);
    int maxGate = 0;
    for (int i = 1; i < numGates; ++i) {
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

void suggestSwitch(Gate* gates, int N) {
    int maxGate = getMaxTimedGate(gates, N);
    int minGate = getMinTimedGate(gates, N);
    int timeDifference = calculateEntryTime(gates[maxGate]) - calculateEntryTime(gates[minGate]);
    if (timeDifference >= 10) {
        for(int i=0;i<N;i++){
            cout<<"time at gate "<<i+1<<" are "<<calculateEntryTime(gates[i])<<endl;
        }
        cout << "Switch people from Gate " << maxGate + 1 << " to Gate " << minGate + 1 << " for quicker entry." << std::endl;
        cout << "Anyone at Gate " << maxGate + 1 << " is willing to Switch?(1/0) : \t";
        int response;
        cin >> response;
        if (response == 1) {
            // Switching logic
            int switchers;
            cout << "How many people want to switch: ";
            cin >> switchers;
            gates[maxGate].size -= switchers;
            gates[minGate].size += switchers;
            cout << "Switching done successfully" << std::endl;
        } else {
            cout << "They will regret." << std::endl;
        }
    } else {
        cout << "No switching is required." << std::endl;
        for(int i=0;i<N;i++){
            cout<<"Final time at gate "<<i+1<<" is "<<calculateEntryTime(gates[i])<<endl;
        }
    }
}
int checker=0;

void Increment(Gate *gates,int people,int N){    // people = M/2 (half of the total people)
    if(checker<people){
        int tempEntered = getRandomNumber(2,10);
        int tempGate = getRandomNumber(0,N-1);
        gates[tempGate].size += tempEntered;
        checker += tempEntered;
        if(checker > people){
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
};


int main() {

    int numGates, totalPeople;
    cout << "Enter the total number of entry gates: ";
    cin >> numGates;

    Gate* gates = new Gate[numGates];
    for (int i = 0; i < numGates; ++i) {
        int processingTime;
        cout << "Enter the processing time for Gate " << i + 1 << " (in minutes): ";
        cin >> processingTime;
        gates[i] = Gate(processingTime);
    }

    cout << "Enter the total number of people to be entered in the stadium: ";
    cin >> totalPeople;

    if (totalPeople > STADIUM_CAPACITY) {
        cout << "Number of people exceeds stadium capacity." << std::endl;
        delete[] gates;
        return 0;
    }
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
    delete[] gates;
    return 0;
}


