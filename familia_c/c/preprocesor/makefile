#sintaxa:
#target:prerequisite
#	recipe
#target+prerequisite+recipe=rule
#OBS:regulile sunt in ordine inversa
#	 in sensul ca prima data se defineste
#	 output si numai apoi fisierele obiect
# @ mascheaza ecoul comenzii
out:main.c
	gcc -E main.c > main.i
	gcc -S main.c 
	gcc -c main.c 
	gcc main.c -o out