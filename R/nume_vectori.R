rm()
supplier1<-c("IPRS","Romania","Components")
names(supplier1)<-c("Name","Country","Products")
print(supplier1)
print("-------------------------------------")
print(names(supplier1))
supplier2<-c("Pravets","Bulgaria","Computers")
tab<-c(supplier1,supplier2)
print(tab)#va trb sa folosim matrice
#vezi fisierul matrici.R
print(supplier1["Country"])#adresare tablou prin sir de caractere
#acelasi lucru este posibil in C++ prin redefinirea operatorului []