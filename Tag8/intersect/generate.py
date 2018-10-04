#for s in range(2, 5):
if True:
	size = 10000
	out = open("inst_"+str(size), "w")
	for i in range(0, size):
		for j in range(0, size):
			out.write(str(2*i)+" "+str(2*i+1)+" "+str(2*j)+" "+str(2*j+1)+"\n")
	out.close()
