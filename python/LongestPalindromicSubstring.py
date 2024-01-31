class Solution:
    def longestPalindrome(self, s: str) -> str:

        extended_s = ['$', ]
        for i in range(0, len(s)):
            extended_s.append('#')
            extended_s.append(s[i])
        extended_s.append('#')
        extended_s.append('%')

        arr = [0 for i in range(0, len(extended_s))]
        right = 0
        center = 0

        for i in range(1, len(extended_s) - 1):
            if i < right:
                arr[i] = min(arr[2 * center - i], right - i)
            else:
                arr[i] = 1
            
            while extended_s[i - arr[i]] == extended_s[i + arr[i]]:
                arr[i] += 1

            if arr[i] + i > right:
                center = i
                right = i + arr[i]

        maximum = max(arr)
        index = arr.index(maximum)

        sub_list = []
        for c in extended_s[index - maximum + 1 : index + maximum]:
            if c != '#':
                sub_list.append(c)

        sub_s = "".join(sub_list)

        return sub_s

