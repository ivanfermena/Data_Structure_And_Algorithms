// Version sin marcas, con esValida(), coste n de esValida()

void resolver(int n, int m, std::vector<char> & sol, int k) {
	for (char x = 'a'; x < 'a' + n; x++){
		sol[k] = x;
		if (esValida(sol, k))
			if (k == m - 1)
				escribir(sol, m);
			else resolver(n, m, sol, k+1);
	}
}

bool esValida(std::vector<char> const & sol, int k){
	int i = 0;
	while (i < k && sol[i] != sol[k]) ++i;
	return i == k;
}

// Version con marca, valor de esValida() cte

void resolver(int n, int m, std::vector<char> & sol, int k, std::vector<bool> & marca) {
	for (char x = 'a'; x < 'a' + n; x++) {
		sol[k] = x;
		if (!marca[x - 'a']) {
			marca[x - 'a'] = true;
			if (k == m - 1)
				escribir(sol, m);
			else resolver(n, m, sol, k + 1, marca);
			marca[x - 'a'] = false;
		}
	}
}