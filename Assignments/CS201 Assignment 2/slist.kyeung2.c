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
    StudentListNode *newStudent; //creates node newstudent
    newStudent = (StudentListNode *) malloc(sizeof(StudentListNode)); //allocates new node memory
    strcpy(newStudent->name, *name); //copies name to name field of new node
    newStudent->id = id; //copies id to id field of new node
    newStudent->next = (*list); //links old list to new node
    (*list) = newStudent; //moves head to point to new node

    //TODO need to 1. sort list by student id
    // 2. check if record's id is in list already, if so dont add record and return 1
    // 3. otherwise add to list in right place and return 0
}

int findStudent(StudentListNode *list, int id, char *name) {
    //TODO 1. find the record with specific id, if found copy the name of that record to parameter name and return 0
    // 2. if not found just return 1
    if (list == NULL) { //checks of list is empty
        return 1;
    }
    else if (list->id == id) { //checks of id is present in id field of list
        name = list->name; //TODO ???maybe sets name to name field of list at id???
        return 0;
    }
    else   //if not found return 1
        return 1;
}

int deleteStudent(StudentListNode **list, int id){
    //TODO 1. delete record from list if id matches id
    // 2. if not found return 1, otherwise delete record from list and return 0
    StudentListNode current = **list;
    StudentListNode *next;

    while (current != NULL) {
        next = current.next;
    }
}

int printList(StudentListNode *list){
    //TODO 1. print record from this list one to each line... like: id|name|
    // 2. If list is empty, prints (empty list)
}