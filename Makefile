FLAGS = -pedantic-errors -std=c++11

instruction.o: instruction.cpp instruction.h
	g++ $(FLAGS) -c $<

Timer.o: Timer.cpp NewGame.h
	g++ $(FLAGS) -c $<

Playing.o: Playing.cpp Timer.h Record.h Menu.h NewGame.h
	g++ $(FLAGS) -c $<

NewGame.o: NewGame.cpp Timer.h Playing.h
	g++ $(FLAGS) -c $<

Record.o: Record.cpp Timer.h
	g++ $(FLAGS) -c $<

Menu.o: Menu.cpp Playing.h NewGame.h Record.h instruction.h
	g++ $(FLAGS) -c $<

main.o: main.cpp Menu.h Record.h
	g++ $(FLAGS) -c $<

main: Timer.o Playing.o NewGame.o Record.o instruction.o Menu.o main.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f instruction.o Timer.o Playing.o NewGame.o Record.o Menu.o main.o main
  
.PHONY: clean