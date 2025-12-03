with open("day3.txt", "r") as file:
    lines = [line.strip() for line in file if line.strip()]

def max_joltage(line):
    max_val = 0
    n = len(line)
    for i in range(n-1):
        for j in range(i+1, n):
            val = int(line[i] + line[j])
            if val > max_val:
                max_val = val
    return max_val

total = sum(max_joltage(line) for line in lines)
print(total)
