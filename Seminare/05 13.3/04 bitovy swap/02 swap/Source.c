void swap(void* adr1,void* adr2,sizeof size) {
	char *p1, *p2;
	p1 = (char*)adr1;
	p2 = (char*)adr2;
	while (size>=1) {
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;

		size--;
		p1 ++;
		p2 ++;
	}

}
int main() {
	int a, b;
	printf("pred: a = ,b = ",&a,&b);
	swap(&a,&b,sizeof(&a));
	printf("po: a = ,b = ",&a,&b);
	return 0;
}