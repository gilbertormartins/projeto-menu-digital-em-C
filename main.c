#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/* ---------- Variáveis Globais ---------- */
char nomeCliente[50];// Declarada fora de todas as funções: visível por todo o arquivo
int opcaoConsumo; // Variável para receber a escolha
float valorParcial;
float totalGeral;

/* ---------- Protótipos ---------- */
void boasVindas(void);
void identificarCliente(void);
void consumoLocalViagem(void);
int menuPrincipal(void);
int menuSecundario(void);

int menuOpcoesCafes(void);
int menuCafeTrad(void);
int menuCafeEspeciais(void);
int menuDoces(void);
int menuSalgados(void);

int tamanhoCafe(void);
int menuQuantidade(void);

void pedidoEnviado(void);
int formaDePagamento(void);
int menuCancelar(void);

float calcularTotal(float totalGeral, float valorParcial);

int carrinho(void);
int finalizarPedido(void);
int imprimirRecibo(void);

/* ---------- Main ---------- */
int main(void) {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int opcaoMenuEscolhido;

    // Laço contínuo do totem: nunca encerra, reinicia para cada cliente
    while (1) {
        boasVindas();
        identificarCliente();
        consumoLocalViagem();
        // Ciclo de compras do cliente atual
        do {
            opcaoMenuEscolhido = menuPrincipal();
        } while (opcaoMenuEscolhido != 4 && opcaoMenuEscolhido != 5 &&
                 opcaoMenuEscolhido != 6 && opcaoMenuEscolhido != 7 && 
                 opcaoMenuEscolhido != 8);
        // Quando o cliente escolhe 4 (Finalizou) ou 5 (Cancelou), + 7 e 8
            // para 7 e 8 Ao sair do do...while, o loop reinicia e volta para boasVindas()!
        // o fluxo atinge o fim desta volta do while(1) e recomeça
        // automaticamente lá em cima na chamada de boasVindas()!
    }
    return 0;
}

/* ---------- Funções ---------- */

int menuPrincipal(void) {
    int escolheMenu;
    int leituraValida;
    int statusFinalizacao;
    int statusSubmenu;

    do {
        printf("\n === MENU ===\n"
               "1 - Cafes\n"
               "2 - Doces D'Aurora\n"
               "3 - Salgados Premium\n"
               "4 - Ver Carrinho\n"
               "5 - Finalizar pedido\n"
               "6 - Cancelar\n"
               "\nEscolha uma opção do menu: ");

        leituraValida = scanf("%d", &escolheMenu);

        if (leituraValida != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            escolheMenu = 0;
            continue;
        }

        switch (escolheMenu) {
            case 1:
                printf("\n-> Voce escolheu a opção 1 - Cafes.\n");
                statusSubmenu = menuOpcoesCafes();
                if (statusSubmenu == 4 || statusSubmenu == 5 || statusSubmenu == 7 || statusSubmenu == 8) {
                    return statusSubmenu;
                }
                escolheMenu = 0;
                break;
            case 2:
                printf("\n-> Voce escolheu a opção 2 - Doces D'Aurora.\n");
                statusSubmenu = menuDoces();
                if (statusSubmenu == 4 || statusSubmenu == 5 || statusSubmenu == 7 || statusSubmenu == 8) {
                    return statusSubmenu;
                }
                escolheMenu = 0;
                break;
            case 3:
                printf("\n-> Voce escolheu a opção 3 - Salgados Premium.\n");
                statusSubmenu = menuSalgados();
                if (statusSubmenu == 4 || statusSubmenu == 5 || statusSubmenu == 7 || statusSubmenu == 8) {
                    return statusSubmenu;
                }
                escolheMenu = 0;
                break;
            case 4:
                printf("\n-> Voce escolheu a opção 4 - Ver Carrinho.\n\n");
                carrinho();
                return 2;
                break;
            case 5:                
                printf("\n-> Voce escolheu a opção 5 - Finalizar pedido.\n");
                statusFinalizacao = finalizarPedido();
                if (statusFinalizacao == 1) {
                    return 5;
                }
                escolheMenu = 0;
                break;
            case 6:
                printf("\n-> Voce escolheu a opção 5 - Cancelar.\n");
                if (menuCancelar() == 1) {
                    return 6;
                }
                escolheMenu = 0;
                break;
            default:
                printf("\nAVISO: Opção inexistente. Por favor, escolha uma opção do menu.\n\n");
                escolheMenu = 0;
                break;
        }
    } while (escolheMenu != 5 && escolheMenu != 6);

    return escolheMenu;
}

void boasVindas(void) {
	printf(
	    "\n === CAFETERIA AURORA ===\n"
	    "Seja muito bem-vindo(a)!\n"
	    "Preparamos cafés selecionados para tornar seu dia ainda mais agradável.\n"
	    "Sinta-se em casa!\n\n"); 
}

void identificarCliente(void) {
    printf("Informe seu nome para que possamos chamá-lo(a) quando seu pedido estiver pronto: ");
    scanf(" %49[^\n]", nomeCliente);
}

