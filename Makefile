all: ConsoleApplication

ConsoleApplication: ConsoleApplication1.cpp
	g++ -O1 ConsoleApplication1.cpp -o ConsoleApplication1
	g++ -g ConsoleApplication1.cpp -o ConsoleApplication1debug


clean:
	del ConsoleApplication1.exe ConsoleApplication1debug.exe