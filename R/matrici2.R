#operatii cu matrici
rm()
temp<-c(1:4)
m0<-matrix(temp,2,2)
temp<-c(1,0,0,1)
m1<-matrix(temp,2,2)
print(m0*m1)#inmultirea elementelor,nu a matricilor
print(m0%*%m1)#inmultirea matricilor
#====================================================
m0<-rbind(m0,c(1,1)) #row bind
print(m0)
m0<-cbind(m0,c(-1,-1,-1))#column bind
print(m0)
print(t(m0))
#====================================================
temp<-c(2,2,1,3)
m0<-matrix(temp,2,2)
i2<-matrix(c(1,0,0,1),2,2)
m0_inversa<-solve(m0,i2)
print(m0_inversa)


