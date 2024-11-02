#include "mbed.h"

DigitalOut led(LED1); // LED for visual feedback

#define STACK_SIZE 4 // Size of the stack (4 elements)
int stack[STACK_SIZE]; // Stack array
int top = 0; // Stack pointer

void push(int value) {
    if (top >= STACK_SIZE) {
        
    // Handle stack full case
    }
    	// Push value onto stack and increment top
        stack[top] = value;     //Insert the value into top 
        top++;                  //increment the top variable 
}

int pop() {
    if (top <= 0) {
        
    // Handle stack empty case
    }
    // Decrement top and return the value
    int value = stack[top]; //Send the top stack value to value.
    top--;                  //decremnet top
    return value;           //return value. 
}

void display_top() {
    if (top <= 0) {
        
// Handle stack empty case
    }
    // Display the top value
    printf("top value is %d \n", top);
}

int main() {
    push(10);				// Push first value
    push(20);				// Push second value
    display_top(); 	        // Display top value after pushing
    pop();				    // Pop the top value
    display_top(); 	        // Display new top value after popping

    while (1) {
        led = !led; // Blink LED
        wait_us(500000); // Wait half a second
    }
}
