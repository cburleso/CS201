#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pqueue.kyeung2.h"

// Moved structs to .h

// Enqueue takes data and puts it into the priority queue in order
int enqueue(PQueueNode **pqueue, int priority, void *data) {

    // Initialzes mainQueue/temp to hold all structs and priority
    PQueueNode *mainQueue;
    PQueueNode *temp;

    // Allocates memory for mainQueue
    mainQueue = (PQueueNode *) malloc(sizeof(mainQueue)); //allocates new node memory

    // Sets current priority
    mainQueue->priority = priority;
    mainQueue->data = data;

    // Conditional for if list is empty or if header priority > given priority
    if((*pqueue) == NULL || (*pqueue)->priority > mainQueue->priority){

        // Places list at end of mainQueue
        mainQueue->next = (*pqueue);

        //Sets list equal to mainQueue
        (*pqueue) = mainQueue;
    } else {
        //Creates temporary copy of list
        temp = (*pqueue);

        //Loops while list copy has nodes and their id < given id
        while(temp->next != NULL && temp->next->priority <= mainQueue->priority){  //changed < to <= incase multiple with same priorities

            //Gets next in temp list
            temp = temp->next;
        }

        //Places temp->next at end of student
        mainQueue->next = temp->next;

        //Sets temp equal to student
        temp->next = mainQueue;
    }

    return 0;
}

// Dequeue removes node at front of list
void *dequeue(PQueueNode **pqueue) {

    //Creates temp copy of *pqueue, and initialzes returnData
    PQueueNode* temp = *pqueue;
    StudentRecord* returnData;

    //If *pqueue is not empty, sets it to start at the next node and unlinks first, otherwise NULL
    if (*pqueue != NULL) {
        //Sets returnData to data of first node of temp
        returnData = temp->data;

        *pqueue = temp->next;
        return returnData;

        // If empty, nothing happens
    } else if (*pqueue == NULL){
        return NULL;
    }
}

// Peek returns data from the first node in the priority queue
void *peek(PQueueNode *pqueue) {

    // Creates temp copy of *pqueue, and initialzes returnData
    StudentRecord* returnData;

    // If *pqueue is not empty, sets it to start at the next node and unlinks first, otherwise NULL
    if (pqueue != NULL) {

        // Sets returnData to data of first node of temp
        returnData = pqueue->data;
        return returnData;

        // If empty nothing happens
    } else if (pqueue == NULL){
        return NULL;
    }
}

// Prints the data from each node in the priority  queue
void printQueue(PQueueNode *pqueue, void (printFunction)(void*)) {

    //Creates temp node
    PQueueNode *currentNode = pqueue;

    //Checks of list is empty
    if (pqueue == NULL) {
        printf("(queue is empty)\n");
    } else if (pqueue != NULL) {

        //Loops while currentNode is not empty
        while (currentNode != NULL) {

            // Prints node's priority
            printf("Priority: %d Data = ", currentNode->priority);

            //Calls printFunction with the node's data
            printFunction(currentNode->data);

            //Gets next node
            currentNode = currentNode->next;
        }
    }
}

// Returns the priority of the first node in pqueue
int getMinPriority(PQueueNode *pqueue) {

    // Creates temp value to hold priority
    int returnPriority;

    // If *pqueue is not empty, sets it to start at the next node and unlinks first, otherwise NULL
    if (pqueue != NULL) {

        // Sets returnData to priority of first node
         returnPriority = pqueue->priority;
        return returnPriority;

    } else if (pqueue == NULL){
        return -1;
    }
}

// Returns number of nodes in data
int queueLength(PQueueNode *pqueue) {

    // Creates iteration node and temp counter
    PQueueNode *currentNode = pqueue;
    int length = 0 ;

    // Checks of list is empty
    if (pqueue != NULL){

        // Loops while currentNode is not empty
        while (currentNode != NULL){
            length += 1;
            // Gets next node
            currentNode = currentNode->next;
        }
    }
    return length;
}

//Prints data as an instance of Student record with name and id
void printStudentRecord(void *data) {

    //Creates temp node
    StudentRecord *nodeInstance = (StudentRecord*) data;

    //Prints formatted data from temp node
    printf("%s %d \n",nodeInstance->name, nodeInstance->id);

}