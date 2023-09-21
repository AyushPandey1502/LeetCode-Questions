class Solution:
    def defangIPaddr(self, address: str) -> str:
        result = address.replace(".", "[.]")
        return result
