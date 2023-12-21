class Candidate:
    def __init__(self, orderNumber, name, teamCode, teamName):
        self.code = "C%03d" % (orderNumber)
        self.name = name
        self.teamCode = teamCode
        self.teamName = teamName

    def __str__(self):
        return self.code + " " + self.name + " " + self.teamCode + " " + self.teamName


if __name__ == "__main__":
    n = int(input())
    hashTeam = {}
    for i in range(n):
        code, name = input(), input()
        hashTeam["Team%02d" % (i+1)] = [code, name]
    m = int(input())
    candidates = []
    for i in range(m):
        name = input()
        tmp = input()
        candidates.append(
            Candidate(i+1, name, hashTeam[tmp][0], hashTeam[tmp][1]))
    candidates.sort(key=lambda x: x.name)
    for candidate in candidates:
        print(candidate)
