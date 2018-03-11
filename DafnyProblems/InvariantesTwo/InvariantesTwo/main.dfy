/*
	- Ejercicio de predicados, evaluacion continua
	- Asume es para cuando no comprende v[k+1..]??
	- No entendemos como poner invariantes o que es necesario poner
	- Los nuevos del juez son con dafny o sin Dafny / A partir de ahora implementacion con Dafny??

function Sum(s : seq<int>) : int 
ensures s == [] ==> Sum(s) == 0
ensures s != [] ==> Sum(s) == s[0] + Sum(s[1..])
{ if s == [] then 0 else s[0] + Sum(s[1..]) }

// Vector de acumulados suponiendo que el vector no es vac’o
// El vector v es de salida. Se asegura en el ensures que estar‡ definido
// se le reserva memoria en el c—digo
method problema1 (a: array<int>) returns (v : array<int>)
requires a != null && a.Length > 0
ensures v != null && v.Length > 0 && a.Length == v.Length
ensures forall k :: 0 <= k < v.Length ==> Sum(a[k..]) == v[k]
{
	v := new int[a.Length];
	var i := v.Length;
	var aux := 0;

	while(i > 0)
	invariant 0 <= i <= v.Length
	invariant aux == Sum(a[i..])
	invariant forall k :: i <= k < v.Length ==> Sum(a[k..]) == v[k]
	invariant a.Length == a.Length
	decreases i
	{
		aux := a[i-1] + aux;
		v[i-1] := aux;
		i := i - 1;
	}
}

// Vector acumulado suponiendo que el vector puede ser vacio

method problema2 (a: array<int>) returns (v : array<int>)
requires a != null 
ensures v != null && a.Length == v.Length
ensures
{
	v := new int[a.Length];
	...
}
*/

// n-esimo termino de la sucesion de Fibonacci
function Fib (n : int) : int
{
	if (n < 2) then n
	else Fib(n-2) + Fib(n-1)
}

method Fibonacci (n : int) returns (f : int)
requires n >= 0
ensures f == Fib(n)  
{
	var aux := 0;
	if(n<2){f:=n;}
	else{
		var i := 0;
		f := 1;
		while(i <= n-2)
		invariant 0 <= i <= n-1
		invariant f == Fib(i+1)
		invariant aux == Fib(i)
		{
			f := f + aux;
			aux := f - aux;
			i := i + 1;
		}
	}
	
}