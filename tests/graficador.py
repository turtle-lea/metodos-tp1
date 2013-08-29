#! usr/bin/python
from matplotlib.pyplot import *
from numpy import *

file = open("test.out")
s = file.read()
s.strip('\n')
s = s.split()
s = [float(x) for x in s]

alpha = s[0]
iteraciones = [s[x] for x in range(1,len(s),2)]
valores = [s[x] for x in range(2,len(s),2)]
print iteraciones, '\n' 
print valores, '\n' 

t = arange(0.,alpha, 0.01)
plot(t,t**2 - alpha, "blue")
plot(iteraciones,valores, "ro")
show()





