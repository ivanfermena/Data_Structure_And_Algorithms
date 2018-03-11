predicate sonCeros(s: seq<int>)
ensures forall u :: 0 <= u < |s| ==> s[u] == 0


method segMaximo (v: array<int>) returns( ini: int, fin : int)
requires v != null && v.Length > 0
ensures 0 <= ini <= fin < v.Length
ensures sonCeros(v[ini..fin])
ensures forall i, j:: 0 <= i <= j < v.Length && sonCeros(v[i..j]) ==> fin - ini >= j - i
{
	ini := 0;
	var iniAux := 0;
	var maxLong := 0;
	var i := 0;

	while(i < v.Length)
	{
		if(v[i] == 0){
			if(maxLong < i - iniAux + 1){
				maxLong := i - iniAux + 1;
				ini := iniAux;
			}
		}else{
			iniAux := i + 1;
		}
		i := i + 1;
	}
	fin:= ini + maxLong - 1;
}