bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp 

bin/testListLinked: testListLinked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp 

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp

bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o

bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	g++ -c testCircle.cpp -o testCircle.o
	mkdir -p bin
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o

bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o Point2D.o
	g++ -c testRectangle.cpp -o testRectangle.o
	mkdir -p bin
	g++ -o bin/testRectangle testRectangle.o Rectangle.o Shape.o Point2D.o

bin/testSquare: testSquare.cpp Square.o  Rectangle.o Shape.o Point2D.o
	g++ -c testSquare.cpp -o testSquare.o
	mkdir -p bin
	g++ -o bin/testSquare testSquare.o Square.o  Rectangle.o Shape.o Point2D.o

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

Shape.o: Shape.h Shape.cpp
	g++ -c Shape.cpp

Circle.o: Circle.h Circle.cpp
	g++ -c Circle.cpp

Rectangle.o: Rectangle.h Rectangle.cpp
	g++ -c Rectangle.cpp

Square.o: Square.h Square.cpp
	g++ -c Square.cpp

clean:
	rm -r *.o *.gch bin