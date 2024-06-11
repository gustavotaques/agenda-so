#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int telefone;
} Contato;


int main(void){
    Contato contato;
    FILE *arquivo;
    int op;

    arquivo = fopen("agenda.bin", "wb");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("BEM VINDO A AGENDA ELETRONICA!\n\n");

    do {
        printf("1 - Adicionar um contato\n");
        printf("2 - Consultar um contato\n");
        printf("3 - Excluir um contato\n");
        printf("4 - Fechar a agenda\n\n");

        printf("Digite a opcao desejada: ");
        scanf("%i", &op);
        printf("\n");


        switch (op) {

        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            break;
        default:
            printf("VALOR INVALIDO!\n\n");
            break;
        }
    } while (op != 4);

    fclose(arquivo);

    return 0;
}