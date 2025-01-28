def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    t = int(data[idx])
    idx += 1
    
    for _ in range(t):
        n, m = int(data[idx]), int(data[idx + 1])
        idx += 2
        
        a = list(map(int, data[idx:idx + n]))
        idx += n
        
        b = list(map(int, data[idx:idx + m]))
        idx += m
        
        # Sort the points
        a.sort()
        b.sort()
        
        # Compute all possible areas
        areas = []
        
        # Case 1: 2 points from y=0 and 1 point from y=2
        if n >= 2 and m >= 1:
            for i in range(n - 1):
                base = a[i + 1] - a[i]
                area = base * 2  # height is 2
                areas.append(area)
        
        # Case 2: 2 points from y=2 and 1 point from y=0
        if m >= 2 and n >= 1:
            for i in range(m - 1):
                base = b[i + 1] - b[i]
                area = base * 2  # height is 2
                areas.append(area)
        
        # Sort areas in descending order
        areas.sort(reverse=True)
        
        # Compute kmax
        kmax = min(n // 2, m) + min(m // 2, n)
        
        # Compute f(k) for k = 1 to kmax
        f = []
        total = 0
        for k in range(1, kmax + 1):
            if k <= len(areas):
                total += areas[k - 1]
                f.append(total)
            else:
                break
        
        # Output results
        print(kmax)
        if kmax > 0:
            print(" ".join(map(str, f)))

if __name__ == "__main__":
    solve()
