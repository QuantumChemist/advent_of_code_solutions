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


# --- Connect the 1000 closest pairs, regardless of cycles ---
edges = pairs[:1000]
print(f"Number of junctions: {num_junctions}")
print(f"Number of connections to make: {len(edges)}")

# --- Use Union-Find to determine circuits after all connections ---
uf = UnionFind(num_junctions)
min_distance = INF
for distance, i, j in edges:
    uf.union(i, j)
    if distance < min_distance:
        min_distance = distance

# --- Count the sizes of all circuits ---
from collections import Counter
root_counts = Counter()
for i in range(num_junctions):
    root = uf.find(i)
    root_counts[root] += 1
sizes = sorted(root_counts.values(), reverse=True)

print(f"Number of circuits after connecting: {len(sizes)}")

if len(sizes) >= 3:
    result = sizes[0] * sizes[1] * sizes[2]
else:
    result = 0

print(f"Minimum distance found: {min_distance}")
print(f"Sizes of three largest circuits: {sizes[:3]}")
print(f"Product of three largest: {result}")

print(f"Minimum distance found: {min_distance}")







