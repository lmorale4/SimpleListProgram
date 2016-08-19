playerProg.exe: player.o SimpleList.o driver.o
	g++ player.o SimpleList.o driver.o -o playerProg.exe

player.o: player.cpp player.h
	g++ -c player.cpp

SimpleList.o: SimpleList.cpp SimpleList.h
	g++ -c SimpleList.cpp

driver.o: driver.cpp
	g++ -c driver.cpp

clean:
	rm *.o playerProg.exe
