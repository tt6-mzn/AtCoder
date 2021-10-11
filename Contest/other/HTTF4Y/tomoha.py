import sys
from typing import List
from copy import deepcopy


class Poly:

	def __init__(self, b: int, n: int, m: int, c: int, p: list) -> None:
		self.b = b  # ミノ番号
		self.n = n  # バウンディングボックスの縦
		self.m = m  # バウンディングボックスの横
		self.c = c  # コスト
		self.p = deepcopy(p)  # ミノのマス情報
	
	def __repr__(self) -> str:
		s = []
		for q in self.p:
			t = ''
			for u in q:
				t += u
			s.append(t)
		return "\n".join(s)


class Board:

	def __init__(self, n: int, k: int, b: int, marks: list, poly_list: list) -> None:
		self.n = n  # 盤面サイズ
		self.k = k  # 印の数
		self.b = b  # ミノの種類数
		self.marks = marks  # 印の座標リスト
		self.poly_list = poly_list  # ミノクラスのリスト
		self.board = [['.' for j in range(n)] for i in range(n)]  # 盤面のマス情報
		self.hist = []  # 操作履歴

		self.board_mark = [[False for i in range(self.n)] for j in range(self.n)]
		for i, j in self.marks:
			self.board_mark[i][j] = True

	def __repr__(self) -> str:
		s = []
		for q in self.board:
			t = ''
			for u in q:
				t += u
			s.append(t)
		return "\n".join(s)

	def puttable(self, b: int, x: int, y: int):
		poly = self.poly_list[b]
		p = poly.p
		for i in range(poly.n):
			for j in range(poly.m):
				if x + i < self.n and y + j < self.n:
					if p[i][j]=='#' and self.board[x+i][y+j]=='#':
						return False
				else:
					return False
		return True


	def put(self, b: int, x: int, y: int):
		poly = self.poly_list[b]
		p = poly.p
		for i in range(poly.n):
			for j in range(poly.m):
				self.board[x+i][y+j] = p[i][j]
		self.hist.append((poly.b, x, y))

	
	def put_score(self, b: int, x: int, y: int) -> int:
		ret = 0
		poly: Poly = self.poly_list[b]
		for i in range(poly.n):
			for j in range(poly.m):
				if poly.p[i][j] == "#" and self.board_mark[x + i][y + j]:
					ret += 1
		return ret
	


def main():
	# input
	N, K, B = map(int, input().split())
	print(N, K, B, file=sys.stderr)
	marks: list = []
	for i in range(K):
		marks.append(tuple(map(int, input().split())))
	print(marks, file=sys.stderr)
	poly_list = []
	for b in range(B):
		n, m, c = map(int, input().split())
		p = []
		for i in range(n):
			q = list(input())
			p.append(q)
		poly_list.append(Poly(b, n, m, c, p))
	for p in poly_list:
		print(p, file=sys.stderr)
	# solve
	board = Board(N, K, B, marks, poly_list)

	min_i = N + 1
	min_j = N + 1
	max_i = -1
	max_j = -1
	for i, j in marks:
		min_i = min(min_i, i)
		max_i = max(max_i, i)
		min_j = min(min_j, j)
		max_j = max(max_j, j)
	for i in range(min_i, max_i + 1):
		for j in range(min_j, max_j + 1):
			print(1, i, j)
	


if __name__ == '__main__':
	main()
	# python main.py < in_b/0000.txt
