h0=[tf(1),tf(0);tf(0),tf(1)]; %matricea identitate
h1=[tf(1),tf(2);tf(3),tf(4)];
sys=feedback(h0,h1);
q=[];
h=connect(sys,q)