size = 10000
f = open("lines_"+str(size), "w")
for i in range(0, size):
	f.write("0 "+str(size)+" "+str(2*i)+" "+str(2*i+1)+"\n");
