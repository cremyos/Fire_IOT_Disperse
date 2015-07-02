CC = gcc 
OUT = fire_iot_deal
all:
	$(CC) -o $(OUT) $(OUT).c -I . -Wall
debug:
	$(CC) -g $(OUT).c -o $(OUT) -I .
clean:
	rm $(OUT)

