//.h contains declarations and prototypes of methods and structures
#ifndef CS201_A1_WARMUP_KYEUNG2_H
#define CS201_A1_WARMUP_KYEUNG2_H

//Struct StudentData is defined, typeDef removed to fix storage error on Linux
struct StudentData;

//addSubtract takes 4 input parameters and returns a value of 1, 0, or -1 depending on calculations
int addSubtract(int n1, int n2, int *sum, int *difference);

//createRecord takes 4 input parameters and returns a value of 1 or 0 depending on name and id length
int createRecord(int id, char *name, struct StudentData **record);

#endif //CS201_A1_WARMUP_KYEUNG2_H