void consumoLocalViagem(void) {
    int leituraValida;

    do {
    // Usa a variável global diretamente no printf
    printf("\n%s, deseja levar ou consumir no local?\n", nomeCliente);
    printf(
        "\n1 - Consumir no local\n"
        "2 - Para viagem\n"
        "Opção: ");

            // Verifica se conseguiu ler 1 número inteiro
        leituraValida = scanf("%d", &opcaoConsumo); // Grava direto na global

        // Se o usuário digitou letras ou caracteres inválidos
        if (leituraValida != 1) {
            int c;
            // Limpa todo o buffer de entrada até o Enter (\n)
            while ((c = getchar()) != '\n' && c != EOF);

            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            opcaoConsumo = 0; // Garante que a condição do while repita o loop
            continue;
        }
        switch (opcaoConsumo) {
            case 1:
                printf("\n-> Voce escolheu a opção 1 - Consumir no local.\n");
                break;
            case 2:
                printf("\n-> Voce escolheu a opção 2 - Para viagem.\n");
                break;
            default:
                printf("\nAVISO: Opção inexistente. Por favor, escolha uma opção do menu.\n\n");
                break;
        }
    } while (opcaoConsumo < 1 || opcaoConsumo > 2);
    // Não precisa de "return opcaoConsumo;" aqui!
}

int menuSecundario(void) {
    int escolheMenuSecundario;
    int leituraValida;
 
    printf("Produto adicionado com sucesso!\n");
    printf("Total atual: R$ %.2f\n\n", totalGeral);

    do {
        printf(
        "1 - Continuar Comprando\n"
        "2 - Ver carrinho\n"
        "3 - Finalizar pedido\n"
        "4 - Cancelar\n"
        "\nEscolha uma opção do menu: ");
                
        // Verifica se conseguiu ler 1 número inteiro
        leituraValida = scanf("%d", &escolheMenuSecundario);

        // Se o usuário digitou letras ou caracteres inválidos
        if (leituraValida != 1) {
            int c;
            // Limpa todo o buffer de entrada até o Enter (\n)
            while ((c = getchar()) != '\n' && c != EOF);

            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            escolheMenuSecundario = 0; // Garante que a condição do while repita o loop
            continue;
        }

        switch (escolheMenuSecundario) {
            case 1:
                printf("\n-> Voce escolheu a opção 1 - Continuar Comprando.\n");
                return 1; // Encerra o menuSecundario e volta para o menu anterior
                break;
            case 2:
                printf("\n-> Voce escolheu a opção 2 - Ver carrinho.\n\n");
                carrinho();
                return 2;
                break;
            case 3:
                printf("\n-> Voce escolheu a opção 3 - Finalizar pedido.\n");
                if (finalizarPedido() == 1) {
                    return 4; // Repassa 4 para avisar que finalizou com sucesso!
                }
                return 3;
            case 4:
                printf("\n-> Voce escolheu a opção 4 - Cancelar.\n");
                menuCancelar();
                return 4;
                break;
            default:
                printf("\nAVISO: Opção inexistente. Por favor, escolha uma opção do menu.\n\n");
                break;
        }
    } while (escolheMenuSecundario < 1 || escolheMenuSecundario > 4);
    return escolheMenuSecundario;
}

int menuOpcoesCafes(void) {
    int escolhaDoCafe;
    int leituraValida;
    int statusSubmenu; // Gaveta para receber o retorno dos submenus

    do {
        printf("\n === CAFÉS ===\n"
               "1 - Cafés Tradicionais\n"
               "2 - Cafés Especiais\n"
               "3 - Voltar ao menu principal\n"
               "4 - Finalizar pedido\n"
               "5 - Cancelar\n"
               "\nEscolha uma opção do menu: ");
        
        leituraValida = scanf("%d", &escolhaDoCafe);

        if (leituraValida != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            escolhaDoCafe = 0;
            continue;
        }

        switch (escolhaDoCafe) {
            case 1:
                printf("\n-> 1 - Cafés Tradicionais.\n");
                statusSubmenu = menuCafeTrad();
                if (statusSubmenu == 6 || statusSubmenu == 1) {
                    return 3; // Volta ao menuPrincipal normalmente
                }
                if (statusSubmenu == 4 || statusSubmenu == 7 || statusSubmenu == 8) {
                    // Repassa o cancelamento/finalização diretamente para o menuPrincipal
                    return statusSubmenu; 
                }
                break;
            case 2:
                printf("\n-> 2 - Cafés Especiais.\n");
                statusSubmenu = menuCafeEspeciais();
                if (statusSubmenu == 6 || statusSubmenu == 1) {
                    return 3;
                }
                if (statusSubmenu == 4 || statusSubmenu == 7 || statusSubmenu == 8) {
                    return statusSubmenu;
                }
                break;
            case 3:
                return 3;
            case 4:
                printf("\n-> 4 - Finalizar pedido.\n");
                if (finalizarPedido() == 1) {
                    return 4; // Avisa o menu principal que finalizou
                }
                break;
            case 5:
                printf("\n-> 5 - Cancelar.\n");
                if (menuCancelar() == 1) {
                    return 5; // Avisa o menu principal para voltar à main
                }
                break;
            default:
                printf("\nAVISO: Opção inexistente. Por favor, escolha uma opção do menu.\n\n");
                break;
        }
    } while (escolhaDoCafe < 1 || escolhaDoCafe > 5);

    return 0;
}

