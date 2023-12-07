"""
processData.py

Description: reads two text files and reconstructs their contents to produce the complete output.

Command Line Arguments: inputfile

Example Invocation: python3 processData.py file.csv

"""

import sys
import csv

with open(sys.argv[1], mode ='r') as file:
    reader = csv.reader(file)
    next(reader)
    data = []
    for lines in reader:
        data.append(float(lines[1]))

print(f"Feed data: {data}")
file.close()

minNum = data[0]
maxNum = data[0]

for x in data:
    if x > maxNum:
        maxNum = x
    if x < minNum:
        minNum = x

dataSum = 0

for y in data:
    dataSum = dataSum + y

average = dataSum / len(data)
print(f"Avg: {average} Min: {minNum} Max: {maxNum}")