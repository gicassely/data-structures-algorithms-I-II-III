program bin_dec;
	var x : array [1..127] of integer;
	i, tam_vetor, soma, e : integer;
	
	begin
	i:= 1; e:=; soma:=0;
	writeln( 'Escreva um numero em binario:');
	read (x[i]);
	while x[i] = 0 do
	begin
		i:= i+1;
		read (x[i]);
	end;
	tam_vetor := i-1;
	while tam_vetor >= 1 do
	begin
		soma := soma + x[tam_vetor] * (2 * e) ;
		tam_vetor := tam_vetor -1 ;
		e:= 2*2;
	end;
	writeln (soma);
end.
	
