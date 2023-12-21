from datetime import datetime


class Movie:
    def __init__(self, orderNumber, type, dateRelease, name, episode):
        self.code = "P%03d" % (orderNumber)
        self.type = type
        self.dateRelease = datetime.strptime(dateRelease, '%d/%m/%Y')
        self.t = dateRelease
        self.name = name
        self.episode = int(episode)

    def __str__(self):
        return "%s %s %s %s %s" % (self.code, self.type, self.t, self.name, self.episode)


if __name__ == "__main__":
    n, m = map(int, input().split())
    hashType = {}
    for i in range(n):
        hashType["TL%03d" % (i+1)] = input()
    movies = []
    for i in range(m):
        movies.append(Movie(i+1, hashType[input()], input(), input(), input()))
    movies.sort(key=lambda x: (x.dateRelease, x.name, -x.episode))
    for movie in movies:
        print(movie)
