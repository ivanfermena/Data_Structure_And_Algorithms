

method practicaAcum(v: array<int>)
requires v != null && v.Length > 0
requires v[v.Length - 1] == 0
requires forall i :: 0 <= i < v.Length ==> v[i] >= 0
ensures forall i,j :: 0 <= i < j < v.Length ==> v[i] == v[i] + Sum(v[j..])