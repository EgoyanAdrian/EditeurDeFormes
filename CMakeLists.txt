cmake_minimum_required(VERSION 3.1)

project(EDF)

set(HEADERS
	include/EDF/Circle.hpp
	include/EDF/Triangle.hpp
	include/EDF/Point.hpp
	include/EDF/Polygon.hpp
	include/EDF/Shape.hpp
	include/EDF/Square.hpp
	include/EDF/Rectangle.hpp
	include/EDF/Ellipse.hpp
	include/Drawable/Menu.hpp
	include/Drawable/menuOutils.hpp
	include/Drawable/menuInfo.hpp
	include/Drawable/SquareDrawable.hpp
	include/Drawable/PointsDrawable.hpp
	include/Drawable/Color.hpp
	include/Drawable/EllipseDrawable.hpp
	include/Drawable/PolygonDrawable.hpp
	include/Drawable/TriangleDrawable.hpp
	include/Drawable/Points.hpp
	include/Drawable/RectangleDrawable.hpp
	include/Drawable/ShapesDrawable.hpp
	include/Drawable/CircleDrawable.hpp
	include/Drawable/Shapes.hpp
	)

set(SOURCES
	src/EDF/Point.cpp
	src/Drawable/menuInfo.cpp
	src/Drawable/Menu.cpp
	src/Drawable/menuOutils.cpp
	src/Drawable/EllipseDrawable.cpp
	src/Drawable/TriangleDrawable.cpp
	src/Drawable/RectangleDrawable.cpp
	src/Drawable/ShapesDrawable.cpp
	src/Drawable/SquareDrawable.cpp
	src/Drawable/CircleDrawable.cpp
	src/Drawable/PointsDrawable.cpp
	src/Drawable/Color.cpp
	src/main.cpp
	)

include_directories(include/lib/SFML)

add_executable(edf ${SOURCES} ${HEADERS})
target_link_libraries(edf sfml-graphics)
target_link_libraries(edf sfml-system)
target_link_libraries(edf sfml-window)
target_include_directories(edf PRIVATE ${CMAKE_SOURCE_DIR})