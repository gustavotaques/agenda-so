#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[11];
} Contato;

void adicionarContatos(FILE *arquivo) {
    Contato contato;

    printf("Digite o nome do contato: ");
    fgets(contato.nome, 100, stdin);
    contato.nome[strlen(contato.nome)-1] = '\0';

    printf("Digite o telefone do contato: ");
    fgets(contato.telefone, 11, stdin);
    contato.telefone[strlen(contato.telefone)-1] = '\0';

    fwrite(&contato, sizeof(Contato), 1, arquivo);
}

void consultarContatos(FILE *arquivo) {
    
}

void excluirContatos(FILE *arquivo) {

}


int main(void){
    FILE *arquivo;
    int op;

    arquivo = fopen("agenda.bin", "wb+");
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
        fflush(stdin);
        printf("\n");

        switch (op) {

        case 1:
            adicionarContatos(arquivo);
            break;
        case 2:
            consultarContatos(arquivo);
            break;
        case 3:
            excluirContatos(arquivo);
            break;
        case 4:
            printf("Agenda fechada. Até breve!\n");
            fclose(arquivo);
            return 0;
        default:
            printf("VALOR INVALIDO!\n\n");
            break;
        }
    } while (op != 4);

    fclose(arquivo);

    return 0;
}