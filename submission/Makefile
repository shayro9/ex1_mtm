CC = gcc
EXEC = AsciiArtTool
OBJS = tool/AsciiArtTool.o RLEList.o tool/main.o
DEBUG_FLAG = -g
COMP_FLAG = -std=c99 -Wall -Werror
INCLUDES = -I/home/mtm/public/2122b/ex1 -Itool
TOOLTARGET = $*.c -o $@

$(EXEC): $(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@

RLEList.o : RLEList.c tool/RLEList.h
	$(CC) -c $(INCLUDES) $(DEBUG_FLAG) $(COMP_FLAG) $(TOOLTARGET)

tool/AsciiArtTool.o : tool/AsciiArtTool.c tool/AsciiArtTool.h tool/RLEList.h
	$(CC) -c $(INCLUDES) $(DEBUG_FLAG) $(COMP_FLAG) $(TOOLTARGET)

tool/main.o: tool/main.c tool/AsciiArtTool.h
	$(CC) -c $(INCLUDES) $(DEBUG_FLAG) $(COMP_FLAG) $(TOOLTARGET)

clean:
	rm -f $(OBJS) $(EXEC)