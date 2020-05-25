# ATC - Demo console app
ATC - Air traffic control  
This is an assignment os part of PSWC course, PES University  
DONE BY: T Tarun Aditya  
Email: tarun.aditya.bc@gmail.com  

**Personal comment**: This project is something I have no interest in working on and I only did it to complete the assignment. The code I have used doesn't handle minor bugs, which are now part of the issues section. It may also be noted that the code used here more or less shows how I code in a rough manner without much consideration as to the security or any other implications it might have in the future. I have no interest in working on it in the future.

## Project statement
Assignment 2:  
Simulation of an Airport: You need to simulate the working of an airport. Let us consider a small but busy airport with two runways, one always used for landings and the other always used for takeoffs. Planes arrive ready to land or ready to take off at random times, so at any given unit of time, the runways may be idle or a plane may be landing or taking off and there may be several planes waiting either to land or take off. We therefore need two queues, called landing and takeoff, to hold these planes. It is better to keep a plane waiting on the ground than in the air, so a small airport allows a plane to take off only if there are no planes waiting to land. Hence, after receiving requests from new planes to land or take off, our simulation will first service the head of the queue of planes waiting to land, and only if the landing queue is empty, will it allow a plane to take off.

## PROJECT GUIDELINES
1. Make sure that you have your code in at least 2 .c files and one .h file. (**DONE**)
2. You need to have a relevant makefile to build the executable. (**DONE**)
3. Accept as many inputs as possible through command line arguments (**DONE**)
4. The “main” function should be restricted to just taking the required inputs, calling other functions for the required processing and then displaying the results (**DONE**)
5. Avoid (minimize) the use of global variables (If you are using, you have to justify why you have to use global variables – apart from saying “it makes your life easier”) (**DONE**)
6. The functions as far as possible, have to accept arguments and return the required result. If you have functions which do not accept any parameters and do not return anything, that code might as well be part of the main function. (**DONE**)
7. When you build the executable, make sure that there are no “warnings” left. (**DONE**)
8. The variables used in your program should have meaningful names. Avoid using i,j,k,l (**DONE**)
9. Write meaningful comments. A program without comments will not be accepted (**DONE**)
10. Check for all possible error conditions and handle these gracefully. (**DONE**)
11. Validate all the input values (**DONE**)
12. Clearly mention any known bugs still left in the program which you are unable to fix.
13. Clearly mention any assumptions you have made (**DONE**)
14. Also, mention any constraints under which your program might work correctly. (**DONE**)
15. GUI is not mandatory.(**DONE**)
16. It would be good to make sure all these programs work on Windows as well as Linux.(**DONE**)
17.  You can use whatever tools you are comfortable with. But, when you submit your program, make sure that there is a “makefile” which just needs the “make” utility and the “gcc” compiler to build your executable.(**DONE**)

## Instructions
- 3 Marks - for following the guidelines in letter and spirit
- 2 Marks - For handling all possible errors in their programs (Checking for return values from functions, validating inputs, etc)
- 5 Marks - The actual working of the program.

# Limitations
1. This is a somewhat weird airport, where we have two runways and two queues (holding patterns), one for takeoff and the other for landing.
2. An airplane cannot takeoff without all airplanes in the landing queue having landed.
3. Airplanes may takeoff and land in a first come first serve order, where even a plane in emergency has to join the que and wait for it's turn.
4. An airplane may freely get out of any que at any point, but it will have to rejoin at the end of the que if it wishes so, i.e. it can't go back to its original position in the queue.
5. An airplane may register in both the landing and takeoff queues as, it may first land and then takeoff (after getting off / taking on passengers).

> [!WARNING]
> If the ATC is restarted with the restart ATC option, you erase all knowledge of all queues, thus requiring each of the planes to re-register in the queues.

# ISSUES/TODO
1. non-numerical input in a numerical input case causes program to crash

# Installation/BUILD
There is no installation for this app. You need to just build it and run it.  
- To build it on windows, run `.\BUILD.ps1` or `make -f build.mk`
- To clean the directory, run `.\BUILD.ps1 clean`.
- On linux, run `make -f build.mk`.   
**NOTE**: You must have `GCC` and `make` installed in your windows/linux machine.

# Usage
To use it, after building it, run `.\ATC.exe` on windows and/or `./ATC.exe` on linux.

# Development
When you are developing, just follow the [BUILD]() process and then the [USAGE]() instructions.  
The cascading of header files:  
Main<-ATC<-AirplaneQueue<-Airplanes

# Contribution
This is a highly unlikely circumstance, but if you want to contribute, you may do so and PR it and I shall gladly merge it into the repo after verification.

# LICENSE
This project has been open-sourced on github under the Apache License, Version 2.0, January 2004. Read the License file for further details.