int menuCafeTrad(void) {
    int escolheCafeTrad;
    int leituraValida;
    int escolheQuantidade;
    int opcaoTamanhoCafe;
    int acaoPosCompra; // <-- Declarada uma única vez aqui!

    do {
        printf("\n === CAFÉS TRADICIONAIS ===\n" 
        "1 - Café Espresso\n"
        "2 - Café Coado Especial\n"
        "3 - Café Americano\n"
        "4 - Café com Leite\n"
        "5 - Cappuccino Tradicional\n"
        "6 - Incluir Mais Itens\n"
        "7 - Finalizar Pedido\n"
        "8 - Cancelar Pedido\n"
        "\nEscolha uma opção do menu: ");
        
        // Verifica se conseguiu ler 1 número inteiro
        leituraValida = scanf("%d", &escolheCafeTrad);

        // Se o usuário digitou letras ou caracteres inválidos
        if (leituraValida != 1) {
            int c;
            // Limpa todo o buffer de entrada até o Enter (\n)
            while ((c = getchar()) != '\n' && c != EOF);

            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            escolheCafeTrad = 0; // Garante que a condição do while repita o loop
            continue;
        }

        switch (escolheCafeTrad) {
            case 1:
                printf("\n-> Voce escolheu a opção 1 - Café Espresso.\n"
                        "Pequeno: R$ 6,50\n"
                        "Médio: R$ 8,00\n"
                        "Grande: R$ 9,50\n");

                opcaoTamanhoCafe = tamanhoCafe();
                escolheQuantidade = menuQuantidade();

                // void calcularValor(int opcaoTamanhoCafe, int escolheQuantidade) {
                //float valorProduto;
            
                if (opcaoTamanhoCafe == 1) {
                    valorParcial = escolheQuantidade * 6.50f;
                } else if (opcaoTamanhoCafe == 2) {
                    valorParcial = escolheQuantidade * 8.0f;
                } else {
                    // Como o valor já foi tratado e só chegam 1, 2 ou 3,
                    // se não for 1 nem 2, obrigatoriamente é 3.
                    valorParcial = escolheQuantidade * 9.50f;
                }

                // 1. Atualiza o total acumulado
                totalGeral = calcularTotal(totalGeral, valorParcial);

                // 2. Abre o menu pós-compra capturando a ação escolhida
                acaoPosCompra = menuSecundario();

                // 3. Se escolheu Continuar Comprando (1), sai de menuCafeTrad para voltar ao fluxo
                if (acaoPosCompra == 1) {
                    return 6; // Retorna 6 (código que significa "Incluir Mais Itens / Voltar")
                }
                
                // Se o cliente escolheu finalizar (3) ou cancelar (4), repassa o código para frente
                return acaoPosCompra;
            case 2:
                printf("\n-> Voce escolheu a opção 2 - Café Coado Especial.\n"
                        "Pequeno: R$ 7,00\n"
                        "Médio: R$ 8,50\n"
                        "Grande: R$ 10,50\n");

                opcaoTamanhoCafe = tamanhoCafe();
                escolheQuantidade = menuQuantidade();

                // void calcularValor(int opcaoTamanhoCafe, int escolheQuantidade) {
                //float valorProduto;
            
                if (opcaoTamanhoCafe == 1) {
                    valorParcial = escolheQuantidade * 7.00f;
                } else if (opcaoTamanhoCafe == 2) {
                    valorParcial = escolheQuantidade * 8.5f;
                } else {
                    // Como o valor já foi tratado e só chegam 1, 2 ou 3,
                    // se não for 1 nem 2, obrigatoriamente é 3.
                    valorParcial = escolheQuantidade * 10.50f;
                }

                // 1. Atualiza o total acumulado
                totalGeral = calcularTotal(totalGeral, valorParcial);

                // 2. Abre o menu pós-compra capturando a ação escolhida
                acaoPosCompra = menuSecundario();
                if (acaoPosCompra == 1) {
                    return 6; // Retorna para o menu principal
                }
                return acaoPosCompra;
            case 3:
                printf("\n-> Voce escolheu a opção 3 - Café Americano.\n"
                        "Pequeno: R$ 7,50\n"
                        "Médio: R$ 9,00\n"
                        "Grande: R$ 10,50\n");

                opcaoTamanhoCafe = tamanhoCafe();
                escolheQuantidade = menuQuantidade();

                // void calcularValor(int opcaoTamanhoCafe, int escolheQuantidade) {
                //float valorProduto;
            
                if (opcaoTamanhoCafe == 1) {
                    valorParcial = escolheQuantidade * 7.50f;
                } else if (opcaoTamanhoCafe == 2) {
                    valorParcial = escolheQuantidade * 9.0f;
                } else {
                    // Como o valor já foi tratado e só chegam 1, 2 ou 3,
                    // se não for 1 nem 2, obrigatoriamente é 3.
                    valorParcial = escolheQuantidade * 10.50f;
                }

                // 1. Atualiza o total acumulado
                totalGeral = calcularTotal(totalGeral, valorParcial);

                // 2. Abre o menu pós-compra capturando a ação escolhida
                acaoPosCompra = menuSecundario();
                if (acaoPosCompra == 1) {
                    return 6; // Retorna para o menu principal
                }
                return acaoPosCompra;
            case 4:
                printf("\n-> Voce escolheu a opção 4 - Café com Leite.\n"
                        "Pequeno: R$ 8,50\n"
                        "Médio: R$ 10,50\n"
                        "Grande: R$ 12,50\n");

                opcaoTamanhoCafe = tamanhoCafe();
                escolheQuantidade = menuQuantidade();

                // void calcularValor(int opcaoTamanhoCafe, int escolheQuantidade) {
                //float valorProduto;
            
                if (opcaoTamanhoCafe == 1) {
                    valorParcial = escolheQuantidade * 8.50f;
                } else if (opcaoTamanhoCafe == 2) {
                    valorParcial = escolheQuantidade * 10.5f;
                } else {
                    // Como o valor já foi tratado e só chegam 1, 2 ou 3,
                    // se não for 1 nem 2, obrigatoriamente é 3.
                    valorParcial = escolheQuantidade * 12.50f;
                }

                // 1. Atualiza o total acumulado
                totalGeral = calcularTotal(totalGeral, valorParcial);

                // 2. Abre o menu pós-compra capturando a ação escolhida
                acaoPosCompra = menuSecundario();
                if (acaoPosCompra == 1) {
                    return 6; // Retorna para o menu principal
                }
                return acaoPosCompra;
            case 5:
                printf("\n-> Voce escolheu a opção 5 - Cappuccino Tradicional.\n"
                        "Pequeno: R$ 10,50\n"
                        "Médio: R$ 12,50\n"
                        "Grande: R$ 14,50\n");

                opcaoTamanhoCafe = tamanhoCafe();
                escolheQuantidade = menuQuantidade();

                // void calcularValor(int opcaoTamanhoCafe, int escolheQuantidade) {
                //float valorProduto;
            
                if (opcaoTamanhoCafe == 1) {
                    valorParcial = escolheQuantidade * 10.50f;
                } else if (opcaoTamanhoCafe == 2) {
                    valorParcial = escolheQuantidade * 12.50f;
                } else {
                    // Como o valor já foi tratado e só chegam 1, 2 ou 3,
                    // se não for 1 nem 2, obrigatoriamente é 3.
                    valorParcial = escolheQuantidade * 14.50f;
                }

                // 1. Atualiza o total acumulado
                totalGeral = calcularTotal(totalGeral, valorParcial);

                // 2. Abre o menu pós-compra capturando a ação escolhida
                acaoPosCompra = menuSecundario();
                if (acaoPosCompra == 1) {
                    return 6; // Retorna para o menu principal
                }
                return acaoPosCompra;
            case 6:
                printf("\n-> Voce escolheu a opção 6 - Incluir Mais Itens.\n");
                return 6;
            case 7:
                printf("\n-> Voce escolheu a opção 7 - Finalizar Pedido.\n");
                return 7;
            case 8:
                printf("\n-> 8 - Cancelar Pedido.\n");
                return 8;
            default:
                printf("\nAVISO: Opção inexistente. Por favor, escolha uma opção do menu.\n\n");
        }
    } while (escolheCafeTrad < 1 || escolheCafeTrad > 8);
    return 0;
}

