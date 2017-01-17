% demonstrate labeling a plot using matlab (pg 346)
x=0:0.01:1;
s=sin(x);
c=cos(x);
xlabel('sin(x)');
ylabel('cos(x)');
legend('turtle');
plot(s,c,'--k','LineWidth',4);
