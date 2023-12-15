%Grafice intalnite in evaluarea complexitatii unui algoritm
n=[0:100];
f0=n;%O(n)
f1=n.*log10(n);%O(nlog(n))
f2=n.*n;%O(n^2)
plot(n,f0,':c',n,f1,'--m',n,f2,'-r');grid
%c=cyan,m=magenta,r=red
%:=linie punctata,--=linie intrerupta,-=linie solida
axis([0 100 0 300])
xlabel('Nr intrari')
ylabel('Nr instructiuni executate')
title('Complexitatea algoritmilor')
legend('O(n)','O(nlog(n)','O(n^2)')