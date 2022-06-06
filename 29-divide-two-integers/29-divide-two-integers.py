class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == 0:
            return 0
		# only case that gives answer outside of [-2 ** 31, 2 ** 31 - 1]
        if dividend == -2 ** 31 and divisor == -1:
            return 2 ** 31 - 1
			
		# we work with positive numbers only and worry about the sign in the end
        if dividend > 0 and divisor > 0 or dividend < 0 and divisor < 0:
            positiveSign = True
        else:
            positiveSign = False
        dividend, divisor = abs(dividend), abs(divisor)

        quotient = 0
        for i in reversed(range(dividend.bit_length() - divisor.bit_length() + 1)):
            if dividend >> i >= divisor:
                dividend -= divisor << i
                quotient |= 1 << i
        
        return quotient if positiveSign else -quotient