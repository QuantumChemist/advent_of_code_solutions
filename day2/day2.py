# lol day2.py
def parse_ranges(input_str):
    return [tuple(map(int, part.split('-'))) for part in input_str.strip().split(',')]

def is_invalid_id(n):
    s = str(n)
    l = len(s)
    for size in range(1, l // 2 + 1):
        if l % size == 0:
            part = s[:size]
            if part * (l // size) == s:
                return True
    return False

def find_invalid_ids(input_str):
    ranges = parse_ranges(input_str)
    invalids = []
    for start, end in ranges:
        for n in range(start, end + 1):
            if is_invalid_id(n):
                invalids.append(n)
    return invalids

# Your input
puzzle_input = """1-14,46452718-46482242,16-35,92506028-92574540,1515128146-1515174322,56453-79759,74-94,798-971,49-66,601-752,3428-4981,511505-565011,421819-510058,877942-901121,39978-50500,9494916094-9494978970,7432846301-7432888696,204-252,908772-990423,21425-25165,1030-1285,7685-9644,419-568,474396757-474518094,5252506279-5252546898,4399342-4505058,311262290-311393585,1895-2772,110695-150992,567521-773338,277531-375437,284-364,217936-270837,3365257-3426031,29828-36350"""

# Find and sum invalid IDs
invalid_ids = find_invalid_ids(puzzle_input)
print("Total sum of invalid IDs:", sum(invalid_ids))