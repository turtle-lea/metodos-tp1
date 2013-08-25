CC = g++

main : obj/main.o obj/funciones.o obj/metodos.o
	$(CC) -o bin/main obj/main.o obj/funciones.o obj/metodos.o 

obj/main.o : src/main.cpp
	$(CC) -c src/main.cpp -o obj/main.o

obj/metodos.o : src/metodos.cpp
	$(CC) -c src/metodos.cpp -o obj/metodos.o

obj/funciones.o : src/funciones.cpp
	$(CC) -c src/funciones.cpp -o obj/funciones.o

clean:
	rm bin/main obj/main.o obj/metodos.o obj/funciones.o


