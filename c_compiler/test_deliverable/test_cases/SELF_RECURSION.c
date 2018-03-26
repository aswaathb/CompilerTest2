int self_recursion(int a){
	if (a==0){
		return a;
	}
	return self_recursion(a-1);
}
