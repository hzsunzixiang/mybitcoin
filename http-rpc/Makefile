.PHONY:clean all
CC=gcc
CFLAGS=-Wall -g 

INCLUDE = -I/usr/local/include/event2

LIB =-L/usr/local/lib -lrt -levent 
LIBHTTPS = -levent -levent_openssl -lssl -lcrypto  -lcurl 

BIN=http-server myserver evhttp_new myconnect  http-client http-client-s


all:$(BIN) #$(BINHTTPS)

$(BIN):%:%.c 
	$(CC) $(CFLAGS)  $^ $(LIB) $(INCLUDE) -o $@

clean:
	rm -f *.o $(BIN) $(BINHTTPS)

