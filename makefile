all: main

main: main.cpp public.cpp public.h
	@g++ -g -o main main.cpp public.cpp -lstdc++fs

clean:
	rm -f main