def Solve():
    sentence = input()
    print(sentence[0:sentence.rfind(" ", 0, 100)]
          if len(sentence) > 100 else sentence)


if __name__ == "__main__":
    for _ in range(int(input())):
        Solve()
