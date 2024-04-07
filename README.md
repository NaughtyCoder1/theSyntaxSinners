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

  Use ID : "rygbeeRAx" and Password : "12121980"
    
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

##Contribution:
  We came up with idea of both versions in group discussions which happened almost regularly. Initially, we came up with idea of version-1 and started coding and later, we 
  came up with idea for version-2, where in certain changes as discussed above were made. Due to shortage of time, we divided in pair of duos coded both versions  
  concurrently. However, it was all done during group meetings. This approach ensured that we discussed and incorporated ideas of every member in the code. 

   1) Jeet Daiya - NaughtyCoder1
     - Researched about how to increment and decrement people in real time and came up with <thread> and <chrono> header files and their functions which were to be 
       implemented in the code
     - Coded the parts consisting of these functions.
     - Implemented checkPassword() function.
     - Designed switchGate() function along with all the members.
     - Implemented timeIncrement() and timerDecrement() function with Raj.
     - Formatted Output.
     - Analyzed time and space complexity with Raj.
     - Wrote description in the document.
       
   2) Raj Makwana - NaughtyCoder2
     - Implemented updateTotalTime() function.
     - Implemented decrement() function.
     - Implemented getMinIndex() ,getMaxIndex() and allZero() function.
     - Made significant changes in switchGate() function and improved efficiency.
     - Added comments.
     - Wrote psuedocode in the document file.
       
   3) Dhruv Gohil - NaughtyCoder3
     - Implmented allocateTime() functions.
     - Implemented suggestSwitch() function.
     - Implemented switching() function.
     - Improved queueManager() function.
     - Added comments and made code more readable.
     - Wrote the psuedocode in the document.
     - Suggested some changes in the switchGate() function for version-1.
    
   4) Neel Shah - NaughtyCoder4
     - Implemented randomAssign() function along with Dhruv.
     - Implemented queueManager() function.
     - Formatted output.
     - Implemented increment() function.
     - Helped in suggestSwitch() function.
     - Made code more readable by changing variable names.
     - Analyzed time and space complexity.
     - Wrote Description in the document.
     - Tried to implement decrement function in version-2 but failed unforutnately.
      
     



