def Check(s):
    if s[0] != "6":
        return False
    for i in range(len(s)):
        if s[i] != "6" and s[i] != "8":
            return False
        if i >= 2 and s[i - 2:i + 1:] == "888":
            return False
    return True


s = input()
print("YES" if Check(s) else "NO")