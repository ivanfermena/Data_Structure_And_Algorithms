function Sum(s : seq<int>) : int ensures s == [] ==> Sum(s) == 0 ensures s != [] ==> Sum(s) == s[0] + Sum(s[1..])
{ if s == [] then 0 else s[0] + Sum(s[1..]) }

method ventana(v : array<int> , m : int) returns (s: int, p1: int) // Entrada de array y marco de ventana - salida suma y prima posicion del marco
requires v != null && v.Length > 0
requires 1 <= m <= v.Length
ensures 0 <= p1 <= v.Length - m
ensures s == Sum(v[p1..p1+m])
ensures forall i, j :: 0 <= i <= j < v.Length ==> s > Sum(v[i..j]) // s va a ser la mayor suma de todo el vector
{
	var i := 0;
	var j := 0;
	var sumAux := 0;

	p1 := 0;
	s := 0;
	
	while(i < m){
		sumAux := sumAux + v[i];
		i := i + 1;
	}

	s := sumAux;

	while(j < v.Length - m)
	invariant 0 <= j <= v.Length - m + 1
	invariant s == Sum(v[j..j+m])
	decreases v.Length - m - j
	{
		sumAux := sumAux - v[j] + v[j + m];
		if (sumAux > s){
			s := sumAux;
			p1 := j;
		}
		j := j + 1;
	}
}