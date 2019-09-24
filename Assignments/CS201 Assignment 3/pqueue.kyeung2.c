#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pqueue.kyeung2.h"

////MOVED STRUCTS TO .h

int enqueue(PQueueNode **pqueue, int priority, void *data) {
    /* This will put the data in the priority queue in the correct place.
     * If there is already one or more nodes in the list having the same
     * priority as the data that you are enqueueing, then put the new node
     * after all of the nodes having that priority. Return zero from this function. */

    //initialzes pqueue to hold all structs and priority
    PQueueNode *mainQueue;
    PQueueNode *temp;

    mainQueue = (PQueueNode *) malloc(sizeof(mainQueue)); //allocates new node memory

    //sets current priority
    mainQueue->priority = priority;
    mainQueue->data = data;

    //Conditional for if list is empty or if header id > given id
    if((*pqueue) == NULL || (*pqueue)->priority > mainQueue->priority){

        //Places list at end of mainQueue
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

void *dequeue(PQueueNode **pqueue) {
    /* Remove the front of the list and return the data from that list node
     * (not the list node itself). If the pqueue is empty, then return NULL. */

    //Creates temp copy of *pqueue, and initialzes returnData
    PQueueNode* temp = *pqueue;
    StudentRecord* returnData;

    //If *pqueue is not empty, sets it to start at the next node and unlinks first, otherwise NULL
    if (*pqueue != NULL) {
        //Sets returnData to data of first node of temp
        returnData = temp->data;

        *pqueue = temp->next;
        return returnData;

    } else if (*pqueue == NULL){
        return NULL;
    }
}
//
void *peek(PQueueNode *pqueue) {
    /* Return the data from the ﬁrst node in the pqueue (not the node itself).
     * If the pqueue is empty, then return NULL. The peek operation does not actually remove a node from the pqueue! */

    //Creates temp copy of *pqueue, and initialzes returnData
    StudentRecord* returnData;

    //If *pqueue is not empty, sets it to start at the next node and unlinks first, otherwise NULL
    if (pqueue != NULL) {

        //Sets returnData to data of first node of temp
        returnData = pqueue->data;
        return returnData;

    } else if (pqueue == NULL){
        return NULL;
    }
}

void printQueue(PQueueNode *pqueue, void (printFunction)(void*)) {
    // Print the data from each node in the queue.

    //Creates temp node
    PQueueNode *currentNode = pqueue;

    //Checks of list is empty
    if (pqueue == NULL) {
        printf("(queue is empty)\n");
    } else if (pqueue != NULL) {
        //Loops while currentNode is not empty

        while (currentNode != NULL) {
            printf("Priority: %d Data = ", currentNode->priority); //TODO CAUSES ERRORS...

            printFunction(currentNode->data);

            //Gets next node
            currentNode = currentNode->next;
        }
    }
}

int getMinPriority(PQueueNode *pqueue) {
    // Return the priority of the ﬁrst node in the pqueue. If the pqueue is empty, return -1

    //Creates temp value to hold priority
    int returnPriority;

    //If *pqueue is not empty, sets it to start at the next node and unlinks first, otherwise NULL
    if (pqueue != NULL) {

        //Sets returnData to priority of first node
         returnPriority = pqueue->priority;
        return returnPriority;

    } else if (pqueue == NULL){
        return -1;
    }
}

int queueLength(PQueueNode *pqueue) {
    //REturn number of nodes in pqueue

    //Creates iteration node and temp counter
    PQueueNode *currentNode = pqueue;
    int length = 0 ;

    //Checks of list is empty
    if (pqueue != NULL){

        //Loops while currentNode is not empty
        while (currentNode != NULL){
            length += 1;
            //Gets next node
            currentNode = currentNode->next;
        }
    }
    return length;
}

void printStudentRecord(void *data) {
    /* Print an instance of StudentRecord as "%s %d", with the name ﬁeld and id ﬁeld.
     * Each priority-queue node will be a container for an instance of some other
     * data structure—this keeps the deﬁnition of the queue node independent of the speciﬁc data
     * that the queue node contains. The void* pointer can point to anything
     * it’s up to the user of the priority queue to cast the pointer to a pointer of the appropriate underlying data type. */

    //Creates temp node
    StudentRecord *nodeInstance = (StudentRecord*) data;

    printf("%s %d \n",nodeInstance->name, nodeInstance->id);

}