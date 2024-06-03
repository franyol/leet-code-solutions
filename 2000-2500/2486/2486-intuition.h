#include <string>

using namespace std;

namespace intuition
{
	class Solution {
		public:
			int appendCharacters(string s, string t) {
				int sub = 0;
				int max_sub = 0;
				int t_len = t.length();
				int t_idx = 0;
				for ( const char& c : s ) {
					if ( c == t[t_idx] ) {
						sub++;
						t_idx++;
						if ( max_sub < sub ) {
							if ( sub == t_len )
								return 0;
							max_sub = sub;
						}
					} else {
						sub = t_idx = 0;
					}
				}
				return t_len - max_sub;
			}
	};
}
