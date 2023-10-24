CC = gcc
CFLAGS =
LDFLAGS =
OBJFILES = utils.o main.o
TARGET = main
all: $(TARGET)
$(TARGET) : $(OBJFILES)
$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
rm -f $(OBJFILES) $(TARGET) *~