#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pqueue.kyeung2.h"

StudentRecord *createStudent(char *name, int id) {
    StudentRecord *studentRec;
    studentRec = (StudentRecord *) malloc(sizeof(StudentRecord));
    studentRec->id = id;
    strcpy(studentRec->name, name);
    return studentRec;
}

void pqueueTests() {
    int minPriority;
    PQueueNode *pqueue = NULL;
    StudentRecord *studentRec;

    studentRec = createStudent("John", 67);
    enqueue(&pqueue, 3, studentRec);

    studentRec = createStudent("Brittany", 890);
    enqueue(&pqueue, 8, studentRec);

    studentRec = createStudent("Robert", 645);
    enqueue(&pqueue, 1, studentRec);

    studentRec = createStudent("Alice", 112);
    enqueue(&pqueue, 9, studentRec);

    studentRec = createStudent("Thomasina", 452);
    enqueue(&pqueue, 2, studentRec);

    studentRec = createStudent("Alfred", 516);
    enqueue(&pqueue, 12, studentRec);

    studentRec = createStudent("Margaret", 341);
    enqueue(&pqueue, 9, studentRec);

    studentRec = createStudent("Robert", 485);
    enqueue(&pqueue, 2, studentRec);

    studentRec = createStudent("Elizabeth", 734);
    enqueue(&pqueue, 1, studentRec);

//    printQueue(pqueue, printStudentRecord);
//
//    printf("--------------------------------------------------\n");
//    studentRec = peek(pqueue);
//    printf("peek: ");
//    printStudentRecord(studentRec);
//
//    studentRec = dequeue(&pqueue);
//    printf("dequeued: ");
//    printStudentRecord(studentRec);
//
//    studentRec = peek(pqueue);
//    printf("peek: ");
//    printStudentRecord(studentRec);
//
//    studentRec = dequeue(&pqueue);
//    printf("dequeued: ");
//    printStudentRecord(studentRec);
//
//    studentRec = peek(pqueue);
//    printf("peek: ");
//    printStudentRecord(studentRec);
//
//    printf("--------------------------------------------------\n");
//
//    studentRec = createStudent("David", 908);
//    enqueue(&pqueue, 1, studentRec);
//
//    studentRec = createStudent("Katherine", 267);
//    enqueue(&pqueue, 2, studentRec);
//
//    studentRec = createStudent("Andrew", 372);
//    enqueue(&pqueue, 20, studentRec);
//
//    printQueue(pqueue, printStudentRecord);
//
//    printf("--------------------------------------------------\n");
//
//    while (queueLength(pqueue) > 0) {
//        minPriority = getMinPriority(pqueue);
//        printf("min priority = %d\n", minPriority);
//        studentRec = dequeue(&pqueue);
//        printf("dequeued: ");
//        printStudentRecord(studentRec);
//    }
}

int main() { //no int for some reason in hibblers
    pqueueTests();
}
