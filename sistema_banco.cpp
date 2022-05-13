#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int op, i = 0, x = 0;
	float saldo = 0, valor = 0, limite = 1000, cheque_especial = 100, deposito_ch = 0;
	bool cont = true;
	float movimentacao[10] = {};
	
	printf("-----Sistema Automatico do Banco Popular-----\n");
	
	while (cont == true){
		printf("\n\n---------------");
		printf("\n(1) para Saldo\n(2) para Extrato\n(3) para Saque\n(4) para Emprestimo\n(5) para Deposito\n(6) para Sair\n");
		
		printf("\nInforme a operacao desejada: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("\n-----Saldo %.2f-----", saldo);
				break;
				
			case 2:
				printf("\n-----Extrato-----");
				printf("\nSaldo %.2f", saldo);
				printf("\nValor disponivel para emprestimo: %.2f", limite);
				printf("\nLimite do cheque especial disponivel %.2f", cheque_especial);
				
				for (x=0; x < i; x = x + 1){
					printf("\nExtrato: %.2f", movimentacao[x]);
				} 
				
				break;
				
			case 3:
				printf("\n-----Saque----");
				printf("\nInforme o valor do saque: ");
				scanf("%f", &valor);
				
				if (valor <= saldo){
					saldo = saldo - valor;
					movimentacao[i] = saldo;
					i = i + 1;
				}
				else if (valor <= (saldo + cheque_especial)){
					printf("Usando cheque especial.");
					saldo = saldo - valor;
					cheque_especial = cheque_especial + saldo;
					printf("\nLimite do cheque especial disponivel %.2f", cheque_especial);
					movimentacao[i] = saldo;
					i = i + 1;
				}
				else{
					printf("Saldo insuficiente.");
				}
				
				printf("\n-----Saldo %.2f-----", saldo);
				break;
				
			case 4:
				printf("\n-----Emprestimo-----");
				printf("\nValor disponivel para emprestimo: %.2f", limite);
				
				printf("\nInforme o valor do emprestimo: ");
				scanf("%f", &valor);
				
				//Bloco if responsavel por verificar se o valor solicitado esta dentro do limite disponivel
				if (valor <= limite){
					limite = limite - valor;
					saldo = saldo + valor;
				}
				else{
					printf("Limite insuficiente.");
				}
				
				printf("\nSaldo %.2f", saldo);
				printf("\nValor disponivel para emprestimo: %.2f", limite);
				break;
				
			case 5:
				printf("\n-----Deposito-----");
				printf("\nInforme o valor do deposito: ");
				scanf("%f", &valor);
				
				/*
				saldo = -30,00
				usei 30,00 do cheque
				cheque_especial = 70,00
				valor = 50,00
				Se o saldo é menor que zero - ok
					se (valor + saldo) < 0
						deposito_ch = valor
						cheque_especial = cheque_especial + deposito_ch
					se nao
						deposito_ch = saldo*(-1)
						cheque_especial = cheque_especial + deposito_ch
				*/
				if (saldo < 0){
					if ((valor + saldo) < 0){
						deposito_ch = valor;
					}
					else{
						deposito_ch = saldo*(-1);
					}
					cheque_especial = cheque_especial + deposito_ch;
				}
				
				saldo = saldo + valor;
				printf("\n-----Saldo %.2f-----", saldo);
				movimentacao[i] = saldo;
				i = i + 1;
				break;
				
			case 6:
				printf("\n-----Sair-----\n");
				cont = false;
				break;
				
			default:
				printf("\n-----Invalido-----");
				
		}
	}
	printf("\n\n---------------");
	printf("\nSaindo do Sistema Automatico do Banco Popular");
	return 0;	
}
