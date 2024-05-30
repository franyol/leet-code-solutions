// Compile:
// g++ -o main 1000-1500/1442.cpp
//
// Plot time complexities:
// ./main 15 | ./plotit
 
#include "1442-intuition.h"
#include "1442-greedy.h"
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
    std::uniform_int_distribution<> dis(1, 100000000);

	intuition::Solution _intuition; 
	greedy::Solution _greedy; 

	std::cout << "Day 1442.cpp exeution (ms) vs N" << std::endl;
	std::cout << "intuition greedy" << std::endl;

	std::chrono::duration<double, std::milli> elapsed;
	for ( int i = 1; i < stoi(argv[1]); i++ ) {
		if ( i < 2 ) std::cout << "0 0" << std::endl;

		std::vector<int> input;
		// Make input array
		for ( int j = 0; j < i; j++ ) {
			input.push_back( dis(gen) );	
		}

		// Time both methods
		auto start = std::chrono::high_resolution_clock::now();
		_intuition.countTriplets( input );
		auto end = std::chrono::high_resolution_clock::now();
		elapsed = end - start;
		std::cout << elapsed.count() << " ";

		start = std::chrono::high_resolution_clock::now();
		_greedy.countTriplets( input );
		end = std::chrono::high_resolution_clock::now();
		elapsed = end - start;
		std::cout << elapsed.count() << std::endl;
	}

	return 0;
}
