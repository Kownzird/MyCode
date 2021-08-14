objects = main.o input.o calcu.o

main:$(objects)
	gcc $(objects) -o main

main.o:main.c
	gcc main.c -c -o main.o

input.o:input.c
	gcc input.c -c -o input.o

calcu.o:calcu.c
	gcc calcu.c -c -o calcu.o

clean:
	rm *.o
	rm main