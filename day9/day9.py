with open("day9.txt", "r") as f:
    code = f.read()
coordinates = []
for line in code.splitlines():
    point = []
    for num in line.split(","):
        point.append(int(num))
    coordinates.append(point)

# find largest rectangle area between opposite corners

max_area = 0
num_points = len(coordinates)
for i in range(num_points):
    for j in range(num_points):
        length = abs(coordinates[i][0] - coordinates[j][0])
        width = abs(coordinates[i][1] - coordinates[j][1])
        area = length * width
        if area > max_area:
            max_area = area

print(f"Largest rectangle area: {max_area}")