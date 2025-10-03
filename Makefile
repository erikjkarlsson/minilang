BIN				:= bin/ml
UNITTESTS := tests/test1.mln
SRC_D := src

all:  $(BIN)

$(SRC_D)/ml.tab.c $(SRC_D)/ml.tab.h: $(SRC_D)/ml.y
	cd src && bison -Wconflicts-sr -Wcounterexamples -t -v -d ml.y

$(SRC_D)/lex.yy.c: $(SRC_D)/ml.l $(SRC_D)/ml.tab.h
	cd src &&	flex ml.l

$(BIN): $(SRC_D)/lex.yy.c $(SRC_D)/ml.tab.c $(SRC_D)/ml.tab.h $(SRC_D)/env.c
	cd src && gcc -g -o ml lex.yy.c env.c ml.tab.c && mv ml ../$(BIN)
	chmod +x $(BIN)

clean:

	rm $(SRC_D)/ml.tab.c $(SRC_D)/lex.yy.c $(SRC_D)/ml.tab.h
	rm $(SRC_D)/ml.output
	rm $(BIN)

test: $(BIN)
	./$(BIN) < $(UNITTESTS)
