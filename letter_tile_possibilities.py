# very similar to Permutations - II
def main():
    def numTilePossibilities(tiles: str) -> int:
        def recur(path, hashmap):
            if len(path) > len(tiles):
                return
            res.append(list(path))
            for val in hashmap:
                if hashmap[val] > 0:
                    path.append(val)
                    hashmap[val] -= 1
                    recur(path, hashmap)
                    path.pop()
                    hashmap[val] += 1

        hashmap = {}
        for tile in tiles:
            if tile in hashmap:
                hashmap[tile] += 1
            else:
                hashmap[tile] = 1
        res = []
        recur([], hashmap)
        return len(res) - 1

    tiles = "AAB"
    print(numTilePossibilities(tiles))


if __name__ == '__main__':
    main()
