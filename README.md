#Queue Manager in Stadium

##About our Project:

Important Note : We have Submitted 2 Version of Our Program.Both of them have same motive to get the people at the gates of the stadium get Entry in minimum time but both are implemented differently.The main code in both the codes is version 1.

##About the Version 1:
  Important Note : Please use C++14 or above version and compile code using Code::Blocks as it uses windows terminal for code. The code consists of lines which helps clear 
  the terminal of code at some places.
    
  About Functionality of the code: 
   
    We implemented this code with the help of Array Data Structure.
    
    First of all Program ask the user to enter the number of gates the stadium consists.Than using random function is used to allocate
    time to each gate.Then there program asks the user to enter the number of people in the Stadium.Then there is Random allocation of 
    half people is done by the user by entering the people at each gate.After the Random Allocation the rest half people will be assigned 
    to random gate in the form group contains random people and the gates are also opened for the peoples in the stadium when the rest 
    people started entering the gates.And after each increment there is switching of the people form one gate to another gate occuring.
    Here comes the most important part of the code.This is the part where the both version of the code differ in this version the switching 
    is done automatically.As people comes randomly after the switching and then the switching switch the people from the gate which 
    contains the maximum people to the gate which contains the minimum people.The time is updated after the each increment and decrement 
    in the code.And here as time goes the people are also entering through the gates such that decrement is alo there.And this code will 
    run till all gates contains zero people.
    
##About the Version 2:
    About Functionality of the code:
    
    We implemented this code with the help of Array Data Structure.
    The first part is same in both the versions.But the difference in this version is that we are not using the random function in this 
    function we directly ask the user the time taken by the gate of the stadium.There also ome option givent o user if they need to enter 
    the same time taken to get entry in the gate.Then the peoples are assigned randomly in the gates.Then Group of random people are 
    assigned to random gate,after each random assignment the people present at gate with maximum time are suggested to switch to the 
    gate with minmum time.If they want to switch then people at the gates are asked how many of them would like to switch.If the people 
    are more than the suggested peoples then there is no switching occurs and if the people in the group willing to swittch is less than 
    the suggested people then they are switched.This occurs at each random assignment of the people.Also there is condition of they do not 
    want to switch.In this case the program continues and peoples are assigning after the suggestion.This program will run till the time 
    at each gates is not nearly same or having very small difference.


##Addtional Features in both the Versions:

Version 1:

      In this version we added several function which helps the program to run with the time.We used the chrono library which help to 


version 2:

      In this version we have tried to simplify the things in the program and it is more basic implementation of the version 1.In version 1 
      we have used the chrono and thread library to run the program with the time. Here we are not using any other library to do such thing. 
      The main difference between both the version is in the switching function.In this version the switching done by the user by suggesting 
      each and every person whether they want to switch or not.This also goes with the time in the different way user have to enter the input 
      every time till all the gates have nearly same time to push all the people thought the gate to enter the stadium.In this code the peoples
      are not entering through the gates.The switching and all are happening while they are standing in the queue.While in the version 1 the the 
      people in the Queue are also passin through the gates and entering the stadium.The advantage of this version is that is easy to understand 
      it very easy to implement.

##Assumptions:

Version 1:


Version 2:

      1)The output of the code is designed considering a person is handling the software.
      2)The people who agreed to switch are switched till required conditions are not met according to the algorithm. 
      3)No individual consent for switching is taken, the switching is done if a majority is agreeing to switch.
      4)The consent is assumed to reach the handler using some mode of communication (e.g. some employee on ground.)
      5)To make it more real time, the p minutes(i.e processing time per person at each gate) is taken randomly within a certain range. In real 
      time the people who will check will not take uniform time.
      6)The rest of M/2 people who will enter are made to enter at random time at a random gate, as in real life, people won't enter in the same amount and at the same gate.
      7)To mimic server refresh/lag, the updates are displayed with some delay.

##Conclution:

      In this both the version the code in minimizing the time of the gates through which they are going to enter.This codes helps the Queue 
      Manager in the Stadium to manage the people and help them to get the quicker entry.Code will help them that how many people should 
      move from which gate to whiuch gate.This will also help them to easily handle the crowd.Our program is able to handle the large input also.
      But make sure that the bigger the input the user enter the time will be taken by the code to reach the final output.In version one the code
      run automatically and wwith respec to the time user have entered.

##Contribution:

Version 1:

Version 2:

    This

