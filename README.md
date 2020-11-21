# Symbol-Shot
<pre>
Group111_Project_Final_Verison <br />
1. Brief identification of group members<br />
  Lee Hiu Long (3035687077)		u3568707@connect.hku.hk<br />
  Liao Jiayang (3035637280)		susan823@connect.hku.hk<br />
</pre>
2. Game description:<br />
  a) Basic Game rules (This part can also be seen by calling Instruction from menu (read from instruction.txt))<br />
  A 10X10 game board consisting of 100 tiles of 6 symbols with different colors is randomly generated at the beginning of each game. 3, 4 or 5 consecutive tiles (can be either horizontal or vertical) of the same symbol will be eliminated. For every swapping, the number of elimination will becountd as "hits",  and the player will get scores according to both number of eliminated symbols and hits.
  To achieve this, players can swap two tiles by entering the positions of tiles to be swapped (e.g. A1 A2). If the player gets 4 consecutive tiles of the same symbol, the whole row or column will be eliminated. If the player gets 5 consecutive tiles, the player gets a '!', which is a bomb and can destroy all tiles of a symbol when the player swaps the bomb with a tile containing that particular symbol.<br />
    At the beginning of each level, the system will give you a '!' randomly in the board.<br />
  To win in a level, the player has to reach a certain amount of scores within the time limit. The next level will also have the shorter time limit (>=30) and a higher score requirement. The score requirement of a level follows a predetermined function f(level) = 100 + 50 * level.<br />
<pre>
3. Features have implemented  (Code requirement 1~5)<br />
  (1) Generation of random game sets or events<br />
      a) 10x10 board randomly generated with 6 different symbols <br />
      b) Every time after elimination, the symbols will first fall down and then randomly generate new symbols in the blank area. After that, the game will print the new board. <br />
  (2) Data structures for storing game status<br />
      a) Using Queue structure to store the records of game (Highest evel, Shortest time, and User name)<br />
      b) 2D array for the board (10x10) --keep updating, and will be generated randomly when level starts<br />
      c) user’s input of swapping pair (e.g. A1 A2) will change to indices in 2D array for internal interpretation<br />
      d) Using external variables (i.e., int level, bool newBoard...) to store the current game progress.<br />
      e) Using C++ structures for a single highest level or shortest time record.<br />
      f) Using C++ classes for timer.<br />
  (3) Dynamic memory management<br />
      a) STL container vector (dynamic) for storing username and top 10 higest level record, its functions are used, and its sorting algorithm is also used for the latter one.<br />
      b) STL container map (dynamic) for storing shortest time level record,with levels as the keys and ShortestTime structure as the values There is no level limit in our game, so the size of the map is dynamic.<br />
      c) Pointer is used in time management (currentTime() function in Timer.cpp)<br />
      
  (4) File input/output (e.g., for loading/saving game status)<br />
    a) Read the instruction.txt file to get the basic information of Symbol-Shot. <br />
    b) Save and restore records<br />
      read, write and restore the user-name, top 10 highest level, and short time of each level to txt files.<br />
      txt Files: UserNameRecord.txt, Highest Level Record.txt, Shortest Time Record.txt<br />
      Exception dealing: if the files do not exist, then create txt files for each saving.<br />
      
  (5) Program codes in multiple files<br />
    cpp and header files:<br />
      1) main.cpp: Initialize the game<br />
      2) Menu.cpp: print the command menu in this stage and enter the other part of Symbol-Shot according to user's input.<br />
      3) Menu.h: header file of menu.cpp<br />
      4) instruction.cpp: Read instruction.txt and Print out it in the console.<br />
      5) instruction.h: header file of instruction.cpp<br />
      6) NewGame.cpp: intialize a new game of Symbol-Shot with a new user name and some external variables.<br />
      7) NewGame.h: header file of NewGame.cpp<br />
      8) Playing.cpp: the main workflow of Symbol-Shot in playing stage.<br />
      9) Playing.h: header file of Playing.cpp<br />
      10) Record.cpp: to save, store, show, and restore the users' game records in Symbol-Shot. These records are saved in txt files, and can be accessed after quit the game.<br />
      11) Record.h: header file of Record.cpp<br />
      12) Timer.cpp: to store the current status of timer (Pause or not? Stop or not?) and return the time of every points.<br />
      13) Timer.h: header file of class Timer.<br />

4. Non-Standard C/C++ libraries<br />
  No Non-Standard C/C++ library is used in this program.
  
5. Compilation and Execution instructions<br />
  (1) make clean //clean all the .o files and main.
  (2) make main  //compile all the .o files and main.
  (3) ./main     // execute main function
</pre>

