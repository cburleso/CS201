//.h contains declarations and prototypes of methods and structures
#ifndef CS201_A3_PQUEUE_KYEUNG2_H
#define CS201_A3_PQUEUE_KYEUNG2_H

//Struct StudentData is defined, typeDef removed to fix storage error on Linux
typedef struct StudentRecord;
typedef struct PQueueStruct;

int enqueue(struct PQueueStruct **pqueue, int priority, void *data);

void *dequeue(struct PQueueStruct **pqueue);

void *peek(struct PQueueStruct *pqueue);

void printQueue(struct PQueueStruct *pqueue, void (printFunction)(void*));

int getMinPriority(struct PQueueStruct *pqueue);

int queueLength(struct PQueueStruct *pqueue);

void printStudentRecord(void *data);

#endif //CS201_A3_PQUEUE_KYEUNG2_H
