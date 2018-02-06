//
//  filter.c
//  Milestone 3 Task 1 Filters
//
//  Created by Grant Rowberry on 2/3/18.
//  Copyright © 2018 Grant Rowberry. All rights reserved.
//

#include "filter.h"
#include <stdio.h>

#define FILTER_IIR_FILTER_COUNT 10 //There are 10 IIR Filters
#define IIR_A_COEFFICIENT_COUNT 11 //There are 11 A coefficients for the IIR filters
#define Z_QUEUE_SIZE IIR_A_COEFFICIENT_COUNT //The Z Queue needs to be the same length as how many A Coeffs there are
#define
#define X_QUEUE_SIZE


//xQueue
static queue_t xQueue;

//yQueue
static queue_t yQueue;

//Array of zQueues
static queue_t zQueue[FILTER_IIR_FILTER_COUNT];



//********************HELPER FUNCTIONS***********************//

//Initializes the X Queue
void initXQueue(){
    
    //Initializes queue
    queue_init(&xQueue, )
    
}

///Initializes the Y Queue
void initYQueue(){
    
}

//Initilizes the Z Queues
void initZQueues() {
    
    //Loops through all the filters
    for (uint32_t i=0; i<FILTER_IIR_FILTER_COUNT; i++) {
        
        //Makes a string
        char* name;
        
        //Puts a string into name
        sprintf(name, "Filter %d", i);
        
        //Initializes a queue
        queue_init(&(zQueue[i]), Z_QUEUE_SIZE, name);
        
        //Loops through the queue
        for (uint32_t j=0; j<Z_QUEUE_SIZE; j++)
            
            //Pushes a zero to the queue
            queue_overwritePush(&(zQueue[i]), 0.0);
    }
}


//Initializes the output queues
void initOutputQueues(){
    
}

//********************MAIN FUNCTIONS***********************//


// Must call this prior to using any filter functions.
void filter_init() {
    // Init queues and fill them with 0s.
    initXQueue();  // Call queue_init() on xQueue and fill it with zeros.
    initYQueue();  // Call queue_init() on yQueue and fill it with zeros.
    initZQueues(); // Call queue_init() on all of the zQueues and fill each z queue with zeros.
    initOutputQueues();  // Call queue_init() all of the outputQueues and fill each outputQueue with zeros.
    
}

// Use this to copy an input into the input queue of the FIR-filter (xQueue).
void filter_addNewInput(double x);

// Fills a queue with the given fillValue. For example,
// if the queue is of size 10, and the fillValue = 1.0,
// after executing this function, the queue will contain 10 values
// all of them 1.0.
void filter_fillQueue(queue_t* q, double fillValue);

// Invokes the FIR-filter. Input is contents of xQueue.
// Output is returned and is also pushed on to yQueue.
double filter_firFilter();

// Use this to invoke a single iir filter. Input comes from yQueue.
// Output is returned and is also pushed onto zQueue[filterNumber].
double filter_iirFilter(uint16_t filterNumber);

// Use this to compute the power for values contained in an outputQueue.
// If force == true, then recompute power by using all values in the outputQueue.
// This option is necessary so that you can correctly compute power values the first time.
// After that, you can incrementally compute power values by:
// 1. Keeping track of the power computed in a previous run, call this prev-power.
// 2. Keeping track of the oldest outputQueue value used in a previous run, call this oldest-value.
// 3. Get the newest value from the power queue, call this newest-value.
// 4. Compute new power as: prev-power - (oldest-value * oldest-value) + (newest-value * newest-value).
// Note that this function will probably need an array to keep track of these values for each
// of the 10 output queues.
double filter_computePower(uint16_t filterNumber, bool forceComputeFromScratch, bool debugPrint);

// Returns the last-computed output power value for the IIR filter [filterNumber].
double filter_getCurrentPowerValue(uint16_t filterNumber);

// Get a copy of the current power values.
// This function copies the already computed values into a previously-declared array
// so that they can be accessed from outside the filter software by the detector.
// Remember that when you pass an array into a C function, changes to the array within
// that function are reflected in the returned array.
void filter_getCurrentPowerValues(double powerValues[]);

// Using the previously-computed power values that are current stored in currentPowerValue[] array,
// Copy these values into the normalizedArray[] argument and then normalize them by dividing
// all of the values in normalizedArray by the maximum power value contained in currentPowerValue[].
void filter_getNormalizedPowerValues(double normalizedArray[], uint16_t* indexOfMaxValue);
