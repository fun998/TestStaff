FindService : main.o stdsoap2.o discoWSC.o wsaapi.o wsddapi.o discoWSClient.o
	gcc main.o stdsoap2.o discoWSC.o wsaapi.o wsddapi.o discoWSClient.o -o FindService

main.o : main.c stdsoap2.o wsaapi.o wsddapi.o wsdd.nsmap discoWSH.h \
discoWSStub.h
	gcc -c main.c -o main.o

discoWSClient.o : discoWSH.h
	gcc -c discoWSClient.c -o discoWSClient.o

wsddapi.o : wsaapi.o wsddapi.c wsddapi.h
	gcc -c wsddapi.c -o wsddapi.o

wsaapi.o : discoWSC.o wsaapi.c wsaapi.h
	gcc -c wsaapi.c -o wsaapi.o

threads.o : threads.c threads.h
	gcc -c threads.c -o threads.o

stdsoap2.o : stdsoap2.c stdsoap2.h
	gcc -c stdsoap2.c -o stdsoap2.o

discoWSC.o : discoWSC.c discoWSH.h discoWSStub.h
	gcc -c discoWSC.c -o discoWSC.o

.PHONY clean :
clean:
	rm *.o
