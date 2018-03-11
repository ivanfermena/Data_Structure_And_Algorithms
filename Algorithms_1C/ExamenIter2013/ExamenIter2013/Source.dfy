predicate isUnos (vc : seq<int>, p : int)
requires 0 <= p < |vc|
{
	forall i :: 0 <= i <= p ==> vc[i] == 1
}

predicate isCeros (vc : seq<int>, p : int)
requires 0 <= p < |vc|
{
	forall i :: p < i < |vc| ==> vc[i] == 0
}

method esValida(vc : array<int>) returns (p: bool)
// Precondicion
requires vc != null && vc.Length >= 0
requires forall i :: 0 <= i < vc.Length ==> vc[i] == 0 || vc[i] == 1
//Postcondicion
	//Primera opcion
//ensures p == exists u :: 0 <= u < vc.Length ==> (forall i :: 0 <= i < u < vc.Length ==> (vc[i] == 1 && vc[u] == 0))
	//Segunda opcion
// Existe un u, i para todo el vector , en el que las posiciones i son 1 y las u son 0
ensures p == exists u :: 0 <= u < vc.Length ==> (isUnos(vc[..], u) && isCeros(vc[..], u))
{
	if(vc.Length == 0){
		return false;
	}

	var isExito := true;
	var isZero := false;
	var i := 0;

	while (i < vc.Length && isExito)
	invariant 0 <= i <= vc.Length
	invariant p == exists u :: 0 <= u < i ==> (isUnos(vc[..], u) && isCeros(vc[..], u))
	decreases vc.Length - i
	{
		if (vc[i]==0 && !isZero){
			isZero := true;
		}
		if (isZero && vc[i] == 1){
			isExito := false;
		}
		i := i + 1;
	}
	return isExito;
}