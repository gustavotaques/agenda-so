#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100
#define TAM_TEL 20

typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TEL];
} Contato;

void adicionarContatos(FILE *arquivo);
int consultarContatos(FILE *arquivo);
void excluirContatos(FILE *arquivo);

int main(void){
    int op;
    FILE *arquivo;

    arquivo = fopen("agenda.bin", "rb+");
    if(arquivo == NULL){
        arquivo = fopen("agenda.bin", "wb+");
        if(arquivo == NULL){
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }
    }

    printf("BEM VINDO A AGENDA ELETRONICA!\n");

    do {
        printf("\n1 - Adicionar um contato\n");
        printf("2 - Consultar um contato\n");
        printf("3 - Excluir um contato\n");
        printf("4 - Fechar a agenda\n\n");

        printf("Digite a opcao desejada: ");       
        scanf("%d", &op);
        getchar();
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
            break;
        default:
            printf("VALOR INVALIDO!\n\n");
            break;
        }
    } while (op != 4);

    fclose(arquivo);

    return 0;
}

void adicionarContatos(FILE *arquivo) {
    Contato contato;

    printf("Digite o nome do contato: ");
    fgets(contato.nome, TAM_NOME, stdin);
    contato.nome[strlen(contato.nome)-1] = 0;

    printf("Digite o telefone do contato: ");
    fgets(contato.telefone, TAM_TEL, stdin);
    contato.telefone[strlen(contato.telefone)-1] = 0;

    fseek(arquivo, 0, SEEK_END);
    fwrite(&contato, sizeof(Contato), 1, arquivo);
}

int consultarContatos(FILE *arquivo) {
    Contato contato;
    char nome[TAM_NOME];

    printf("Digite o nome do contato a ser consultado: ");
    fgets(nome, TAM_NOME, stdin);
    nome[strlen(nome)-1] = 0;
    

    fseek(arquivo, 0, SEEK_SET);
    while(fread(&contato, sizeof(Contato), 1, arquivo)){
        if(strcmp(contato.nome, nome) == 0){
            printf("\nContato encontrado!\n\nNome: %s\nTelefone: %s\n\n", contato.nome, contato.telefone);
            return 0;
        }
    }
    printf("\nContato nao encontrado! :(\n");
    return -1;
}

void excluirContatos(FILE *arquivo) {

}