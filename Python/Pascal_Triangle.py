def pascal_triangle(n):
    if n == 0:
        return []
    elif n == 1:
        return [[1]]
    else:
        prev = pascal_triangle(n-1)
        curr = [1]
        for i in range(len(prev[-1])-1):
            curr.append(prev[-1][i]+prev[-1][i+1])
        curr.append(1)
        prev.append(curr)
        return prev

for i in pascal_triangle(5):
    print(i)