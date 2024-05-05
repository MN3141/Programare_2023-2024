#sintaxa:
#target:prerequisite
#	recipe
#target+prerequisite+recipe=rule
#OBS:regulile sunt in ordine inversa
#	 in sensul ca prima data se defineste
#	 output si numai apoi fisierele obiect
# @ mascheaza ecoul comenzii
output:main.o function.o  function2.o
	gcc main.o function.o function2.o -o output
# 					a treia regula ce ruleaza
main.o:main.c function.h
	gcc -c main.c 
#					a doua regula ce ruleaza
function.o:function.c function.h
	gcc -c function.c 
# 					prima regula ce ruleaza
#OBS: includem antetul din nou deoarce in cadrul function.h nu s-au folosit directivele #ifndef si #endif;numite si file guards
function2.o:function2.c 
	gcc -c function2.c 
#OBS: datorita faptului ca function2.h contine directiva ifndef,nu mai este nevoita specificarea antetului in cadrul acestui fisier
clean:
	@rm *.o
test:
	echo "TEST"