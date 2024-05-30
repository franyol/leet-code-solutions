#include <vector>
#include <iostream>

using namespace std;

namespace greedy
{
	class Solution {
		public:
			int countTriplets(vector<int>& arr) {
				int count = 0;
				int N = arr.size();

				for ( int j = 0; j < N-1; j++ ) {
					int last = 0;
					for ( int i = j; i < N; i++ ) {
						last ^= arr[i];
						if ( last == 0 ) {
							count += i - j;
						}
					}
				}
				return count;
			}
	};
}


