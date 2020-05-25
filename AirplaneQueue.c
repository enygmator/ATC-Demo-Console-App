#include"AirplaneQueue.h"

/// <summary>
/// Traverse a queue (Linked list) node by node, destruct the nodes and free the memory
/// </summary>
/// <param name="airplaneQueue">The head of the queue to be destroyed</param>
void TraverseAndFreeTillEndOfQueue(AirplaneQueue* airplaneQueue)
{
    AirplaneQueue* tempque = airplaneQueue, *posttempque;
    //Loop till all nodes are destroyed and memory is freed
    while (tempque)
    {
        posttempque = tempque->next;
        free(tempque);
        tempque = posttempque;
    }
}

/// <summary>
/// Returns the size of the queue (Linked list)
/// </summary>
/// <param name="airplaneQueue">The queue whose size you want</param>
/// <returns>The number of nodes in the queue</returns>
int sizeOfQueue(AirplaneQueue* airplaneQueue)
{
    AirplaneQueue* tempque = airplaneQueue;
    int number = 0;
    if(tempque != NULL) //checks if queue head is NULL
    {
        number += 1;
        //Loops till the next node is NULL and increments counter
        while (tempque->next)
        {
            number++;
            tempque = tempque->next;
        }
    }
    return number;
}

/// <summary>
/// Adds an "Airplane" object at the end of the specified queue (Linked list). It verifies if the airplane isn't already in the queue
/// </summary>
/// <param name="airplane">The "Airplane" object you want to add (You can use compound-designated (on-the-fly) initialization)</param>
/// <param name="airplaneQueue">The queue you want to add the airplane to</param>
/// <param name="request">The type of request of the airplane (landing/takeoff) (dependent on the queue)</param>
/// <returns>The head of the queue to which the airplane has been added (useful when creating first node)</returns>
AirplaneQueue* AddToAirplaneQueue(Airplane airplane, AirplaneQueue* airplaneQueue, Request request)
{
    AirplaneQueue* tempque = airplaneQueue;
    if(tempque != NULL) //checks if queue head is NULL
    {
        //loops until next node is NULL
        while (tempque->next)
        {
            if (tempque->airplane.airplaneID == airplane.airplaneID) //checks if airplane already exists
            {
                printf("Airplane is already in the queue\n");
                return airplaneQueue;
            }
            tempque = tempque->next;
        }
        if (tempque->airplane.airplaneID == airplane.airplaneID) //Checks if last node is NULL
        {
            printf("Airplane is already in the queue\n");
            return airplaneQueue;
        }
        //Handles failure of allocating memory
        if(!(tempque->next = (AirplaneQueue*)malloc(sizeof(AirplaneQueue))))
        {
            printf("Failed allocate memory for the airplane\n");
            return airplaneQueue;
        }
        tempque = tempque->next;
    }
    else
    {
        //Handles failure of allocating memory
        if(!(tempque = (AirplaneQueue*)malloc(sizeof(AirplaneQueue))))
        {
            printf("Failed allocate memory for the airplane\n");
            return airplaneQueue;
        }
        airplaneQueue = tempque; //assigns to return pointer to head of the queue
    }
    tempque->next = NULL;
    tempque->airplane = airplane;
    printf("Added airplane %d to %s queue.\n", airplane.airplaneID, request ? "landing" : "takeoff");
    return airplaneQueue;
}

