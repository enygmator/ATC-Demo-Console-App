/// <summary>
/// This enumerator specifies whether the queue process is takeoff / landing
/// </summary>
typedef enum Request
{
    TakeoffRequest, //0: takeoff
    LandingRequest  //1: Land
} Request;

/// <summary>
/// This structure represents an airplane. At the moment it only has an identification number.
/// </summary>
typedef struct Airplane
{    
    int airplaneID; //This variable identifies an airplane uniquely
} Airplane;