#include <vector>
#include <iostream>

using namespace std;

namespace intuition
{
	bool isTriplet ( vector<int>& arr, int i, int j, int k );

	class Solution {
		public:
			int countTriplets(vector<int>& arr) {
				int count = 0,
					N = arr.size();

				for ( int i = 0 ; i < N-1 ; i++ ) {
					for ( int j = i+1; j < N ; j++ ) {
						for ( int k=j; k < N ; k++ ) {
							if (isTriplet ( arr, i, j, k ))
								count ++;
						}
					}
				} 
				return count;
			}
	};

	bool isTriplet ( vector<int>& arr, int i, int j, int k ) {
		int a = arr[i];
		int b = arr[j];
		for ( int a_i=i+1; a_i < j; a_i++ ) {
			a ^= arr[a_i];
		}
		for ( int b_i=j+1; b_i <= k; b_i++ ) {
			b ^= arr[b_i];
		}
		return a == b;
	}
}
