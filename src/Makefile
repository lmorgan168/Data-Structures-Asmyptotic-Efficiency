CC = cl
CFLAGS = /std:c++17 /EHsc /O2 /I.
LDFLAGS = /Fe:timing.exe

SRCS = timing.cpp words.cpp
OBJS = timing.obj words.obj

all: timing.exe

timing.exe: $(OBJS)
    $(CC) $(LDFLAGS) $(OBJS)

.cpp.obj:
    $(CC) $(CFLAGS) /c $<

clean:
    del $(OBJS) timing.exe
