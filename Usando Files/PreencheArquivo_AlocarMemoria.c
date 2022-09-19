#include <stdio.h>
#include <stdlib.h>
/*
Ian da Silva Correia
ADS

Preenche Arquivo com números digitados e Aloca memoria de forma dinamica
*/

//Variaveis globais
int Q = 10;

//Prototipos de funções
int alocar_vetor();
int realocar_vetor (int);
void grava_arquivo (int*);

int main(int argc, char *argv[]) {
	
	int *vet_num;
	int i, aux;
	
	//alocar memoria para o vetor
	vet_num = alocar_vetor();
	
	//preenche o vetor e realoca caso necessario
	printf("\nP3 - Questao 2\nPreenche arquivo com os numeros digitados\nDigite 0 para finalizar\n");
	for(i=0;i<Q;i++){
		scanf("%d", &aux);
		if(aux != 0){
			vet_num[i] = aux;
		}else{
			vet_num[i] = '\0';
			break;
		}
		if(i==(Q-1)){
			printf("\nAdicionar mais numeros causara a expansao do vetor\nDigite 0 caso deseje finalizar.\n");
			Q = Q + 10;
			vet_num = realocar_vetor (vet_num);
		}
	}
	grava_arquivo(vet_num);
	
	return 0;
}

int alocar_vetor (){
	int *vet_num;
	if(malloc(Q * sizeof(int)) == NULL){
		printf("\nErro ao alocar Memoria\n");
		exit(0);
	}else{
		vet_num = malloc(Q * sizeof(int));
		printf("\nMemoria alocada com sucesso\n");
	}
	return vet_num;
}

int realocar_vetor (int vet_num){
	
	if(realloc(vet_num, Q * sizeof(int)) == NULL){
		printf("\nErro ao realocar Memoria\n");
		exit(0);
	}else{
		vet_num = realloc(vet_num, Q * sizeof(int));
		printf("\nMemoria realocada com sucesso\n");
	}
	return vet_num;
}

void grava_arquivo (int *vet_num){
	int i;
	FILE *resultado = fopen("resultado.txt", "a");
	
	// Verificação de abertura	 
	if(resultado == NULL){
		printf("Impossivel abrir algum dos arquivos!");
		exit(0);
	}else{
		printf("Arquivos abertos com sucesso!");
	}
	
	//preenche arquivo
	for(i=0;i<Q;i++){
		if(vet_num[i] != 0){
			fprintf(resultado, "%d\n", vet_num[i]);
		}else{
			break;
		}
	}
	fclose(resultado);
}