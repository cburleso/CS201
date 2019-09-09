//.c file contains body of declarations and initialzation of structs and other variables
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "warmup.kyeung2.h"

//struct StudentData is defined with variables name and id, studentData header added to fix storage error message on linux
typedef struct StudentData{
    char name [32];
    int id;
    } StudentData;

//Method addSubtract uses pointers to update the sum and difference values in memory during calculations
int addSubtract(int n1, int n2, int *sum, int *difference) {
    *sum = n1 + n2;
    *difference = n1 - n2;

    if (n1 > n2) {
        return 1;
    }

    else if (n1 = n2) {
        return 0;
    }

    else
        return -1;
}

//Method createRecord using the struct's variables and pointers to help complier associate values
int createRecord(int id, char *name, struct StudentData **record) {

    //Conditional sets record to empty and returns 1 if length requirement of variables are not met
    if (strlen(name) > 31 || id <= 0) {
        *record = NULL;
        return 1;
    }

    /* Otherwise, struct StudentData is used to create newRecord and malloc'ed, and the id
    field in the struct is updated with the current value. Similarly, name is too updated
    before a pointer is passsed to the new memory and the method returns 0. */
    else {
        StudentData *newRecord;
        newRecord = (StudentData *) malloc(sizeof(StudentData));
        (*newRecord).id = id;
        strcpy(newRecord->name, name);
        *record = newRecord;
        return 0;
    }

}