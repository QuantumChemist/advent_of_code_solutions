# mach ich part two halt mit Python ...

def read_input(file_path):
    with open(file_path, 'r') as file:
        return file.read().strip()
    
day6 = read_input('day6.txt')
zahl = 0

for i in day6:
    print(i)
    zahl += 1
    if zahl == 14:
        break


