program primeiroex;
  var x: array [1..100] of integer;
      y: array [1..100] of integer;
      z: array [1..100] of integer;
      i, u, o, t, tam_vetx, tam_vety, tam_vetz : integer;
  begin
	i:= 1;
	read (x[i]);
	while x[i] <> 0 do
	begin
		i:= i+1;
		read (x[i]);
	end;
	tam_vetx:= i-1;
	
	u:= 1;
	read (y[u]);
	while y[u] <> 0 do
	begin
		u:= u+1;
		read (y[u]);
	end;
	tam_vety:= u-1;
	t:= 0;
	while t <> 0 do
	begin
		if y[u] = x[i] then
			u:= u+1;
		
		x[i]:= i+1;
		
		if u = tam_vety then
		begin
			writeln('Sim');
			t:= 1;
		end;
	end;
end.	
		
	
	
	
		
