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
    int found = findStudent(*list, id, &name); //sets find to use findstudent method

    if (found == 0) { //gets return for duplicates
        return 1;
    }

    StudentListNode *student; //creates node student
    student = (StudentListNode *) malloc(sizeof(StudentListNode)); //allocates new node memory

    student->id = id; //copies id to id field of new node
    strcpy(student->name, name); //copies name to name field of new node


//TODO pops all nodes then adds student, the student node will be the deepest one.
//            StudentListNode *last = *list; //creaes direct copy of list
//            student->next = NULL; //sets node to point to NULL
//
//            if(*list == NULL){ //If list is empty, copys student to list
//                *list = student;
//                return 0;
//            }
//
//            while(last ->next != NULL){ //Otherwise, move to end of list
//                last = last->next;
//            }
//
//            last->next = student; //Add student node to end of list
//            return 0;

//TODO adds to top of stack, the student node will be the most current one.

//            student->next = *list; //appends current list head to student's NULL
//            (*list) = student; //sets list equal to student
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
    StudentListNode* temp = *list, *prev; //creates temp nodes

    while (temp != NULL && temp->id != id){ //loops while temp not empty
        prev = temp;
        temp = temp->next; //moves to next node
    }

    if(temp != NULL && temp->id == id){ //checks if temp not empty and id is a match
        *list = temp->next;
        return 0;
    }

    if(temp == NULL) { //if temp empty
        return 1;
    }

    prev->next = temp->next; //unlinks node from the list
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
        printf("(empty list)\n");
    }
    return 0;
}
