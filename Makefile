main: main.cpp
	g++ main.cpp ball.cpp objects.cpp -o game.exe -O1 -Wall -Wno-missing-braces -Iinclude/ -Llib/ -lraylib -lopengl32 -lgdi32 -lwinmm