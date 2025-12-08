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


# --- Union-Find (Disjoint Set Union) implementation ---
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr == yr:
            return False
        if self.size[xr] < self.size[yr]:
            xr, yr = yr, xr
        self.parent[yr] = xr
        self.size[xr] += self.size[yr]
        return True

# --- Collect all pairs and their distances ---

num_junctions = len(junction_box)
print(f"Number of junctions: {num_junctions}")
pairs = []
for i in range(num_junctions):
    for j in range(i+1, num_junctions):
        distance = math.dist(junction_box[i], junction_box[j])
        pairs.append((distance, i, j))

# --- Sort all pairs by distance ---
pairs.sort()



# --- PART TWO: Connect pairs until all are in one circuit ---
uf = UnionFind(num_junctions)
num_circuits = num_junctions
last_pair = None
for distance, i, j in pairs:
    if uf.find(i) != uf.find(j):
        uf.union(i, j)
        num_circuits -= 1
        if num_circuits == 1:
            last_pair = (i, j)
            print(f"Last connection: {junction_box[i]} <-> {junction_box[j]}")
            print(f"Distance: {distance}")
            print(f"Product of X coordinates: {junction_box[i][0] * junction_box[j][0]}")
            break







