#ex vectori
#ex1:
rm()
s<-c()
i<-3
while(i<36)
{
  s<-c(s,(0.1^i)*(0.2^(i-1)))
  i<-i+3
}
#ex2:
m<-c(2)
i<-2
while(i<25)
{
  m<-c(m,2^i /i)
  i<-i+1
}
#ex3:
sum<-0
for(i in 10:100)
{
  sum<-sum+(i^3+4*i^2)
}
#ex4:
sum2<-0
for(i in 1:25)
{
  sum2<-sum2+(2^i/i + 3^i/i^2)
}
print("EX1:")
print(s)
print("EX2:")
print(m)
print("EX3")
print(sum)
print("EX4")
print(sum2)
