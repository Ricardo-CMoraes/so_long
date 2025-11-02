# 🎮 So_Long - A Jornada do Coletor (MiniLibX)

> Um pequeno jogo 2D top-down desenvolvido em C utilizando a biblioteca gráfica MiniLibX, parte do currículo da Escola 42.

## 🌟 Visão Geral

O objetivo do `so_long` é criar um jogo 2D minimalista onde o jogador deve atravessar um mapa, coletar todos os itens necessários e alcançar a saída, tudo isso em um número mínimo de movimentos. O projeto foca em:
* Análise e validação de mapas.
* Manipulação de eventos (teclado).
* Renderização gráfica com sprites e texturas.
* Gerenciamento de janelas com a MiniLibX.

## 🕹️ Demonstração



## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C
* **Biblioteca Gráfica:** MiniLibX
* **Compilador:** GCC
* **Ferramentas:** `make`

## ⚙️ Funcionalidades Implementadas

### Obrigatório (Mandatory)

* ✅ **Validação de Mapa:** O programa verifica se o mapa possui formato retangular, é cercado por paredes ('1'), e contém exatamente 1 Posição Inicial ('P'), pelo menos 1 Coletável ('C') e exatamente 1 Saída ('E').
* ✅ **Controles de Movimento:** O jogador se move usando as teclas `W`, `A`, `S`, `D`.
* ✅ **Contador de Movimentos:** O número de movimentos é exibido no terminal.
* ✅ **Saída Limpa:** O jogo fecha corretamente ao pressionar `ESC` ou fechar a janela.
* ✅ **Caminho Válido:** Verificação se é possível coletar todos os itens e chegar à saída (utilizando, por exemplo, BFS ou Flood Fill).

### Bônus (Opcional)

* ✨ **Inimigos/Patrulhas:** Adição de inimigos ('X') com movimentos autônomos.
* ✨ **Animação:** Implementação de animações para o jogador ou itens colecionáveis.
* ✨ **Contador On-Screen:** O número de movimentos é renderizado diretamente na janela do jogo.

## 🚀 Como Compilar e Jogar

### Pré-requisitos

Para compilar e executar este projeto, você precisará ter o compilador GCC e as dependências da MiniLibX instaladas em seu ambiente (geralmente Linux com X11 ou macOS).

### 1. Clonar o Repositório

```bash
git clone <URL_DO_SEU_REPOSITORIO>
cd so_long