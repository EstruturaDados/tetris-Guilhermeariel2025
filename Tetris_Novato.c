#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_FILA 5  // Definindo o tamanho fixo da fila de peças

// Definindo a struct para representar uma peça
typedef struct {
    char nome;  // Tipo da peça ('I', 'O', 'T', 'L')
    int id;     // ID único da peça, gerado automaticamente
} Peca;

// Fila circular
Peca fila[TAMANHO_FILA];  // A fila de peças com capacidade fixa
int frente = 0;           // Índice do primeiro elemento na fila
int tras = 0;             // Índice do último elemento na fila
int tamanho = 0;          // Número atual de elementos na fila

// Função para gerar uma nova peça com ID automático
Peca gerarPeca(int id) {
    Peca peca;
    char tipos[] = {'I', 'O', 'T', 'L'};  // Tipos possíveis de peças
    peca.nome = tipos[id % 4];  // Alterna entre os tipos
    peca.id = id;               // Atribui o ID único
    return peca;
}

// Função para exibir o estado atual da fila
void exibirFila() {
    printf("Fila de pecas\n");
    if (tamanho == 0) {
        printf("A fila esta vazia\n");
    } else {
        // Exibindo os elementos da fila
        for (int i = 0; i < tamanho; i++) {
            int indice = (frente + i) % TAMANHO_FILA;  // Calculando a posição circular
            printf("[%c %d] ", fila[indice].nome, fila[indice].id);
        }
        printf("\n");
    }
}

// Função para inserir uma peça na fila (enqueue)
void inserirPeca(Peca peca) {
    if (tamanho < TAMANHO_FILA) {
        fila[tras] = peca;  // Coloca a peça no final da fila
        tras = (tras + 1) % TAMANHO_FILA;  // Move o índice 'tras' circularmente
        tamanho++;  // Incrementa o tamanho da fila
        printf("Peça %c %d inserida na fila\n", peca.nome, peca.id);
    } else {
        printf("A fila esta cheia, nao e possivel inserir uma nova peça\n");
    }
}

// Função para jogar (remover) uma peça da fila (dequeue)
void jogarPeca() {
    if (tamanho > 0) {
        printf("Peça %c %d removida da fila\n", fila[frente].nome, fila[frente].id);
        frente = (frente + 1) % TAMANHO_FILA;  // Move o índice 'frente' circularmente
        tamanho--;  // Decrementa o tamanho da fila
    } else {
        printf("A fila esta vazia, nao e possivel remover uma peça\n");
    }
}

// Função para exibir o menu e obter a escolha do usuário
int menu() {
    int opcao;
    printf("\nTabela: Visualizacao a fila de pecas.\n");
    printf("Curadoria de TI.\n");
    printf("Opcoes de acao:\n");
    printf("Codigo Ação\n");
    printf("1 Jogar peça (dequeue)\n");
    printf("2 Inserir nova peça (enqueue)\n");
    printf("0 Sair\n");
    printf("Escolha uma acao: ");
    scanf("%d", &opcao);
    return opcao;
}

int main() {
    int idPeca = 0;  // ID inicial da peça
    Peca peca;

    // Inicializando a fila com 5 peças
    printf("Inicializando a fila com 5 pecas...\n");
    for (int i = 0; i < TAMANHO_FILA; i++) {
        peca = gerarPeca(idPeca);
        inserirPeca(peca);
        idPeca++;
    }

    // Exibe a fila inicial
    exibirFila();

    int opcao;
    while (1) {
        // Exibe o menu e recebe a opção do usuário
        opcao = menu();

        switch (opcao) {
            case 1:
                // Jogar peça (dequeue)
                jogarPeca();
                exibirFila();
                break;
            case 2:
                // Inserir nova peça (enqueue)
                peca = gerarPeca(idPeca);  // Gera uma nova peça
                idPeca++;
                inserirPeca(peca);
                exibirFila();
                break;
            case 0:
                // Sair do programa
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }

    return 0;
}
