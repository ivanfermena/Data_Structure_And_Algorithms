function Sum(s : seq<int>) : int ensures s == [] ==> Sum(s) == 0 ensures s != [] ==> Sum(s) == s[0] + Sum(s[1..])
{ if s == [] then 0 else s[0] + Sum(s[1..])}

method practicaAcum(v: array<int>)
requires v != null && v.Length > 0
requires v[v.Length - 1] == 0
requires forall i :: 0 <= i < v.Length ==> v[i] >= 0
ensures forall i,j :: 0 <= i < j < v.Length ==> v[i] == v[i] + Sum(v[j..])
modifies v
ensures v.Length == old(v.Length - 1)
ensures forall i :: 0 <= i < v.Length ==> v[i] in old(v[..])
ensures forall j :: 0 <= j < old(v.Length) ==> old(v[j]) in v[..]