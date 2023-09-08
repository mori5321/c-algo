# run.test:
# 	clang \
# 	*.c
# 	test.c \
# 	sentinel_search.c \
# 	sentinel_search_test.c \
# 	linear_search_test.c \
# 	linear_search.c \
# 	-o test.out && ./test.out ; rm ./test.out

SHELL := /bin/zsh

CC = clang
CFLAGS = 
LIB=$(shell find ./lib -name "*.c")
# LIB= $(wildcard ./lib/*.c) $(wildcard ./lib/*/*.c)

build:
	$(CC) $(CFLAGS) -c $(LIB)

clean:
	rm ./**/*.o

test:
	make build
	$(CC) $(CFLAGS) -o test.out ./tests/**/*.c ./**/*.o
	./test.out; rm ./test.out
	make clean







#
# run.test: $(SOURCES)
# 	$(CC) $(CFLAGS) $(SOURCES) -o $(OUT)
# 	./$(OUT) ; rm -f $(OUT)
#
# build:
# 	$(CC) $(CFLAGS) linear_search_test.c test_util.c -o $ linear_search_test.o
# 	$(CC) $(CFLAGS) sentinel_search_test.c test_util.c -o $ sentinel_search_test.o
#
