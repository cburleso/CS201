//.h contains declarations and prototypes of methods and structures
#ifndef CS201_A3_PQUEUE_KYEUNG2_H
#define CS201_A3_PQUEUE_KYEUNG2_H

//Struct StudentData is defined, typeDef removed to fix storage error on Linux

// Struct for priority queue
typedef struct PQueueStruct {
    int priority;
    void *data;
    struct PQueueStruct *next;
} PQueueNode;

// Struct for studentRecord
typedef struct{
    int id;
    char name[32];
} StudentRecord;

// Enqueue takes data and puts it into the priority queue in order
int enqueue(struct PQueueStruct **pqueue, int priority, void *data);

// Dequeue removes node at front of list
void *dequeue(struct PQueueStruct **pqueue);

// Peek returns data from the first node in the priority queue
void *peek(struct PQueueStruct *pqueue);

// Prints the data from each node in the priority  queue
void printQueue(struct PQueueStruct *pqueue, void (printFunction)(void*));

// Returns the priority of the first node in pqueue
int getMinPriority(struct PQueueStruct *pqueue);

// Returns number of nodes in data
int queueLength(struct PQueueStruct *pqueue);

//Prints data as an instance of Student record with name and id
void printStudentRecord(void *data);

#endif //CS201_A3_PQUEUE_KYEUNG2_H
