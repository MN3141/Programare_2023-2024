h0=tf(3);
h1=tf(2);
sys=append(h0,h1);
q=[1 0; 2 1 ]; % linie matrice=subsistem
h=connect(sys,q,1,2)

