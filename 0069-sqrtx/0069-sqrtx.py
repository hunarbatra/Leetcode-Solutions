class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x

        lo, hi = 1, x // 2

        while lo <= hi:
            mid = (lo + hi) // 2
            sq = mid * mid

            if sq == x:
                return mid
            elif sq < x:
                lo = mid + 1
            else:
                hi = mid - 1

        return hi