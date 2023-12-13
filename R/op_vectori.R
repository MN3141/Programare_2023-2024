#Fie x,y doua tablouri
#x+y=suma elemente
#x*y=produs elemente
rm()
x<-c(1,0.12,2,10)
y<-seq(0,3,0.5)
print(x+y)
print(x*y)
print(x^y)
#În cazul în care vectorii sunt de lungimi diferite se repetă valorile din vectorul mai “scurt” de
#atâtea ori până când ajunge la lungimea celui mai lung. Apoi se efectuează operațiile aritmetice de bază.
print(t(x))