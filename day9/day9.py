def shoelace_formula(p1, p2, p3, p4):
    return abs((p1[0]*p2[1] + p2[0]*p3[1] + p3[0]*p4[1] + p4[0]*p1[1]) - (p1[1]*p2[0] + p2[1]*p3[0] + p3[1]*p4[0] + p4[1]*p1[0])) / 2

# Advent of Code Day 9 - Part Two
from collections import deque

with open("day9.txt", "r") as f:
    code = f.read()
coordinates = []
for line in code.splitlines():
    x, y = map(int, line.split(","))
    coordinates.append((x, y))

# Normalize coordinates to a grid
xs = [x for x, y in coordinates]
ys = [y for x, y in coordinates]
min_x, max_x = min(xs), max(xs)
min_y, max_y = min(ys), max(ys)
width = max_x - min_x + 3  # pad for border
height = max_y - min_y + 3

def to_grid(x, y):
    return x - min_x + 1, y - min_y + 1

grid = [["." for _ in range(width)] for _ in range(height)]
red_tiles = set()

# Mark red tiles (the path)
for i in range(len(coordinates)):
    x1, y1 = coordinates[i]
    x2, y2 = coordinates[(i+1)%len(coordinates)]
    grid_x1, grid_y1 = to_grid(x1, y1)
    grid_x2, grid_y2 = to_grid(x2, y2)
    red_tiles.add((grid_x1, grid_y1))
    # Fill straight lines between points
    if grid_x1 == grid_x2:
        for y in range(min(grid_y1, grid_y2), max(grid_y1, grid_y2)+1):
            grid[y][grid_x1] = "#"
            red_tiles.add((grid_x1, y))
    elif grid_y1 == grid_y2:
        for x in range(min(grid_x1, grid_x2), max(grid_x1, grid_x2)+1):
            grid[grid_y1][x] = "#"
            red_tiles.add((x, grid_y1))

# Flood fill to find inside (green tiles)
visited = [[False for _ in range(width)] for _ in range(height)]
green_tiles = set()
directions = [(-1,0),(1,0),(0,-1),(0,1)]

def in_bounds(x, y):
    return 0 <= x < width and 0 <= y < height

# Flood from outside to mark non-green
queue = deque()
for x in range(width):
    queue.append((x, 0))
    queue.append((x, height-1))
for y in range(height):
    queue.append((0, y))
    queue.append((width-1, y))
while queue:
    x, y = queue.popleft()
    if not in_bounds(x, y) or visited[y][x] or grid[y][x] == "#":
        continue
    visited[y][x] = True
    for dx, dy in directions:
        nx, ny = x+dx, y+dy
        if in_bounds(nx, ny):
            queue.append((nx, ny))

# All unvisited and not red are inside (green)
for y in range(height):
    for x in range(width):
        if not visited[y][x] and grid[y][x] != "#":
            grid[y][x] = "X"
            green_tiles.add((x, y))

# Build binary grid: 1 if red or green, 0 otherwise
bin_grid = [[0 for _ in range(width)] for _ in range(height)]
for y in range(height):
    for x in range(width):
        if (x, y) in red_tiles or (x, y) in green_tiles:
            bin_grid[y][x] = 1

# Compute 2D prefix sum
prefix = [[0 for _ in range(width+1)] for _ in range(height+1)]
for y in range(1, height+1):
    for x in range(1, width+1):
        prefix[y][x] = bin_grid[y-1][x-1] + prefix[y-1][x] + prefix[y][x-1] - prefix[y-1][x-1]

def rect_sum(x1, y1, x2, y2):
    # inclusive coordinates
    return prefix[y2+1][x2+1] - prefix[y1][x2+1] - prefix[y2+1][x1] + prefix[y1][x1]

# Now, for each pair of red tiles, check rectangles using prefix sum
max_area = 0
red_tiles = list(red_tiles)
for i in range(len(red_tiles)):
    for j in range(i+1, len(red_tiles)):
        x1, y1 = red_tiles[i]
        x2, y2 = red_tiles[j]
        minx, maxx = min(x1, x2), max(x1, x2)
        miny, maxy = min(y1, y2), max(y1, y2)
        area = (maxx - minx + 1) * (maxy - miny + 1)
        total = rect_sum(minx, miny, maxx, maxy)
        if total == area:
            if area > max_area:
                max_area = area

print(f"Largest rectangle area (red/green only): {max_area}")


