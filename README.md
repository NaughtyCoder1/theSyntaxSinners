#Queue Manager in Stadium
#Memebers
1)Jeet Daiya (202301017, NaughtyCoder1)
2)Raj Makwana (202301183, NaughtyCoder2)
3)Dhruv Gohil (202301110, NaughtyCoder3)
4)Neel Shah (202301093, NaughtyCoder4)

##About our Project:

Important Note: We have Submitted 2 Version of Our Program. Both of them have same motive to get the people at the gates of the stadium get Entry in minimum time but both are implemented differently. The main code in both the codes is version 1.

##About the Version 1:
  Important Note: Please use C++-14 or above version and compile code using Code::Blocks as it uses windows terminal for code. The code consists of lines which helps clear 
  the terminal of code at some places.
    
  About Functionality of the code: 
   
    We implemented this code with the help of Array of Structures Data Structure.
    
    First of all, code ask the user to enter the number of gates the stadium consists. Then using random function is used to allocate
    time to each gate. Then there program asks the user to enter the number of people in the Stadium. Then there is Random allocation of  
    half people are done by the user by entering the people at each gate. After the Random Allocation the rest half people will be assigned 
    to random gate in the form group contains random people and the gates are also opened for the peoples in the stadium when the rest 
    people started entering the gates. And after each increment there is switching of the people form one gate to another gate occurring.
    Here comes the most important part of the code. This is the part where the both version of the code differ in this version the switching 
    is done automatically. As people comes randomly after the switching and then the switching switch the people from the gate which 
    contains the maximum people to the gate which contains the minimum people. The time is updated after the each increment and decrement 
    in the code. And here as time goes the people are also entering through the gates such that decrement is also there. And this code will 
    run till all gates contains zero people.
    
##About the Version 2:
    About Functionality of the code:
    
    We implemented this code with the help of Array of Class Data Structure.
    The first part is same in both the versions. But the difference in this version is that we are not using the random function in this 
    function we directly ask the user the time taken by the gate of the stadium. There also one option given to user if they need to enter 
    the same time taken to get entry in the gate. Then the people are assigned randomly in the gates. Then Group of random people are 
    assigned to random gate, after each random assignment the people present at gate with maximum time are suggested to switch to the 
    gate with minimum time. If they want to switch then people at the gate are asked how many of them would like to switch. If the people 
    are more than the suggested people then switching of the extra people does not occur and if the people in the group willing to switch is 
    less than or equal the suggested people then they are switched. This occurs at each random assignment of the people. Also, there is 
    condition if they do not want to switch. In this case the program continues and peoples are assigned after the suggestion. This program 
    will run till the time at each gate is not nearly same or have very small difference.


##Addtional Features in both the Versions:

Version 1:

      In this version we have added several functions which helps the program to run with the time. We used the chrono library which help to provide a real time update of 
      increment and decrement of the people on each gate.


version 2:

      In this version we have tried to simplify the things in the program. In version 1 we have used the chrono and thread library to run the program with the time. Here we   
      are not using any other library to do such thing. The main difference between both the version is in the switching function. In this version the switching done by the 
      user by suggesting each and every person whether they want to switch or not. This also goes with the time in the different way user have to enter the input 
      every time till all the gates have nearly same time to push all the people thought the gate to enter the stadium. In this code the people
      are not entering through the gates. The switching and increment are happening while they are standing in the queue. While in the version 1 the 
      people in the Queue are also passing through the gates and entering the stadium. The advantage of this version is that is easy to understand and
      implement.

##Conclusion:

      In both the version the code is minimizing the time of the gates through which they are going to enter. This code helps the Queue 
      Manager in the Stadium or at any place to manage the people and help them to get the quicker entry. This will also help them to easily handle the crowd. Our program is 
      able to handle large input also. But make sure that larger the input the user enters larger the time will be taken by the code to reach the final output. In version-1 the 
      code runs automatically and with respect to the time gates have.

##Contribution:
  We came up with idea of both versions in group discussions which happened almost regularly. Initially, we came up with idea of version-1 and started coding and later, we 
  came up with idea for version-2, where in certain changes as discussed above were made. Due to shortage of time, we divided in pair of duos coded both versions  
  concurrently. However, it was all done during group meetings. This approach ensured that we discussed and incorporated ideas of every member in the code. 

  1) Jeet Daiya
     - Researched about how to increment and decrement people in real time and came up with <thread> and <chrono> header files and their functions which were to be 
       implemented in the code
     - Coded the parts consisting of these functions
     - 



