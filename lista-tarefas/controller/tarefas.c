#include "../headers/controler_header/tarefas.h"

#include <stdio.h>
#include <string.h>

void adicionar_tarefa() {
    if (task_count >= MAX_TASKS) {
        printf("❌ Limite máximo de tarefas atingido!\n");
        return;
    }
    
    printf("📝 Digite a descrição da tarefa: ");
    fgets(tasks[task_count].descricao, MAX_DESCRIPTION, stdin);
    tasks[task_count].descricao[strcspn(tasks[task_count].descricao, "\n")] = '\0';
    
    tasks[task_count].concluida = 0;
    tasks[task_count].id = next_id++;
    task_count++;
    
    printf("✅ Tarefa adicionada com sucesso!\n");
}

void listar_tarefas() {
    if (task_count == 0) {
        printf("📋 Nenhuma tarefa encontrada.\n");
        return;
    }
    
    printf("\n📋 LISTA DE TAREFAS:\n");
    printf("==========================================\n");
    
    for (int i = 0; i < task_count; i++) {
        printf("ID: %d | Status: %s | %s\n", 
               tasks[i].id,
               tasks[i].concluida ? "✅ Concluída" : "⏳ Pendente", 
               tasks[i].descricao);
    }
    
    printf("==========================================\n");
    printf("Total de tarefas: %d\n", task_count);
}

void concluir_tarefa() {
    if (task_count == 0) {
        printf("📋 Nenhuma tarefa disponível.\n");
        return;
    }
    
    int id;
    printf("🎯 Digite o ID da tarefa para marcar como concluída: ");
    
    if (scanf("%d", &id) != 1) {
        printf("❌ ID inválido!\n");
        return;
    }
    
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].id == id) {
            if (tasks[i].concluida) {
                printf("ℹ️  Tarefa já está concluída!\n");
            } else {
                tasks[i].concluida = 1;
                printf("✅ Tarefa marcada como concluída!\n");
            }
            return;
        }
    }
    
    printf("❌ Tarefa com ID %d não encontrada!\n", id);
}

void remover_tarefa() {
    if (task_count == 0) {
        printf("📋 Nenhuma tarefa disponível.\n");
        return;
    }
    
    int id;
    printf("🗑️  Digite o ID da tarefa para remover: ");
    
    if (scanf("%d", &id) != 1) {
        printf("❌ ID inválido!\n");
        return;
    }
    
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].id == id) {
            for (int j = i; j < task_count - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            task_count--;
            printf("🗑️  Tarefa removida com sucesso!\n");
            return;
        }
    }
    
    printf("❌ Tarefa com ID %d não encontrada!\n", id);
}

