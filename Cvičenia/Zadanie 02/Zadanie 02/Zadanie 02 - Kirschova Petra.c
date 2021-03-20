#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//generator nahodneho cisla
int random(int min, int max) {
	if ((max - min + 1) != 0)
		return (rand() % (max - min + 1) + min);
	return 0;
}

//pocitanie vzdialenosti 2 bodov
double vzdialenost(int x1, int y1, int x2, int y2) {
	return (sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
}

//odchylka uhla v stupnoch
int nepresnost_N1(int s) {
	int k;
	k = s*s*45 / (sqrt(s) + s*s + 100);
	return random(-k, k);
}

//odchylka drahy v metroch
int nepresnost_N2(int s) {
	int k;
	k = s / 10;
	return random(-k, k);
}

//suradnica x
int poziciaX(int x0, int y0, int s, int n1, int n2) {
	double alpha;
	alpha = atan2(y0, x0) + n1*M_PI / 180; //uhol alpha je v radianoch, pripocitam odchylku prepocitanu do radianov
	return (x0 - (s + n2)*cos(alpha));    //k sile pripocitam odchylku drahy
}

//suradnica y
int poziciaY(int x0, int y0, int s, int n1, int n2) {
	double alpha;
	alpha = atan2(y0, x0) + n1*M_PI / 180;
	return (y0 - (s + n2)*sin(alpha));
}

int main() {
	int x_j, y_j, x_l, y_l, x_new, y_new, kolo, sila, draha, uhol;
	double v, u;

	srand(time(NULL));
	//jamka ma suradnice(0,0)
	x_j = 0;
	y_j = 0;
	//lopta ma nahodne suradnice v intervale (-100,100)
	x_l = random(-100, 100);
	y_l = random(-100, 100);

	v = vzdialenost(x_l, y_l, y_j, x_j);

	//v pripade,ze je lopticka na zaciatku blizsie ako 10 m tak sa generuju suradnice znovu, pokial nie je vzdialenost vacsia
	while (v <= 10) {
		x_l = random(-100, 100);
		y_l = random(-100, 100);
		v = vzdialenost(x_l, y_l, y_j, x_j);
	}

	printf("START\n");
	printf("lopticka je na pozicii (%d,%d)\njej vzdialenost od jamky je %d m\n", x_l, y_l, (int)v);
	u = atan2(y_l, x_l);
	printf("s x-ovou osou zviera uhol %.2f rad = %.2f stupnov \n", u, u * 180 / M_PI);

	kolo = 0;
	while (v > 1) { //kym sa nedostane do vzdialenosti 1m od jamky

		kolo++;
		printf("\nKOLO %d: aktualne suradnice su (%d,%d)\n", kolo, x_l, y_l);
		printf("Zadaj silu uderu v m (od 1 do %d): ",(int)v);
		scanf("%d", &sila);
		if ((sila >= 1) && (sila <= (int)v)) { 
			uhol = nepresnost_N1(sila);		//do premennej uhol si ulozim odchylku uhla
			draha = nepresnost_N2(sila);	//do premennej draha si ulozim odchylku drahy
			printf("\nodchylka uhla = %d, odchylka drahy = %d\n", uhol, draha);

			//k povodnemu uhlu (v rad) pripocitam odchylku uhla (v rad), vypisem v stupnoch, k zadanej sile pripocitam odchylku drahy
			printf("novy uhol = %.2f, nova draha = %d\n", (atan2(y_l, x_l) + uhol*M_PI / 180) * 180 / M_PI, sila + draha); 
			
			//generujem nove suradnice
			x_new = poziciaX(x_l, y_l, sila, uhol, draha);
			y_new = poziciaY(x_l, y_l, sila, uhol, draha);
			v = vzdialenost(x_new,y_new, y_j, x_j);
			printf("\nnove suradnice su (%d,%d)\nvzdialenost od jamky je %d m\n", x_new, y_new, (int)v);
			if (v <= 1) //ak sa dostala lopticka na min. 1m od jamky tak sa vyskoci z cyklu
				break; 

			//vypocitam novy uhol 
			u = atan2(y_new, x_new);
			printf("s x-ovou osou zviera uhol %.2f rad = %.2f stupnov \n\n", u, u * 180 / M_PI);

			//v dalsom kole pracujem s novymi suradniciami
			x_l = x_new;
			y_l = y_new;
		}
		else		
			continue;
	}
	printf("\nGratulujem, trafil si jamku!\n");
	return 0;
}