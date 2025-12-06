# mach ich part two halt mit Python ...

def read_input(file_path):
    with open(file_path, 'r') as file:
        return [line.rstrip('\n') for line in file]
    
lines = read_input('day6.txt')
# Find the maximum line length to handle uneven lines
max_len = max(len(line) for line in lines)

# Pad lines to the same length if needed
padded_lines = [line.ljust(max_len) for line in lines]
previous_column_chars = []

print('Columns:')
for col in range(max_len):
    column_chars = [padded_lines[row][col] for row in range(len(padded_lines))]
    if column_chars[4] != ' ':
        previous_column_chars = column_chars.copy()
    if column_chars == "[' ', ' ', ' ', ' ', ' ']":
        column_chars = ["+"]
    elif column_chars[4] == ' ':
       column_chars[4] = previous_column_chars[4]

    print("".join(column_chars))



