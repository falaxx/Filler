# Filler
Create a player to fight other students on the filler board by placing more pieces than your opponent 

## Description 

In this game, two players fight each other and play one after the other.
The goal is to collect as many points as possible by placing the highest number of pieces on the game board.
The pieces are random, and the game stops when the first error occurs, when a piece cannot be placed anymore or has been wrongly placed.
The game takes place in your terminal, but i also did a sdl2 visualation.
![](fdf.gif)


## Installation 

You need to install sdl2 
```
brew sdl2
```
Then simply
```
make
```
or 
```
make re
```
## Usage 
```
 ./filler_vm -f path [-i | -p1 path | -p2 path] [-s | -q | -t time]
-t --timeset timeout in second
-q --quietquiet mode
-i --interactiveinteractive mode(default)
-p1 --player1use filler binary as a first player
-p2 --player2use filler binary as a second player
-f --fileuse a map file (required)
-s --seeduse the seed number (initialization random) (man srand)
```
