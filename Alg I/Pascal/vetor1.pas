program vetor1;
var   v : array [1..100] of integer;
      i,

begin
	i := 1;
	
	while v[i] <> 0 do
	begin
		read v[i];
		i:= i+1;
	end;
	tam := i-1;
	
	while i <= tam do
	begin
		
