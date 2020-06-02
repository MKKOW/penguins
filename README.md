# Penguins
Small text-based game made for first semester of Computer Science degree in May/June 2019.
# Rules
- It is a turn-based game. The goal is to collect fish scattered around the board.
- The board is a grid with a rectangular shape with dimensions of m x n fields (m -rows, n - columns). There are fish (1-3) in each box. Box can be empty.
- Two stages of the game:
  - placement of penguins on the board
  - actual gameplay
- Phase one - placement
  - The player receives a board (which is saved in separate file) on which he will place his penguins.
  - In one move, the player places one of his penguins on one of the available spaces having exactly one fish. Movement is mandatory. At the moment of placing penguin on the field, the fish in this field is counted to the players score (removed from the field). The number of penguins available is known to the player.
  - The first phase ends when all penguins of all players are placed on the board.
- Phase two - movement
  - In his move, the player chooses one of his penguins to transfer to another field. The penguin can move horizontally or vertically, through any number of unoccupied fields. The movement is limited by the size of the board, an empty field and other penguins. The fish on the target field are counted as collected. Movement is mandatory.
  - The second phase ends when no player can make a move.
- The player who collects the most fish by the end of the game wins.
# Interaction
Each player is represented by seprate instance of the program. Every instance have to by compiled seperatly. The name of each player is set by modyfing variable `const char* nasze` in `interaktywna.c`. (I know it is dumb but that was the requirment of the lecturer).
Every time the player makes a move(every time the program is executed) state of the game is read from file and later saved to another file. Those files can be the same file.

By default the program will compile into interactive version (representig human player). The program can be compiled into AI version by adding `#define AI` into `main.c` and `interaktywna.c`.

Interactive version was tested only on Windows 10 and (propably) will work only on Windows. The AI version was tested on both Windows and Linux.

Sample interaction:

```bash
player1.exe phase=placement penguins=2 board01.txt 1.txt
player2.exe phase=placement penguins=2 1.txt 2.txt
player1.exe phase=placement penguins=2 2.txt 3.txt
player2.exe phase=placement penguins=2 3.txt 4.txt
player1.exe phase=movement 4.txt 5.txt
player1.exe phase=movement 5.txt 6.txt
```

After each execution the boad will appear in terminal with instructions in Polish.

In folder Boards there are some sample boards to start the game

# Why is it made like that ?
The requirment by the lecturer was to make the game in such way that there would be an interactive version, as well as a version that could be run against versions made by other students.
