#include"ATCDashboard.h"

//Here global variables have been used, since we will not have multiple instances of ATC
//and all functions will be accessing the same linked list, and because the main function would
//not have to worry about maintaining an ATC queue which is clearly the ATC's job and not the main's.
//The Main function is a client getting information and telling the ATC what to do, not how to do.

AirplaneQueue* LandingQueue; //The landing queue head node (Linked list)
AirplaneQueue* TakeoffQueue; //The takeoff queue head node (Linked list)

/// <summary>
/// Starts the ATC by clearing the memory of the previous ATC queues, if any. and assigning NULL to the
/// head of the queues.
/// </summary>
void ATCStart()
{
    TraverseAndFreeTillEndOfQueue(LandingQueue);
    TraverseAndFreeTillEndOfQueue(TakeoffQueue);
    LandingQueue = NULL;
    TakeoffQueue = NULL;
    printf("ATC has initiated.\nThe landing and takeoff queues are now empty.\n");
}

/// <summary>
/// Prints the Landing hold pattern (queue/ Linked List) in User friendly manner
/// </summary>
void PrintLandingHoldPattern()
{
    printf("The Landing hold pattern:\n");
    PrintAirplaneQueue(LandingQueue);
}

/// <summary>
/// Prints the Takeoff hold pattern (queue/ Linked List) in User friendly manner
/// </summary>
void PrintTakeoffHoldPattern()
{
    printf("The Takeoff hold pattern:\n");
    PrintAirplaneQueue(TakeoffQueue);
}

//NOTE:
//Airplanes can be registered in the landing and takeoff queue at the same time, since all
//landings have to take place before takeoffs and the airplane can preregister to land and takeoff at the same time

/// <summary>
/// This function adds a new airplane to the landing queue.
/// </summary>
/// <param name="airplane">The "Airplane" object which you want to add to the queue</param>
void AddAirplaneToLandQueue(Airplane airplane)
{
    LandingQueue = AddToAirplaneQueue(airplane, LandingQueue, LandingRequest);
}

/// <summary>
/// Queries the airplane position and tells you how many airplanes you gotta wait before you land
/// </summary>
/// <param name="airplaneID">The "Airplane" object whose position you query</param>
void RequestToLand(int airplaneID)
{
    int pos = GetAirplanePosition(airplaneID, LandingQueue);
    if(pos == -1)
    {
        printf("The airplane might not exist.\n");
        return;
    }
    printf("You are %d landings from landing\n", pos);
}

/// <summary>
/// Lands an airplane from the head of the Landing queue
/// </summary>
void Land()
{
    LandingQueue = RemoveFromAirplaneQueueAtFront(LandingQueue, LandingRequest);
    PrintTakeoffHoldPattern();
    PrintLandingHoldPattern();
}

/// <summary>
/// Removes an airplane from anywhere in the Landing queue
/// </summary>
/// <param name="airplaneID">The "Airplane" object which you want to remove from the queue</param>
void ExitLandQueue(int airplaneID)
{
    LandingQueue = RemoveFromAirplaneQueue(airplaneID, LandingQueue, LandingRequest);
}

/// <summary>
/// This function adds a new airplane to the takeoff queue.
/// </summary>
/// <param name="airplane">The "Airplane" object which you want to add to the queue</param>
void AddAirplaneToTakeoffQueue(Airplane airplane)
{
    TakeoffQueue = AddToAirplaneQueue(airplane, TakeoffQueue, TakeoffRequest);
}

/// <summary>
/// Queries the airplane position and tells you how many airplanes you gotta wait before you takeoff
/// </summary>
/// <param name="airplaneID">The "Airplane" object whose position you query</param>
void RequestToTakeoff(int airplaneID)
{
    int landNum;
    int pos = GetAirplanePosition(airplaneID, TakeoffQueue);
    if(pos == -1)
    {
        printf("The airplane might not exist.\n");
        return;
    }
    if (!(landNum = sizeOfQueue(LandingQueue)))
    {
        printf("The landing queue is empty.\nSo, you are %d planes away from takeoff.\n", pos);
        PrintTakeoffHoldPattern();
    }
    //Doesn't let you take off if the landing queue isn't empty
    else
    {
        printf("All the planes have not landed. They must land first.\n");
        printf("So, you are %d landings and %d takeoffs away from takeoff\n", landNum, pos);
    }
}

/// <summary>
/// Takes off an airplane from the head of the Landing queue. It is made sure that the landing queue is empty before taking off.
/// </summary>
void Takeoff()
{
    if (!sizeOfQueue(LandingQueue))
    {
        TakeoffQueue = RemoveFromAirplaneQueueAtFront(TakeoffQueue, TakeoffRequest);
        PrintTakeoffHoldPattern();
    }
    else printf("All the planes have not landed. They must land first for takeoffs to occur.\n");
}

/// <summary>
/// Removes an airplane from anywhere in the takeoff queue
/// </summary>
/// <param name="airplaneID">The "Airplane" object which you want to remove from the queue</param>
void ExitTakeoffQueue(int airplaneID)
{
    TakeoffQueue = RemoveFromAirplaneQueue(airplaneID, TakeoffQueue, TakeoffRequest);
}