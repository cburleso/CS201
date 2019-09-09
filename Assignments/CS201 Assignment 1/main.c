#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup.kyeung2.h"

int main(void) {
    printf("\nProgram start... \n\n");

    int n1 = 1;
    int n2 = 2;
    int sum = 0;
    int difference = 0;
    int returnValue = addSubtract(n1, n2, &sum, &difference);
    printf("The return value for part 1 is %d\n", returnValue);

    int id = 17;
    char *name = "Edsger_Dijkstra";
    struct StudentData *record;
    returnValue = createRecord(id, name, &record);
    printf("The return value for part 2 is %d\n", returnValue);

    printf("\n\nProgram end...");

    return 0;
}