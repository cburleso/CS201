#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "slist.kyeung2.h"

//StudentListNodeStruct header added to fix storage error message on linux
typedef struct StudentListNodeStruct{
    int id;
    char name [32];
    struct StudentListNodeStruct *next;
} StudentListNode;

int insertStudent(StudentListNode **list, int id, char *name) {
    int found = findStudent(*list, id, name); //sets find to use findstudent method // TODO REMOVED & from name

    if (found == 0) { //gets return for duplicates
        return 1;
    }

    StudentListNode *temp;

    StudentListNode *student; //creates node student
    student = (StudentListNode *) malloc(sizeof(StudentListNode)); //allocates new node memory
    student->id = id; //copies id to id field of new node
    strcpy(student->name, name); //copies name to name field of new node

    if((*list) == NULL|| (*list)->id > student->id){
        student->next = (*list);
        (*list) = student;
    }
    else{
        temp = (*list);
        while(temp->next != NULL && temp->next->id < student->id){
            temp = temp->next;
        }

        student->next = temp->next;
        temp->next = student;
    }

    return 0;
}

int findStudent(StudentListNode *list, int id, char *name) {


    if (list == NULL) {
        return 1;
    } else {
        while (list != NULL && list->id != id) { //loops while temp not empty
            list = list->next; //moves to next node
        }

        if (list == NULL) {
            return 1;
        }
        else if (list->id == id) {
            strcpy(name, list->name); //copies name to name field of node
            return 0;
        }
    }
}

int deleteStudent(StudentListNode **list, int id){
    StudentListNode* tempStudent = *list, *previousStudent;
    while(tempStudent != NULL && tempStudent -> id == id){
        *list = tempStudent->next;
//        tempStudent = *list; //TODO may not need
        return 0;
    }
    while(tempStudent != NULL){
        while(tempStudent != NULL &&tempStudent->id != id){
            previousStudent = tempStudent;
            tempStudent = tempStudent->next;
        }
        if(tempStudent ==NULL){
            return 1;
        }

        previousStudent->next = tempStudent->next;
        return 0;
    }
}

int printList(StudentListNode *list){
    StudentListNode *currentNode = list; //creates current node
    char butt[20];//TODO........................
    if (list != NULL){ //if list is empty, prints...

        while (currentNode != NULL){ //loops while current node is not empty
        printf("%d |%s| \n",currentNode->id, currentNode->name); //formatted print
        currentNode = currentNode->next; //sets current node to next in list
        }
    }

    else{ //if list is empty, prints...
        printf("(list is empty)\n");
    }
    return 0;
}