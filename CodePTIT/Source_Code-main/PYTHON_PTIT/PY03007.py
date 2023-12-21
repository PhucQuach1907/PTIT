import re
import sys
words = []
for line in sys.stdin:
    for word in line.split():
        words.append(word)
text = " ".join(words)
sentences = re.split(r'[.?!]', text)
for sentence in sentences:
    if (len(sentence) > 0):
        print(sentence.strip().capitalize())
