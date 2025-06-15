#include "../headers/controler_header/buscar_tarefa.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void str_to_lower(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower((unsigned char) str[i]);
}

void buscar_tarefa(const Tarefa* tasks, int task_count) {
    if (task_count == 0) {
        printf("Nenhuma tarefa disponível para buscar.\n");
        return;
    }

    int opcao;
    printf("\n🔍 Como você gostaria de buscar a tarefa?\n");
    printf("1. Por ID\n");
    printf("2. Por descrição\n");
    printf("3. Por prioridade\n");
    printf("4. Por status de conclusão\n");
    printf("Digite sua escolha (1-4): ");
    scanf("%d", &opcao);

    int found = 0;
    printf("\n🔍 RESULTADOS DA BUSCA:\n");
    printf("==========================================\n");

    switch (opcao) {
        case 1: { // Busca por ID
            int id;
            printf("🔍 Digite o ID da tarefa: ");
            scanf("%d", &id);
            
            for (int i = 0; i < task_count; i++) {
                if (tasks[i].id == id) {
                    found = 1;
                    printf("ID: %d\n", tasks[i].id);
                    printf("Status: %s\n", tasks[i].concluida ? "✅ Concluída" : "⏳ Pendente");
                    printf("Descrição: %s\n", tasks[i].descricao);
                    printf("Prioridade: %d\n", tasks[i].prioridade);
                    printf("------------------------------------------\n");
                }
            }
            break;
        }
        case 2: { // Busca por descrição
            char keyword[MAX_DESCRIPTION];
            printf("🔍 Digite uma palavra-chave na descrição: ");
            scanf("%*c"); // Limpa o buffer do scanf anterior
            fgets(keyword, sizeof(keyword), stdin);
            keyword[strcspn(keyword, "\n")] = '\0';

            char keyword_lower[MAX_DESCRIPTION];
            strcpy(keyword_lower, keyword);
            str_to_lower(keyword_lower);

            for (int i = 0; i < task_count; i++) {
                char descricao_lower[MAX_DESCRIPTION];
                strcpy(descricao_lower, tasks[i].descricao);
                str_to_lower(descricao_lower);

                if (strstr(descricao_lower, keyword_lower) != NULL) {
                    found = 1;
                    printf("ID: %d\n", tasks[i].id);
                    printf("Status: %s\n", tasks[i].concluida ? "✅ Concluída" : "⏳ Pendente");
                    printf("Descrição: %s\n", tasks[i].descricao);
                    printf("Prioridade: %d\n", tasks[i].prioridade);
                    printf("------------------------------------------\n");
                }
            }
            break;
        }
        case 3: { // Busca por prioridade
            int prioridade;
            printf("🔍 Digite a prioridade (1-3): ");
            scanf("%d", &prioridade);

            for (int i = 0; i < task_count; i++) {
                if (tasks[i].prioridade == prioridade) {
                    found = 1;
                    printf("ID: %d\n", tasks[i].id);
                    printf("Status: %s\n", tasks[i].concluida ? "✅ Concluída" : "⏳ Pendente");
                    printf("Descrição: %s\n", tasks[i].descricao);
                    printf("Prioridade: %d\n", tasks[i].prioridade);
                    printf("------------------------------------------\n");
                }
            }
            break;
        }
        case 4: { // Busca por status
            printf("🔍 Selecione o status:\n");
            printf("1. Tarefas pendentes\n");
            printf("2. Tarefas concluídas\n");
            printf("Digite sua escolha (1-2): ");
            scanf("%d", &opcao);

            bool status = (opcao == 1) ? false : true;

            for (int i = 0; i < task_count; i++) {
                if (tasks[i].concluida == status) {
                    found = 1;
                    printf("ID: %d\n", tasks[i].id);
                    printf("Status: %s\n", tasks[i].concluida ? "✅ Concluída" : "⏳ headers/controler_header/adicionar.h headers/controler_header/alterar_tarefa.h headers/controler_header/buscar_tarefa.h headers/controler_header/concluir_tarefa.h headers/controler_header/listar_tarefas.h headers/controler_header/mostrar_estatistica.h headers/controler_header/remover_tarefa.h headers/controler_header/tarefa.hPendente");
                    printf("Descrição: %s\n", tasks[i].descricao);
                    printf("Prioridade: %d\n", tasks[i].prioridade);
                    printf("------------------------------------------\n");
                }
            }
            break;
        }
        default:
            printf("❌ Opção inválida!\n");
            return;
    }

    if (!found) {
        printf("❌ Nenhuma tarefa encontrada com os critérios especificados.\n");
    }

    printf("==========================================\n");

    // Confirmação antes de voltar ao menu
    printf("\nDeseja voltar ao menu principal? (s/n): ");
    char resposta;
    scanf(" %c", &resposta);
    if (tolower(resposta) != 's') {
        printf("\nRetornando ao menu de busca...\n");
        buscar_tarefa(tasks, task_count);
  }
}
