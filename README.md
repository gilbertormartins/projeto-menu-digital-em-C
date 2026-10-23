# ☕ Totem de Autoatendimento - Cafeteria Aurora

Sistema interativo de terminal desenvolvido em **Linguagem C**, simulando o fluxo completo de um totem de autoatendimento para cafeteria. O programa foi projetado com foco em navegação clara, objetiva, experiência do usuário (UX em CLI), integridade da entrada de dados e operação em ciclo contínuo e acúmulo de valores. Primeiro código desenvolvido para a faculdade na matéria de lógica, que ainda está em andamento na data desta publicação.

## 🌟 Destaques e Pontos Fortes do Código

* **Tratamento Rigoroso de Entrada (`scanf` seguro):**

  * Todos os menus verificam se a leitura retornou um número válido (`leituraValida != 1`).

  * Implementação de esvaziamento explícito do buffer do teclado (`while ((c = getchar()) != '\n' && c != EOF);`), prevenindo completamente travamentos ou laços infinitos causados por entradas alfanuméricas acidentais.

* **Ciclo de Totem Contínuo (`while (1)`):**

  * O sistema opera no modelo de terminal comercial de autoatendimento: ao finalizar ou cancelar um pedido, as variáveis de sessão (`totalGeral`, `nomeCliente`) são resetadas e a interface recarrega automaticamente para o próximo cliente.

* **Modularidade e Arquitetura Limpa:**

  * Código estruturado com divisão clara de protótipos de função, fluxo principal e submenus especializados (Cafés Tradicionais, Especiais, Doces, Salgados, Carrinho e Pagamento).

* **Limpeza de Tela Multiplataforma via ANSI Escape:**

  * Uso de `printf("\033[H\033[J")` para limpar a tela do terminal de maneira nativa em sistemas modernos (Linux, macOS e Windows Terminal), sem depender de chamadas inseguras e lentas de shell como `system("cls")` ou `system("clear")`.

* **Validação de Regras de Negócio:**

  * Bloqueio de finalização de pedidos vazios (`totalGeral <= 0`).

  * Restrição de quantidades estritamente positivas no carrinho (`escolheQuantidade > 0`).

  * Configuração de localização (`setlocale(LC_ALL, "pt_BR.UTF-8")`) para exibição adequada de acentuação e pontuação monetária.

## 📋 Funcionalidades

1. **Identificação do Cliente:** Captura do nome para personalização do atendimento e extrato.

2. **Modalidade de Consumo:** Escolha entre "Consumir no local" ou "Para viagem".

3. **Cardápio Segmentado:**

   * **Cafés Tradicionais:** Espresso, Coado Especial, Americano, Café com Leite e Cappuccino.

   * **Cafés Especiais:** Mocha Belga, Latte Baunilha, Caramelo Macchiato, Cappuccino de Avelã e Gelado Gourmet.

   * **Precificação por Tamanho:** Cálculo dinâmico para copos Pequeno, Médio e Grande.

   * **Doces D'Aurora:** Cheesecakes, Tortas Belgas e Folhados.

   * **Salgados Premium:** Croissants artesanais, Quiches e Sanduíches gourmet.

4. **Gerenciamento do Pedido:** Visualização de subtotal, acúmulo contínuo de itens e conferência de carrinho.

5. **Pagamento e Fechamento:** Simulação de pagamento (Débito, Crédito ou Voucher), emissão opcional de recibo e envio para produção.

## 🛠️ Tecnologias Utilizadas

* **Linguagem C** (Padrão C99 / C11)

* **Bibliotecas Padrão:**

  * `<stdio.h>`: Operações de entrada/saída formatadas e manipulação de fluxos.

  * `<stdlib.h>`: Utilitários gerais do sistema.

  * `<locale.h>`: Suporte à localização e caracteres em português.

## 🚀 Como Compilar e Executar

### Pré-requisitos

Certifique-se de ter um compilador C instalado (como **GCC** ou **Clang**).

### Passo a passo

1. **Clone o repositório:**

   ```
   git clone https://github.com/gilbertormartins/projeto-menu-digital-em-C.git
   cd projeto-menu-digital-em-C
   
   ```

2. **Compile o programa:**

   ```
   gcc main.c -o cafeteria
   
   ```

3. **Execute:**

   * **Linux / macOS:**

     ```
     ./cafeteria
     
     ```

   * **Windows (Prompt de Comando / PowerShell):**

     ```
     .\cafeteria.exe
     
     ```

## 👤 Autor

**Gilberto Martins**

* [Perfil no GitHub](https://github.com/gilbertormartins)

* Graduando em Ciência da Computação
