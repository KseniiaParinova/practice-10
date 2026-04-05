CC = gcc
CFLAGS = -Wall -Wextra -fPIC
LDFLAGS = -lm

# Определение ОС
ifeq ($(OS),Windows_NT)
    STATIC_LIB = libmathutils.a
    SHARED_LIB = mathutils.dll
    IMPORT_LIB = libmathutils.dll.a
    EXE_STATIC = program_static.exe
    EXE_SHARED = program_shared.exe
    SHARED_FLAGS = -shared -Wl,--out-implib,$(IMPORT_LIB)
    EXPORT_DEF = -DMATHUTILS_EXPORTS
    RM = del /Q
else
    STATIC_LIB = libmathutils.a
    SHARED_LIB = libmathutils.so
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

mathutils_static.o: mathutils.c mathutils.h
	$(CC) $(CFLAGS) -c mathutils.c -o mathutils_static.o

$(STATIC_LIB): mathutils_static.o
	ar rcs $@ $^

$(EXE_STATIC): main.c $(STATIC_LIB)
	$(CC) $(CFLAGS) main.c -L. -lmathutils $(LDFLAGS) -o $@

# Динамическая библиотека
shared: $(SHARED_LIB) $(EXE_SHARED)

mathutils_shared.o: mathutils.c mathutils.h
	$(CC) $(CFLAGS) $(EXPORT_DEF) -c mathutils.c -o mathutils_shared.o

$(SHARED_LIB): mathutils_shared.o
	$(CC) $(SHARED_FLAGS) $^ -o $@

$(EXE_SHARED): main.c $(SHARED_LIB)
	$(CC) $(CFLAGS) main.c -L. -lmathutils $(LDFLAGS) -o $@

clean:
	$(RM) *.o *.a *.so *.dll $(EXE_STATIC) $(EXE_SHARED) 2>/dev/null || true