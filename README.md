# Snake-Game
This is our second semester group project. 
<br>
Made By- <br> 1.Ritesh Singh  <br>
         2.Pawan Asati 
         <br>
         3.Abhinav Deval 

<br>
<p>
Problem Statements...

1.How do we make the snake?
Simply make a double linked list with one head and two co-ordinates for the grid (x,y)

2.How are we supposed to give movement to the snake?
We can do it by adding a node in front of the head by making addNode() and then deleting the last node by making removeTail() to keep it's size same.

3.Ok so we gave basic movement, but how are we supposed to give it a user defined movement that too with a momentum.
We can use
if (kbhit()) { char ch = getch();}
to get constant user input and use them acc to condition defined by us

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
we can use '|' and '--' ,'+' for giving beautifull look

6.How to make snake speed equivalent for Horizontal and vertical direction?
=>The Speed are same for both but due to represntion the spacing b/w horizontal letter and vertical are differnt so it looks like it have greater speed in vertical
direction.so for fixing that I increase the horizontal spacing.->by using '--' at printing timing.

7.how to spawn fruit at random position but inside the boundary??
at first we choose the random function for geting an number then we take modulo of width and height with that number so modulo give value inside that boundary.

8.Theres a bug, the fruit can spawn on the snake itself.
How do we solve it?
We make a function isOnSnake to check if the spawned fruit is on snake or not if on the snake then generate again.

9.The snake's speed is constant, to make the game fun we need to keep it constantly increasing.
We can do it by changing Sleep function parameter in a manner we wish.

10.For now we have made so that the snakes movement speed is increasing at a constant level but for is to be better, we should increase it exponentially with respect to score.
We can easily do it by introducing a function library i.e. conio.h and use its exponential functions.

11.Now we can add the pause UI feature.
We can usually do it by simply using the application od do-while loop.

12.But Adding the feature of restart needed special attention.
While implementing the feature of restart we need to restart the start game loop and also reset various parameters like speed, score, direction etc. and also reset the snake body.
