import sys
input_data = sys.stdin.read().strip().split()
t = int(input_data[0])

pos = 1
out = []
for _ in range(t):
    n = int(input_data[pos]); pos += 1
    a = list(map(int, input_data[pos:pos+n]))
    pos += n

    freq = [0]*(n+1)
    b = [0]*n
    max_freq = 0
    next_new = 1

    for i in range(n):
        needed = a[i]
        if i == 0:
            # First element must be a[i] to start
            b[i] = needed
            freq[needed] = 1
            max_freq = 1
        else:
            if freq[needed] < max_freq:
                # Need to raise freq of needed to match max_freq
                b[i] = needed
                freq[needed] += 1
                # If this increment surpasses max_freq, update it
                if freq[needed] > max_freq:
                    max_freq = freq[needed]
            else:
                # freq[needed] == max_freq
                # We can try placing a filler element with freq < max_freq
                # If max_freq == 0 (only at the very start), we must place needed again.
                if max_freq == 0:
                    # Just place needed
                    b[i] = needed
                    freq[needed] = 1
                    max_freq = 1
                else:
                    # Find a filler element with freq < max_freq
                    # We'll pick a fresh unused element (freq=0) to ensure freq < max_freq.
                    while next_new <= n and (freq[next_new] != 0 or next_new == needed):
                        next_new += 1

                    if next_new <= n and freq[next_new] < max_freq:
                        # Use filler
                        b[i] = next_new
                        freq[next_new] += 1
                    else:
                        # No suitable filler found, must raise needed
                        b[i] = needed
                        freq[needed] += 1
                        if freq[needed] > max_freq:
                            max_freq = freq[needed]

    out.append(" ".join(map(str, b)))

print("\n".join(out))