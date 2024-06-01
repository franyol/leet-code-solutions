#include <string>

using namespace std;

namespace intuition
{
	/*
	 * Time complexity  :  O(N)
	 * Space complexity :  O(1)
	 * */
	class Solution {
		public:
			int scoreOfString(const char* s, const int N) {
				int score = 0;
				for ( int i=0; i < N-1; i++ ) {
					// We could try math abs, but let's do it ourselves
					if (s[i] > s[i+1]) {
						score += s[i] - s[i+1];
					} else {
						score += s[i+1] - s[i];
					}
				}
				return score;
			}
	};
}
