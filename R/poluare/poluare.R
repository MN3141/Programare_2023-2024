#Date
ozon<-c(49,86,100,32,51,31,31,31,47,47,131,215,230,103,69,98,72,143,192,122,190,222,150,200,86,49,131,230,290)
ziua<-seq(1,length(ozon))
m<-mean(ozon)
s<-sd(ozon)
print("Date obtinute:")
print(ozon)
print(summary(ozon))#afiseaza mediana,max,min,quartilele 1 si 3
print("Frecvente:")
print(table(ozon))#frecventele valorilor
print("Cuantila 25:")
print(quantile(ozon,probs=.25))
plot(ziua,ozon,type='p')#a se extinde fereastra cu graficul
fDensitate<-dnorm(ozon,m,s)
fRepartitie<-pnorm(ozon,m,s)
plot(ozon,fDensitate)
plot(ozon,fRepartitie)
grid(nx=NULL,ny=NULL)
hist(ozon)