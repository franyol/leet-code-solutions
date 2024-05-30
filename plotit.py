#! /usr/bin/env python3

import plotext as plt
import sys
from time import sleep
import typer

def main( winsize: int = 61, hist: bool = False ):
    """!

    examples: \n
        * topic_record.py "USI" wan_cellular1,signal_stats,sinr --count 1000 | plotit.py --hist --winsize 500\n
        * topic_record.py 4A000 motors_current,current_fr motors_current,current_rr motors_current,current_rl motors_current,current_fl | plotit.py

    """
    title = input().strip()
    axes = input().strip()

    axes_names = axes.split()
    axes = [{"name": name, 'y': []} for name in axes_names]

    print("Waiting for data")

    for line in sys.stdin:
        plt.title(title)
        line = line.split()
        if len(line) != len(axes_names):
            continue

        skip = False
        for i in range(len(line)):
            try:
                float(line[i])
            except:
                skip = True
        if skip:
            continue
        for i in range(len(line)):
            axes[i]['y'].append(float(line[i]))

        # Winsize limit
        if len(axes[0]['y']) > winsize:
            for ax in axes:
                ax['y'].pop(0)
        
        for ax in axes:
            if hist:
                plt.hist(ax['y'], 60, label=ax["name"])
            else:
                plt.plot(ax['y'], label=ax["name"])
         
        plt.theme('clear')
        plt.show()
        plt.clear_figure()

if __name__ == "__main__":
    typer.run(main)

