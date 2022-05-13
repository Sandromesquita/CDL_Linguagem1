#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int matricula = 30;
	
	int *ponteiro;
	
	ponteiro = &matricula;
	
	printf("\nMatricula: %d", matricula);
	printf("\nEndereco da variavel matricula: %x", &matricula);
	printf("\nConteudo da variavel ponteiro: %x", ponteiro);
	
	int cpf = 123456;
	int *pont2;	
	pont2 = &cpf;
	
	printf("\n\nCPF: %d", cpf);
	printf("\nEndereco da variavel CPF: %x", &cpf);
	printf("\nConteudo da variavel pont2: %x", pont2);
	
	return 0;
}
