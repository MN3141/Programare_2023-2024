print("Running python script...")
fout=open("dummy.txt",'w')
fout.write("IPRS-Macro")
for i in range(10):
    fout.write(str(i))
fout.close()