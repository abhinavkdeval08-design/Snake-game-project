# Snake-Game
This is our second semester group project. 
<br>
Made By- <br> 1.Ritesh Singh  <br>
         2.Pawan Asati 
         <br>
         3.Abhinav Deval 

<br>

//==============================================================================================================================================

<p>
Data structure Use
-> Linked list (The snake is represented as a linked list of nodes (struct Node).)
-> Queue (implemented in the snake's movement.)
-> Array (for implementing two different types of fruits)


About 'C' Code
stdio.h -> standard input/output (for printf).
conio.h -> console input functions (kbhit(), getch()).
stdlib.h -> memory allocation (malloc, free).
windows.h -> Sleep() and system("cls") for clearing screen.
time.h -> random seeds or timing {for using srand()}


//==============================================================================================================================================

Problem Statements...

1.How do we make the snake?
Simply make a linked list with one pointer and two co-ordinates for the grid (x,y)

2.How are we supposed to give movement to the snake?
We can do it by adding a node in front of the head by making addNode() and then deleting the last node by making removeTail() to keep it's size same.

3.Ok so we gave basic movement, but how are we supposed to give it a user defined movement that too with a momentum.
We can use
if (kbhit()) { char ch = getch();}
to get constant user input and use them acc to condition defined by us.

For a retained momentum of the snakes direction of movement as per the user input
we are using enum function to initialize directional words with specefic integers
then we added all the necessary conditions and used integere direction to define a particular direction so that it can be kept as the current movement direction to keep moemetum.

4.We noticed y axis inverison
As it is not a graph paper rather the terminal...
it prints the grid as
y=0.....
y=1.....
y=2.....

therefore for UP movemnt of snake the inserted node should be y-- not y++.

5.How to make an beautifull border
We can use '|' and '--' ,'+' for giving beautifull look

6.How to make snake speed equivalent for Horizontal and vertical direction?
The Speed are same for both but due to represntion the spacing b/w horizontal letter and vertical are differnt so it looks like it have greater speed in vertical
direction.so for fixing that I increase the horizontal spacing.->by using '--' at printing timing.

7.how to spawn fruit at random position but inside the boundary??
At first we choose the random function for geting an number then we take modulo of width and height with that number so modulo give value inside that boundary.

8.Theres a bug, the fruit can spawn on the snake itself.
How do we solve it?
We make a function isOnSnake to check if the spawned fruit is on snake or not if on the snake then generate again.

9.The snake's speed is constant, to make the game fun we need to keep it constantly increasing.
We can do it by changing Sleep function parameter in a manner we wish.

10.Now we can add the pause UI feature.
We can usually do it by simply using the application od do-while loop.

11.But Adding the feature of restart needed special attention.
While implementing the feature of restart we need to restart the start game loop and also reset various parameters like speed, score, direction etc. and also reset the snake body.

12.Flickering of the output in the terminal was a problem for our game.
We solved it by using printf("\033[H\033[J").

13.We also wanted to add a highscore system.
We simply did it by defining a universal variable and then adding the condition of it to check itslef with score to find the greater one and store it.

14.We thought of making our game better by adding two different types of fruit with differetnt scores.
We simply did it by implementing array in our fruit system and we used rand() to chose between fruits.

15.We wanted to m ake our game elegant so we added animations.
We used Sleep plenty of times for delay to animate the things.

THANK YOU ^_^
</p>