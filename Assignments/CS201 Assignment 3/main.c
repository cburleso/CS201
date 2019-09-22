#include <stdio.h>
#include <string.h>
#include "pqueue.kyeung2.h"
//
////TODO THIS MAIN IS TO BE USED TO TEST THE .C and .H, DO NOT CHANGE OR SUBMIT
//
int main() {
    /* Create a student named John, with id = 67. Enqueue this student with priority = 3.
     * Create a student named Brittany, with id = 890. Enqueue this student with priority = 8.
     * Create a student named Robert, with id = 645. Enqueue this student with priority = 1.
     * Create a student named Alice, with id = 112. Enqueue this student with priority = 9.
     * Create a student named Thomasina, with id = 452. Enqueue this student with priority = 2.
     * Create a student named Alfred, with id = 516. Enqueue this student with priority = 12.
     * Create a student named Margaret, with id = 341. Enqueue this student with prioirity = 9.
     * Create a student named Robert, with id = 485. Enqueue this student with priority = 2.
     * Create a student named Elizabeth, with id = 734. Enqueue this student with priority = 1 */


    struct PQueueStruct *theQueue = NULL;
    char name[32];
    int number;

    int priority;
    int returnValue;

    void *data;

//    // Create a student named John, with id = 67. Enqueue this student with priority = 3.
//    strcpy(name, "John");
//    &data(&theQueue, 23, 67);
//    returnValue =  enqueue(&theQueue, priority, data);
//    if (returnValue == 0)
//        printf("inserted %s\n", name);
//    else
//        printf("failed to insert %s\n", name);
//    return 0;
}
