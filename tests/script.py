from import os 

os.system("mkdir dir_prueba")

for i in range (1,7):
	os.system("../codigo/bin/test_f_Newton < test.in >test.out")
	filename_1 = "test_"+str(i)+".in"
	filename_2 = "test_"+str(i)+".out"
	



