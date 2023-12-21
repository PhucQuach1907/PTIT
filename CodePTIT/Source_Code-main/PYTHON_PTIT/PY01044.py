s1 = set(sorted(input().lower().split()))
s2 = set(sorted(input().lower().split()))
print(" ".join(sorted(s1 | s2)))
print(" ".join(sorted(s1 & s2)))
