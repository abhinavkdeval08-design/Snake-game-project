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
void menu();

// defined height and wedth
#define WIDTH 40 
#define HEIGHT 20

int SPEED = 350;
int DEC = 10; //inc speed

// Globaly decleared variable
int fruitX, fruitY;
int score = 0;
int highScore = 0;
char fruitSymbols[] = {'$','%'};
int fruitValues[]   = {20, 10};
int fruitCount = 2;

char currentFruitSymbol;
int currentFruitValue;

// structure define -> (Linklist)
struct Node
{
    int x, y;
    struct Node *next;
};

struct Node *head = NULL;

int main()
{
    srand((unsigned)time(NULL));  // random fruit positions
    menu();   // start from main menu instead of starting game
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

void clearSnake()
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
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

    int idx = rand() % fruitCount;
    currentFruitSymbol = fruitSymbols[idx];
    currentFruitValue  = fruitValues[idx];
}

int isHead(int x, int y)
{
    if (head == NULL)
        return 0;
    return (head->x == x && head->y == y);
}

void drawboard()
{
    printf("\033[H");  // clear screen each frame
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
                    printf("%c ", currentFruitSymbol);
                    printed = 1;
                }

                if (!printed)
                    printf("  ");
            }
        }
        printf("\n");
    }

    printf("Your Score: %d\n",score);
    printf("High Score: %d\n", highScore);
    printf("Controls: w, a, s, d\n");
    printf("Press P to pause.\n\n");

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

void clearScreen() {
    printf("\033[H\033[J");
}

void showTeam() {
    clearScreen();
    printf("============== TEAM =============\n\n");
    printf("This is our Second Semester Group Project.\n\n");
    printf("Made By:\n");
    printf("1. Ritesh Singh\n");
    printf("2. Pawan Asati\n");
    printf("3. Abhinav Deval\n");
    printf("\nPress any key to go back to menu...");
    getch();
}

void showControls() {
    clearScreen();
    printf("======== CONTROLS ========\n\n");
    printf("w : Move Up\n");
    printf("s : Move Down\n");
    printf("a : Move Left\n");
    printf("d : Move Right\n");
    printf("p : Pause / Resume\n");
    printf("r : Restart (after game over)\n");
    printf("e : Exit (after game over)\n");
    printf("\nPress any key to go back to menu...");
    getch();
}

void menu() {
    while (1) {
        clearScreen();
        printf("\n----Wellcome to Snake Game----\n");
        Sleep(500);
        printf("Loading");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".\n");
        Sleep(500);
        clearScreen();
        printf("=================================\n");
        printf("          SNAKE GAME\n");
        printf("=================================\n\n");
        printf("1. About Team\n");
        printf("2. Controls\n");
        printf("3. Start Game\n");
        printf("4. Exit\n\n");
        printf("Select option (1-4): ");

        char ch = getch();   

        if (ch == '1') {
            showTeam();
        } 
        else if (ch == '2') {
            showControls();
        } 
        else if (ch == '3') {
            gameStart();     // start the game
            } 
        else if (ch == '4') {
            clearScreen();
            printf("Exiting");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            clearScreen();

            printf("T");
            Sleep(200);
            printf("H");
            Sleep(200);
            printf("A");
            Sleep(200);
            printf("N");
            Sleep(200);
            printf("K");
            Sleep(200);
            printf(" ");
            Sleep(200);
            printf("Y");
            Sleep(200);
            printf("O");
            Sleep(200);
            printf("U");
            Sleep(200);
            printf("!");
            Sleep(1000);
            exit(0);
        }
    }
}

void gameStart()
{
    int pause = 0;
    clearSnake();
    score = 0;     // new game from menu → fresh score
    direction = RIGHT;   // new game always start from right..
    SPEED = 350;   
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

            if(ch == 'p')
            pause = !pause;

            if (ch == 'w' && direction != DOWN)
                direction = UP;

            else if (ch == 's' && direction != UP)
                direction = DOWN;

            else if (ch == 'a' && direction != RIGHT)
                direction = LEFT;

            else if (ch == 'd' && direction != LEFT)
                direction = RIGHT;
        }

    if (pause)
    {
        drawboard();
        printf("GAME PAUSED - Press P to resume\n");
        Sleep(200);
        continue;
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
        {   if (score > highScore)
            highScore = score;
            printf("\nGAME OVER!\nFinal Score: %d\n", score);
            printf("High Score: %d\n", highScore);
            printf("Press R to restart or press E to exit.\n\n");
            char a =getch();
            if(a == 'r')
            {   clearSnake();
                struct Node* temp;
                while(head != NULL)
                {
                    temp=head;
                    head=head->next;
                    free(temp);
                }
                score=0;
                direction = RIGHT;
                pause = 0;
                SPEED = 350;
                generateFruit();
                addNode(12, 12);
                for (int i = 0; i < 3; i++)
                {
                    int newX = head->x + 1;
                    int newY = head->y;

                    addNode(newX, newY);
                    drawboard();
                    Sleep(400);
                }
                continue;
            }
            else if(a=='e'){
            printf("Returning to main menu...\n");
            Sleep(700);
            break;
            }
        }

        // FRUIT EATING LOGIC
        addNode(newX, newY);
        if (newX == fruitX && newY == fruitY)
        {
            score += currentFruitValue;     // + points!
            generateFruit(); // fruit will generate immediately and random..
            if (SPEED > 120)  //less flickering if speed > 120
            SPEED -= DEC;
        }
        else
        {
            removeTail();
        }
        drawboard();
        Sleep(SPEED);
    }
}
