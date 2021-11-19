class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        # Init
        max_n = 2
        d = 0
        
        # Count max_n
        while x > max_n or y > max_n:
            max_n *= 2
        
        # Count distance
        while (max_n != 1):
            if (x >= max_n and y >= max_n):
                x -= max_n
                y -= max_n
            elif (x >= max_n and y < max_n):
                d += 1
                x -= max_n
            elif (x < max_n and y >= max_n):
                d += 1
                y -= max_n
            
            max_n /= 2
        
        # Complete
        if x != y: d += 1
            
        return d

