g++ -c -Wall *.cpp

g++ main.o Menu.o Text.o Point.o PointsDrawable.o ShapesDrawable.o RectangleDrawable.o CircleDrawable.o -lsfml-system -lsfml-window -lsfml-graphics -o run

rm *.o