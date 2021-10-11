import sys
from typing import List
from copy import deepcopy


class Poly:
	def __init__(self, b: int, n: int, m: int, c: int, p: list) -> None:
		self.b = b
		self.n = n
		self.m = m
		self.c = c
		self.p = deepcopy(p)

	def __repr__(self) -> str:
		s = []
		for t in self.p:
			s.append(t)
		return "\n".join(s)

class Board:
	pass

def main():
	# input
	n, k, b = map(int, input().split())
	# print(n, k, b, file=sys.stderr)
	marks: list = []
	for i in range(k):
		marks.append(tuple(map(int, input().split())))
	# print(marks, file=sys.stderr)
	poly_list: list = []
	for i in range(b):
		ni, mi, ci = map(int, input().split())
		p = []
		for j in range(ni):
			p.append(input())
		poly_list.append(Poly(i + 1, ni, mi, ci, p))
	# for p in poly_list:
		# print(p, file=sys.stderr)


if __name__ == '__main__':
	main()