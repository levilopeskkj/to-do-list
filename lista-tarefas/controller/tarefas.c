#include "../headers/controler_header/tarefas.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAREFAS 100
#define MAX_DESCRIPTION 256


void str_to_lower(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower((unsigned char) str[i]);
}


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
                    printf("Status: %s\n", tasks[i].concluida ? "✅ Concluída" : "⏳ Pendente");
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

void listar_tarefas(const Tarefa* tasks, int task_count) {
    if (task_count == 0) {
        printf("Nenhuma tarefa encontrada.\n");
        return;
    }

    printf("\n📋 Lista de Tarefas:\n");
    printf("%-6s %-6s %-10s %-50s\n", "ID", "Status", "Prioridade", "Descrição");
    printf("%-6s %-6s %-10s %-50s\n", "==", "======", "========", "==========");

    for (int i = 0; i < task_count; i++) {
        printf("%-6d ", tasks[i].id);
        printf("%-6s ", tasks[i].concluida ? "✅" : "⌛");
        printf("%-10d ", tasks[i].prioridade);
        printf("%-50s\n", tasks[i].descricao);
    }
    printf("\n");
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
        printf("❌ Nenhuma tarefa disponível para remover.\n");
        return;
    }

    int opcao_busca;
    printf("\n🗑️ Como você gostaria de encontrar a tarefa para remover?\n");
    printf("1. Por ID\n");
    printf("2. Por descrição\n");
    printf("3. Por prioridade\n");
    printf("4. Por status de conclusão\n");
    printf("Digite sua escolha (1-4): ");
    scanf("%d", &opcao_busca);

    int found_search = 0;
    Tarefa found_tasks[MAX_TAREFAS]; // Array temporário para tarefas encontradas
    int found_tasks_count = 0;

    printf("\n🔍 RESULTADOS DA BUSCA PARA REMOÇÃO:\n");
    printf("==========================================\n");

    switch (opcao_busca) {
        case 1: { // Busca por ID
            int id_busca;
            printf("🔍 Digite o ID da tarefa: ");
            scanf("%d", &id_busca);
            for (int i = 0; i < *task_count; i++) {
                if (tasks[i].id == id_busca) {
                    found_search = 1;
                    found_tasks[found_tasks_count++] = tasks[i];
                    printf("ID: %d | Status: %s | Prioridade: %d | Descrição: %s\n", 
                           tasks[i].id, tasks[i].concluida ? "✅" : "⏳", tasks[i].prioridade, tasks[i].descricao);
                }
            }
            break;
        }
        case 2: { // Busca por descrição
            char keyword[MAX_DESCRIPTION];
            printf("🔍 Digite uma palavra-chave na descrição: ");
            scanf("%*c"); 
            fgets(keyword, sizeof(keyword), stdin);
            keyword[strcspn(keyword, "\n")] = '\0';
            char keyword_lower[MAX_DESCRIPTION];
            strcpy(keyword_lower, keyword);
            str_to_lower(keyword_lower);
            for (int i = 0; i < *task_count; i++) {
                char descricao_lower[MAX_DESCRIPTION];
                strcpy(descricao_lower, tasks[i].descricao);
                str_to_lower(descricao_lower);
                if (strstr(descricao_lower, keyword_lower) != NULL) {
                    found_search = 1;
                    found_tasks[found_tasks_count++] = tasks[i];
                    printf("ID: %d | Status: %s | Prioridade: %d | Descrição: %s\n", 
                           tasks[i].id, tasks[i].concluida ? "✅" : "⏳", tasks[i].prioridade, tasks[i].descricao);
                }
            }
            break;
        }
        case 3: { // Busca por prioridade
            int prioridade_busca;
            printf("🔍 Digite a prioridade (1-3): ");
            scanf("%d", &prioridade_busca);
            for (int i = 0; i < *task_count; i++) {
                if (tasks[i].prioridade == prioridade_busca) {
                    found_search = 1;
                    found_tasks[found_tasks_count++] = tasks[i];
                    printf("ID: %d | Status: %s | Prioridade: %d | Descrição: %s\n", 
                           tasks[i].id, tasks[i].concluida ? "✅" : "⏳", tasks[i].prioridade, tasks[i].descricao);
                }
            }
            break;
        }
        case 4: { // Busca por status
            int status_opcao;
            printf("🔍 Selecione o status:\n1. Tarefas pendentes\n2. Tarefas concluídas\nDigite sua escolha (1-2): ");
            scanf("%d", &status_opcao);
            bool status_busca = (status_opcao == 1) ? false : true;
            for (int i = 0; i < *task_count; i++) {
                if (tasks[i].concluida == status_busca) {
                    found_search = 1;
                    found_tasks[found_tasks_count++] = tasks[i];
                    printf("ID: %d | Status: %s | Prioridade: %d | Descrição: %s\n", 
                           tasks[i].id, tasks[i].concluida ? "✅" : "⏳", tasks[i].prioridade, tasks[i].descricao);
                }
            }
            break;
        }
        default:
            printf("❌ Opção de busca inválida!\n");
            return;
    }

    if (!found_search) {
        printf("❌ Nenhuma tarefa encontrada com os critérios especificados para remoção.\n");
        printf("==========================================\n");
        return;
    }
    printf("==========================================\n");

    int id_remover;
    printf("\n🗑️ Digite o ID da tarefa que deseja remover da lista acima: ");
    scanf("%d", &id_remover);

    int found_to_remove = 0;
    int index_to_remove = -1;

    // Encontrar a tarefa pelo ID na lista principal de tarefas
    for (int i = 0; i < *task_count; i++) {
        if (tasks[i].id == id_remover) {
            // Verificar se o ID está na lista de tarefas encontradas (para evitar remover algo não listado)
            bool present_in_found_list = false;
            for(int j = 0; j < found_tasks_count; j++){
                if(found_tasks[j].id == id_remover){
                    present_in_found_list = true;
                    break;
                }
            }
            if(present_in_found_list){
                found_to_remove = 1;
                index_to_remove = i;
                break;
            }
        }
    }

    if (!found_to_remove) {
        printf("❌ Tarefa com ID %d não encontrada na lista de busca ou inválida para remoção.\n", id_remover);
        return;
    }

    // Confirmar remoção
    printf("\n⚠️ Tem certeza que deseja remover a seguinte tarefa?\n");
    printf("ID: %d\n", tasks[index_to_remove].id);
    printf("Status: %s\n", tasks[index_to_remove].concluida ? "✅ Concluída" : "⏳ Pendente");
    printf("Descrição: %s\n", tasks[index_to_remove].descricao);
    printf("Prioridade: %d\n", tasks[index_to_remove].prioridade);
    printf("\nDigite 's' para confirmar ou 'n' para cancelar: ");
    
    char resposta;
    scanf(" %c", &resposta);
    
    if (tolower(resposta) != 's') {
        printf("❌ Remoção cancelada.\n");
        return;
    }

    int id_of_removed_task = tasks[index_to_remove].id; // Store the ID of the task being removed

    // Remover a tarefa (shift à esquerda) e reajustar IDs
    for (int i = index_to_remove; i < *task_count - 1; i++) {
        tasks[i] = tasks[i + 1]; // Shift data
        tasks[i].id = id_of_removed_task + (i - index_to_remove); // Re-calculate ID
    }
    (*task_count)--;
    printf("✅ Tarefa removida com sucesso!\n");

    // Confirmar antes de voltar ao menu
    printf("\nDeseja voltar ao menu principal? (s/n): ");
    char resposta_menu;
    scanf(" %c", &resposta_menu);
    if (tolower(resposta_menu) != 's') {
        printf("\nRetornando ao menu de remoção...\n");
        remover_tarefa(tasks, task_count); // Chama recursivamente para permitir outra remoção
    }
}
