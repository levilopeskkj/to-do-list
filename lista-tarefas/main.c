#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// View headers
#include "headers/view_header/menu.h"

// Controller headers
#include "headers/controler_header/tarefa.h"
#include "headers/controler_header/adicionar.h"
#include "headers/controler_header/listar_tarefas.h"
#include "headers/controler_header/concluir_tarefa.h"
#include "headers/controler_header/remover_tarefa.h"
#include "headers/controler_header/mostrar_estatistica.h"
#include "headers/controler_header/alterar_tarefa.h"
#include "headers/controler_header/buscar_tarefa.h"

#define MAX_TAREFAS 100
#define MAX_DESCRIPTION 256

// Global variables
Tarefa tasks[MAX_TAREFAS];
int task_count = 0;
int next_id = 1;

int main() {
    char escolha;

    printf("    _                  _         _     _     _   \n");
    printf("   | |_ ___         __| | ___   | |   (_)___| |_ \n");
    printf("   | __/ _ \\ _____ / _` |/ _ \\  | |   | / __| __|\n");
    printf("   | || (_) |_____| (_| | (_) | | |___| \\__ \\ |_ \n");
    printf("    \\__\\___/       \\__,_|\\___/  |_____|_|___/\\__|\n");
    printf("                                                      \n");
    printf("     Bem-vindo ao Todo List!\n");
    
    while (1) {
        mostrar_menu();
        if (scanf("%c", &escolha) != 1) {
            printf(" Op o inv lida! Digite um n mero.\n");
            continue;
        }

        switch (escolha) {
            case '1':
                int prioridade = 0;
                adicionar_tarefa(tasks, &task_count, &next_id, &prioridade); 
                break;
            case '2':
                listar_tarefas(tasks, task_count);
                break;
            case '3':
                concluir_tarefa(tasks, &task_count);
                break;
            case '4':
                remover_tarefa(tasks, &task_count);
                break;
            case '5':
                mostrar_estatistica(tasks, task_count);
                break;
            case '6':
                alterar_tarefa(tasks, task_count); // Option 6 is Alterar tarefa
                break;
            case '7':
                buscar_tarefa(tasks, &task_count); // Option 7 is Buscar tarefa
                break;
            case '8':
                printf(" Obrigado por usar o Todo List! At  logo!\n");
                printf(" _                  _                \n");
                printf("| |__  _   _  ___  | |__  _   _  ___ \n");
                printf("| '_ \\| | | |/ _ \\ | '_ \\| | | |/ _ \\\n");
                printf("| |_) | |_| |  __/ | |_) | |_| |  __/\n");
                printf("|_.__/ \\__, |\\___| |_.__/ \\__, |\\___|\n");
                printf("       |___/              |___/      \n");

                exit(0);
            default:
                printf(" Op o inv lida! Escolha entre 1 e 8.\n");
        }
        
        printf("\nPressione Enter para Confirmar...");
        getchar();
        getchar();
        system("clear");
    }
    
    return 0;
}