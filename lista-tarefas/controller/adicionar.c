#include "../headers/controler_header/adicionar.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void adicionar_tarefa(Tarefa* tasks, int* task_count, int* next_id, int* prioridade) {
    if (*task_count >= MAX_TAREFAS) {
        printf("❌ Limite máximo de tarefas atingido!\n");
        return;
    }

    printf("📝 Digite a descrição da tarefa: ");
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    fgets(tasks[*task_count].descricao, MAX_DESCRIPTION, stdin);
    tasks[*task_count].descricao[strcspn(tasks[*task_count].descricao, "\n")] = '\0';

    printf("🎯 Selecione a prioridade da tarefa (1-3): ");
    scanf("%d", prioridade);
    
    while (*prioridade < 1 || *prioridade > 3) {
        printf("❌ Prioridade inválida! Selecione um número entre 1 e 3: ");
        scanf("%d", prioridade);
    }

    tasks[*task_count].concluida = 0;
    tasks[*task_count].prioridade = *prioridade;
    tasks[*task_count].id = *next_id;
    
    printf("ID: %d\n", tasks[*task_count].id);
    printf("Descrição: %s\n", tasks[*task_count].descricao);
    printf("Prioridade: %d\n", tasks[*task_count].prioridade);
    printf("Status: %s\n", tasks[*task_count].concluida ? "✅ Concluída" : "⏳ Pendente");    
    
    (*next_id)++;
    (*task_count)++;
    
    printf("✅ Tarefa adicionada com sucesso!\n");
}