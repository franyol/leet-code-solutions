// Compile:
// g++ -o main 0-500/344/344.cpp
//
// Plot time complexities:
// ./main 15 | ./plotit
 
#include "344-intuition.h"
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <climits>

void print_vect ( const std::vector<int>& vect );

int main ( int argc, char* argv[] ) {

	if ( argc < 2 ) {
		std::cerr << "Usage: " << argv[0] << " <N_MAX:[int]>" << std::endl;
		return 1;
	}

	// Seed with a real random value, if available
    std::random_device rd;
    std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(CHAR_MIN, CHAR_MAX);

	intuition::Solution _intuition; 

	std::cout << "Day 344.cpp runtime (ms) vs N" << std::endl;
	std::cout << "intuition" << std::endl;

	std::chrono::duration<double, std::milli> elapsed;
	for ( int i = 1; i < stoi(argv[1]); i++ ) {
		if ( i < 2 ) {
			std::cout << "0" << std::endl;
			continue;
		}

		std::vector<char> input;
		input.reserve(i);
		
		// Make input array
		for ( int  j=0; j<i; j++ ) {
			input.push_back(static_cast<char>(dist(gen)));
		}
		
		// Time both methods
		/*
		auto start = std::chrono::high_resolution_clock::now();
		_intuition.countTriplets( input );
		auto end = std::chrono::high_resolution_clock::now();
		elapsed = end - start;
		std::cout << elapsed.count() << " ";
		*/

		auto start = std::chrono::high_resolution_clock::now();
		_intuition.reverseString( input );
		auto end = std::chrono::high_resolution_clock::now();
		elapsed = end - start;
		std::cout << elapsed.count() << std::endl;
	}

	return 0;
}

