// Kevin Yeung CS201 October 21, 2019

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#include "pqueue.kyeung2.h"
#include "pqueue.jhibbele.h"

// ******* INITIALIZATION OF STRUCTS/ENUMS ******* //
typedef enum EventTypeEnum {
    PROCESS_SUBMITTED,
    PROCESS_STARTS,
    PROCESS_ENDS,
    PROCESS_TIMESLICE_EXPIRES
} EventType;

typedef struct {
    int pid;
    int burstTime;
    int waitTime;
    int numPreemptions;
    int lastTime;
} Process;

typedef struct {
    EventType eventType;
    Process *process;
} Event;

// ******* INITIALIZATION OF VARIABLES/OBJS ******* //
// Numeric value initialization for calculations
int NUM_PROCESSES = 5;

int SJF = 1;
int FCFS = 2;
int RR = 3;

int currentTime, waitTime, totalWaitTime, i  = 0;

// Boolean for busy state checking
bool machineBusy = false;

// Creates queues for process/events
PQueueNode *processQueue = NULL;
PQueueNode *eventQueue = NULL;

// Creates array for processes
Process processArray[5];

// ******* METHOD DECLARATIONS ******* //
// Method creates and inserts processes into array
Process *createProcesses(){

    // Creates obj tempProcess and allocates space
    Process *tempProcess;
    tempProcess = (Process *) malloc(sizeof(Process));

    // Puts data into tempProcess and adds it to array
    tempProcess->pid = 1;
    tempProcess->burstTime = 6;
    processArray[0] = *tempProcess;

    tempProcess->pid = 2;
    tempProcess->burstTime = 7;
    processArray[1] = *tempProcess;

    tempProcess->pid = 3;
    tempProcess->burstTime = 2;
    processArray[2] = *tempProcess;

    tempProcess->pid = 4;
    tempProcess->burstTime = 5;
    processArray[3] = *tempProcess;

    tempProcess->pid = 5;
    tempProcess->burstTime = 2;
    processArray[4] = *tempProcess;

    // Array of processes returned
    return processArray;
}

// Method enqueues processes with given times
void enqueueProcesses(PQueueNode **eventPQueue, Process *processes, int numProcesses){

    // Given start times for jobs
    int processStartTimes[] = {0, 3, 4, 6, 6};

    // Iterates for all processes and enqueues new event which points to the current process
    for (i = 0; i < numProcesses; i += 1) {

        // Creates event object and allocates space
        Event *tempEvent;
        tempEvent = (Event *) malloc(sizeof(Event));

        // Sets data for event and enqueus it with start time
        tempEvent->eventType = PROCESS_SUBMITTED;
        tempEvent->process = &processes[i];
        enqueue(eventPQueue, processStartTimes[i], tempEvent);
    }
}

// Method converts enum cases to string
const char* toString(EventType input){
    switch (input) {
        case PROCESS_SUBMITTED: return "PROCESS_SUBMITTED";
        case PROCESS_STARTS: return "PROCESS_STARTS";
        case PROCESS_ENDS: return "PROCESS_ENDS";
        case PROCESS_TIMESLICE_EXPIRES: return "PROCESS_TIMESLICE_EXPIRES";
    }
}

