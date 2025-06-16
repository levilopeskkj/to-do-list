#include "../headers/controler_header/listar_tarefas.h"
#include <stdio.h>

void listar_tarefas(const Tarefa* tasks, int task_count) {
    if (task_count == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    printf("\n📋 LISTA DE TAREFAS\n");
    printf("==========================================\n");
    
    for (int i = 0; i < task_count; i++) {
        printf("ID: %d\n", tasks[i].id);
        printf("Status: %s\n", tasks[i].concluida ? "✅ Concluída" : "⏳ Pendente");
        printf("Descrição: %s\n", tasks[i].descricao);
        printf("Prioridade: %d\n", tasks[i].prioridade);
        printf("------------------------------------------\n");
    }
    
    printf("Total de tarefas: %d\n", task_count);
    printf("==========================================\n");
}