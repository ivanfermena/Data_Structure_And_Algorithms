function Sum(vc:seq<int>) : int
ensures vc == [] ==> Sum(vc) == 0
ensures vc != [] ==> Sum(vc) == vc[0] + Sum(vc[1..])
{
	if(|vc| == 0) then 0
	else vc[0] + Sum(vc[1..])
}

method ventana(vc : array<int>, m : int) returns (s: int, p1 : int)
requires vc != null && vc.Length >= 0
requires 0 <= m <= vc.Length
ensures s == Sum(vc[..m])