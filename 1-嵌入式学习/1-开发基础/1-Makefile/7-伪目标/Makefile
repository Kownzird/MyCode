objects = main.o input.o calcu.o 

main:$(objects)
	gcc $(objects) -o main

.PHONY:clean

%.o : %.c
	gcc $^ -c -o $@

clean:
	rm *.o
	rm main