import random
import string

N = 10000

src = "".join(random.choice(string.ascii_lowercase) for _ in range(N))
dst = "".join(random.choice(string.ascii_lowercase) for _ in range(N))

with open("data.txt", "w") as f:
	f.write(src+'\n')
	f.write(dst+'\n')