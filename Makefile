BIN				:= bin/ml
UNITTESTS := tests/test1.mln
SRC_D := src

all:  $(BIN)

$(SRC_D)/calc.tab.c $(SRC_D)/calc.tab.h: $(SRC_D)/calc.y
	cd src && bison -Wconflicts-sr -Wcounterexamples -t -v -d calc.y

$(SRC_D)/lex.yy.c: $(SRC_D)/calc.l $(SRC_D)/calc.tab.h
	cd src &&	flex calc.l

$(BIN): $(SRC_D)/lex.yy.c $(SRC_D)/calc.tab.c $(SRC_D)/calc.tab.h $(SRC_D)/env.c
	cd src && gcc -o calc lex.yy.c env.c calc.tab.c && mv calc ../$(BIN)
	chmod +x $(BIN)

clean:
	rm $(BIN)
	rm $(SRC_D)/calc.tab.c $(SRC_D)/lex.yy.c $(SRC_D)/calc.tab.h
	rm $(SRC_D)/calc.output

test: calc
	./$(BIN) < $(UNITTESTS)
