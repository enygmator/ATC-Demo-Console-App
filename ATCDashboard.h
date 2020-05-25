#include"AirplaneQueue.h"

void ATCStart();

void AddAirplaneToLandQueue(Airplane airplane);
void RequestToLand(int airplaneID);
void ExitLandQueue(int airplaneID);
void Land();

void AddAirplaneToTakeoffQueue(Airplane airplane);
void RequestToTakeoff(int airplaneID);
void ExitTakeoffQueue(int airplaneID);
void Takeoff();

void PrintLandingHoldPattern();
void PrintTakeoffHoldPattern();