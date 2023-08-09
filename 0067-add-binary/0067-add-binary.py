class Solution:
    def addBinary(self, a: str, b: str) -> str:
        def addBinaryStrings(a, b):
            result = ""
            carry = 0
            i = len(a) - 1
            j = len(b) - 1

            while i >= 0 or j >= 0 or carry:
                _sum = carry
                if i >= 0:
                    _sum += int(a[i])
                    i -= 1
                if j >= 0:
                    _sum += int(b[j])
                    j -= 1

                carry = _sum // 2
                result = str(_sum % 2) + result

            return result

        return addBinaryStrings(a, b)