int menuCafeEspeciais(void) {
    int escolheCafeEspecial;
    int leituraValida;
    int escolheQuantidade;
    int opcaoTamanhoCafe;
    int acaoPosCompra;

    do {
        printf("\n === CAFÉS ESPECIAIS ===\n" 
        "1 - Mocha Belga\n"
        "2 - Latte Baunilha\n"
        "3 - Caramelo Macchiato\n"
        "4 - Cappuccino de Avelã\n"
        "5 - Café Gelado Gourmet\n"
        "6 - Incluir Mais Itens\n"
        "7 - Finalizar Pedido\n"
        "8 - Cancelar Pedido\n"
        "\nEscolha uma opção do menu: ");

        // Verifica se conseguiu ler 1 número inteiro
        leituraValida = scanf("%d", &escolheCafeEspecial);

        // Se o usuário digitou letras ou caracteres inválidos
        if (leituraValida != 1) {
            int c;
            // Limpa todo o buffer de entrada até o Enter (\n)
            while ((c = getchar()) != '\n' && c != EOF);

            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            escolheCafeEspecial = 0; // Garante que a condição do while repita o loop
            continue;
        }

        switch (escolheCafeEspecial) {
            case 1:
                printf("\n-> Voce escolheu a opção 1 - Mocha Belga.\n"
                        "Pequeno: R$ 14,50\n"
                        "Médio: R$ 16,50\n"
                        "Grande: R$ 18,50\n");

                opcaoTamanhoCafe = tamanhoCafe();
                escolheQuantidade = menuQuantidade();

                // void calcularValor(int opcaoTamanhoCafe, int escolheQuantidade) {
                //float valorProduto;
            
                if (opcaoTamanhoCafe == 1) {
                    valorParcial = escolheQuantidade * 14.50f;
                } else if (opcaoTamanhoCafe == 2) {
                    valorParcial = escolheQuantidade * 16.50f;
                } else {
                    // Como o valor já foi tratado e só chegam 1, 2 ou 3,
                    // se não for 1 nem 2, obrigatoriamente é 3.
                    valorParcial = escolheQuantidade * 18.50f;
                }

                // 1. Atualiza o total acumulado
                totalGeral = calcularTotal(totalGeral, valorParcial);

                // 2. Abre o menu pós-compra capturando a ação escolhida
                acaoPosCompra = menuSecundario();
                if (acaoPosCompra == 1) {
                    return 6; // Retorna para o menu principal
                }
                return acaoPosCompra;
            case 2:
                printf("\n-> Voce escolheu a opção 2 - Latte Baunilha.\n"
                        "Pequeno: R$ 13,50\n"
                        "Médio: R$ 15,50\n"
                        "Grande: R$ 17,50\n");

                opcaoTamanhoCafe = tamanhoCafe();
                escolheQuantidade = menuQuantidade();

                // void calcularValor(int opcaoTamanhoCafe, int escolheQuantidade) {
                //float valorProduto;
            
                if (opcaoTamanhoCafe == 1) {
                    valorParcial = escolheQuantidade * 13.50f;
                } else if (opcaoTamanhoCafe == 2) {
                    valorParcial = escolheQuantidade * 15.50f;
                } else {
                    // Como o valor já foi tratado e só chegam 1, 2 ou 3,
                    // se não for 1 nem 2, obrigatoriamente é 3.
                    valorParcial = escolheQuantidade * 17.50f;
                }

                // 1. Atualiza o total acumulado
                totalGeral = calcularTotal(totalGeral, valorParcial);

                // 2. Abre o menu pós-compra capturando a ação escolhida
                acaoPosCompra = menuSecundario();
                if (acaoPosCompra == 1) {
                    return 6; // Retorna para o menu principal
                }
                return acaoPosCompra;
            case 3:
                printf("\n-> Voce escolheu a opção 3 - Caramelo Macchiato.\n"
                        "Pequeno: R$ 15,50\n"
                        "Médio: R$ 17,50\n"
                        "Grande: R$ 19,50\n");

                opcaoTamanhoCafe = tamanhoCafe();
                escolheQuantidade = menuQuantidade();

                // void calcularValor(int opcaoTamanhoCafe, int escolheQuantidade) {
                //float valorProduto;
            
                if (opcaoTamanhoCafe == 1) {
                    valorParcial = escolheQuantidade * 15.50f;
                } else if (opcaoTamanhoCafe == 2) {
                    valorParcial = escolheQuantidade * 17.50f;
                } else {
                    // Como o valor já foi tratado e só chegam 1, 2 ou 3,
                    // se não for 1 nem 2, obrigatoriamente é 3.
                    valorParcial = escolheQuantidade * 19.50f;
                }

                // 1. Atualiza o total acumulado
                totalGeral = calcularTotal(totalGeral, valorParcial);

                // 2. Abre o menu pós-compra capturando a ação escolhida
                acaoPosCompra = menuSecundario();
                if (acaoPosCompra == 1) {
                    return 6; // Retorna para o menu principal
                }
                return acaoPosCompra;
            case 4:
                printf("\n-> Voce escolheu a opção 4 - Café com Leite.\n"
                        "Pequeno: R$ 14,00\n"
                        "Médio: R$ 16,00\n"
                        "Grande: R$ 18,00\n");

                opcaoTamanhoCafe = tamanhoCafe();
                escolheQuantidade = menuQuantidade();

                // void calcularValor(int opcaoTamanhoCafe, int escolheQuantidade) {
                //float valorProduto;
            
                if (opcaoTamanhoCafe == 1) {
                    valorParcial = escolheQuantidade * 14.00f;
                } else if (opcaoTamanhoCafe == 2) {
                    valorParcial = escolheQuantidade * 16.00f;
                } else {
                    // Como o valor já foi tratado e só chegam 1, 2 ou 3,
                    // se não for 1 nem 2, obrigatoriamente é 3.
                    valorParcial = escolheQuantidade * 18.00f;
                }

                // 1. Atualiza o total acumulado
                totalGeral = calcularTotal(totalGeral, valorParcial);

                // 2. Abre o menu pós-compra capturando a ação escolhida
                acaoPosCompra = menuSecundario();
                if (acaoPosCompra == 1) {
                    return 6; // Retorna para o menu principal
                }
                return acaoPosCompra;
            case 5:
                printf("\n-> Voce escolheu a opção 5 - Café Gelado Gourmet.\n"
                        "Pequeno: R$ 15,00\n"
                        "Médio: R$ 17,00\n"
                        "Grande: R$ 19,00\n");

                opcaoTamanhoCafe = tamanhoCafe();
                escolheQuantidade = menuQuantidade();

                // void calcularValor(int opcaoTamanhoCafe, int escolheQuantidade) {
                //float valorProduto;
            
                if (opcaoTamanhoCafe == 1) {
                    valorParcial = escolheQuantidade * 15.00f;
                } else if (opcaoTamanhoCafe == 2) {
                    valorParcial = escolheQuantidade * 17.00f;
                } else {
                    // Como o valor já foi tratado e só chegam 1, 2 ou 3,
                    // se não for 1 nem 2, obrigatoriamente é 3.
                    valorParcial = escolheQuantidade * 19.00f;
                }

                // 1. Atualiza o total acumulado
                totalGeral = calcularTotal(totalGeral, valorParcial);

                // 2. Abre o menu pós-compra capturando a ação escolhida
                acaoPosCompra = menuSecundario();
                if (acaoPosCompra == 1) {
                    return 6; // Retorna para o menu principal
                }
                return acaoPosCompra;
            case 6:
                printf("\n-> Voce escolheu a opção 6 - Incluir Mais Itens.\n");
                return 6;
            case 7:
                printf("\n-> Voce escolheu a opção 7 - Finalizar Pedido.\n");
                return 7;
            case 8:
                printf("\n-> 8 - Cancelar Pedido.\n");
                return 8;
            default:
                printf("\nAVISO: Opção inexistente. Por favor, escolha uma opção do menu.\n\n");
                break;
        }
    } while (escolheCafeEspecial < 1 || escolheCafeEspecial > 8);
    return 0;
}

