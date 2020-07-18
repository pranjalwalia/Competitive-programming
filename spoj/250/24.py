def fact(n):
	ans = n
	for i in range(1,n):
		ans = ans*i
	return ans
if __name__=="__main__":
	 t=int(input())
	 for i in range(t):
	 	n = int(input())
	 	print(fact(n))
