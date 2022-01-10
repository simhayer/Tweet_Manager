testA4: queueFunctions.o miscFunctions.o testA4.o helper.o
	gcc -Wall -std=c99 -lm queueFunctions.o miscFunctions.o helper.o testA4.o -o testA4
queueFunctions.o: queueFunctions.c header.h
	gcc -Wall -std=c99 -lm -c queueFunctions.c
miscFunctions.o: miscFunctions.c header.h
	gcc -Wall -std=c99 -lm -c miscFunctions.c
testA4.o: testA4.c header.h
	gcc -Wall -std=c99 -lm -c testA4.c
helper.o: helper.c header.h
	gcc -Wall -std=c99 -lm -c helper.c
clean:
	rm *.o testA4