int tamanhoCafe(void) {
    int opcaoTamanhoCafe;
    int leituraValida;
    
    do {
    printf("\n === TAMANHO === \n"
	    "1 - Pequeno\n"
	    "2 - Médio\n"
	    "3 - Grande\n"
        "\nEscolha o tamanho do seu café: ");
        
        // Verifica se conseguiu ler 1 número inteiro
        leituraValida = scanf("%d", &opcaoTamanhoCafe);

        // Se o usuário digitou letras ou caracteres inválidos
        if (leituraValida != 1) {
            int c;
            // Limpa todo o buffer de entrada até o Enter (\n)
            while ((c = getchar()) != '\n' && c != EOF);

            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            opcaoTamanhoCafe = 0; // Garante que a condição do while repita o loop
            continue;
        }

	switch(opcaoTamanhoCafe) {
		case 1:
			printf("Você escolheu a opção: 1 - Pequeno.\n");
			return 1;
		case 2:
			printf("Você escolheu a opção: 2 - Médio.\n");
			return 2;
		case 3:
			printf("Você escolheu a opção: 3 - Grande.\n");
			return 3;
		default:
			printf("\nAVISO: Opção inexistente. Por favor, escolha uma opção do menu.\n\n");
			return 0;
        }
    } while (opcaoTamanhoCafe < 1 || opcaoTamanhoCafe > 3);
    return 0;
}

