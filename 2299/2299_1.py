# author: gaoshh1
class Solution:

    def strongPasswordCheckerII(self, password: str) -> bool:
        specialCharSet = "!@#$%^&*()-+"
        smallChar = False
        bigChar = False
        number = False
        specialChar = False
        prev = ''
        if (len(password) < 8):
            return False
        for i in password:
            if i == prev:
                return False
            asc = ord(i)
            if (asc >= 65 and asc <= 90):
                bigChar = True
            if (asc >= 97 and asc <= 122):
                smallChar = True
            if (asc >= 48 and asc <= 57):
                number = True
            if (specialCharSet.find(i) != -1):
                specialChar = True
            prev = i
        if (bigChar and smallChar and number and specialChar):
            return True
        return False
