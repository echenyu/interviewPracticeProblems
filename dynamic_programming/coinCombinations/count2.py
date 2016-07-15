def mincoins(n):
	arr = [0] * (n + 1)
	coins = [1, 5, 10, 25]
	for i in range(len(coins)):
		if coins[i] in range(len(arr)):
			arr[coins[i]] = 1
	for i in range(1, n + 1):
		choices = []
		if arr[i] > 0:
			continue
		for j in range(len(coins)):
			if i - coins[j] >= 0:
				choices.append(1 + arr[i - coins[j]])
		arr[i] = min(choices)
	return arr[n]

def main():
	print(mincoins(9999999))

main()