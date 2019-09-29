#include <stdio.h>
#include <stdlib.h>
#include <slist.jhibbele.h>

void printStudentRecord(void *data) {
  StudentListNode *node = (StudentListNode *) data;
  printf("name = %s, id = %d\n", node->name, node->id);
}


void printList2(StudentListNode *theList, void (printFunction)(void*)) {
  StudentListNode *node;
  node = theList;
  while (node != NULL) {
    printFunction(node);
    node = node->next;
  }
}

main() {
  StudentListNode *studentList = NULL;
  insertStudent(&studentList, 1, "Student One");
  insertStudent(&studentList, 2, "Student Two");
  insertStudent(&studentList, 3, "Student Three");
  printList2(studentList, printStudentRecord);
}
