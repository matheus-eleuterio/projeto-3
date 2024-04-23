#include <stdio.h>
#include <stdlib.h>
#include "tarefas.h"

#define MAX_CONTATOS 255

struct Contato {
    char nome[50];
    char sobrenome[50];
    char email[100];
    char telefone[15];
};

struct Contato agenda[MAX_CONTATOS];
int numContatos = 0;

void adicionarContato() {
    if (numContatos >= MAX_CONTATOS) {
        printf("Limite de contatos atingido!\n");
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]", agenda[numContatos].nome);
    printf("Sobrenome: ");
    scanf(" %[^\n]", agenda[numContatos].sobrenome);
    printf("Email: ");
    scanf(" %[^\n]", agenda[numContatos].email);
    printf("Telefone: ");
    scanf(" %[^\n]", agenda[numContatos].telefone);

    numContatos++;
    printf("Contato adicionado com sucesso!\n");
}

void listarContatos() {
    if (numContatos == 0) {
        printf("Nenhum contato na agenda!\n");
        return;
    }

    printf("\nLista de contatos:\n");
    for (int i = 0; i < numContatos; i++) {
        printf("%d. %s %s - %s - %s\n", i+1, agenda[i].nome, agenda[i].sobrenome, agenda[i].email, agenda[i].telefone);
    }
}

void deletarContato() {
    if (numContatos == 0) {
        printf("Nenhum contato para deletar!\n");
        return;
    }

    char telefone[15];
    printf("Digite o telefone do contato a ser deletado: ");
    scanf(" %[^\n]", telefone);

    int encontrado = 0;
    for (int i = 0; i < numContatos; i++) {
        if (strcmp(telefone, agenda[i].telefone) == 0) {
            encontrado = 1;
            for (int j = i; j < numContatos - 1; j++) {
                agenda[j] = agenda[j+1];
            }
            numContatos--;
            printf("Contato deletado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Contato nao encontrado!\n");
    }
}

void salvarAgenda() {
    FILE *arquivo;
    arquivo = fopen("agenda.bin", "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fwrite(agenda, sizeof(struct Contato), numContatos, arquivo);
    fclose(arquivo);

    printf("Agenda salva em arquivo binario!\n");
}

void carregarAgenda() {
    FILE *arquivo;
    arquivo = fopen("agenda.bin", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    numContatos = fread(agenda, sizeof(struct Contato), MAX_CONTATOS, arquivo);
    fclose(arquivo);

    printf("Agenda carregada do arquivo binario!\n");
}
