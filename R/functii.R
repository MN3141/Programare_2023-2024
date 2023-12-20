rm()
f0<-function(x)
{
  return(x^2-1)
}
f1<-function(x,y=1) #parametru implicit ca in C++
{
  return(x^2+y-1)
}
f2<-function(x)
{
  k<-0
  if(x==0)
    k<- -1
  else
    k<- 1/x
  return(k)
}
x<-c(-100:100)
y<-x
print(f1(2,3))
print(f2(0))
plot(x,f0(x))


