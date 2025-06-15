#include "../headers/controler_header/remover_tarefa.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void remover_tarefa(Tarefa* tasks, int* task_count) {
    if (*task_count == 0) {
        printf("❌ Nenhuma tarefa disponível para remover.\n");
        return;
    }

    int id;
    printf("🔍 Digite o ID da tarefa que deseja remover: ");
    scanf("%d", &id);

    int found = 0;
    int index = -1;

    // Encontrar a tarefa pelo ID
    for (int i = 0; i < *task_count; i++) {
        if (tasks[i].id == id) {
            found = 1;
            index = i;
            break;
        }
    }

    if (!found) {
        printf("❌ Nenhuma tarefa encontrada com o ID %d.\n", id);
        return;
    }

    // Mostrar detalhes da tarefa a ser removida
    printf("\n📝 TAREFA SELECIONADA PARA REMOÇÃO\n");
    printf("==========================================\n");
    printf("ID: %d\n", tasks[index].id);
    printf("Status: %s\n", tasks[index].concluida ? "✅ Concluída" : "⏳ Pendente");
    printf("Descrição: %s\n", tasks[index].descricao);
    printf("Prioridade: %d\n", tasks[index].prioridade);
    printf("==========================================\n");

    // Confirmar remoção
    char confirmacao;
    printf("\n⚠️  Tem certeza que deseja remover esta tarefa? (s/n): ");
    scanf(" %c", &confirmacao);

    if (tolower(confirmacao) == 's') {
        // Remover a tarefa deslocando os elementos
        for (int i = index; i < *task_count - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        (*task_count)--;
        printf("✅ Tarefa removida com sucesso!\n");
    } else {
        printf("❌ Operação de remoção cancelada.\n");
    }
}