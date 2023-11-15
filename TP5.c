#include <stdio.h>
#include <string.h>
#include <locale.h>

#define N 10 

struct Aluno{
	char nome[50];
	float nota1;
	float nota2;
	float media; 
};

void limpar_struct(struct Aluno *aluno){
	strcpy(aluno->nome, "NULL");
	aluno->nota1 = 0.0;
	aluno->nota2 = 0.0;
	aluno->media = 0.0;
}

void ler_dados_struct(struct Aluno *aluno){
	printf("Digite o nome do aluno: ");
	fflush(stdin);
	fgets(aluno->nome, 50, stdin);
		
	printf("Digite a 1ª nota: ");	
	fflush(stdin);
	scanf("%f", &aluno->nota1);
	
	printf("Digite a 2ª nota: ");	
	fflush(stdin);
	scanf("%f", &aluno->nota2);
	
	aluno->media = (aluno->nota1 + aluno->nota2) / 2;
}

void guardar_arquivo(struct Aluno *aluno, FILE *f){
	fprintf(f, "Nome: %s\nNota 1: %.2f\nNota 2: %.2f\nMédia: %.2f\n\n", aluno->nome, aluno->nota1, aluno->nota2, aluno->media);
}

int main(){
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	struct Aluno aluno[N];
	int i;
	
	for(i = 0; i < N; i++){
		limpar_struct(&aluno[i]);
	}
	
	FILE *f;
	
	f = fopen("arquivo.txt", "w");
	
	if(f == NULL) {
		printf("Erro ao tentar abrir o arquivo!");	
		system("pause");
		return 1;	
	}
	
	for(i = 0; i < N; i++){
		ler_dados_struct(&aluno[i]);
		system("cls");
	}
	
	for(i = 0; i < N; i++){
		guardar_arquivo(&aluno[i], f);
	}
	
	fclose(f);
	
	return 0;
}