// Method runs a simulation of processes and displays info. Output should match given results
void runSimulation(int mode, int quantum, PQueueNode *eventPQueue) {
    
    // Conditional checks for FSFS or SJF selection
    if (mode == 1) {
        // sets currentTime as returned value from pqueue method
        currentTime = getMinPriority(eventPQueue);

        // Creates object event as popped item from PQueue
        Event *event = dequeue(&eventPQueue);

        // Iterates while the current event contains data
        while (event != NULL){

            // Creates process object from event
            Process *process = event->process;

            // Conditional checks if the eventType given is equal to the submitted job
            if (event->eventType == PROCESS_SUBMITTED){
                printf("t = %d   %s  pid = %d\n", currentTime, toString(event->eventType), process->pid);
                process->lastTime = currentTime;

                // Conditional checks if machine is busy
                if (!machineBusy){

                    // Creates an new event, allocates memory, and sets data
                    Event *newEvent = (Event *) malloc(sizeof(Event));
                    newEvent->eventType = PROCESS_STARTS;
                    newEvent->process = process;

                    // Adds event to the queue with the current time and changes machine state
                    enqueue(&eventPQueue, currentTime, newEvent);
                    machineBusy = true;
                } else {
                    // Adds process to job queue
                    enqueue(&processQueue, process->burstTime, process);
                }

            }

            // Otherwise if the event matches process start
            else if (event->eventType == PROCESS_STARTS){

                // Display process and current time
                printf("t = %d   %s  pid = %d\n", currentTime, toString(event->eventType), process->pid);

                // Calculate process wait time and updates total wait
                waitTime = currentTime - process->lastTime;
                totalWaitTime += waitTime;

                // Updates process wait
                process->waitTime = waitTime;

                // Creates event, allocates space, and updates before adding it to event queue
                Event *newEvent = (Event *) malloc(sizeof(Event));
                newEvent->eventType = PROCESS_ENDS;
                newEvent->process = process;
                enqueue(&eventPQueue, currentTime + process->burstTime, newEvent);

            }

            // Checks if event is process end
            else if (event->eventType == PROCESS_ENDS){

                // Prints result and updates wait time
                printf("t = %d   %s  pid = %d  waitTime = %d\n", currentTime, toString(event->eventType), process->pid, process->waitTime);
                totalWaitTime += process->waitTime;

                // Conditional checks if queue is empty
                if (queueLength(processQueue) > 0){

                    // Dequeues next process and creates event to update status
                    process = dequeue(&processQueue);
                    Event *newEvent = (Event *) malloc(sizeof(Event));
                    newEvent->eventType = PROCESS_STARTS;
                    newEvent->process = process;
                    enqueue(&eventPQueue, currentTime, newEvent);
                } else {
                    // Updates machine state if no jobs are running
                    machineBusy = false;
                }
            }

            // Updates current time and event
            currentTime = getMinPriority(eventPQueue);
            event = dequeue(&eventPQueue);
        }
    }

    // Second mode is similar to first but runs shortest jobs first
    if (mode == 2){
        currentTime = getMinPriority(eventPQueue);
        Event *event = dequeue(&eventPQueue);

        while (event != NULL){
            Process *process = event->process;

            if (event->eventType == PROCESS_SUBMITTED){
                printf("t = %d   %s  pid = %d\n", currentTime, toString(event->eventType), process->pid);
                process->lastTime = currentTime;

                if (!machineBusy){
                    Event *newEvent = (Event *) malloc(sizeof(Event));
                    newEvent->eventType = PROCESS_STARTS;
                    newEvent->process = process;

                    enqueue(&eventPQueue, currentTime, newEvent);
                    machineBusy = true;
                } else {
                    enqueue(&processQueue, 0, process);
                }

            } else if (event->eventType == PROCESS_STARTS){
                printf("t = %d   %s  pid = %d\n", currentTime, toString(event->eventType), process->pid);

                waitTime = currentTime - process->lastTime;
                totalWaitTime += waitTime;
                process->waitTime = waitTime;

                Event *newEvent = (Event *) malloc(sizeof(Event));
                newEvent->eventType = PROCESS_ENDS;
                newEvent->process = process;

                enqueue(&eventPQueue, currentTime + process->burstTime, newEvent);

            } else if (event->eventType == PROCESS_ENDS){
                printf("t = %d   %s  pid = %d  waitTime = %d\n", currentTime, toString(event->eventType),
                       process->pid,
                       process->waitTime);

                totalWaitTime += process->waitTime;

                if (queueLength(processQueue) > 0){
                    process = dequeue(&processQueue);

                    Event *newEvent = (Event *) malloc(sizeof(Event));
                    newEvent->eventType = PROCESS_STARTS;
                    newEvent->process = process;

                    enqueue(&eventPQueue, currentTime, newEvent);
                } else {
                    machineBusy = false;
                }
            }
            currentTime = getMinPriority(eventPQueue);
            event = dequeue(&eventPQueue);
        }
    }
}

int main(int argc, char *argv[]) {
    createProcesses();

    // FCFS test
    printf("FCFS\n");

    // Processes are added to queue
    enqueueProcesses(&eventQueue, &processArray[0], NUM_PROCESSES);

    // Simulates FCFS (2) with jobs
    runSimulation(FCFS, 0, eventQueue);

    // Calculate and displays mean wait time
    printf("\nmean wait time: %d\n", totalWaitTime/(NUM_PROCESSES*2));

    // Resets eventQueue and totalWaitTime for next test
    eventQueue = NULL;
    totalWaitTime = 0;

    // FCFS test
    printf("\nSJF\n");
    enqueueProcesses(&eventQueue, &processArray[0], NUM_PROCESSES);
    runSimulation(SJF, 0, eventQueue);
    printf("\nmean wait time: %d\n", totalWaitTime/(NUM_PROCESSES*2));

    return(0);
}