class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        
        base = "1"
        l = []
        while n > 1 :
            i = 0
            while i < len(base):
                counter = 1
                while i + counter < len(base) and base[i] == base[i + counter]:
                    counter += 1
                l.append([base[i], counter])
                i += counter

            base = ""
            for pair in l:
                base += str(pair[1])
                base += pair[0]
            n -= 1
            l = []
        
        return base


        