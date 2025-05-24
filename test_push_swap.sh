#!/bin/bash

# Verificar se foi passado um argumento para o número de elementos
if [ $# -eq 0 ]; then
    NUM_COUNT=100  # Valor padrão: 100 números
else
    NUM_COUNT=$1   # Usar o argumento fornecido
fi

# Validar se NUM_COUNT é um número positivo
if ! [[ "$NUM_COUNT" =~ ^[0-9]+$ ]] || [ "$NUM_COUNT" -le 0 ]; then
    echo "Erro: Por favor, forneça um número positivo de elementos."
    exit 1
fi

# Gerar NUM_COUNT números aleatórios únicos (entre -1000 e 1000, por exemplo)
NUMBERS=()
while [ ${#NUMBERS[@]} -lt "$NUM_COUNT" ]; do
    # Gerar número aleatório entre -1000 e 1000
    NUM=$((RANDOM % 2001 - 1000))
    # Verificar se o número já existe
    if [[ ! " ${NUMBERS[@]} " =~ " ${NUM} " ]]; then
        NUMBERS+=("$NUM")
    fi
done

# Converter array em string para usar como argumento
ARG=$(IFS=" "; echo "${NUMBERS[*]}")

# Executar push_swap e contar operações
OUTPUT=$(./push_swap $ARG)
OP_COUNT=$(echo "$OUTPUT" | wc -l)

# Definir limite de operações com base no número de elementos
# Para 100 números, o limite é 700; para outros, ajustar proporcionalmente
if [ "$NUM_COUNT" -le 5 ]; then
    LIMIT=40  # Exemplo: limite para poucos números
elif [ "$NUM_COUNT" -le 100 ]; then
    LIMIT=700 # Limite para 100 números
else
    LIMIT=$((NUM_COUNT * 12)) # Ajuste proporcional para mais números
fi

# Verificar se o número de operações é menor que o limite
if [ "$OP_COUNT" -lt "$LIMIT" ]; then
    echo "✅ Sucesso: $OP_COUNT operações (menos que $LIMIT)"
else
    echo "❌ Falha: $OP_COUNT operações (excede $LIMIT)"
fi

# Verificar se a ordenação está correta com checker_linux
CHECK=$(echo "$OUTPUT" | ./checker_linux $ARG)
if [ "$CHECK" = "OK" ]; then
    echo "✅ Ordenação correta (checker: OK)"
else
    echo "❌ Ordenação incorreta (checker: KO)"
fi

# Opcional: exibir os números gerados (para depuração)
echo "Números gerados ($NUM_COUNT): $ARG"
