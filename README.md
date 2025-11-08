# Sistema de Fila de Operações Bancárias

## Integrantes
- Luiz Eduardo de Sales Carneiro
- Yuri Estrela Leal

## Estrutura de Dados Implementada
**Lista Encadeada com Inserção Ordenada por Prioridade**

### Cada operação tem:

* **ID**
* **Tipo de operação** (consulta, transferência, etc.)
* **Prioridade** (quanto maior o número, maior a urgência)

### Aplicação Prática
Este projeto implementa um sistema de gerenciamento de operações financeiras em um banco, onde as transações são organizadas em uma fila de prioridades. O sistema permite:

- **Transferências** (Imediatas - Alta Prioridade / Agendadas - Média Prioridade)
- **Consultas** de saldo (Baixa Prioridade)
- **Extratos** do mês anterior (Baixíssima Prioridade)

As operações são processadas por ordem de prioridade, garantindo que transações críticas sejam atendidas primeiro.

## Estrutura do Projeto

```bash
fila-transacoes-financeiras/
|--- aplicacao/
|			|--- main.c
|			|--- fila-transacoes.h
|			|--- fila-transacoes.c
|--- README.md
```

## Compilação e Execução

### 1. Compilar o projeto

No terminal (Linux ou WSL):

```bash
gcc -o main main.c
```

### 2. Executar

```bash
./main
```

## Exemplo de Execução

```bash
-----Operações Financeiras-----
1. Transferências
2. Consulta
3. Extrato do mês anterior
4. Imprimir fila
5. Processar Fila
6. Sair
>1
```

O usuário escolhe **"1. Transferências"**.

---

```bash
-----Transferências disponíveis-----
1. Transferência imediata
2. Transferência agendada
>1
```

O usuário escolhe **"1. Transferência imediata"**, que é adicionada à fila com **alta prioridade**.

---

```bash
-----Operações Financeiras-----
1. Transferências
2. Consulta
3. Extrato do mês anterior
4. Imprimir fila
5. Processar Fila
6. Sair
>1
```

O menu principal é exibido novamente, e o usuário faz **outra operação de transferência**.

---

```bash
-----Transferências disponíveis-----
1. Transferência imediata
2. Transferência agendada
>2
```

O usuário escolhe **"2. Transferência agendada"**, que tem **prioridade média**.

---

```bash
-----Operações Financeiras-----
1. Transferências
2. Consulta
3. Extrato do mês anterior
4. Imprimir fila
5. Processar Fila
6. Sair
>2
```

Agora o usuário realiza uma **consulta**, operação de **baixa prioridade**.

---

```bash
-----Operações Financeiras-----
1. Transferências
2. Consulta
3. Extrato do mês anterior
4. Imprimir fila
5. Processar Fila
6. Sair
>3
```

O usuário solicita o **extrato do mês anterior**, uma operação de **prioridade muito baixa** (não urgente).

---

```bash
-----Operações Financeiras-----
1. Transferências
2. Consulta
3. Extrato do mês anterior
4. Imprimir fila
5. Processar Fila
6. Sair
>4
```

Ao selecionar **“Imprimir fila”**, o sistema lista todas as operações pendentes.

---

```bash
--------Operações--------

ID: 1 | Operação: Transferência imediata | Prioridade: 4 |
ID: 2 | Operação: Transferência agendada | Prioridade: 3 |
ID: 3 | Operação: Consulta | Prioridade: 2 |
ID: 4 | Operação: Extrato do mês anterior | Prioridade: 1 |

Pressione <ENTER> para voltar ao menu de operações.
```

A fila é impressa mostrando todas as operações pendentes, ordenadas da **mais prioritária para a menos prioritária**.

> Quanto maior o número da prioridade, maior a urgência da operação.

---

```bash
-----Operações Financeiras-----
1. Transferências
2. Consulta
3. Extrato do mês anterior
4. Imprimir fila
5. Processar Fila
6. Sair
>5
```

O usuário escolhe **“Processar Fila”**, para executar a operação mais prioritária.

---

```bash
--------Operação a ser processada--------
ID: 1 | Operação: Transferência imediata | Prioridade: 4 |

Pressione <ENTER> para voltar ao menu de operações.
```

O sistema processa e **remove da fila** a operação de maior prioridade (no caso, a transferência imediata).

---

```bash
-----Operações Financeiras-----
1. Transferências
2. Consulta
3. Extrato do mês anterior
4. Imprimir fila
5. Processar Fila
6. Sair
>4
```

O usuário imprime novamente a fila para confirmar que a primeira operação foi removida.

---

```bash
--------Operações--------

ID: 2 | Operação: Transferência agendada | Prioridade: 3 |
ID: 3 | Operação: Consulta | Prioridade: 2 |
ID: 4 | Operação: Extrato do mês anterior | Prioridade: 1 |

Pressione <ENTER> para voltar ao menu de operações.
```

O sistema confirma que a **transferência imediata foi processada** e as demais continuam na fila, respeitando a ordem de prioridade.