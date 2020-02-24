#!/bin/python3

import math
import os
import random
import re
import sys

def numberOfPaths(maze):
	MOD = 10**9 + 7
	d = [[[0 for i in range(1002)] for j in range(1002)] for k in range (3)]
	m = len(maze)
	n = len(maze[0])

	for i in range(m):
		for j in range(n):
			if maze[i][j] == 'S':
				startX = i
				startY = j
			if maze[i][j] == 'E':
				endX = i
				endY = j

	d[2][endX][endY] = 1

	for i in range(m - 1, -1, -1):
		if i == m - 1:
			for j in range(endY - 1, -1, -1):
				if maze[i][j] != '#':
					d[1][i][j] = (d[1][i][j + 1] + d[2][i][j + 1]) % MOD
			for j in range(endY + 1, n, 1):
				if maze[i][j] != '#':
					d[0][i][j] = (d[0][i][j - 1] + d[2][i][j - 1]) % MOD
		else:
			for j in range(n):
				if maze[i][j] != '#':
					for k in range(3):
						d[2][i][j] = (d[2][i][j] + d[k][i + 1][j]) % MOD

			for j in range(n - 1, -1, -1):
				if maze[i][j] != '#':
					d[1][i][j] = (d[1][i][j + 1] + d[2][i][j + 1]) % MOD

			for j in range(0, n, 1):
				if maze[i][j] != '#':
					d[0][i][j] = (d[0][i][j - 1] + d[2][i][j - 1]) % MOD


	
	res = 0

	for i in range(3):
		res = (res + d[i][startX][startY]) % MOD

	return res




if __name__ == '__main__':
    #fptr = open(os.environ['OUTPUT_PATH'], 'w')
    sys.stdin = open("input.txt", "r") 

    maze_rows = int(input().strip())
    maze_columns = int(input().strip())

    maze = []

    for _ in range(maze_rows):
        maze.append(list(map(lambda x: x[0], input().rstrip().split())))

    result = numberOfPaths(maze)

    print(str(result) + '\n')

    #fptr.close()
