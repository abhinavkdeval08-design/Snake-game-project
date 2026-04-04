#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

// Functions
void addNode(int x, int y);
void removeTail();
void gameStart();
void generateFruit();
void drawboard();

// defined height and wedth
#define WIDTH 30
#define HEIGHT 15

// Globaly decleared variable
int fruitX, fruitY;
int score = 0;

// structure define -> (Linklist)
struct Node
{
    int x, y;
    struct Node *next;
};

struct Node *head = NULL;

int main()
{
    srand((unsigned)time(NULL)); // seed random once
    gameStart();
    return 0;
}


void addNode(int x, int y)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = head;
    head = newNode;
}

void removeTail()
{
    struct Node *temp = head;
    if (!temp || !temp->next)
        return;

    while (temp->next->next)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};
int direction = RIGHT;


void generateFruit()
{
    fruitX = rand() % (WIDTH - 2) + 1;
    fruitY = rand() % (HEIGHT - 2) + 1;
}

void drawboard()
{
    system("cls"); // clear screen each frame
    //=> We use cls for windows system

    for (int row = 0; row < HEIGHT; row++) // rows
    {
        for (int col = 0; col < WIDTH; col++) // columns
        {
            // Border
            if (row == 0 || row == HEIGHT - 1 || col == 0 || col == WIDTH - 1)
            {
                printf("#");
            }
            else
            {
                // Snake check
                int printed = 0;
                struct Node *temp = head;
                while (temp != NULL)
                {
                    if (temp->x == col && temp->y == row)
                    {
                        printf("O");
                        printed = 1;
                        break;
                    }
                    temp = temp->next;
                }

                // Fruit
                if (!printed && col == fruitX && row == fruitY)
                {
                    printf("F");
                    printed = 1;
                }

                if (!printed)
                    printf(" ");
            }
        }
        printf("\n");
    }
}

void gameStart()
{
    generateFruit();
    addNode(12, 12);
    struct Node *temp = head;

    for (int i = 0; i < 2; i++)
    {
        int newX = head->x + 1;
        int newY = head->y;

        addNode(newX, newY);
        drawboard();
        Sleep(500);
    }

    while (1)
    {
        int newX = head->x;
        int newY = head->y;

        if (kbhit())
        {
            char ch = getch();

            if (ch == 'w' && direction != DOWN)
                direction = UP;

            else if (ch == 's' && direction != UP)
                direction = DOWN;

            else if (ch == 'a' && direction != RIGHT)
                direction = LEFT;

            else if (ch == 'd' && direction != LEFT)
                direction = RIGHT;
        }

        if (direction == UP)
            newY--;

        if (direction == DOWN)
            newY++;

        if (direction == LEFT)
            newX--;

        if (direction == RIGHT)
            newX++;

        addNode(newX, newY);
        removeTail();
        drawboard();

        // system("cls");
        // struct Node *temp = head;
        // while (temp != NULL)
        // {
        //     // system("cls"); // clear screen each frame
        //    // drawboard();
        //     // printf(" < %d , %d > ",temp->x,temp->y);
        //     temp = temp->next;
        // }
        // printf("\n");
        Sleep(250);
    }
}