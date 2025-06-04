        #include "../headers/controler_header/tarefas.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAREFAS 100
#define MAX_DESCRIPTION 256

// Função auxiliar para converter strings para minúsculo
void str_to_lower(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower((unsigned char) str[i]);
}

void adicionar_tarefa() {
    if (task_count >= MAX_TASKS) {
        printf("❌ Limite máximo de tarefas atingido!\n");
        return;
    }

    printf("📝 Digite a descrição da tarefa: ");
    
    // Limpa o buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    fgets(tasks[task_count].descricao, MAX_DESCRIPTION, stdin);
    tasks[task_count].descricao[strcspn(tasks[task_count].descricao, "\n")] = '\0';

    tasks[task_count].concluida = 0;
    tasks[task_count].id = next_id;
    next_id++;
    task_count++;

    printf("✅ Tarefa adicionada com sucesso!\n");
}


void buscar_tarefa(const Tarefa* tasks, int task_count) {
    if (task_count == 0) {
        printf("Nenhuma tarefa disponível para buscar.\n");
        return;
    }

    char keyword[MAX_DESCRIPTION];
    printf("🔍 Digite uma palavra-chave para buscar nas tarefas: ");
    if (fgets(keyword, sizeof(keyword), stdin) == NULL) {
        printf("❌ Erro ao ler palavra-chave.\n");
        return;
    }

    // Remover o caractere de nova linha
    keyword[strcspn(keyword, "\n")] = '\0';

    // Criar cópia da palavra-chave em minúsculas para busca case-insensitive
    char keyword_lower[MAX_DESCRIPTION];
    strcpy(keyword_lower, keyword);
    str_to_lower(keyword_lower);

    printf("\n🔍 RESULTADOS DA BUSCA:\n");
    printf("==========================================\n");
    int found = 0;

    for (int i = 0; i < task_count; i++) {
        char descricao_lower[MAX_DESCRIPTION];
        strcpy(descricao_lower, tasks[i].descricao);
        str_to_lower(descricao_lower);

        if (strstr(descricao_lower, keyword_lower) != NULL) {
            found = 1;
            printf("ID: %d\n", tasks[i].id);
            printf("Status: %s\n", tasks[i].concluida ? "✅ Concluída" : "⏳ Pendente");
            printf("Descrição: %s\n", tasks[i].descricao);
            printf("------------------------------------------\n");
        }
    }

    if (!found) {
        printf("❌ Nenhuma tarefa encontrada com a palavra-chave '%s'.\n", keyword);
    }

    printf("==========================================\n");
}


void listar_tarefas(const Tarefa* tasks, int task_count) {
    if (task_count == 0) {
        printf("📋 Nenhuma tarefa encontrada.\n");
        return;
    }
    
    printf("\n📋 LISTA DE TAREFAS:\n");
    printf("==========================================\n");
    
    for (int i = 0; i < task_count; i++) {
        printf("ID: %d\n", tasks[i].id);
        printf("Status: %s\n", tasks[i].concluida ? "✅ Concluída" : "⏳ Pendente");
        printf("Descrição: %s\n", tasks[i].descricao);
        printf("------------------------------------------\n");
    }
    
    printf("==========================================\n");
    printf("Total de tarefas: %d\n", task_count);
}

void concluir_tarefa(Tarefa* tasks, int* task_count) {
    if (*task_count == 0) {
        printf("📋 Nenhuma tarefa disponível.\n");
        return;
    }

    int id;
    printf("🎯 Digite o ID da tarefa para marcar como concluída: ");
    if (scanf("%d", &id) != 1) {
        printf("❌ ID inválido!\n");
        return;
    }

    for (int i = 0; i < *task_count; i++) {
        if (tasks[i].id == id) {
            tasks[i].concluida = 1;
            printf("✅ Tarefa marcada como concluída!\n");
            return;
        }
    }

    printf("❌ Tarefa não encontrada com o ID %d.\n", id);
}

void remover_tarefa(Tarefa* tasks, int* task_count) {
    if (*task_count == 0) {
        printf("📋 Nenhuma tarefa disponível.\n");
        return;
    }

    int id;
    printf("🗑️ Digite o ID da tarefa para remover: ");
    if (scanf("%d", &id) != 1) {
        printf("❌ ID inválido!\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < *task_count; i++) {
        if (tasks[i].id == id) {
            found = 1;
            for (int j = i; j < *task_count - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            (*task_count)--;
            printf("🗑️ Tarefa removida com sucesso!\n");
            break;
        }
    }

    if (!found) {
        printf("❌ Tarefa não encontrada com o ID %d.\n", id);
    }
}
