PREFIX = /usr
LUALIB = $(PREFIX)/local/lib/lua/5.1
CFLAGS = -O2 -Wall -fPIC -shared
TARGET = network

INCS   = -I$(PREFIX)/include/lua5.1
LIBS   = -Lm

all:
	$(CC) $(CFLAGS) $(LIBS) $(INCS) $(TARGET).c -o $(TARGET).so
clean:
	rm $(TARGET).so
install:
	mv $(TARGET).so $(LUALIB)
