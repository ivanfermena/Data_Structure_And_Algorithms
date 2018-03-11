function Sum(s : seq<int>) : int ensures s == [] ==> Sum(s) == 0 ensures s != [] ==> Sum(s) == s[0] + Sum(s[1..])
{ if s == [] then 0 else s[0] + Sum(s[1..]) }

method Feb2013(v: array<int>, m : int) returns (s : int, p1 : int)
requires v != null
requires 1 <= m <= v.Length
ensures 0 <= p1 <= v.Length - m // La pesicion puede ser cualquiera del vector menos por la m
ensures s == Sum(v[p1..p1+m])
ensures forall u :: 0 <= u <= (v.Length - m) ==> (Sum(v[u..u+m]) <= s) // Dictamos que la suma sea maxima
{
	var i := 0; var j := 0; 
	var sumPares := 0;
	while(i < m){
		sumPares := sumPares + v[i];
		i := i + 1;
	}

	p1 := 0;
	s := sumPares;

	while(j < v.Length - m)
	invariant 0 <= j <= v.Length - m
	invariant sumPares == Sum(v[j..j+m+1]) 
	decreases v.Length - m - j
	{
		sumPares := sumPares - v[j] + v[j + m];
		if(sumPares > s) { 
			s := sumPares; // Asignamos el valor de maximos a suma
			p1 := j + 1; // 
		}
		j := j + 1;
	}
}