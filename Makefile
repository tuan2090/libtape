CC = /bin/gcc
CFLAGS = -Wall
CMAIN = ./main.c
COUTPUT = ./bin/tapescript

$(COUTPUT): $(CMAIN)
	$(CC) $(CFLAGS) -o $(COUTPUT) $(CMAIN)
