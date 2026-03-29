all:
	g++ ./src/main.cpp ./src/sorting/implementation/*.cpp ./src/utils/implementation/*.cpp -o src/sorting-benchmark && ./src/sorting-benchmark