/// <summary>
/// Removes an "Airplane" object from the specified queue (Linked list)
/// </summary>
/// <param name="airplaneID">The "Airplane" object you want to remove</param>
/// <param name="airplaneQueue">The queue you want to remove the airplane from</param>
/// <param name="request">The type of request of the airplane (landing/takeoff) (dependent on the queue)</param>
/// <returns>The head of the queue from which the airplane has been removed (useful when deleting the first node)</returns>
AirplaneQueue* RemoveFromAirplaneQueue(int airplaneID, AirplaneQueue* airplaneQueue, Request request)
{
    AirplaneQueue* tempque = airplaneQueue, *pretempque, *tempque2;
    if(tempque != NULL) //checks if queue head is NULL
    {
        while (tempque->next)
        {
            if (tempque->airplane.airplaneID == airplaneID) break; //breaks if airplane exists
            pretempque = tempque;
            tempque = tempque->next;
        }
        if (tempque->airplane.airplaneID != airplaneID && tempque->next == NULL) //checks if airplane exists after loop
        {
            printf("Airplane is not in the %s queue\n", request ? "landing" : "takeoff");
            return airplaneQueue;
        }
        if (tempque->airplane.airplaneID == airplaneQueue->airplane.airplaneID)
        {
            tempque2 = tempque->next;
            free(tempque); //removes airplane if request name matches head airplane's name
            printf("The airplane was removed from the %s queue.\n", request ? "landing" : "takeoff");
            return tempque2; //returns new head pointer of queue
        }
        else
        {
            pretempque->next = tempque->next;
            free(tempque); //removes airplane if request name matches head airplane's name
            printf("The airplane was removed from the %s queue.\n", request ? "landing" : "takeoff");
            return airplaneQueue;
        }
    }
    else
    {
        printf("Airplane is not in the %s queue as the %s queue is empty\n", request ? "landing" : "takeoff");
        return airplaneQueue;
    }
}

/// <summary>
/// Removes the "Airplane" object at the front of the specified queue
/// </summary>
/// <param name="airplaneQueue">The queue you want to remove the airplane from</param>
/// <param name="request">The type of request of the airplane (landing/takeoff) (dependent on the queue)</param>
/// <returns>The head of the queue from which the airplane has been removed (since the first node is being deleted)</returns>
AirplaneQueue* RemoveFromAirplaneQueueAtFront(AirplaneQueue* airplaneQueue, Request request)
{
    AirplaneQueue* tempque = airplaneQueue;
    AirplaneQueue* tempque2;
    if(tempque != NULL)
    {
        //Removes airplane at the front of the queue
        tempque2 = tempque->next;
        free(tempque);
        printf("The plane has %s\n", request ? "Landed" : "taken off");
    }
    //queue is empty
    else
    {
        tempque2 = tempque;
        printf("The %s queue is empty.\n", request ? "landing" : "takeoff");
    }
    return tempque2;
}

/// <summary>
/// Prints the specified airplane queue in a user-friendly manner
/// </summary>
/// <param name="airplaneQueue">The queue which has to be printed</param>
void PrintAirplaneQueue(AirplaneQueue* airplaneQueue)
{
    AirplaneQueue* tempque = airplaneQueue;
    if(!sizeOfQueue(airplaneQueue)) //If queue is empty
    {
        printf("is empty.\n");
        return;
    }
    printf("\n");
    while (tempque)
    {
        printf("/%d/-", tempque->airplane.airplaneID);
        tempque = tempque->next;
    }
    printf("///\n");
}

/// <summary>
/// Gets the position of an airplane in the specified queue
/// </summary>
/// <param name="airplaneID">The "Airplane" object whose position you want</param>
/// <param name="airplaneQueue">The queue from which you want to retrieve the airplane's position from</param>
/// <returns>Integer position of the airplane in the queue (-1 if position is not obtainable)</returns>
int GetAirplanePosition(int airplaneID, AirplaneQueue* airplaneQueue)
{
    AirplaneQueue* tempque = airplaneQueue;
    if(tempque != NULL)
    {
        int pos = 0;
        //increments position until airplane number matches and then return the position
        while (tempque->next)
        {
            if (tempque->airplane.airplaneID == airplaneID) return pos;
            pos++;
            tempque = tempque->next;
        }
        //returns -1 if airplane isn't found
        if (tempque->airplane.airplaneID != airplaneID && tempque->next == NULL) return -1;
        else return pos;
    }
    //returns -1 of the queue is empty
    else
    {
        return -1;
    }
}