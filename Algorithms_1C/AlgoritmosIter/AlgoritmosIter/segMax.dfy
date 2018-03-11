predicate sonCeros(v: seq <int>)
ensures sonCeros(v) == forall i :: 0 <= i < |v| ==> v[i] == 0

method segMax(v : array<int>) returns (ini : int, fin : int)
requires v != null && v.Length > 0
ensures 0 <= ini <= fin < v.Length
ensures sonCeros(v[ini..fin]) // Vemos que todos sean ceros desde ini a fin
ensures forall i, j :: 0 <= i <= j < v.Length && sonCeros(v[i..j]) ==> j-i <= fin - ini // COmprobamos que todos los valores de dentro del valor se cumplen
{
	var iniAux := 0; // Iniciamos dos variables auxiliares, el maximo y maximoLong
	var maxLong := 0;
	var i := 0;
	ini := 0;

	while(i < v.Length){
		if(v[i]==0){ //Comprobamos si el elemento es el predicado
			if(maxLong < i - iniAux + 1 ){ // Miramos el valor de elementos desde ini hasta el i que sea igual a  0
				ini := iniAux;
				maxLong := i - iniAux + 1;
			}
		}else{
			iniAux := i + 1;
		}
		i := i + 1;
	}
	fin:= ini + maxLong - 1;
}