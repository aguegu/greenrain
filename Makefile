CC = g++
CFLAGS = -O2 -g -Wall 

SOURCES = greenrain.cpp dropflow.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = greenrain

:$(TARGET)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) -lcurses

clean: 
	rm -rvf $(OBJECTS) $(TARGET)
