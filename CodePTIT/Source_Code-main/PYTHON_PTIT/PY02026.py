n, m = map(int, input().split())
A = set(sorted(list(map(int, input().split()))))
B = set(sorted(list(map(int, input().split()))))
print("YES" if A == B else "NO")
