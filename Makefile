all:
	g++ `pkg-config --cflags --libs yaml-cpp` main.cpp -o cssutilitycli -std=c++17
install :
	mv cssutilitycli /usr/local/bin	