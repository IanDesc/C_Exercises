#include <stdio.h>
#include <stdlib.h>

/*
Ian da Silva Correia.
ADS

Leitor de arquivos e gerador de boletim
*/

int main(int argc, char *argv[]){
	float nota;
	char leitor[2200];
	int i, j,
		ra, 
		acertos,
		opcao[31],
		respostas[31];
	
	FILE *gabarito = fopen("gabarito.txt", "r"),
		 *prova = fopen("prova.txt", "r"),
		 *boletim = fopen("boletim.txt", "a+");
		 
	// Verificação de abertura
	if(gabarito == NULL || prova == NULL || boletim == NULL){
		printf("Impossivel abrir algum dos arquivos!");
		exit(0);
	}else{
		printf("Arquivos abertos com sucesso!\n");
	}
	
	// Passa respostas para vetor
	for(i=0;i<30;i++){
		fscanf(gabarito, "%d", &respostas[i]);
		//printf("\n%d", respostas[i]);
	}
	
	// Verifica acertos e preenche arquivo
	for(i=0;i<10;i++){
		acertos = 0;
		nota = 0;
		
		fscanf(prova, "%d;", &ra);
		//printf("\n%d\n", ra);
		
		for(j=0;j<30;j++){
			fscanf(prova, "%d;", &opcao[j]);
			if(opcao[j] == respostas[j]){
				acertos++;
				nota = nota + 0.5;
			}
			//printf("\n%d", opcao[j]);
		}
		
		//preenche arquivo
		fprintf(boletim, "------------------------------\n");
		fprintf(boletim, "RA.........: %d\n", ra);
		fprintf(boletim, "Acertos....: %d\n", acertos);
		fprintf(boletim, "RA.........: %2.2f\n", nota);
		if(nota >= 7.5){
			fprintf(boletim, "Resultado..: Aprovado\n");
		}else{
			fprintf(boletim, "Resultado..: Reprovado\n");
		}
		fprintf(boletim, "------------------------------\n\n");
	}
	
	for(i=0;i<69;i++){
		fgets(leitor, 32, boletim);
		printf("%s", leitor);
	}
	
	fclose(gabarito),
		(prova),
		(boletim);
	return 0;
}