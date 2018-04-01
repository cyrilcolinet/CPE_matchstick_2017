# Matchstick - Leave the last matchstick!

- **Binary name:** matchstick
- **Repository name:** CPE_matchstick_2017
- **Repository rights:** ramassage-tek
- **Language:** C
- **Compilation:** via Makefile, including re, clean and fclean rules


# Subject

You all know the very famous Battleship game. Well, I hope so.<br />
You must code a terminal version of this game.<br />
The two players are ONLY allowed to communicate using the signals **SIGUSER1** and **SIGUSER2**.

The map size is 8x8. On each turn, you must display your positions, and then your enemy’s positions.

At the end of the game (when all the ships of a player have been hit), you must display whether “I won” (and return 0) or “Enemy won” (and return 1).

> :bulb: You are allowed to use one (and only one) global variable, if you can justify it.

```
∼/B-PSU-200> ./navy -h
USAGE
        ./navy [pid] <pos>

DESCRIPTION
        pid PID of the first player (Only for the 2nd player).
        pos file representing the positions of the ships.
```

The file passed as parameter must contain lines formatted the following way (without spaces):

`LENGTH  :  FIRST_SQUARE  :  LAST_SQUARE`

where **LENGTH** is the length of the ship, **FIRST_SQUARE** and **LAST_SQUARE** its first and last positions.<br />
In this file, you must have 4 ships (of lengths 2,3,4 and 5).<br />
If the navy file is invalid, you have to quit the program and consider it as an error.

## Example

> :exclamation: The display must be **EXACTLY** the same as the one below.

Here is an example game.<br />
The user inputs as written between `_` character.

```
∼/B-PSU-200> cat maps/pos1
2:C1:C2
3:D4:F4
4:B5:B8
5:D7:H7
```

```
∼/B-PSU-200> cat maps/pos2
2:C4:D4
3:H1:H3
4:E6:H6
5:B1:F1
```

### ▷ Connection

#### Player one

```
∼/B-PSU-200> ./navy maps/pos1
my_pid: 4242
waiting for enemy connection...

enemy connected

```

#### Player two

```
∼/B-PSU-200> ./navy 4242 maps/pos2
my_pid: 4250
successfully connected

```

### ▷ Turn \#1

#### Player one

```
my positions:
|A B C D E F G H
-+---------------
1|. . 2 . . . . .
2|. . 2 . . . . .
3|. . . . . . . .
4|. . . 3 3 3 . .
5|. 4 . . . . . .
6|. 4 . . . . . .
7|. 4 . 5 5 5 5 5
8|. 4 . . . . . .

enemy’s positions:
|A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

attack: _Z0_
wrong position
attack: _B6_
B6: missed

```

#### Player two

```
my positions:
|A B C D E F G H
-+---------------
1|. 5 5 5 5 5 . 3
2|. . . . . . . 3
3|. . . . . . . 3
4|. . 2 2 . . . .
5|. . . . . . . .
6|. . . . 4 4 4 4
7|. . . . . . . .
8|. . . . . . . .

enemy’s positions:
|A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

waiting for enemy’s attack...
B6: missed

attack: _4_
wrong position
attack: _C1_
C1: hit

```

### ▷ Turn \#2

#### Player one

```
my positions:
|A B C D E F G H
-+---------------
1|. . x . . . . .
2|. . 2 . . . . .
3|. . . . . . . .
4|. . . 3 3 3 . .
5|. 4 . . . . . .
6|. 4 . . . . . .
7|. 4 . 5 5 5 5 5
8|. 4 . . . . . .

enemy’s positions:
|A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. o . . . . . .
7|. . . . . . . .
8|. . . . . . . .

attack: _C4_
C4: hit

waiting for enemy’s attack...
D1: missed

```

#### Player two

```
my positions:
|A B C D E F G H
-+---------------
1|. 5 5 5 5 5 . 3
2|. . . . . . . 3
3|. . . . . . . 3
4|. . . . . . . .
5|. . 2 2 . . . .
6|. o . . 4 4 4 4
7|. . . . . . . .
8|. . . . . . . .

enemy’s positions:
|A B C D E F G H
-+---------------
1|. . x . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

waiting for enemy’s attack...
C4: hit

attack: _D1_
D1: missed

```

### ▷ Etc...

### ▷ Last turn

#### Player one

```
attack: _H6_
H6: hit

my positions:
|A B C D E F G H
-+---------------
1|o . x o . o . o
2|. . 2 . . o . .
3|. o . . o . . .
4|. . . x x x . .
5|. x o . . o o .
6|. x . . . . . .
7|o x . x x x 5 5
8|. x . o . o . o

enemy’s positions:
|A B C D E F G H
-+---------------
1|. x x x x x . x
2|. . . o . o . x
3|. o . . . . o x
4|. . x x o . . o
5|. . . . . o . .
6|. o . . x x x x
7|. . o . . . o .
8|. . . . . o . .

I won

```

#### Player two

```
waiting for enemy’s attack...
H6: hit

my positions:
|A B C D E F G H
-+---------------
1|. x x x x x . x
2|. . . o . o . x
3|. o . . . . o x
4|. . x x o . . o
5|. . . . . o . .
6|. o . . x x x x
7|. . o . . . o .
8|. . . . . o . .

enemy’s positions:
|A B C D E F G H
-+---------------
1|o . x o . o . o
2|. . . . . o . .
3|. o . . o . . .
4|. . . x x x . .
5|. x o . . o o .
6|. x . . . . . .
7|o x . x x x . .
8|. x . o . o . o

Enemy won

```

## Bonus

> :exclamation: You have to make the mandatory part before adding bonus !

Here are some example of bonus :
- play against an AI,
- a nice interface, music, etc...,
- multiplayer mode with more than two players,
- customize game,
- networking,
- and whatever you feel like.

## Authorized functions

- read, write, malloc, free, time, getpid, random, srandom
