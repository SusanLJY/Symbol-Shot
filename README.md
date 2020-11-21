# Symbol-Shot
<pre>
Group111_Project_Final_Verison <br />
1. Brief identification of group members<br />
  Lee Hiu Long (3035687077)		u3568707@connect.hku.hk<br />
  Liao Jiayang (3035637280)		susan823@connect.hku.hk<br />
</pre>
2. Game description:<br />
  a) Basic Game rules (This part can also be seen in the instruction.txt)<br />
  A 10X10 game board consisting of 100 tiles of 6 symbols with different colors is randomly generated at the beginning of each game. 3, 4 or 5 consecutive tiles (can be either horizontal or vertical) of the same symbol will be eliminated. For every swapping, the number of elimination will becountd as "hits",  and the player will get scores according to both number of eliminated symbols and hits.
  To achieve this, players can swap two tiles by entering the positions of tiles to be swapped (e.g. A1 A2). If the player gets 4 consecutive tiles of the same symbol, the whole row or column will be eliminated. If the player gets 5 consecutive tiles, the player gets a '!', which is a bomb and can destroy all tiles of a symbol when the player swaps the bomb with a tile containing that particular symbol.<br />
  To win in a level, the player has to reach a certain amount of scores within the time limit. The next level will also have the shorter time limit (>=30) and a higher score requirement. The score requirement of a level follows a predetermined function f(level) = 100 + 50 * level.<br />
<pre>
3. Features have implemented  (Code requirement 1~5)<br />
  (1) Generation of random game sets or events<br />
      a) 10x10 board randomly generated with 5 different symbols <br />
      b) Every time after elimination, the symbols will first fall down and then randomly generate new symbols in the blank area. After that, the game will print the new board. <br />
  ##(2) Data structures for storing game status<br />
      a) Using Queue structure to store the records of game (Highest evel, Shortest time, and User name)<br />
      b) 2D array for the board (10x10) --keep updating, and will be generated randomly when level starts<br />
      c) user’s input of swapping pair (e.g. A1 A2) will change to indices in 2D array for internal interpretation<br />
      d) 
  ###(3) Dynamic memory management<br />
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
###4. File input/output (e.g., for loading/saving game status)<br />
  (1) Pause (stop the timer)<br />
      Store the current game status in 1st file<br />
  (2) View Winning records <br />
      Store the time records in a file<br />
5. Program codes in multiple files<br />
  cpp and header files:
    main.cpp: Initialize the game<br />
    
    Menu.cpp: print the command menu in this stage and enter the other part of Symbol-Shot according to user's input.<br />
    Menu.h: header file of menu.cpp<br />
    
    instruction.cpp: Read instruction.txt and Print out it in the console.<br />
    instruction.h: header file of instruction.cpp<br />
    
    NewGame.cpp: intialize a new game of Symbol-Shot with a new user name and some external variables.
    NewGame.h: header file of NewGame.cpp
    
    Playing.cpp: the main workflow of Symbol-Shot in playing stage.
    Playing.h: header file of Playing.cpp
    
    Record.cpp: to save, store, show, and restore the users' game records in Symbol-Shot. These records are saved in txt files, and can be accessed after quit the game.
    Record.h: header file of Record.cpp
    
    Timer.cpp: 
    
  1st file: Initialize the board and menu<br />
  2nd file: Store the current board, time, score<br />
  3rd file: Get input, check and eliminate the symbols<br />
  4th file: Pause<br />
  5th file: Store winning records.<br />
6. Non-Standard C/C++ libraries<br />
  (1) Time.h
7. Compilation and Execution instructions<br />
  (1) make clean //clean all the .o files and main.
  (2) make main  //compile all the .o files and main.
  (3) ./main     // execute main function
</pre>

