// Compile:
// g++ -o main 2000-2500/2486/2486.cpp
//
// Plot time complexities:
// ./main 15 | ./plotit
 
#include "2486-intuition.h"
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

	std::cout << "Day 2486.cpp exeution (ms) vs N (s length)" << std::endl;
	std::cout << "intuition" << std::endl;

	std::chrono::duration<double, std::milli> elapsed;
	for ( int i = 1; i < stoi(argv[1]); i++ ) {

		// t string length random
		std::uniform_int_distribution<> dis_N2(static_cast<int>(i-i/2),
												static_cast<int>(i+i/2));
		std::string input_s;
		std::string input_t;
		// Make input array
		for ( int j = 0; j < i; j++ ) {
			input_s.push_back( static_cast<char>(dis(gen)) );	
		}
		int N2 = dis_N2(gen);
		for ( int j = 0; j < N2; j++ ) {
			input_t.push_back( static_cast<char>(dis(gen)) );
		}

		// Time both methods
		auto start = std::chrono::high_resolution_clock::now();
		_intuition.appendCharacters( input_s, input_t );
		auto end = std::chrono::high_resolution_clock::now();
		elapsed = end - start;
		std::cout << elapsed.count() << std::endl;
	}

	return 0;
}
