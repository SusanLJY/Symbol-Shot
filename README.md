# Symbol-Shot
Group111_Project_ Proposal
1. Brief identification of group members
  Lee Hiu Long (3035687077)		Liao Jiayang (3035637280) 
  u3568707@connect.hku.hk		  susan823@connect.hku.hk
2. Game description:
  a) Basic Game rules
  A 10X10 game board consisting of 100 tiles of 5 symbols are randomly generated in each game-start. 3 to 5 consecutive tiles (can be either horizontal or vertical) of the same symbol will be eliminated and the player will get some scores. To achieve this, players can swap two tiles by entering the positions of tiles to be swapped (e.g. A1 A2). If the player gets 4 consecutive tiles of the same symbol, the whole row or column will be eliminated. If the player gets 5 consecutive tiles, the player gets a ‘!’, which is a bomb and can destroy all tiles of a symbol when the player swaps the bomb with a tile containing that particular symbol.
  To win a level, the player has to reach a certain amount of scores within the time limit of 3 minutes. The next level will also have the same time limit of 3 minutes but have a higher score requirement. The score requirement of a level follows a predetermined function f(n) with n as the level number.

3. Features plan to implement  (Code requirement 1~5)
  (1) Generation of random game sets or events
      a) 10x10 board randomly generated with 5 different symbols 
      b) Every time after elimination and falling of the symbols, the game will randomly generate new symbols in the blank area.
  (2) Data structures for storing game status
      a) Using Stacks structure to store the menu and the whole game
      b) 2D array for the board (10x10) --keep updating
      c) Using Radix Sort to check the elimination
      d) user’s input of swapping pair (e.g. A1 A2) will change to indices in 2D array for internal interpretation
  (3) Dynamic memory management
      a) Every time will check if the swapping is valid
        i)If yes, 
            1) eliminate the symbols according to the rules
            2) Add score according to the elimination.
            3) Upper symbols fall down
            4) Generate new symbols randomly in the blank space
            5) Looping until all eliminations are done.
        ii) If no,
            1) Ask the user to input a new swapping pair.
      b) After fulfilling the score in a given time, back to the menu.
         i) New game, Next Level, Quit, Winning records (time and score), 
4. File input/output (e.g., for loading/saving game status)
  (1) Pause (stop the timer)
      Store the current game status in 1st file
  (2) View Winning records	
      Store the time records in a file
5. Program codes in multiple files
  1st file: Initialize the board and menu
  2nd file: Store the current board, time, score
  3rd file: Get input, check and eliminate the symbols
  4th file: Pause
  5th file: Store winning records.
