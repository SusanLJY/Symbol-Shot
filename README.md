# Symbol-Shot
<pre>
Group111_Project_ Proposal<br />
1. Brief identification of group members<br />
  Lee Hiu Long (3035687077)		u3568707@connect.hku.hk<br />
  Liao Jiayang (3035637280)		susan823@connect.hku.hk<br />
</pre>
2. Game description:<br />
  a) Basic Game rules<br />
  A 10X10 game board consisting of 100 tiles of 5 symbols are randomly generated in each game-start. 3 to 5 consecutive tiles (can be either horizontal or vertical) of the same symbol will be eliminated and the player will get some scores. To achieve this, players can swap two tiles by entering the positions of tiles to be swapped (e.g. A1 A2). If the player gets 4 consecutive tiles of the same symbol, the whole row or column will be eliminated. If the player gets 5 consecutive tiles, the player gets a ‘!’, which is a bomb and can destroy all tiles of a symbol when the player swaps the bomb with a tile containing that particular symbol.<br />
  To win a level, the player has to reach a certain amount of scores within the time limit of 3 minutes. The next level will also have the same time limit of 3 minutes but have a higher score requirement. The score requirement of a level follows a predetermined function f(n) with n as the level number.<br />
<pre>
3. Features plan to implement  (Code requirement 1~5)<br />
  (1) Generation of random game sets or events<br />
      a) 10x10 board randomly generated with 5 different symbols <br />
      b) Every time after elimination and falling of the symbols, the game will randomly generate new symbols in the blank area.<br />
  (2) Data structures for storing game status<br />
      a) Using Stacks structure to store the menu and the whole game<br />
      b) 2D array for the board (10x10) --keep updating<br />
      c) Using Radix Sort to check the elimination<br />
      d) user’s input of swapping pair (e.g. A1 A2) will change to indices in 2D array for internal interpretation<br />
  (3) Dynamic memory management<br />
      a) Every time will check if the swapping is valid<br />
        i)If yes, <br />
            1) eliminate the symbols according to the rules<br />
            2) Add score according to the elimination.<br />
            3) Upper symbols fall down<br />
            4) Generate new symbols randomly in the blank space<br />
            5) Looping until all eliminations are done.<br />
        ii) If no,<br />
            1) Ask the user to input a new swapping pair.<br />
      b) After fulfilling the score in a given time, back to the menu.<br />
         i) New game, Next Level, Quit, Winning records (time and score), <br />
4. File input/output (e.g., for loading/saving game status)<br />
  (1) Pause (stop the timer)<br />
      Store the current game status in 1st file<br />
  (2) View Winning records <br />
      Store the time records in a file<br />
5. Program codes in multiple files<br />
  1st file: Initialize the board and menu<br />
  2nd file: Store the current board, time, score<br />
  3rd file: Get input, check and eliminate the symbols<br />
  4th file: Pause<br />
  5th file: Store winning records.<br />
</pre>
