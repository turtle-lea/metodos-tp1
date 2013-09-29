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
	rm -f -r bin obj timetests

test1: folder obj/funciones.o obj/metodos.o obj/criterios.o
	$(CC) -c src/test1.cpp -o obj/test1.o
	$(CC) -o bin/test1 obj/test1.o obj/funciones.o obj/metodos.o obj/criterios.o

tester: folder obj/funciones.o obj/metodos.o obj/criterios.o
	$(CC) -c src/tester.cpp -o obj/tester.o
	$(CC) -o bin/tester obj/tester.o obj/funciones.o obj/metodos.o obj/criterios.o
	
testearMetodos: folder folder obj/funciones.o obj/metodos.o obj/criterios.o
	$(CC) -c src/testearMetodos.cpp -o obj/testearMetodos.o
	$(CC) -o bin/testearMetodos obj/testearMetodos.o obj/funciones.o obj/metodos.o obj/criterios.o

testearError: folder folder obj/funciones.o obj/metodos.o obj/criterios.o
	$(CC) -c src/tester_error.cpp -o obj/tester_error.o
	$(CC) -o bin/tester_error obj/tester_error.o obj/funciones.o obj/metodos.o obj/criterios.o

testearBiseccion: folder obj/funciones.o obj/metodos.o obj/criterios.o
	$(CC) -c src/tester_biseccion.cpp -o obj/tester_biseccion.o
	$(CC) -o bin/tester_biseccion obj/tester_biseccion.o obj/funciones.o obj/metodos.o obj/criterios.o

time: folder obj/funciones.o obj/metodos.o obj/criterios.o
	mkdir -p ./timetests
	$(CC) -c src/time_tester.cpp -o obj/time_tester.o
	$(CC) -o bin/time obj/time_tester.o obj/funciones.o obj/metodos.o obj/criterios.o