int menuQuantidade(void) {
    int escolheQuantidade = 0;
    int leituraValida;

    while (1) { // Roda continuamente até encontrar um return com valor válido
        printf("\n === QUANTIDADE ===\n"
            "Indique a quantidade desejada: ");
        
        // Apenas um scanf com validação de leitura
        leituraValida = scanf("%d", &escolheQuantidade);

        // Se o usuário digitou letras ou caracteres inválidos
        if (leituraValida != 1) {
            int c;
            // Limpa o buffer de entrada até o Enter (\n)
            while ((c = getchar()) != '\n' && c != EOF);

            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            continue; // Volta ao início do while
        }

        // Validação da quantidade escolhida
        if (escolheQuantidade > 0) {
            printf("\n-> Voce escolheu %d unidade(s).\n", escolheQuantidade);
            return escolheQuantidade; // Retorna e encerra a função
        } else {
            printf("\nAVISO: Quantidade deve ser maior que zero! Tente novamente.\n");
        }
    }
}


float calcularTotal(float totalGeral, float valorParcial) {
	totalGeral = totalGeral + valorParcial;
	return totalGeral;
}

int menuDoces(void) {
    int escolheDoce;
    int leituraValida;
    int escolheQuantidade;
    int acaoPosCompra;

    do {
        printf("\n === DOCES D'AURORA ===\n"
               "1 - Cheesecake de Frutas Vermelhas (R$ 18,90)\n"
               "2 - Torta Belga de Chocolate (R$ 19,90)\n"
               "3 - Mille-Feuille de Baunilha (R$ 17,90)\n"
               "4 - Voltar ao menu principal\n"
               "5 - Finalizar pedido\n"
               "6 - Cancelar pedido\n"
               "\nEscolha uma opção do menu: ");

        leituraValida = scanf("%d", &escolheDoce);

        if (leituraValida != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            escolheDoce = 0;
            continue;
        }

        switch (escolheDoce) {
            case 1:
                printf("\n-> Voce escolheu a opção 1 - Cheesecake de Frutas Vermelhas.\n");
                escolheQuantidade = menuQuantidade();
                valorParcial = escolheQuantidade * 18.90f;
                totalGeral = calcularTotal(totalGeral, valorParcial);

                acaoPosCompra = menuSecundario();
                if (acaoPosCompra == 1) {
                    return 3; // Voltar ao fluxo / menu anterior
                }
                return acaoPosCompra;

            case 2:
                printf("\n-> Voce escolheu a opção 2 - Torta Belga de Chocolate.\n");
                escolheQuantidade = menuQuantidade();
                valorParcial = escolheQuantidade * 19.90f;
                totalGeral = calcularTotal(totalGeral, valorParcial);

                acaoPosCompra = menuSecundario();
                if (acaoPosCompra == 1) {
                    return 3;
                }
                return acaoPosCompra;

            case 3:
                printf("\n-> Voce escolheu a opção 3 - Mille-Feuille de Baunilha.\n");
                escolheQuantidade = menuQuantidade();
                valorParcial = escolheQuantidade * 17.90f;
                totalGeral = calcularTotal(totalGeral, valorParcial);

                acaoPosCompra = menuSecundario();
                if (acaoPosCompra == 1) {
                    return 3;
                }
                return acaoPosCompra;

            case 4:
                return 3; // Volta para o menu principal

            case 5:
                printf("\n-> Voce escolheu Finalizar Pedido.\n");
                if (finalizarPedido() == 1) {
                    return 4; // Código 4 propaga finalização para a main
                }
                break;

            case 6:
                printf("\n-> Voce escolheu Cancelar Pedido.\n");
                if (menuCancelar() == 1) {
                    return 5; // Código 5 propaga cancelamento para a main
                }
                break;

            default:
                printf("\nAVISO: Opção inexistente. Por favor, escolha uma opção do menu.\n\n");
                break;
        }
    } while (escolheDoce < 1 || escolheDoce > 6);

    return 0;
}

