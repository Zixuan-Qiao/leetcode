class Solution:
    def reverse(self, x: int) -> int:

        if x < 0:
            x = -x
            flag = True
        else:
            flag = False

        l = []
        while x > 0:
            l.append(x % 10)
            x = x // 10

        sum = 0
        base = 10**(len(l) - 1)
        bound = 2**31
        for i in range(0, len(l)):
            sum += l[i] * base

            if sum > bound:
                return 0

            base /= 10

        if sum == bound and flag == False:
            return 0

        if flag == True:
            sum = -sum

        return int(sum)