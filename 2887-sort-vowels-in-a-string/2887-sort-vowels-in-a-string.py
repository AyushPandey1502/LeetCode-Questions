class Solution:
    def sortVowels(self, s: str) -> str:
        vowels = []
        consonant = []
        result = []
        for i in s:
            if i in "aeiouAEIOU":
                vowels.append(i)
            else:
                consonant.append(i)
        vowels.sort()
        i = j = 0
        for alph in s:
            if alph in 'aeiouAEIOU':
                result.append(vowels[i])
                i += 1
            else:
                result.append(consonant[j])
                j += 1
        return "".join(result)
        