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
for point_i in coordinates:
    for point_j in coordinates:
        length = abs(point_i[0] - point_j[0])
        width = abs(point_i[1] - point_j[1])
        area = length * width
        #print(f"Points: {point_i}, {point_j} => Length: {length}, Width: {width}, Area: {area}")
        if area > max_area:
            max_area = area

print(f"Largest rectangle area: {max_area}")