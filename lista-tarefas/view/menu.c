#include <stdio.h>
#include <stdlib.h>
#include "/home/levi/Documentos/C/projeto_todo_list/lista-tarefas/headers/controler_header/tarefas.h"
#include "/home/levi/Documentos/C/projeto_todo_list/lista-tarefas/headers/view_header/menu.h"

// Função para mostrar o menu
void mostrar_menu() {
    printf("\n🎯 TODO LIST - GERENCIADOR DE TAREFAS\n");
    printf("==========================================\n");
    printf("1. ➕ Adicionar tarefa\n");
    printf("2. 📋 Listar tarefas\n");
    printf("3. ✅ Marcar tarefa como concluída\n");
    printf("4. 🗑️  Remover tarefa\n");
    printf("5. 📊 Mostrar estatísticas\n");
    printf("6. 🚪 Sair\n");
    printf("==========================================\n");
    printf("Escolha uma opção: ");
}



void mostrar_estatisticas() {
    if (task_count == 0) {
        printf("📊 Nenhuma tarefa para mostrar estatísticas.\n");
        return;
    }
    
    int completed = 0;
    int pending = 0;
    
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].concluida) {
            completed++;
        } else {
            pending++;
        }
    }
    
    printf("\nESTATÍSTICAS:\n");
    printf("==========================================\n");
    printf("Total de tarefas: %d\n", task_count);
    printf("Tarefas concluídas: %d\n", completed);
    printf("Tarefas pendentes: %d\n", pending);
    
    if (task_count > 0) {
        float completion_rate = ((float)completed / task_count) * 100;
        printf("Taxa de conclusão: %.1f%%\n", completion_rate);
    }
    
    printf("==========================================\n");
}
