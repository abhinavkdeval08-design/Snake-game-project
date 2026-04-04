#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>


struct   Node {
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
    if (!temp || !temp->next) 
        return;

    while (temp->next->next)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
<<<<<<< Updated upstream
}

enum Direction{UP,DOWN,LEFT,RIGHT};
int direction = RIGHT;

void gameStart()
{

    addNode(12,12);
    struct Node* temp = head;
        while(temp!=NULL)
        {
            printf(" < %d , %d > ",temp->x,temp->y);
            temp=temp->next;
        }
        printf("\n");

    for(int i=0; i<2; i++)
    {
       
        
        int newX=head->x+1;
        int newY=head->y;

        addNode(newX,newY);
        Sleep(500);

        system("cls");
        struct Node* temp = head;
        while(temp!=NULL)
        {
            printf(" < %d , %d > ",temp->x,temp->y);
            temp=temp->next;
        }
        printf("\n");
    }

    while(1)
    {
        int newX=head->x;
        int newY=head->y;

        if (kbhit())
        {
            char ch=getch();

            if(ch=='w' && direction!=DOWN)
            direction=UP;

            else if(ch=='s' && direction!=UP)
            direction=DOWN;

            else if(ch=='a' && direction!=RIGHT)
            direction=LEFT;

            else if(ch=='d' && direction!=LEFT)
            direction=RIGHT;

        }

        if(direction==UP)
        newY--;

        if(direction==DOWN)
        newY++;

        if(direction==LEFT)
        newX--;

        if(direction==RIGHT)
        newX++;

        addNode(newX,newY);
        removeTail();

        system("cls");
        struct Node* temp = head;
        while(temp!=NULL)
        {
            printf(" < %d , %d > ",temp->x,temp->y);
            temp=temp->next;
        }
        printf("\n");
        Sleep(250);

    }
}

int main()
{

    gameStart();


    return 0;
}
=======
}
>>>>>>> Stashed changes
