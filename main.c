#include <stdio.h>
#include "tarefas.h"

int main() {
    int opcao;

    do {
        printf("\n1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Deletar contato\n");
        printf("4. Salvar agenda em arquivo binario\n");
        printf("5. Carregar agenda do arquivo binario\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato();
                break;
            case 2:
                listarContatos();
                break;
            case 3:
                deletarContato();
                break;
            case 4:
                salvarAgenda();
                break;
            case 5:
                carregarAgenda();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
