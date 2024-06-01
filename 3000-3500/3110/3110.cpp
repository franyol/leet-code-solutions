// Compile:
// g++ -o main 3000-3500/3110/3110.cpp
//
// Plot time complexities:
// ./main 15 | ./plotit
 
#include "3110-intuition.h"
#include <iostream>
#include <string>
#include <random>
#include <chrono>

int main ( int argc, char* argv[] ) {

	if ( argc < 2 ) {
		std::cerr << "Usage: " << argv[0] << " <N_MAX:[int]>" << std::endl;
		return 1;
	}

	// Seed with a real random value, if available
    std::random_device rd;

    // Choose a random number generator
    std::mt19937 gen(rd());

    // Define the range
    std::uniform_int_distribution<> dis(97, 122);

	intuition::Solution _intuition; 

	std::cout << "Day 3110.cpp exeution (ms) vs N" << std::endl;
	std::cout << "intuition" << std::endl;

	std::chrono::duration<double, std::milli> elapsed;
	for ( int i = 1; i < stoi(argv[1]); i++ ) {
		if ( i < 2 ) std::cout << "0" << std::endl;

		std::string input = "";
		// Make input array
		for ( int j = 0; j < i; j++ ) {
			input.push_back( (char) dis(gen) );	
		}

		// Time both methods
		const char* st = input.c_str();
		const int n = input.length();
		auto start = std::chrono::high_resolution_clock::now();
		_intuition.scoreOfString( st, n );
		auto end = std::chrono::high_resolution_clock::now();
		elapsed = end - start;
		std::cout << elapsed.count() << std::endl;
	}

	return 0;
}
