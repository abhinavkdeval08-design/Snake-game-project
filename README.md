# Snake-Game
This is our second semester group project. 
<br>
Made By- <br> 1.Ritesh Singh  <br>
         2.Pawan Asati 
         <br>
         3.Abhinav Deval 


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

5.Theres a bug, the fruit can spawn on the snake itself.
How do we solve it?
We make a function isOnSnake to check if the spawned fruit is on snake or not if on the snake then generate again.