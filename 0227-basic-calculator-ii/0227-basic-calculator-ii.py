from math import floor

class Solution:
    def calculate(self, s: str) -> int:
        s = s.replace('/', '//')
        return floor(eval(s))
