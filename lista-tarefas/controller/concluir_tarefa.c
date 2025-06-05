#include "../headers/controler_header/concluir_tarefa.h"
#include <stdio.h>

void concluir_tarefa(Tarefa* tasks, int* task_count) {
    if (*task_count == 0) {
        printf("❌ Nenhuma tarefa disponível para marcar como concluída.\n");
        return;
    }

    int id;
    printf("🔍 Digite o ID da tarefa que deseja marcar como concluída: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < *task_count; i++) {
        if (tasks[i].id == id) {
            if (tasks[i].concluida) {
                printf("ℹ️  Esta tarefa já está marcada como concluída.\n");
            } else {
                tasks[i].concluida = 1;
                printf("✅ Tarefa marcada como concluída com sucesso!\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("❌ Nenhuma tarefa encontrada com o ID %d.\n", id);
    }
}