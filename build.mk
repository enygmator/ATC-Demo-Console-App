ATC.exe : Main.o ATCDashboard.o AirplaneQueue.o
	gcc $? -o ATC.exe
Main.o : Main.c
	gcc -c $? -o $@
ATCDashboard.o : ATCDashboard.c
	gcc -c $? -o $@
AirplaneQueue.o : AirplaneQueue.c
	gcc -c $? -o $@
# This make file can be run using > make -f build.mk