int menuSalgados(void) {
    int escolheSalgado;
    int leituraValida;
    int escolheQuantidade;
    int acaoPosCompra;

    do {
        printf("\n === SALGADOS PREMIUM ===\n"
               "1 - Croissant de Brie e Presunto Parma (R$ 19,90)\n"
               "2 - Quiche Lorraine Artesanal (R$ 18,90)\n"
               "3 - Sanduíche Caprese Gourmet (R$ 21,90)\n"
               "4 - Voltar ao menu principal\n"
               "5 - Finalizar pedido\n"
               "6 - Cancelar pedido\n"
               "\nEscolha uma opção do menu: ");

        leituraValida = scanf("%d", &escolheSalgado);

        if (leituraValida != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            escolheSalgado = 0;
            continue;
        }

        switch (escolheSalgado) {
            case 1:
                printf("\n-> Voce escolheu a opção 1 - Croissant de Brie e Presunto Parma.\n");
                escolheQuantidade = menuQuantidade();
                valorParcial = escolheQuantidade * 19.90f;
                totalGeral = calcularTotal(totalGeral, valorParcial);

                acaoPosCompra = menuSecundario();
                if (acaoPosCompra == 1) {
                    return 3;
                }
                return acaoPosCompra;

            case 2:
                printf("\n-> Voce escolheu a opção 2 - Quiche Lorraine Artesanal.\n");
                escolheQuantidade = menuQuantidade();
                valorParcial = escolheQuantidade * 18.90f;
                totalGeral = calcularTotal(totalGeral, valorParcial);

                acaoPosCompra = menuSecundario();
                if (acaoPosCompra == 1) {
                    return 3;
                }
                return acaoPosCompra;

            case 3:
                printf("\n-> Voce escolheu a opção 3 - Sanduíche Caprese Gourmet.\n");
                escolheQuantidade = menuQuantidade();
                valorParcial = escolheQuantidade * 21.90f;
                totalGeral = calcularTotal(totalGeral, valorParcial);

                acaoPosCompra = menuSecundario();
                if (acaoPosCompra == 1) {
                    return 3;
                }
                return acaoPosCompra;

            case 4:
                return 3; // Volta para o menu principal

            case 5:
                printf("\n-> Voce escolheu Finalizar Pedido.\n");
                if (finalizarPedido() == 1) {
                    return 4;
                }
                break;

            case 6:
                printf("\n-> Voce escolheu Cancelar Pedido.\n");
                if (menuCancelar() == 1) {
                    return 5;
                }
                break;

            default:
                printf("\nAVISO: Opção inexistente. Por favor, escolha uma opção do menu.\n\n");
                break;
        }
    } while (escolheSalgado < 1 || escolheSalgado > 6);

    return 0;
}

int menuCancelar(void) {
    int opcaoCancelar;    
    int leituraValida;
    int c;
    
    do {
        printf("\n === Deseja cancelar o pedido? === \n"
               "1 - Sim.\n"
               "2 - Não.\n"
               "Opção: ");
        leituraValida = scanf("%d", &opcaoCancelar);
        if (leituraValida != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            opcaoCancelar = 0;
            continue;
        }
        switch (opcaoCancelar) {
            case 1:
                printf("\nVolte sempre! Estamos prontos com cafés, doces e salgados preparados com todo carinho.\n"
                       "Tenha um excelente dia e até breve!\n\n"
                       "Pressione [ENTER] para voltar ao início...");
                // Limpa sobras do buffer (inclusive o Enter do scanf anterior)
                while ((c = getchar()) != '\n' && c != EOF);
                
                // Aguarda o usuário teclar Enter
                getchar();
                // Reseta os dados globais para o próximo cliente
                totalGeral = 0.0f;
                nomeCliente[0] = '\0';
                // Limpa a tela antes de voltar ao início sem chamar o shell
                printf("\033[H\033[J");
                return 1;
            case 2:
                printf("Retornando ao pedido...\n");
                return 2;
            default: 
                printf("\nAVISO: Opção inexistente. Por favor, escolha uma opção do menu.\n\n");
                break;
        }
    } while (opcaoCancelar < 1 || opcaoCancelar > 2);

    return 0;
}

