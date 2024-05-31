// Compile:
// g++ -o main 0-500/260/260.cpp
//
// Plot time complexities:
// ./main 15 | ./plotit
 
#include "260-greedy.h"
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <algorithm>
#include <climits>
#include <set>

void print_vect ( const std::vector<int>& vect );

int main ( int argc, char* argv[] ) {

	if ( argc < 2 ) {
		std::cerr << "Usage: " << argv[0] << " <N_MAX:[int]>" << std::endl;
		return 1;
	}

	// Seed with a real random value, if available
    std::random_device rd;
    std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

	greedy::Solution _greedy; 

	std::cout << "Day 260.cpp runtime (ms) vs N" << std::endl;
	std::cout << "greedy" << std::endl;

	std::chrono::duration<double, std::milli> elapsed;
	for ( int i = 1; i < stoi(argv[1]); i++ ) {
		if ( i < 2 ) {
			//std::cout << "0" << std::endl;
			continue;
		}

		std::vector<int> input;
		std::set<int> numbers_set;
		
		// Make input array
		while ( numbers_set.size() < i ) {
			numbers_set.insert(dist(gen));
		}

		int j = 0;
		for ( auto it = numbers_set.begin(); it != numbers_set.end(); ++it ) {
			if ( j < 2 ) {
				input.push_back( *it );
				j++;
			} else {
				input.push_back( *it );
				input.push_back( *it );
			}
		}
		
		std::shuffle(input.begin(), input.end(), gen);
		std::cerr << std::endl << "Input: " << std::endl;
		print_vect ( input );

		// Time both methods
		/*
		auto start = std::chrono::high_resolution_clock::now();
		_intuition.countTriplets( input );
		auto end = std::chrono::high_resolution_clock::now();
		elapsed = end - start;
		std::cout << elapsed.count() << " ";
		*/

		std::cerr << std::endl << "Output:" << std::endl;
		auto start = std::chrono::high_resolution_clock::now();
		print_vect(_greedy.singleNumber( input ));
		std::cerr << std::endl;
		auto end = std::chrono::high_resolution_clock::now();
		elapsed = end - start;
		std::cout << elapsed.count() << std::endl;
	}

	return 0;
}

void print_vect ( const std::vector<int>& vect ) {
	std::cerr << "[ ";
	for ( const int& n : vect ) {
		std::cerr << n << " ";
	}
	std::cerr << "]";
}
