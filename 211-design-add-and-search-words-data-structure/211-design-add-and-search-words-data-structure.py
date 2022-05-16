class WordDictionary:
    def __init__(self):
        self.dict1 = defaultdict(set)

    def addWord(self, word):
        self.dict1[len(word)].add(word)

    def search(self, word):
        if "." not in word:
            return word in self.dict1[len(word)]
        else:
            for w in self.dict1[len(word)]:
                i = 0

                while i < len(word) and (w[i] == word[i] or word[i] == "."):
                    i += 1

                if i == len(word):
                    return True