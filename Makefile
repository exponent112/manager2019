CC = gcc
CFLAG = -W -Wall
TARGET = manager
OBJECTS = menu.o user.o main.o
D_OBJECTS = menu_d.o user_d.o main_d.o

all : $(TARGET)

manager_debug : $(D_OBJECTS)
	$(CC) $(CFLAG) -o $@ ${D_OBJECTS}

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAG) -o ${TARGET} ${OBJECTS}

menu_d.o : menu.c
	$(CC) -DDEBUG_MODE $(CFLAG) -c -o $@ $^

user_d.o : user.c
	$(CC) -DDEBUG_MODE $(CFLAG) -c -o $@ $^	

main_d.o : main.c
	$(CC) -DDUBUG_MODE $(CFLAG) -c -o $@ $^

clean :
	rm *.o manager manager_debug
 
