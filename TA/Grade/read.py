import re
pattern = re.compile(r"Testing Services Student Score Report.*?335-0356", re.S)

def parse(content):
	group = re.findall(pattern, content)

	return group[1]

def parse_group(s):
	namepattern = re.compile(r"^Testing.*$", re.M)
	nameline = re.findall(namepattern, s)
	name = nameline[0][38:]
	ID = re.findall()

if __name__ == '__main__':
	with open("test.txt") as f:
		content = f.read()
	f.close()
	s = parse(content)
	parse_group(s)
	# print(s)