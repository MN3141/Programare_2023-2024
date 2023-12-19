#despre matrici
rm()
m0<-matrix(0,2,2)#matrice nula patratica
temp<-c(1,0,0,1)
m1<-matrix(temp,2,2)#matrice identitate
m2<-matrix((scan("matrice.txt")),3,3)
m3<-matrix(scan("matrice2.txt"),3,3)
temp<-c("IPRS","Romania","Components","Pravets","Bulgaria","Computers","Texas Instruments","USA","Components")
m4<-matrix(temp,3,3,TRUE)
#OBS:byrow specifica daca elementele sunt puse de-a lungul liniei sau coloanei
colnames(m4)<-c("Name","Country","Product")
print(m0)
print(m1)
print(m2)
print(m3)
print(m4)
print(m4[2,2])