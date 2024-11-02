#ifndef __TRAFFICLIGHT__
#define __TRAFFICLIGHT__

#include "mbed.h"
using namespace chrono;

#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2

class TrafficLight 
{
    public:
    typedef enum {STOP, READY, GO, WARNING} LIGHT_STATE;

    private:
    DigitalOut redLED;
    DigitalOut yellowLED;
    DigitalOut greenLED;
    Ticker t;
    LIGHT_STATE State;
    std::chrono::microseconds TickerTime;

    void yellowFlashISR();
    void flashYellow(bool flash);
    void updateOutput();

    public:
    //Constructor
    TrafficLight(PinName redPin = TRAF_RED1_PIN, PinName yellowPin = TRAF_YEL1_PIN, PinName greenPin=TRAF_GRN1_PIN); 

    //Destructor
    ~TrafficLight();

    //Advance the traffic lights to the next state
    LIGHT_STATE nextState();

    //Stops the sigal and resets the lights to red.
    void stop();

    //Sets the speed of the flasher. 
    void SetFlashSpeed(std::chrono::microseconds FlashTime);

    //Gets the speed of the flasher. 
    void GetFlashSpeed();

};


#endif