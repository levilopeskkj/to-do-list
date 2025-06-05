#include "../headers/controler_header/alterar_tarefa.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void alterar_tarefa(Tarefa* tasks, int task_count) {
    if (task_count == 0) {
        printf("❌ Nenhuma tarefa disponível para alterar.\n");
        return;
    }

    int id;
    printf("🔍 Digite o ID da tarefa que deseja alterar: ");
    scanf("%d", &id);

    int found = 0;
    int index = -1;

    // Encontrar a tarefa pelo ID
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].id == id) {
            found = 1;
            index = i;
            break;
        }
    }

    if (!found) {
        printf("❌ Tarefa não encontrada com ID %d.\n", id);
        return;
    }

    // Mostrar a tarefa atual
    printf("\n📝 Tarefa atual:\n");
    printf("ID: %d\n", tasks[index].id);
    printf("Status: %s\n", tasks[index].concluida ? "✅ Concluída" : "⏳ Pendente");
    printf("Descrição: %s\n", tasks[index].descricao);
    printf("Prioridade: %d\n", tasks[index].prioridade);
    printf("\n❓ Quais atributos você deseja alterar?\n");
    printf("1. Descrição\n");
    printf("2. Prioridade\n");
    printf("3. Status\n");
    printf("4. Todos os atributos\n");
    printf("Digite sua escolha (1-4): ");

    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: { // Alterar descrição
            printf("📝 Digite a nova descrição: ");
            scanf("%*c"); // Limpa o buffer do scanf anterior
            fgets(tasks[index].descricao, MAX_DESCRIPTION, stdin);
            tasks[index].descricao[strcspn(tasks[index].descricao, "\n")] = '\0';
            break;
        }
        case 2: { // Alterar prioridade
            printf("🎯 Digite a nova prioridade (1-3): ");
            scanf("%d", &tasks[index].prioridade);
            while (tasks[index].prioridade < 1 || tasks[index].prioridade > 3) {
                printf("❌ Prioridade inválida! Selecione um número entre 1 e 3: ");
                scanf("%d", &tasks[index].prioridade);
            }
            break;
        }
        case 3: { // Alterar status
            printf("🎯 Selecione o novo status:\n");
            printf("1. Pendente\n");
            printf("2. Concluída\n");
            printf("Digite sua escolha (1-2): ");
            scanf("%d", &opcao);
            tasks[index].concluida = (opcao == 1) ? false : true;
            break;
        }
        case 4: { // Alterar todos os atributos
            printf("📝 Digite a nova descrição: ");
            scanf("%*c"); // Limpa o buffer do scanf anterior
            fgets(tasks[index].descricao, MAX_DESCRIPTION, stdin);
            tasks[index].descricao[strcspn(tasks[index].descricao, "\n")] = '\0';

            printf("🎯 Digite a nova prioridade (1-3): ");
            scanf("%d", &tasks[index].prioridade);
            while (tasks[index].prioridade < 1 || tasks[index].prioridade > 3) {
                printf("❌ Prioridade inválida! Selecione um número entre 1 e 3: ");
                scanf("%d", &tasks[index].prioridade);
            }

            printf("🎯 Selecione o novo status:\n");
            printf("1. Pendente\n");
            printf("2. Concluída\n");
            printf("Digite sua escolha (1-2): ");
            scanf("%d", &opcao);
            tasks[index].concluida = (opcao == 1) ? false : true;
            break;
        }
        default:
            printf("❌ Opção inválida!\n");
            return;
    }

    // Confirmar alterações
    printf("\n✅ Alterações realizadas com sucesso!\n");
    printf("\n📝 Tarefa atualizada:\n");
    printf("ID: %d\n", tasks[index].id);
    printf("Status: %s\n", tasks[index].concluida ? "✅ Concluída" : "⏳ Pendente");
    printf("Descrição: %s\n", tasks[index].descricao);
    printf("Prioridade: %d\n", tasks[index].prioridade);

    // Confirmar antes de voltar ao menu
    printf("\nDeseja voltar ao menu principal? (s/n): ");
    char resposta;
    scanf(" %c", &resposta);
    if (tolower(resposta) != 's') {
        printf("\nRetornando ao menu de alteração...\n");
        alterar_tarefa(tasks, task_count);
    }
}