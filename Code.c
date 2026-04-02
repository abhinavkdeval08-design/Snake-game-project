#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>


struct Node {
    int x, y;
    struct Node* next;
};

struct Node* head = NULL;

void addNode(int x, int y) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = head;
    head = newNode;
}

void removeTail() {
    struct Node* temp = head;
    if (!temp || !temp->next) return;

    while (temp->next->next)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}


