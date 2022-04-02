class Solution(object):
    def plusOne(self, digits):
        lst = []
        digits.reverse();
        carry = 1
        for x in digits:
            sum = x + carry
            if(sum >= 10):
                carry = 1
            else:
                carry = 0
            lst.append(sum%10)
        if(carry == 1):
            lst.append(1)
        lst.reverse()
        return lst