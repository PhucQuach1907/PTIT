import itertools
str = input()
for x in itertools.permutations(str, len(str)):
    print("".join(x))