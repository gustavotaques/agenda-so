#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[11];
} Contato;


int main(void){
    Contato contato;
    Contato contatos[100];
    int ncontatos = 0;
    FILE *arquivo;
    int op;

    arquivo = fopen("agenda.bin", "w+b");
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
            printf("Digite o nome do contato: ");
            scanf("%s", contato.nome);
            printf("\n");
            printf("E seu telefone: ");
            scanf("%s", contato.telefone);
            printf("\n");
            fwrite(&contato, sizeof(Contato), 1, arquivo);
            break;
        case 2:
            while (fread(&contato, sizeof(Contato), 1, arquivo) == 1) {
                contatos[ncontatos++] = contato;
            }
            for (int i=0; i<ncontatos; i++) {
                printf("Nome: %s\n", contatos[i].nome);
                printf("Nome: %s\n", contatos[i].telefone);
            }
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