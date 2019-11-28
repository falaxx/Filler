# Filler
Create a player to fight other students on the filler board by placing more pieces than your opponent 

## Description 

In this game, two players fight each other and play one after the other.

The goal is to collect as many points as possible by placing the highest number of pieces on the game board.

The pieces are random, and the game stops when the first error occurs, when a piece cannot be placed anymore or has been wrongly placed.

The game takes place in your terminal normally but as you can see it's not great.

![](terminal.gif)

But i also make a visualisation with the SDL2, here is multiple games where i face myself 

You can see my strategy is pretty simple, i want to circle my opponent with a heat map calculation in my code.

![](multiples.gif)


## Installation 

You need to install sdl2 
```
brew sdl2
```
Then simply
```
make
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
Example : 
```
./filler_vm -f maps/map02 -p1 players/fmerding.filler -p2 players/hcao.filler
```
