

ex_calculator: RPNCalculator.o RPNCalculator1.o RPNCalculatorDriver.o
	g++ RPNCalculator.o RPNCalculator1.o RPNCalculatorDriver.o -o ex_calculator


RPNCalculator.o: RPNCalculator.cpp
	g++ -c RPNCalculator.cpp -o RPNCalculator.o

RPNCalculator1.o: RPNCalculator.hpp
	g++ -c RPNCalculator.hpp -o RPNCalculator1.o


RPNCalculatorDriver.o: RPNCalculatorDriver.cpp
	g++ -c RPNCalculatorDriver.cpp -o RPNCalculatorDriver.o

clean:
	rm *.o ex_calculator