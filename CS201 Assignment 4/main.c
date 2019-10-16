#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "pqueue.kyeung2.h"

typedef enum EventTypeEnum { //given enum
    PROCESS_SUBMITTED,
    PROCESS_STARTS,
    PROCESS_ENDS,
    PROCESS_TIMESLICE_EXPIRES //CREATED TO MATCH GIVEN ENUM
} EventType;

typedef struct { //given struct
    int pid; //unique id
    int burstTime;  // time process needs to complete
    int waitTime;   // time process has been waiting
    int numPreemptions; //used for round robin, is number of times process was paused
    int lastTime; // tracks specific value of currentTime, currentTime - process ->lastTime
} Process;

typedef struct { //given struct
    EventType eventType;
    Process *process;
} Event;

// Create new array of processes
Process processArray[5];

int NUM_PROCESSES = 5;

// Process queue
PQueueNode *ProcessQueue = NULL;
PQueueNode *eventQueue = NULL;

// Current time variable
int currentTime = 0;

int waitTime, totalWaitTime;

bool machineBusy = false;

const char* stringEventType(EventType type){
    switch (type)
    {
        case PROCESS_SUBMITTED: return "PROCESS_SUBMITTED";
        case PROCESS_STARTS: return "PROCESS_STARTS";
        case PROCESS_ENDS: return "PROCESS_ENDS";
        case PROCESS_TIMESLICE_EXPIRES: return "PROCESS_TIMESLICE_EXPIRES";
    }
}

Process *createProcesses(){ //creates the 5 processes from table, return in array

    Process *processOne;
    processOne = (Process *) malloc(sizeof(Process)); // Create process one
    processOne->pid = 1;
    processOne->burstTime = 6;
    processArray[0] = *processOne;

    Process *processTwo;
    processTwo = (Process *) malloc(sizeof(Process)); // Create process two
    processTwo->pid = 2;
    processTwo->burstTime = 7;
    processArray[1] = *processTwo;

    Process *processThree;
    processThree = (Process *) malloc(sizeof(Process)); // Create process three
    processThree->pid = 3;
    processThree->burstTime = 2;
    processArray[2] = *processThree;

    Process *processFour;
    processFour = (Process *) malloc(sizeof(Process)); // Create process four
    processFour->pid = 4;
    processFour->burstTime = 5;
    processArray[3] = *processFour;

    Process *processFive;
    processFive = (Process *) malloc(sizeof(Process)); // Create process five
    processFive->pid = 5;
    processFive->burstTime = 2;
    processArray[4] = *processFive;

//    printf("here is the event queue after creating 5 things\n");
//    printf(processArray);
//    printf("\n");

    return processArray;
}

//enqueues processes in event queue at given time specified
void enqueueProcesses(PQueueNode **eventPQueue, Process *processes, int numProcesses){
    int startTimes[] = {0, 3, 4, 6, 6}; // Start times of processes 1 - 5
    for (int i = 0; i < numProcesses; i++){
        Event *newEvent;
        newEvent = (Event *) malloc(sizeof(Event));
        newEvent->eventType = PROCESS_SUBMITTED;
        newEvent->process = &processes[i];
        enqueue(eventPQueue, startTimes[i], newEvent); // Enqueue new Event (pointing to current process)
    }
}

//void printEvent(void *data) {
//    Process *process;
//    Event *event;
//    event = (Event *) data;
//    process = event->process;
//    if (event->eventType == PROCESS_ENDS)
//        printf("t = %d   %s  pid = %d  waitTime = %d\n", currentTime, stringEventType(event->eventType), process->pid,
//               process->waitTime);
//    else {
//        printf("t = %d   %s  pid = %d\n", currentTime, stringEventType(event->eventType), process->pid);
//    }
//}

