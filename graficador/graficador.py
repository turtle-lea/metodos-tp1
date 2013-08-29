#! usr/bin/python
from matplotlib.pyplot import *
from numpy import *

file = open("valores.txt")
alpha = 5.25
s = file.read()
s.strip('\n')
s = s.split()
s = [float(x) for x in s]
s_2 = [x**2 - alpha for x in s]

t = arange(0.,5.,0.01)
plot(t,t**2 - alpha)
plot(s,s_2, "ro")

show("r")





