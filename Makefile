build:
	clang++ -O3 -std=c++20 main.cpp -o renderer

clean:
	rm renderer