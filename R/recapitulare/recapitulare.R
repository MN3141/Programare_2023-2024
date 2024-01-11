rm()
tab0<-c(1,5,7,3)
print(mean(tab0))
tab1<-rep(7,7)
tab2<-scan()
tab3<-seq(from=4,to=8,length.out=80)
tab4<-tab3[1:6]
tabChar<-c("NEAG","MIHAI")
mat0<-matrix(tab1,2,2)
mat1<-matrix(tab3,2,2,byrow = TRUE)
mat0<-rbind(mat0,c(5,1))
mat0<-cbind(mat0,c(1,0,-1))
matIdentity<-matrix(c(1,0,0,0,1,0,0,0,1),3,3)
mat2<-solve(mat0,matIdentity)
mat3<-matrix(c(1,2,3,4,5,6,7,8,9),3,3)
mat3<-mat2%*%mat3
tab5<-c(3,4, 5 ,6 ,7 ,9 ,14, 23)
tab5<-tab5[3:5] # sau asa:tab5<-subset(tab5,tab5>=5& tab5<=7)
index<-4
tab6<-NULL
while(index<=22)
{
  tab6<-c(tab6,0.3^(index),0.3^(index+1))
  index<-index+1
}
functie1<-function(a,b,c,d)
{
  rez<-(a*b)^c +12*(d)^0.6
  return (rez)
}
functie2<-function(a,b,c)
{
  rez<-exp(a)+b/c
  return (rez)
}
index<-1
suma<-0
while(index<=15)
{
  suma<-suma+index+index^2
  index<-index+1
}
month<-"Ianuarie"
lista<-list(a=tabChar,b=month)#!!!!
print(lista$b)