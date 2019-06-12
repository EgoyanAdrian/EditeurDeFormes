g++ -c -Wall BaseShapes/*.cpp
g++ -c -Wall DrawableShapes/*.cpp
g++ -c -Wall GuiMenu/*.cpp
g++ -c -Wall main.cpp

g++ main.o Menu.o menuOutils.o menuInfo.o Point.o PointsDrawable.o ShapesDrawable.o RectangleDrawable.o SquareDrawable.o CircleDrawable.o EllipseDrawable.o TriangleDrawable.o Color.o -lsfml-system -lsfml-window -lsfml-graphics -o run

rm *.o
