<h1 align="center">push_swap</h1> 

The goal of that project was to sort a data list made of integers. <br>
The trick is, that you could only use a limited set of instructions, and make use of a secondary empty array to move your data in and out. <br>
Although since I used radix, I only needed 6 of them. <br>
<br>
Now let's suppose you wish to sort the table 'a', and after executing a few instructions, we have this architecture.

<img src="https://i.imgur.com/unioD03.png"></img>
<br>
<br>
The instructions used in this project are: <br>
## sa (swap a)
Swaps the two top element of the a list
<img src="https://i.imgur.com/lLkX2iR.png"></img>
## sb (swap b)
Swaps the two top element of the b list
<img src="https://i.imgur.com/WHscxe6.png"></img>
## pa (push a)
Sends the first element on top of b to a
<img src="https://i.imgur.com/bcuhSyt.png"></img>
## pb (push b)
Sends the first element on top of a to b
<img src="https://i.imgur.com/qy1D2xj.png"></img>
## ra (rotate a)
Shifts every element in the a list towards the top (last number becomes the first) <br>
<img src="https://i.imgur.com/unioD03.png"></img>
<br>Becomes<br> 
<img src="https://i.imgur.com/TwgPC0t.png"></img>
## rra (reverse rotate a)
Shifts every element in the a list towards the bottom (first number becomes the last) <br>
<img src="https://i.imgur.com/unioD03.png"></img>
<br>Becomes<br>
<img src="https://i.imgur.com/DKREQxT.png"></img>
