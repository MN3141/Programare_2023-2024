%sisteme in paralel
h0=tf(2);
h1=tf(0.5);
sys=parallel(h0,h1);
q=[1 0;2 0];
h=connect(sys,q,1,1)