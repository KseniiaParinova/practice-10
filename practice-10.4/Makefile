CC = gcc
CFLAGS = -Wall -Wextra -fPIC
VERSION = 1.0.0
SONAME = libcalc.so.1
REAL_NAME = libcalc.so.$(VERSION)

.PHONY: all clean test run info

all: $(REAL_NAME) $(SONAME) libcalc.so test

calc.o: calc.c calc.h
	$(CC) $(CFLAGS) -c calc.c -o calc.o

# Создание версионированной библиотеки
$(REAL_NAME): calc.o
	$(CC) -shared -Wl,-install_name,$(SONAME) calc.o -o $(REAL_NAME)

# Символическая ссылка для soname (нужна для запуска)
$(SONAME): $(REAL_NAME)
	ln -sf $(REAL_NAME) $(SONAME)

# Символическая ссылка для компиляции
libcalc.so: $(REAL_NAME)
	ln -sf $(REAL_NAME) libcalc.so

test: main.c libcalc.so
	$(CC) main.c -L. -lcalc -o test_program

run: test $(SONAME)
	./test_program

info: $(REAL_NAME)
	@echo "=== Структура библиотеки ==="
	ls -la libcalc*
	@echo ""
	@echo "=== install_name из библиотеки ==="
	otool -D $(REAL_NAME)
	@echo ""
	@echo "=== Зависимости test_program ==="
	otool -L test_program

clean:
	rm -f *.o test_program

distclean: clean
	rm -f libcalc.so* test_program
