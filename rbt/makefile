OPENCV_LIBS=`pkg-config --cflags --libs /usr/local/Cellar/opencv/4.5.1_3/lib/pkgconfig/opencv4.pc`
CFLAGS=-g

run.out: rbt.cpp viz.cpp main.cpp
	g++ $(OPENCV_LIBS) $(CFLAGS) -std=c++11 rbt.cpp viz.cpp main.cpp -o run.out 
