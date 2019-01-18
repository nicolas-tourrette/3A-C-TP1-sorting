CC = gcc
CFLAGS = -Wall
LDFLAGS =
SRCS = main.c events.c performances.c
OBJFILES = main.o events.o performances.o
OPTIONS = -lm
TARGET = comparaison

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS) $(OPTIONS)

.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<

clean:
	rm -f $(OBJFILES) $(TARGET)

cleanobj:
	rm -f $(OBJFILES)

depend:
	makedepend -I. $(SRCS)

exe: $(TARGET)
	./$(TARGET)

# DO NOT DELETE

main.o: events.h /usr/include/stdio.h /usr/include/stdlib.h
main.o: /usr/include/time.h /usr/include/features.h
main.o: /usr/include/stdc-predef.h /usr/include/math.h /usr/include/string.h
main.o: /usr/include/strings.h
events.o: events.h /usr/include/stdio.h /usr/include/stdlib.h
events.o: /usr/include/time.h /usr/include/features.h
events.o: /usr/include/stdc-predef.h /usr/include/math.h
events.o: /usr/include/string.h /usr/include/strings.h
performances.o: performances.h events.h /usr/include/stdio.h
performances.o: /usr/include/stdlib.h /usr/include/time.h
performances.o: /usr/include/features.h /usr/include/stdc-predef.h
performances.o: /usr/include/math.h /usr/include/string.h
performances.o: /usr/include/strings.h
