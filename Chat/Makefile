all: server.o client.o
	g++ server.o -o server
	g++ client.o -o client

server.o: ./src/server.cpp 
	g++ -c ./src/server.cpp 

client.o: ./src/client.cpp
	g++ -c ./src/client.cpp

clean:
	rm *.o server client