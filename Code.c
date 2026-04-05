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
#define WIDTH 40
#define HEIGHT 20

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

int isOnSnake(int x, int y)
{
    struct Node *temp = head;
    while (temp)
    {
        if (temp->x == x && temp->y == y)
            return 1;

        temp = temp->next;
    }

    return 0;
}

void generateFruit()
{
    do
    {
        fruitX = rand() % (WIDTH - 2) + 1;
        fruitY = rand() % (HEIGHT - 2) + 1;
    } while (isOnSnake(fruitX, fruitY));
}

int isHead(int x, int y)
{
    if (head == NULL)
        return 0;
    return (head->x == x && head->y == y);
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
            if (row == 0 && col == 0)
                printf("+");
            else if (row == 0 && col == WIDTH - 1)
                printf("+");
            else if (row == HEIGHT - 1 && col == 0)
                printf("+");
            else if (row == HEIGHT - 1 && col == WIDTH - 1)
                printf("+");
            else if (row == 0 || row == HEIGHT - 1)
                printf("--");
            else if (col == 0 || col == WIDTH - 1)
                printf("|");

            else
            {
                // Snake check
                int printed = 0;
                struct Node *temp = head;
                while (temp != NULL)
                {
                    if (temp->x == col && temp->y == row)
                    {
                        if (isHead(col, row))
                            printf("@ "); // bada / distinct head
                        else
                            printf("o "); // chhota body
                        printed = 1;
                        break;
                    }
                    temp = temp->next;
                }

                // Fruit
                if (!printed && col == fruitX && row == fruitY)
                {
                    // printf("F ");
                    printf("* ");
                    printed = 1;
                }

                if (!printed)
                    printf("  ");
            }
        }
        printf("\n");
    }
}

int checkCollision(int nx, int ny)
{
    if (nx <= 0 || nx >= WIDTH - 1 || ny <= 0 || ny >= HEIGHT - 1)
        return 1; // Wall
    struct Node *temp = head;
    while (temp)
    {
        if (temp->x == nx && temp->y == ny)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void gameStart()
{
    generateFruit();
    addNode(12, 12);
    struct Node *temp = head;

    for (int i = 0; i < 3; i++)
    {
        int newX = head->x + 1;
        int newY = head->y;

        addNode(newX, newY);
        drawboard();
        Sleep(400);
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

        if (checkCollision(newX, newY))
        {
            printf("\nGAME OVER!\nFinal Score: %d\n", score);
            break;
        }

        // FRUIT EATING LOGIC
        addNode(newX, newY);
        if (newX == fruitX && newY == fruitY)
        {
            score += 10;     // +10 points!
            generateFruit(); // fruit will generate immediately and random..
        }
        else
        {
            removeTail();
        }
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
