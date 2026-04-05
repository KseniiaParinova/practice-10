CC = gcc
CFLAGS = -Wall -Wextra -fPIC

# Определение ОС
ifeq ($(OS),Windows_NT)
    STATIC_LIB = libstrutils.a
    SHARED_LIB = strutils.dll
    IMPORT_LIB = libstrutils.dll.a
    EXE_STATIC = program_static.exe
    EXE_SHARED = program_shared.exe
    SHARED_FLAGS = -shared -Wl,--out-implib,$(IMPORT_LIB)
    EXPORT_DEF = -DSTRUTILS_EXPORTS
    RM = del /Q
else
    STATIC_LIB = libstrutils.a
    SHARED_LIB = libstrutils.so
    IMPORT_LIB = 
    EXE_STATIC = program_static
    EXE_SHARED = program_shared
    SHARED_FLAGS = -shared
    EXPORT_DEF = 
    RM = rm -f
endif

.PHONY: all static shared clean

all: static shared

# Статическая библиотека
static: $(STATIC_LIB) $(EXE_STATIC)

strutils_static.o: strutils.c strutils.h
	$(CC) $(CFLAGS) -c strutils.c -o strutils_static.o

$(STATIC_LIB): strutils_static.o
	ar rcs $@ $^

$(EXE_STATIC): main.c $(STATIC_LIB)
	$(CC) $(CFLAGS) main.c -L. -lstrutils -o $@

# Динамическая библиотека
shared: $(SHARED_LIB) $(EXE_SHARED)

strutils_shared.o: strutils.c strutils.h
	$(CC) $(CFLAGS) $(EXPORT_DEF) -c strutils.c -o strutils_shared.o

$(SHARED_LIB): strutils_shared.o
	$(CC) $(SHARED_FLAGS) $^ -o $@

$(EXE_SHARED): main.c $(SHARED_LIB)
	$(CC) $(CFLAGS) main.c -L. -lstrutils -o $@

clean:
	$(RM) *.o *.a *.so *.dll $(EXE_STATIC) $(EXE_SHARED) 2>/dev/null || true

show-static: $(STATIC_LIB)
	ar -t $(STATIC_LIB)

size:
	ls -lh $(EXE_STATIC) $(EXE_SHARED) 2>/dev/null
