"""
processData.py

Description: reads two text files and reconstructs their contents to produce the complete output.

Command Line Arguments: inputfile

Example Invocation: python3 processData.py file.csv

"""

import sys
import csv

file1 = open(sys.argv[1], 'r')  
reader = csv.reader(file1)  
headings = next(reader)
data = []

for l in reader:
    data.append(float(l[1]))
    
print(f"Feed data: {data}")
file1.close()

minNum = 0
maxNum = 0

for i in range(len(data)):
    if i == 0:
        minNum = i
        maxNum = i
        continue
    if i > maxNum:
        maxNum = i
    if i < minNum:
        minNum = i
        
dataSum = 0

for i in range(len(data)):
    dataSum += i
    
average = dataSum / len(data)
print(f"Avg: {average} Min: {minNum} Max: {maxNum}")