import random

def main():
	f = open('../../tests/testRand.in','w')
	for x in range(0,75):
		floatRand = random.uniform(0.000001,50)
		f.write(repr(floatRand) + "\n")
	f.write('#')
	f.close()
if __name__ == '__main__':
	main()