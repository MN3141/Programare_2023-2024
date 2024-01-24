#Sondaj nebernoullian<->schema bilei neintoarse
nrAlbe<-50
nrNegre<-450
nrExtrase<-100
nrAlbeDoriteMax<-50
tabExtrageri<-c(0:nrAlbeDoriteMax)
fDensitate<-dhyper(tabExtrageri,nrAlbe,nrNegre,nrExtrase)
fRepartitie<-phyper(tabExtrageri,nrAlbe,nrNegre,nrExtrase)
plot(tabExtrageri,fDensitate)
grid(nx=NULL,ny=NULL)
plot(tabExtrageri,fRepartitie)
