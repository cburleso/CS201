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
    StudentListNode *student; //creates node student
    
    student = (StudentListNode *) malloc(sizeof(StudentListNode)); //allocates new node memory

    student->id = id; //copies id to id field of new node
    strcpy(student->name, name); //copies name to name field of new node

    student->next = *list; //links old list to new node

    (*list) = student; //moves head to point to new node
    return 0;
}






//int findStudent(StudentListNode *list, int id, char *name) {
//    StudentListNode *student; //creates node student
//
//    //TODO 1. find the record with specific id, if found copy the name of that record to parameter name and return 0
//    // 2. if not found just return 1
////    if (list == NULL) { //checks of list is empty
////        return 1;
////    }
////    else {
////        while (list){
////            if (list->id == id) { //checks of id is present in id field of list
////                name = list->name; //TODO ???maybe sets name to name field of list at id???
////                return 0;
////            }
////        }
////    }
//    while (list != NULL){
//        if(list->id = id){
//            strcpy(list->name, name);
//            return 0;
//        }
//        student = student->next;
//    }
//    return 1;
//}
//
//int deleteStudent(StudentListNode **list, int id){
//    //TODO 1. delete record from list if id matches id
//    // 2. if not found return 1, otherwise delete record from list and return 0
////    StudentListNode current = **list;
////    StudentListNode *next;
////
////    while (list != NULL){
////        if(current.id = id){
////
////            return 0;
////        }
////        next = next->next;
////    }
////    return 1;
//
//    StudentListNode *current = *list, *prev;
//
//    if(current != NULL && current->id ==id){
//        *list = current->next;
//        free(current);
//        return 0;
//    }
//
//    while(current != NULL && current -> id != id){
//        prev = current;
//        current = current->next;
//    }
//
//    if (current == NULL) { //checks of list is empty
//        return 1;
//    }
//}
//
int printList(StudentListNode *list){
    StudentListNode *currentNode = list; //creates current node

    while (currentNode != NULL){ //loops while current node is not empty
        printf("%d |%d| \n",list->id, list->name); //formatted print
        currentNode = currentNode->next; //sets current node to next in list
    }
    if(list == NULL){ //if list is empty, prints...
        printf("(empty list)");
    }
    return 0;
}