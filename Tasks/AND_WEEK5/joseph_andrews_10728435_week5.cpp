#include "uop_msb.h"
#include "mbed.h"
using namespace uop_msb;

// Define pins
    // Temperature sensor input (A0)
    AnalogIn objTemp(A0);
    // PWM output for LED (choose any pin)
    PwmOut ledlight(TRAF_GRN2_PIN);


int main() {
           // 100 ms polling interval
           ledlight.period(0.1f); //100ms
           ledlight.write(0.0); //Sets LED to 100% brightness. 
           // Variable to store the temperature
           double dTemp;
           // Variable to store the LED brightness (PWM duty cycle)
           float fBrightness;
    
    while (true) {
        // Step 1: Read the analog input from the temperature sensor
        // Read analog value (0.0 to 1.0)
        dTemp = objTemp.read();
        // Step 2: Convert the analog reading to temperature in degrees Celsius
        // Convert to temperature (0°C to 100°C)
        dTemp *= 100.0; //Normalises the signal between 0 and 100
        // Step 3: Adjust the brightness of the LED based on the temperature
        // Scale brightness proportionally between 20°C and 40°C
        float fMinT = 20.0;
        float fMaxT = 40.0;
        float fMinB = 0.0;
        float fMaxB = 1.0;

        //Sets the brightness based on range of temperature
        if (dTemp < 20.0) {
            fBrightness = 0.0;
        } else if (dTemp > 40.0) {
            fBrightness = 1.0;
        } else {
            fBrightness = fMinB + (fMinT - dTemp) * (fMaxB - fMinB) / (fMaxT - fMinT);
        }

        // Step 4: Set the PWM duty cycle to control LED brightness
        // Set LED brightness (0.0 = off, 1.0 = fully on)
        ledlight.write(fBrightness);

        // Step 5: Wait for the polling interval (100 ms)
        wait_us(100000);
    }
}
