def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    t = int(data[0])
    idx = 1
    results = []
    
    for _ in range(t):
        n, m = map(int, data[idx:idx+2])
        idx += 2
        a = list(map(int, data[idx:idx+n]))
        idx += n
        b = list(map(int, data[idx:idx+m]))
        idx += m

        #Sort points
        a.sort()
        b.sort()

        #Calculate k_max
        k_max = min(n // 2 * m, m // 2 * n)
        results.append(str(k_max))
        
        if k_max > 0:
            #Calculate scores
            scores = []
            ai, aj = 0, n-1
            bi, bj = 0, m-1
            
            for _ in range(k_max):
                if (aj - ai) > (bj - bi):
                    #Take from a
                    score = abs(a[aj] - a[ai])
                    aj -= 1
                    ai += 1
                else:
                    #Take from b
                    score = abs(b[bj] - b[bi])
                    bj -= 1
                    bi += 1
                
                scores.append(str(score))
            
            results.append(" ".join(scores))

    #Output results
    sys.stdout.write("\n".join(results) + "\n")

solve()
