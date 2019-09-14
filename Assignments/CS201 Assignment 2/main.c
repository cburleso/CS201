#include <stdio.h>
#include <string.h>
#include "slist.kyeung2.h"
//
////TODO THIS MAIN IS TO BE USED TO TEST THE .C and .H, DO NOT CHANGE OR SUBMIT
//
main() {
    StudentListNode *theList = NULL;
    char name[32];
    int number;
    int rc;

    strcpy(name, "John");
    rc = insertStudent(&theList, 23, name);
    if (rc == 0)
        printf("inserted %s\n", name);
    else
        printf("failed to insert %s\n", name);

    strcpy(name, "Elizabeth");
    rc = insertStudent(&theList, 3, name);
    if (rc == 0)
        printf("inserted %s\n", name);
    else
        printf("failed to insert %s\n", name);

    strcpy(name, "Franklin");
    rc = insertStudent(&theList, 1, name);
    if (rc == 0)
        printf("inserted %s\n", name);
    else
        printf("failed to insert %s\n", name);

    strcpy(name, "Petunia");
    rc = insertStudent(&theList, 42, name);
    if (rc == 0)
        printf("inserted %s\n", name);
    else
        printf("failed to insert %s\n", name);

    strcpy(name, "Archimedes");
    rc = insertStudent(&theList, 14, name);
    if (rc == 0)
        printf("inserted %s\n", name);
    else
        printf("failed to insert %s\n", name);

    strcpy(name, "Phoebe");
    rc = insertStudent(&theList, 23, name);
    if (rc == 0)
        printf("inserted %s\n", name);
    else
        printf("failed to insert %s\n", name);

    printList(theList);

    //---------------------------------------------------------------
//
//    number = 1;
//    rc = findStudent(theList, number, name);
//    if (rc == 0)
//        printf("found student %d: %s\n", number, name);
//    else
//        printf("did not find student with id = %d\n", number);
//
//    number = 2;
//    rc = findStudent(theList, number, name);
//    if (rc == 0)
//        printf("found student %d: %s\n", number, name);
//    else
//        printf("did not find student with id = %d\n", number);
//
//    number = 42;
//    rc = findStudent(theList, number, name);
//    if (rc == 0)
//        printf("found student %d: %s\n", number, name);
//    else
//        printf("did not find student with id = %d\n", number);
//
//    number = 100;
//    rc = findStudent(theList, number, name);
//    if (rc == 0)
//        printf("found student %d: %s\n", number, name);
//    else
//        printf("did not find student with id = %d\n", number);
//
//    number = 23;
//    rc = findStudent(theList, number, name);
//    if (rc == 0)
//        printf("found student %d: %s\n", number, name);
//    else
//        printf("did not find student with id = %d\n", number);

    ////---------------------------------------------------------------

//    number = 14;
//    rc = deleteStudent(&theList, number);
//    if (rc == 0)
//        printf("deleted %d\n", number);
//    else
//        printf("failed to delete %d\n", number);
//
//    number = 1;
//    rc = deleteStudent(&theList, number);
//    if (rc == 0)
//        printf("deleted %d\n", number);
//    else
//        printf("failed to delete %d\n", number);
//
//    number = 3;
//    rc = findStudent(theList, number, name);
//    if (rc == 0)
//        printf("found student %d: %s\n", number, name);
//    else
//        printf("did not find student with id = %d\n", number);
//
//    number = 6;
//    rc = deleteStudent(&theList, number);
//    if (rc == 0)
//        printf("deleted %d\n", number);
//    else
//        printf("failed to delete %d\n", number);
//
//    number = 3;
//    rc = deleteStudent(&theList, number);
//    if (rc == 0)
//        printf("deleted %d\n", number);
//    else
//        printf("failed to delete %d\n", number);
//
//    number = 42;
//    rc = deleteStudent(&theList, number);
//    if (rc == 0)
//        printf("deleted %d\n", number);
//    else
//        printf("failed to delete %d\n", number);
//
//    number = 1;
//    rc = deleteStudent(&theList, number);
//    if (rc == 0)
//        printf("deleted %d\n", number);
//    else
//        printf("failed to delete %d\n", number);
//
//    number = 23;
//    rc = deleteStudent(&theList, number);
//    if (rc == 0)
//        printf("deleted %d\n", number);
//    else
//        printf("failed to delete %d\n", number);
//    printList(theList);
//
//    number = 1;
//    rc = findStudent(theList, number, name);
//    if (rc == 0)
//        printf("found student %d: %s\n", number, name);
//    else
//        printf("did not find student with id = %d\n", number);
}
