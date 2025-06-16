#ifndef UTILS_H
#define UTILS_H

#include "tarefa.h"
#include <ctype.h>

// Função auxiliar para transformar string em lowercase
void str_to_lower(char* str);

// Função auxiliar para mostrar detalhes de uma tarefa
void mostrar_detalhes_tarefa(const Tarefa* task);

// Função auxiliar para busca case-insensitive
bool busca_descricao_insensitive(const char* texto, const char* busca);

// Função auxiliar para validar prioridade
bool validar_prioridade(int prioridade);

// Função auxiliar para validar descrição
bool validar_descricao(const char* descricao);

// Função auxiliar para mostrar preview das alterações
void mostrar_preview(Tarefa* antes, Tarefa* depois);

#endif // UTILS_H
