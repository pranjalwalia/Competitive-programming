#python code
def fact(n):
    if(n==1):
        return 1
    return (n*fact(n-1))               #using recursive functions print factorial of given number


x = int(input())
print(fact(x))
