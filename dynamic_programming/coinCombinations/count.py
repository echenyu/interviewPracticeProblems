def count(S, n):

	table = [[0 for x in range(4)] for x in range(n+1)]

	for i in range(4):
		table[0][i] = 1

	for i in range(1, n+1):
		for j in range(4):
			if i - S[j] >= 0:
				x = table[i - S[j]][j]
			else:
				x = 0
			if (j >= 1):
				y = table[i][j-1]
			else:
				y = 0

			table[i][j] = x + y

	return table[n][3]



def main():
	arr = [1, 5, 10, 25]
	n = 25
	print(count(arr, n))

import time
start_time = time.time()
main()
print("--- %s milliseconds ---" % (int(round(1000*(time.time() - start_time)))))