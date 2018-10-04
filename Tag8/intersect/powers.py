def generate(f, offsetX, offsetY, exp):
	if exp<=0:
		return
	size = 1<<exp
	f.write(str(offsetX)+" "+str(offsetX+size-1)+" "+str(offsetY)+" "+str(offsetY+size-1)+"\n")
	f.write(str(offsetX+size)+" "+str(offsetX+2*size-1)+" "+str(offsetY+size)+" "+str(offsetY+2*size-1)+"\n")
	generate(f, offsetX, offsetY+size, exp-1)
	generate(f, offsetX+size, offsetY, exp-1)


exp_glob = 20
f = open("powers_"+str(exp_glob), "w")
generate(f, 0, 0, exp_glob)
f.close();
