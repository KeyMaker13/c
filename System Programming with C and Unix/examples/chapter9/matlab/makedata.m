% demonstrate fopen and fclose in matlab (pg 337)
% this program creates a file named data1.txt used in other examples
fid1=fopen('data1.txt','w');
fprintf(fid1,'14\n11\n8\n5\n');
fclose(fid1);
