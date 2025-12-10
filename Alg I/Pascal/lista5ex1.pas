program quest1;
const max = 100;
type vetor = array [1..max] of integer;
var v,w,y : vetor;

procedure ler(var x: vetor);
var i : integer;
begin
	i:= 1;	
	read x[i];
	while x[i] <> 0 do
	begin
		i:= i+1;		
		read x[i];
	end;
end;
		
begin

ler(v);
ler(w);

end.
