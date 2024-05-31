#include <vector>
#include <iostream>

using namespace std;

namespace greedy {
	class Solution {
		public: 
			vector<int> singleNumber ( vector<int>& nums ) {
				int xored = 0;
				int N = nums.size();

				for ( int& num : nums ) {
					xored ^= num;
				}

				int rightmost = xored & -xored; // two's compliment

				int n1 = 0, n2 = 0;
				for ( int& num : nums ) {
					if ( rightmost & num ) {
						n1 ^= num;
					} else {
						n2 ^= num;
					}
				}

				return { n1, n2 };
			}
	};
}

