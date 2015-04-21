GetProfiles: main.o stdsoap2.o duration.o OnvifMediaC.o OnvifMediaClient.o
	gcc main.o stdsoap2.o OnvifMediaC.o duration.o OnvifMediaClient.o -o GetProfiles

main.o: main.c MediaBinding.nsmap OnvifMediaH.h
	gcc -c main.c -o main.o

OnvifMediaClient.o: OnvifMediaClient.c
	gcc -c OnvifMediaClient.c -o OnvifMediaClient.o

duration.o: duration.c duration.h OnvifMediaH.h
	gcc -c duration.c -o duration.o

stdsoap2.o: stdsoap2.c stdsoap2.h
	gcc -c stdsoap2.c -o stdsoap2.o

.PHONY clean:
clean:
	rm *.o
