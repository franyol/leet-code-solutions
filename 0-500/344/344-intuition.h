#include <vector>

using namespace std;

namespace intuition
{
	class Solution {
		public:
			void reverseString(vector<char>& s) {
				int N = s.size();
				char temp;
				for ( int i = 0; i < N/2; ++i ) {
					temp = s[i];
					s[i] = s[N-i-1];
					s[N-i-1] = temp;
				}
			}
	};
}
