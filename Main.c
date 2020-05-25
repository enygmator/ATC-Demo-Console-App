#include"ATCDashboard.h"

/// <summary>
/// Prints the menu of commands that can be executed by the ATC as required
/// </summary>
void PrintMenu()
{
    printf("Enter you choice from the following:\n");
    printf("t - takeoff\nl - land\n1 - request to take off\n2 - request to land\n3 - Add airplane to takeoff queue\n"
    "4 - Add airplane to land queue\n5 - remove airplane from takeoff queue\n6 - remove airplane from landing queue\n"
    "7 - Print Takeoff hold pattern\n8 - Print Landing hold pattern\n"
    "r - restart ATC\ne - Exit\nm - show this menu\n");
}

void main(void)
{
    printf("Welcome to the airplane/ATC simulation\nStarting the ATC...\n");
    ATCStart();
    printf("The ATC has been started.\n");
    char choice = 'r'; //User choice of command
    PrintMenu();
    //Following lines of code execute commands the way the user wants them to be executed
    //by storing choice (input) in a variable
    while (choice != 'e')
    {
        int airplaneID = 0; //Variable input for addition of new airplane to ATC's radar
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 't': //Takeoff (service head of takeoff queue)
            Takeoff();
            break;
        case 'l': //Land (service head of land queue)
            Land();
            break;
        case '1': //Get the status of airplane in takeoff queue (position of airplane and how long it has to wait in queue)
            printf("Request To Takeoff: Enter the airplane ID: ");
            scanf("%d", &airplaneID); //airplane ID to query
            RequestToTakeoff(airplaneID);
            break;
        case '2': //Get the status of airplane in Land queue (position of airplane and how long it has to wait in queue)
            printf("Request To Land: Enter the airplane ID: ");
            scanf("%d", &airplaneID); //airplane ID to query
            RequestToLand(airplaneID);
            break;
        case '3': //Add airplane to takeoff queue at end
            printf("Enter the airplane ID to add to takeoff queue: ");
            scanf("%d", &airplaneID); //get which airplane to add
            AddAirplaneToTakeoffQueue((Airplane){airplaneID});
            break;
        case '4': //Add airplane to Land queue at end
            printf("Enter the airplane ID to add to landing queue: ");
            scanf("%d", &airplaneID); //get which airplane to add
            AddAirplaneToLandQueue((Airplane){airplaneID});
            break;
        case '5': //Remove airplane from takeoff queue at any point in queue (including at the head)
            printf("Enter the airplane ID to remove from takeoff queue: ");
            scanf("%d", &airplaneID); //get which airplane to remove
            ExitTakeoffQueue(airplaneID);
            break;
        case '6': //Remove airplane from landing queue at any point in queue (including at the head)
            printf("Enter the airplane ID to remove from landing queue: ");
            scanf("%d", &airplaneID); //get which airplane to remove
            ExitLandQueue(airplaneID);
            break;        
        case '7': //Print the takeoff hold pattern (takeoff queue)
            PrintTakeoffHoldPattern();
            break;
        case '8': //Print the landing hold pattern (land queue)
            PrintLandingHoldPattern();
            break;
        case 'r': //Restart the ATC (clear all queues and free up useless memory)
            printf("ATC will restart: ");
            ATCStart();
            break;
        case 'e': //Exit the program
            break;
        case 'm': //prints the ATC commands menu
            PrintMenu();
            break;
        default:
            break;
        }
    }    
    return;
}