#include <stdio.h>
#include <stdlib.h>

//// biblioteca própria
#include "headers/controler_header/tarefas.h"
#include "headers/view_header/menu.h"

//////


#define MAX_TASKS 100
#define MAX_DESCRIPTION 256

Tarefa tasks[MAX_TASKS];
int task_count = 0;
int next_id = 1;


int main() {
    int escolha;
    
    printf("🎉 Bem-vindo ao Todo List!\n");
    
    while (1) {
        mostrar_menu();
        if (scanf("%d", &escolha) != 1) {
            printf("❌ Opção inválida! Digite um número.\n");
            continue;
        }

        switch (escolha) {
            case 1:
                adicionar_tarefa();
                break;
            case 2:
                listar_tarefas();
                break;
            case 3:
                concluir_tarefa();
                break;
            case 4:
                remover_tarefa();
                break;
            case 5:
                mostrar_estatisticas();
                break;
            case 6:
                printf("👋 Obrigado por usar o Todo List! Até logo!\n");
                exit(0);
            default:
                printf("❌ Opção inválida! Escolha entre 1 e 6.\n");
        }
        
        printf("\nPressione Enter para continuar...");
        getchar();
    }
    
    return 0;
}