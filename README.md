# PERSONAL LEET CODE SOLUTIONS REPO

I use this repository to record my leet code daily challenge solutions, I also like to plot the execution times of my solutions and compare them, also to check it's time complexity. This is a personal repo so don't expect any explanation of how i got to the solutions, but you may be interested in the plot tool I use which works on python:

to use it, simply enter the venv with

```
source pyenv/bin/activate
```

( Disclaimer, you must have linux for the program to work as it is intended )

Here is an example of how to plot time complexities with the first solution I published here:


Compile it (If it's C):
```
g++ -o main 1000-1500/1442/1442.cpp
```

Run it
```
./main 15
```

Plot it ( Requires Linux Pipes )
```
./main 15 | ./plotit
```
