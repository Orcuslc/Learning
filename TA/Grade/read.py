import re
import random

def split(content):
	pattern = re.compile(r"Testing Services Student Score Report.*?335-0356", re.S)
	pages = re.findall(pattern, content)
	return pages

def parse_page(page):
	namepattern = re.compile(r"^Testing.*$", re.M)
	nameline = re.findall(namepattern, page)
	name = nameline[0][38:]
	ID = re.findall(r"[0-9]{8}", page)[0]
	grade = re.findall(r"[0-9].*\.[0-9]{4}%", page)[0]
	errorpattern = re.compile(r"Format.*?If allowed", re.S)
	errors = re.findall(errorpattern, page)[0][57:-14].split('\n\n')
	return [name, ID, grade, errors]

def parse(path):
	with open(path) as f:
		content = f.read()
	f.close()
	pagelist = split(content)
	for page in pagelist:
		[name, ID, grade, errors] = parse_page(page)
		if len(errors) < 3: # No error
			errors = "Wow! No errors!"
		else:
			errors = " ".join(errors)
		print("Name:" + name, "ID:" + ID, "grade:" + grade, "errors:" + errors)


def test():
	path = "test.txt"
	with open("test.txt") as f:
		content = f.read()
	f.close()
	pages = split(content)
	[name, ID, grade, errors] = parse_page(pages[random.randint(0, len(pages)-1)])
	errors = " ".join(errors)
	print("Name:" + name, "ID:" + ID, "grade:" + grade, "errors:" + errors)

if __name__ == '__main__':
	# test()
	parse('test.txt')