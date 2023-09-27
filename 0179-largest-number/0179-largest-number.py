class Solution:
    def largestNumber(self, num):
        num = [str(x) for x in num]
        num.sort(key=lambda x: x * 10, reverse=True)
        return ''.join(num).lstrip('0') or '0'
