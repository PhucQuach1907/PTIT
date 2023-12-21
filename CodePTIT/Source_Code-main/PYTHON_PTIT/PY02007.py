import sys
diff = set()
for line in sys.stdin:
    for var in line.split():
        diff.add(int(var) % 42)
print(len(diff))
