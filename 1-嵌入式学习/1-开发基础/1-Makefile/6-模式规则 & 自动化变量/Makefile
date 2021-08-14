objects = main.o input.o calcu.o 

main:$(objects)
	gcc $(objects) -o main

%.o : %.c
	gcc $^ -c -o $@

clean:
	rm *.o
	rm main