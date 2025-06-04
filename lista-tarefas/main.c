#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//// biblioteca própria
#include "headers/controler_header/tarefas.h"
#include "headers/view_header/menu.h"

//////

#define MAX_TAREFAS 100
#define MAX_DESCRIPTION 256

Tarefa tasks[MAX_TAREFAS];
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
                adicionar_tarefa(tasks, &task_count, &next_id);
                break;
            case 2:
                listar_tarefas(tasks, task_count);
                break;
            case 3:
                concluir_tarefa(tasks, &task_count);
                break;
            case 4:
                remover_tarefa(tasks, &task_count);
                break;
            case 5:
                mostrar_estatisticas(tasks, task_count);
                break;
            case 6:
                buscar_tarefa(tasks, task_count);
                break;
            case 7:
                printf("👋 Obrigado por usar o Todo List! Até logo!\n");
                exit(0);
            default:
                printf("❌ Opção inválida! Escolha entre 1 e 7.\n");
        }
        
        printf("\nPressione Enter para continuar...");
        getchar();
    }
    
    return 0;
}