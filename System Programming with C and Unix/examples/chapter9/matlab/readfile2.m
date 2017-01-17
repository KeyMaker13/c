% demonstrate reading data from a file using textscan (pg 338)
fid1=fopen('data1.txt','r');
b=textscan(fid1,'%1d');
b{:}
fclose(fid1);
