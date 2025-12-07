# copied from here https://www.reddit.com/r/adventofcode/comments/1pg9w66/comment/nsrfdee/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button

diagram = []
with open("day7.txt") as f:
    diagram = f.readlines()
	
beams = dict()

beams[diagram[0].index('S')] = 1
for row in diagram[1:]:
    for beam in beams.copy():
        if row[beam] == '^':
            if beam-1 in beams:
                beams[beam-1] += beams[beam]
            else:
                beams[beam-1] = beams[beam]
            if beam+1 in beams:
                beams[beam+1] += beams[beam]
            else:
                beams[beam+1] = beams[beam]
            beams.pop(beam)
nsplits = 0
for beam in beams:
    nsplits += beams[beam]
print(nsplits)