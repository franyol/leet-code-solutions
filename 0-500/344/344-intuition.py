from typing import List
from typer import run
import random
import datetime

class Solution(object):
    def reverseString(self, s: List[str]) -> None:
        for i in range (len(s)//2) :
            temp = s[i]
            s[i] = s[-1-i]
            s[-i-1] = temp

def main ( n: int ):
    letters = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
    input = [];
    print ( "344 python version: execution ms vs N" )
    print ( "intuition" )
    for i in range (n):
        for _ in range (i):
            input.append( random.choice( letters ) )

        sol = Solution()

        start = datetime.datetime.now()
        sol.reverseString( input )
        end = datetime.datetime.now()

        print ( (end - start).total_seconds() * 1000 )

if __name__ == "__main__":
    run(main)

