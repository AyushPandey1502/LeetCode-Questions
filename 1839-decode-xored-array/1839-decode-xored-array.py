class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        target = [first]
        for i in range(1,len(encoded)+1):
            target.append(target[i-1] ^ encoded[i-1])
        return target