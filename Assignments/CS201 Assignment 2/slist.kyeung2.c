#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "slist.kyeung2.h"

//StudentListNodeStruct header added to fix storage error message on linux
struct StudentListNodeStruct{
    int id;
    char name [32];
    struct StudentListNodeStruct *next;
};

//Insert method updates lists with main parameters
int insertStudent(StudentListNode **list, int id, char *name) {

    //Uses find method to check for duplicates
    int found = findStudent(*list, id, name);
    if (found == 0) {
        return 1;
    }

    //Initializes nodes
    StudentListNode *temp;
    StudentListNode *student;

    //Allocates student node memory
    student = (StudentListNode *) malloc(sizeof(StudentListNode)); //allocates new node memory

    //Moves parameters to node field
    student->id = id;
    strcpy(student->name, name);

    //Conditional for if list is empty or if header id > given id
    if((*list) == NULL || (*list)->id > student->id){

        //Places list at end of student
        student->next = (*list);

        //Sets list equal to student
        (*list) = student;
    }
    else{
        //Creates temporary copy of list
        temp = (*list);

        //Loops while list copy has nodes and their id < given id
        while(temp->next != NULL && temp->next->id < student->id){

            //Gets next in temp list
            temp = temp->next;
        }

        //Places temp->next at end of student
        student->next = temp->next;

        //Sets temp equal to student
        temp->next = student;
    }
    return 0;
}

int findStudent(StudentListNode *list, int id, char *name) {
    //Checks if list is empty
    if (list == NULL) {
        return 1;
    }
    else {
        //Loops while list not empty and list id not equal to given id
        while (list != NULL && list->id != id) {
            list = list->next;
        }

        //Another list == NULL check for after while loop
        if (list == NULL) {
            return 1;
        }

        //Checks if header id is equal to given ic
        else if (list->id == id) {
            //If id is a match, copies list name to name parameter
            strcpy(name, list->name);
            return 0;
        }
    }
}

int deleteStudent(StudentListNode **list, int id){
    //Creates temp nodes
    StudentListNode* temp = *list, *previousStudent;

    //Loops while temp not empty and id == given id
    while(temp != NULL && temp->id == id){

        //Sets list to what is left of temp
        *list = temp->next;
        return 0;
    }

    //Loops while temp not empty
    while(temp != NULL){

        //Loops while temp not empty and id not equal to given id
        while(temp != NULL && temp->id != id){
            previousStudent = temp;
            temp = temp->next;
        }

        //Checks of temp is NULL
        if(temp == NULL){
            return 1;
        }

        previousStudent->next = temp->next;
        return 0;
    }
}

int printList(StudentListNode *list){

    //Creates temp node
    StudentListNode *currentNode = list;

    //Checks of list is empty
    if (list != NULL){

        //Loops while currentNode is not empty
        while (currentNode != NULL){

        //Prints formatted result
        printf("%d |%s| \n",currentNode->id, currentNode->name);

        //Gets next node
        currentNode = currentNode->next;
        }
    }

    else
        printf("(list is empty)\n");

    return 0;
}