import sys
import re


def Processing(line):
    sentence = ""
    for x in line.split():
        sentence += (" "+x if x != "." and x != "!" and x != "?" else x)
    if sentence[-1] != "." and sentence[-1] != "!" and sentence[-1] != "?":
        sentence += "."
    sentence = sentence.strip()
    res = re.split(r'[.?!]', sentence)
    for x in res:
        if len(x) > 0:
            tmp = x + sentence[sentence.find(x) + len(x)]
            print(tmp.strip().capitalize())


if __name__ == "__main__":
    for line in sys.stdin:
        Processing(line.strip().lower())
