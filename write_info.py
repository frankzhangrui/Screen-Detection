g = open("info.txt","w")
with open("labels.csv","r") as f:
	for line in f:
		curLine = line.strip().split(",")
		file_name = curLine[0]
		xmin = curLine[1]
		ymin = curLine[2]
		xmax = str(int(curLine[5])-int(curLine[1]))
		ymax = str(int(curLine[6])-int(curLine[2]))
		g.write("pos/"+file_name+".jpg"+"\t" + str(1)+"\t"+ xmin + "  " + ymin+ "  "+ xmax + "  " + ymax+"\n")
g.close()
