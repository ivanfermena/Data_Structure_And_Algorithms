int fibo(int numero) {
	if (numero == 0) return 0;
	else if (numero == 1) return 1;
	else return fibo(numero - 1) + fibo(numero - 2);
}