int carrinho(void) {
    int opcaoCarrinho;    
    int leituraValida;
    
    printf("O total do seu pedido até agora é: %.2f\n", totalGeral);
    
    do {
    printf("\n === ESCOLHA UMA OPÇÃO === \n"
	    "1 - Finalizar pedido.\n"
	    "2 - Incluir mais itens.\n");

        // Verifica se conseguiu ler 1 número inteiro
        leituraValida = scanf("%d", &opcaoCarrinho);

        // Se o usuário digitou letras ou caracteres inválidos
        if (leituraValida != 1) {
            int c;
            // Limpa todo o buffer de entrada até o Enter (\n)
            while ((c = getchar()) != '\n' && c != EOF);
            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            opcaoCarrinho = 0; // Garante que a condição do while repita o loop
            continue;
        }
        	
        switch (opcaoCarrinho) {
            case 1:
                printf("\nFinalizar pedido.\n");
                if (finalizarPedido() == 1) {
                    return 5; // Avisa toda a cadeia para encerrar e voltar à main()
                }
                return 2;
            case 2:
                printf("\nIncluir mais itens.\n");
                return 2;
            default:
                printf("\nAVISO: Opção inexistente. Por favor, escolha uma opção do menu.\n\n");
                break;
        }
    } while (opcaoCarrinho < 1 || opcaoCarrinho > 2);
    return 0;
}

int formaDePagamento(void) {
	int escolhePagamento; // Declarada antes do uso
    int leituraValida;
    
    do {
	printf("\n === ESCOLHA SUA FORMA DE PAGAMENTO ===\n"
	"1 - Débito\n"
	"2 - Crédito\n"
	"3 - Voucher\n"
	"Opção: ");
	        // Verifica se conseguiu ler 1 número inteiro
        leituraValida = scanf("%d", &escolhePagamento);

        // Se o usuário digitou letras ou caracteres inválidos
        if (leituraValida != 1) {
            int c;
            // Limpa todo o buffer de entrada até o Enter (\n)
            while ((c = getchar()) != '\n' && c != EOF);

            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            escolhePagamento = 0; // Garante que a condição do while repita o loop
            continue;
        }

	switch(escolhePagamento) {
        case 1:
            printf("Você escolheu a opção: Débito.\n"
            "Insira o cartão no leitor e siga as instruções\n\n");
            return 1;
        case 2:
            printf("Você escolheu a opção: Crédito.\n"
            "Insira o cartão no leitor e siga as instruções\n\n");
            return 2;
        case 3:
            printf("Você escolheu a opção: Voucher.\n"
            "Insira o cartão no leitor e siga as instruções\n\n");
            return 3;
		default:
			printf("\nAVISO: Opção inexistente. Por favor, escolha uma opção do menu.\n\n");
			return 0;
    }
    } while (escolhePagamento < 1 || escolhePagamento > 3);
    return 0;
}

int finalizarPedido(void) {
    if (totalGeral > 0) {
        printf("\n === EXTRATO DO PEDIDO ===\n");
        // Traduz o número para texto na hora de mostrar:
            printf("Cliente: %s\n", nomeCliente);
            
        if (opcaoConsumo == 1) {
            printf("Tipo de Consumo: Consumir no local\n");
        } else {
            printf("Tipo de Consumo: Para viagem\n");
        }
        
        printf("Valor: R$ %.2f\n\n", totalGeral);
        formaDePagamento();
        imprimirRecibo();
        pedidoEnviado(); // Recebe retorno positivo do pagamento. 
        return 1; // SUCESSO: pedido pago e finalizado
    } else {
        printf("\nAVISO: O carrinho está vazio. Selecione um produto antes de finalizar!\n");
        return 0; // FALHA: carrinho vazio, não deve encerrar a aplicação
    }
}

int imprimirRecibo(void) {
    int opcaoRecibo;
    int leituraValida;
    int c;
    
    do {
        printf("\n === RECIBO ===\n"
               "Deseja imprimir o recibo?\n"
               "1 - Sim.\n"
               "2 - Não.\n"
               "Opção: ");
        leituraValida = scanf("%d", &opcaoRecibo);
        // Limpa qualquer sobra do teclado, inclusive o Enter (\n)
        while ((c = getchar()) != '\n' && c != EOF);
        if (leituraValida != 1) {
            printf("\n[ERRO] Entrada invalida! Digite apenas numeros.\n");
            opcaoRecibo = 0;
            continue;
        }
        switch (opcaoRecibo) {
            case 1:
                printf("\n-> Por favor, retire o recibo no local indicado.\n");
                break;
            case 2:
                printf("\n-> O recibo não será impresso.\n");
                break;
            default:
                printf("\nAVISO: Opção inexistente. Por favor, escolha 1 ou 2.\n");
                break;
        }
    } while (opcaoRecibo < 1 || opcaoRecibo > 2);
    return opcaoRecibo;
}

void pedidoEnviado(void) {
    int c;
    
    printf("\n %s, seu pedido foi enviado com sucesso para a equipe.\n", nomeCliente);
    printf("Acompanhe o andamento do seu pedido no painel do estabelecimento.\n\n");
    printf("  ============   Volte sempre!    =========== \n"
           "      Estamos prontos com cafés, doces e\n"
           "     salgados preparados com todo carinho.\n\n"
           "      Tenha um excelente dia e até breve!\n"
           "  ============ ~ ============= ~ ============ \n\n"
           "Pressione [ENTER] para iniciar um novo atendimento...\n");
    // Garante que não há caracteres residuais
    while ((c = getchar()) != '\n' && c != EOF);

    // Reseta os dados globais para o próximo cliente
    totalGeral = 0.0f;
    nomeCliente[0] = '\0';

    // Limpa a tela
    printf("\033[H\033[J");
}