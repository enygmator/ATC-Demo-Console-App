#include"Airplanes.h"
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

/// <summary>
/// This Structure is a node of the queue (Linked list) of type Airplane
/// </summary>
typedef struct AirplaneQueue
{
    Airplane airplane;  //The "Airplane" object of the node of the queue
    struct AirplaneQueue* next; //Link to the next node of the Linked List queue
} AirplaneQueue;

void TraverseAndFreeTillEndOfQueue(AirplaneQueue* airplaneQueue);
int sizeOfQueue(AirplaneQueue* airplaneQueue);
AirplaneQueue* AddToAirplaneQueue(Airplane airplane, AirplaneQueue* airplaneQueue, Request request);
AirplaneQueue* RemoveFromAirplaneQueue(int airplaneID, AirplaneQueue* airplaneQueue, Request request);
AirplaneQueue* RemoveFromAirplaneQueueAtFront(AirplaneQueue* airplaneQueue, Request request);
void PrintAirplaneQueue(AirplaneQueue* airplaneQueue);
int GetAirplanePosition(int airplaneID, AirplaneQueue* airplaneQueue);