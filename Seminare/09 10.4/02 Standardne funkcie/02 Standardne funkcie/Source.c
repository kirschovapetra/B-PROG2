#include <stdio.h>
#include <string.h>

/*1. [http://www.cplusplus.com/reference/clibrary/cstring/strlen/ strlen]
Vstupom funkcie je re�azec, funkcia vr�ti po�et znakov.
Vysk��ajte, �o sa stane, ak v predo�lej �lohe neuko��te re�azec znakom '\0' a zavol�te funkciu strlen.
Naprogramujte si vlastn� verziu tejto funkcie.*/
int str_len(char str[]) {
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}

/*2. [http://www.cplusplus.com/reference/clibrary/cstring/strcmp/ strcmp]
Vstupom funkcie s� dva re�azce, v�stupom je 0, ak s� zhodn�, kladn� ��slo, ak prv� re�azec je v��� (nesk�r v lexikografickom porad�), 
z�porn� ak prv� je men��. Vysk��ajte si t�to funkciu.
Dok�ete pou�i� t�to funkciu v kombin�cii s [http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ qsort] na zotriedenie 
parametrov z pr�kazov�ho riadku?
Naprogramujte si vlastn� verziu tejto funkcie.*/
int str_cmp(char str1[], char str2[]) {
	int i,z;
	int n = strlen(str1);
	int m = strlen(str2);
	if (n>m) {
		z = n;
		n = m;
		m = z;
	}
	for (i = 0; i < n; i++) {
		if (str1[i] > str2[i])
			return 1;
		else
			return -1;
	}
	return 0;
}



/*3. [http://www.cplusplus.com/reference/clibrary/cstring/strchr/ strchr]
N�jde prv� v�skyt zadan�ho znaku v re�azci, vr�ti pointer na t�to poz�ciu - vysk��ajte si pr�klad z cplusplus.com
Nap�te vlastn� verziu tejto funkcie, ktor� ale nevracia pointer, ale poz�ciu (index) prv�ho v�skytu p�smena, alebo -1, ak sa v re�azci nenach�dza.
Nap�te funkciu, ktor� vr�ti index posledn�ho v�skytu p�smena, alebo -1, ak sa v re�azci nenach�dza.
Nap�te funkciu, ktor� vr�ti po�et v�skytov p�smena v re�azci.*/
int str_chr(char c, char str[]) {
	int i,ind = -1;
	for (i = 0; i < strlen(str); i++) {
		if (c==str[i]) {
			ind = i;
		}
	}
	return -1;
}

/*4. [http://www.cplusplus.com/reference/clibrary/cstring/strstr/ strstr]
N�jde prv� v�skyt podre�azca.
Vedeli by ste naprogramova� vlastn� verziu s pou�it�m [http://www.cplusplus.com/reference/clibrary/cstring/strncmp/ strncmp] ?
Vedeli by ste naprogramova� vlastn� verziu bez pou�itia kni�ni�n�ch funkci�?*/
int str_str_b(char str1[], char str[]) {
	int i,j;
	for (i = 0; i < strlen(str);i++) {
		if (str[i] == str1[0]) {
			if (i + strlen(str1) > strlen(str))
				return 0;
			else {
				for (j = i; j < strlen(str1); j++) {
					if (str[j] != str1[j-i])
						return 0;
				}
			}	
		}
	}
	return 1;
}

/*5. [http://www.cplusplus.com/reference/clibrary/cstring/strtok/ strtok]
Tokeniz�cia stringu - rozdel� ho na podre�azce, napr. ke� m�te �iarkami oddelen� �daje, potrebujete rozdeli� text na vety, slov�...
Vysk��ajte si spravi� program, ktor� na��ta riadok z kl�vesnice (pomocou fgets, pripravte dos� dlh� pole na uchovanie znakov), 
rozdel� ho na slov� (pomocou strtok) a vyp�e slov� v opa�nom porad� (najjednoduch�ie je uchova� v�sledn� smern�ky, 
ktor� vr�ti strtok do po�a smern�kov, a to pole prejs� odzadu)*/
int str_tok(char str[], int c,int n, int pole[][10]) {
	int i, poz = 0;
	for (i = 0;i<strlen(str);i++) {
		return 0;
	}

}

int main() {
	return 0;
}