void runSimulation(int schedulerType, int quantum, PQueueNode *eventPQueue) {
    // runs the simulation, prints out info about event/process... see assignment output
    int ignore = quantum;

    // FCFS
    if (schedulerType == 1){
        currentTime = getMinPriority(eventPQueue);
        Event *event = dequeue(&eventPQueue);
        while (event != NULL){
            Process *process = event->process;
            if (event->eventType == PROCESS_SUBMITTED){
                printf("t = %d   %s  pid = %d\n", currentTime, stringEventType(event->eventType), process->pid);
                process->lastTime = currentTime;
                if (!machineBusy){
                    Event *newEvent = (Event *) malloc(sizeof(Event));
                    newEvent->eventType = PROCESS_STARTS;
                    newEvent->process = process;
                    enqueue(&eventPQueue, currentTime, newEvent);
                    machineBusy = true;
                } else {
                    enqueue(&ProcessQueue, process->burstTime, process);
                }

            } else if (event->eventType == PROCESS_STARTS){
                printf("t = %d   %s  pid = %d\n", currentTime, stringEventType(event->eventType), process->pid);
                waitTime = currentTime - process->lastTime;
                totalWaitTime += waitTime;
                process->waitTime = waitTime;
                Event *newEvent = (Event *) malloc(sizeof(Event));
                newEvent->eventType = PROCESS_ENDS;
                newEvent->process = process;
                enqueue(&eventPQueue, currentTime + process->burstTime, newEvent);

            } else if (event->eventType == PROCESS_ENDS){
                printf("t = %d   %s  pid = %d  waitTime = %d\n", currentTime, stringEventType(event->eventType),
                       process->pid,
                       process->waitTime);
                totalWaitTime += process->waitTime;//////////
                if (queueLength(ProcessQueue) > 0){
                    process = dequeue(&ProcessQueue);
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

    // FCFS
    if (schedulerType == 2){
        currentTime = getMinPriority(eventPQueue);
        Event *event = dequeue(&eventPQueue);
        while (event != NULL){
            Process *process = event->process;
            if (event->eventType == PROCESS_SUBMITTED){
                printf("t = %d   %s  pid = %d\n", currentTime, stringEventType(event->eventType), process->pid);
                process->lastTime = currentTime;
                if (!machineBusy){
                    Event *newEvent = (Event *) malloc(sizeof(Event));
                    newEvent->eventType = PROCESS_STARTS;
                    newEvent->process = process;
                    enqueue(&eventPQueue, currentTime, newEvent);
                    machineBusy = true;
                } else {
                    enqueue(&ProcessQueue, 0, process);
                }

            } else if (event->eventType == PROCESS_STARTS){
                printf("t = %d   %s  pid = %d\n", currentTime, stringEventType(event->eventType), process->pid);
                waitTime = currentTime - process->lastTime;
                totalWaitTime += waitTime;
                process->waitTime = waitTime;
                Event *newEvent = (Event *) malloc(sizeof(Event));
                newEvent->eventType = PROCESS_ENDS;
                newEvent->process = process;
                enqueue(&eventPQueue, currentTime + process->burstTime, newEvent);

            } else if (event->eventType == PROCESS_ENDS){
                printf("t = %d   %s  pid = %d  waitTime = %d\n", currentTime, stringEventType(event->eventType),
                       process->pid,
                       process->waitTime);

                totalWaitTime += process->waitTime;//////////

                if (queueLength(ProcessQueue) > 0){
                    process = dequeue(&ProcessQueue);
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

    //fcfs use 1
    printf("FCFS\n");
    totalWaitTime = 0;
    enqueueProcesses(&eventQueue, &processArray[0], NUM_PROCESSES);
    runSimulation(2, 0, eventQueue);
    eventQueue = NULL;
    printf("\n mean wait time: %d", totalWaitTime/(NUM_PROCESSES*2));


    //sjf use 2
    printf("\nSJF\n");
    totalWaitTime = 0;
    enqueueProcesses(&eventQueue, &processArray[0], NUM_PROCESSES);
    runSimulation(1, 0, eventQueue);
    printf("\n mean wait time: %d", totalWaitTime/(NUM_PROCESSES*2));

    return(0);
}