#include <stdio.h>
#include <stdlib.h>

typedef struct{
int x, y;
}ponto;

ponto *criaPonto(int x, int y);
ponto *lePonto();
int quadrante(ponto *pon);
int distancia(ponto *pon1, ponto *pon2);

int main(int argc, char *argv[]) {
	ponto *pon1, *pon2;
	int qua;
	
	pon1 = lePonto();
	pon2 = criaPonto(23, -15);
	qua = quadrante(pon1);
	printf("\nA Posição do quadrante é.: %d", qua);
	
	qua = distancia(pon1, pon2);
	printf("\nA distancia entre os dois pontos é.: %d", qua);
	
	
	return 0;
}

ponto *criaPonto(x, y){
	ponto *p = (ponto *)malloc(sizeof(ponto));
	p->x = x;
	p->y = y; 
	
	return p;
}

ponto *lePonto(){
	int x, y;
	printf("\nDigite o valor X do plano Cartesiano.: ");
	scanf("%d", &x);
	printf("\nDigite o valor Y do plano Cartesiano.: ");
	scanf("%d", &y);
	ponto *pon = criaPonto(x, y);
	return pon;
}

int quadrante(ponto *pon){
	if(pon->x > 0 && pon->y > 0) return 1;
	if(pon->x < 0 && pon->y > 0) return 2;
	if(pon->x < 0 && pon->y < 0) return 3;
	if(pon->x > 0 && pon->y < 0) return 4;
}

int distancia(ponto *pon1, ponto *pon2){
	int resultado = (pon1->x - pon2->x) + (pon1->y - pon2->y);
	return resultado;
}




