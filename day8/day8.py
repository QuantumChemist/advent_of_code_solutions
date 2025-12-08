import math
INF = float("inf")

junction_box = []
circuit = []
min_distance = INF

with open("day8.txt", "r") as f:
    code = f.read()

for line in code.splitlines():
    row = []
    for num in line.split(","):
        row.append(int(num))
    junction_box.append(row)

for junc1 in junction_box:
    for junc2 in junction_box:
        circ = set()
        if junc1 != junc2:
            distance = math.dist(junc1, junc2)
            if distance < min_distance:
                min_distance = distance
                circ.add((tuple(junc1), tuple(junc2)))
        circuit.append(circ)

print(f"Minimum distance found: {min_distance}")







