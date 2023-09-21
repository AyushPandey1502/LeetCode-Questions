from math import floor

class Solution:
    def calculate(self, s: str) -> int:
        return floor(eval(s.replace('/','//')))
