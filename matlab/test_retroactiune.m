h0=tf(1,[1 1])
h1=tf(10)
sys=append(h0,h1)
q=[1 -2;2 1]
h=connect(sys,q)
tf(h)