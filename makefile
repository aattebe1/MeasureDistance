CC=gcc
CFLAGS=-lwiringPi -lrt
SRC_DIR=./src
OBJ_DIR=./obj
SRC=MeasureDistance.c HCSR04.c LCM1602.c
OBJ=MeasureDistance.o HCSR04.o LCM1602.o

%.o: $(SRC)
	$(CC) -c -o $(OBJ_DIR)/$@ $(SRC_DIR)/$^ $(CFLAGS)

MeasureDistance: $(OBJ)
	$(CC) -o $@ $(OBJ_DIR)/$^ $(CFLAGS)
