#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "pqueue.kyeung2.h"

//StudentListNodeStruct header added to fix storage error message on linux
typedef struct {
    int id;
    char name[32];
} StudentRecord;

typedef struct PQueueStruct {
    int priority;
    void *data;
    struct PQueueStruct *next;
} PQueueNode;

int enqueue(PQueueNode **pqueue, int priority, void *data) {
    /* This will put the data in the priority queue in the correct place.
     * If there is already one or more nodes in the list having the same
     * priority as the data that you are enqueueing, then put the new node
     * after all of the nodes having that priority. Return zero from this function. */
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
    if (pqueue != NULL){

        //Loops while currentNode is not empty
        while (currentNode != NULL){

            //Prints formatted result
            printf("Data in queue: ",currentNode->data, "\n");

            //Gets next node
            currentNode = currentNode->next;
        }
    } else
        printf("(queue is empty)\n");
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
    } else
        printf("(queue is empty)\n");

    return length;
}

void printStudentRecord(void *data) {
    /* Print an instance of StudentRecord as "%s %d", with the name ﬁeld and id ﬁeld.
     * Each priority-queue node will be a container for an instance of some other
     * data structure—this keeps the deﬁnition of the queue node independent of the speciﬁc data
     * that the queue node contains. The void* pointer can point to anything
     * it’s up to the user of the priority queue to cast the pointer to a pointer of the appropriate underlying data type. */

    //Creates temp node
    StudentRecord *nodeInstance = data;

    //Checks of node/list is empty
    if (nodeInstance != NULL){

        //Loops while node/list is not empty
        while (nodeInstance != NULL){

            //Prints formatted result
            printf("%d |%s| \n",nodeInstance->id, nodeInstance->name);
        }
    }

    else
        printf("(data is empty)\n");
}