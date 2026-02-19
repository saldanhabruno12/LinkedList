#include <stdlib.h>
#include <stdio.h>

typedef struct Numero{
	int valor;
	struct Numero *proximo;
} Numero;

struct Numero *head = NULL;

void linkedList(int numero) {
	struct Numero *novoNumero = head;
	struct Numero *posicaoCorreta = NULL;

	//verifica se a cabeça está vazia
	if (novoNumero == NULL) {
		novoNumero = (struct Numero*)malloc(sizeof(struct Numero));
		novoNumero->valor = numero;
		novoNumero->proximo = NULL;
		head = novoNumero;
	}
	else {
		//enquanto o novoNumero tiver proximo
		while (novoNumero->proximo != NULL && novoNumero->proximo->valor < numero) {
			novoNumero = novoNumero->proximo;
		}
		//se for nulo, verificamos se é maior ou menor que o int numero
		if (novoNumero->valor > numero) {
			posicaoCorreta = (struct Numero*)malloc(sizeof(struct Numero));
			posicaoCorreta->valor = numero;
			posicaoCorreta->proximo = novoNumero;
			head = posicaoCorreta;
		}
		else {
			posicaoCorreta = (struct Numero*)malloc(sizeof(struct Numero));
			posicaoCorreta->valor = numero;
			posicaoCorreta->proximo = novoNumero->proximo;
			novoNumero->proximo = posicaoCorreta;
		}
	}
}

void exibirStack() {
	struct Numero* temp = head;

	if (temp == NULL) {
		printf("Stack esta vazia");
	}
	else {
		printf("Elementos da lista:\n");
		while (temp != NULL) {
			if (temp->proximo != NULL) {
				printf("%d----->", temp->valor);
			}
			else {
				printf("%d----->NULL", temp->valor);
			}
			temp = temp->proximo;
		}
	}
}

int main() {

	int numero;

	
	linkedList(69);
	linkedList(20);
	linkedList(12);
	linkedList(45);
	linkedList(15);
	linkedList(18);
	linkedList(2);
	linkedList(1);
	linkedList(10);
	linkedList(13);

	exibirStack();
	
	printf("Teste\n");
	getchar();
	return 0;
}