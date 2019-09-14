//.h contains declarations and prototypes of methods and structures
#ifndef CS201_A2_WARMUP_KYEUNG2_H
#define CS201_A2_WARMUP_KYEUNG2_H

//Struct StudentData is defined, typeDef removed to fix storage error on Linux
typedef struct StudentListNodeStruct StudentListNode ;
//typedef struct StudentListNode;


int insertStudent(struct StudentListNodeStruct **list, int id, char *name);

int findStudent(struct StudentListNodeStruct *list, int id, char *name);

int deleteStudent(struct StudentListNodeStruct **list, int id);

int printList(struct StudentListNodeStruct *list);

#endif //CS201_A2_WARMUP_KYEUNG2_H
