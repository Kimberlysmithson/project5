Targets=stock


#application builds
all: $(TARGETS)
stock: iofun.o main.o stock.o transaction.o portfolio.o
	g++ -o $@ $^

#object files
iofun.o: iofun.h iofun.cpp
main.o: main.cpp iofun.h stock.h transaction.h portfolio.h
stock.o: stock.h stock.cpp
transaction.o: transaction.cpp transaction.h
portfolio.o: portfolio.cpp portfolio.h


#delete all binaries
clean:
	rm -f *.o $(TARGETS)
