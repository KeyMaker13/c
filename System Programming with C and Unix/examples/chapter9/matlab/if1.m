% demonstrate if statements in matlab (pg 342)
for i=1:3,
  if i >= 2,
    disp('Hello');
  end
end
i=0;
while i<3,
  if i >= 2,
    disp('Goodbye');
  else
    disp('Oops - forgot something');
  end
  i=i+1;
end
