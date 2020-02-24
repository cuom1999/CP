#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'longestPath' function below.
#
# The function is expected to return a STRING.
# The function accepts 2D_CHARACTER_ARRAY maze as parameter.
#

LEFT, RIGHT, DOWN = 0, 1, 2

distMax = [[[-1000000000 for i in range(1505)] for j in range (1505)] for k in range(3)]
direction = [[[0 for i in range(1505)] for j in range(1505)] for k in range(3)]
moveDir = ['L', 'R', 'D']


def update(maze, m, n, d, i, j):
	if maze[i][j] == '#':
		return
	if (d == RIGHT) and (j < n - 1):
		u = distMax[RIGHT][i][j + 1]
		v = distMax[DOWN][i][j + 1]
		if (u > v):
			direction[RIGHT][i][j] = RIGHT; 
			distMax[RIGHT][i][j] = u + 1;
		else:
			direction[RIGHT][i][j] = DOWN;
			distMax[RIGHT][i][j] = v + 1;

	elif (d == LEFT) and (j >= 1):
		u = distMax[LEFT][i][j - 1]
		v = distMax[DOWN][i][j - 1]
		if (u > v):
			direction[LEFT][i][j] = LEFT; 
			distMax[LEFT][i][j] = u + 1;
		else:
			direction[LEFT][i][j] = DOWN;
			distMax[LEFT][i][j] = v + 1;

	elif (d == DOWN):
		maxInd = 0
		maxVal = -1000000000
		for k in range(3):
			u = distMax[k][i + 1][j]
			if (u > maxVal):
				maxVal = u;
				maxInd = k;

		distMax[DOWN][i][j] = maxVal + 1;
		direction[DOWN][i][j] = maxInd;

def longestPath(maze):
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
	distMax[LEFT][endX][endY] = 0;
	distMax[RIGHT][endX][endY] = 0;
	distMax[DOWN][endX][endY] = 0;

	for i in range(m - 1, -1, -1):
		if (i == m - 1):
			for j in range(endY - 1, -1, -1):
				update(maze, m, n, RIGHT, i, j)

			for j in range(endY + 1, n, 1):
				update(maze, m, n, LEFT, i, j)

		else:
			for j in range(n):
				update(maze, m, n, DOWN, i, j);

			for j in range(n - 1, -1, -1):
				update(maze, m, n, RIGHT, i, j);

			for j in range(n):
				update(maze, m, n, LEFT, i, j);
	
	longestPathRes = -1000000000 - 5;
	startDir = -1;

	for i in range(3):
		u = distMax[i][startX][startY];
		if (longestPathRes < u):
			longestPathRes = u;
			startDir = i; 

	if (longestPathRes < 0):
		return "Not_Exist";
	
	curX = startX
	curY = startY
	curDir = startDir
	nextDir = direction[curDir][curX][curY]

	path = ""

	while ((curX != endX) or (curY != endY)):
		path += moveDir[curDir];
		
		if (curDir == 0):
			curY = curY - 1;
		elif (curDir == 1):
			curY = curY + 1
		else:
			curX = curX + 1

		curDir = nextDir;
		nextDir = direction[curDir][curX][curY];

	return path



if __name__ == '__main__':
	sys.stdin = open('input001.txt', 'r')
    
	maze_rows = int(input().strip())

	maze_columns = int(input().strip())

	maze = []

	for _ in range(maze_rows):
		maze.append(list(map(lambda x: x[0], input().rstrip().split())))

	result = longestPath(maze)

	print(result + '\n')
