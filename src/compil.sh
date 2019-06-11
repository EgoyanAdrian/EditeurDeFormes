g++ -c -Wall *.cpp

g++ main.o Menu.o menuOutils.o menuInfo.o Text.o Point.o PointsDrawable.o ShapesDrawable.o RectangleDrawable.o SquareDrawable.o CircleDrawable.o EllipseDrawable.o TriangleDrawable.o Color.o -lsfml-system -lsfml-window -lsfml-graphics -o run

rm *.o
