CC = g++

main : folder obj/main.o obj/funciones.o obj/metodos.o obj/criterios.o
	$(CC) -o bin/main obj/main.o obj/funciones.o obj/metodos.o obj/criterios.o

folder:
	mkdir -p ./bin
	mkdir -p ./obj

obj/main.o : src/main.cpp
	$(CC) -c src/main.cpp -o obj/main.o

obj/metodos.o : src/metodos.cpp
	$(CC) -c src/metodos.cpp -o obj/metodos.o

obj/funciones.o : src/funciones.cpp
	$(CC) -c src/funciones.cpp -o obj/funciones.o

obj/criterios.o : src/criterios.cpp
	$(CC) -c src/criterios.cpp -o obj/criterios.o

clean:
	rm -f -r bin obj


