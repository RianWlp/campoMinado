# campoMinado

## Regras

A área de jogo consiste num campo de quadrados retangular. Cada quadrado pode ser revelado clicando sobre ele, e se o quadrado clicado contiver uma mina, então o jogo acaba. Se, por outro lado, o quadrado não contiver uma mina, uma de duas coisas poderá acontecer:

- Um número aparece, indicando a quantidade de quadrados adjacentes que contêm minas.
- Nenhum número aparece. Neste caso, o jogo revela automaticamente os quadrados que se encontram adjacentes ao quadrado vazio, já que não podem conter minas.

O jogo é ganho quando todos os quadrados que não têm minas são revelados.

Opcionalmente, o jogador pode marcar qualquer quadrado que acredita que contém uma mina com uma bandeira, bastando para isso clicar sobre ele com o botão direito do mouse. Em alguns casos, carregar com ambos os botões do mouse num número que contenha tantas bandeiras imediatamente à sua volta quanto o valor desse número revela todos os quadrados sem bombas que se encontrem adjacentes a ele. Em contrapartida, o jogo acaba se se efectuar essa acção quando os quadrados errados estiverem marcados com as bandeiras.

---

## Regras detalhadas do Campo Minado

### Tabuleiro
- O jogo ocorre em uma grade (geralmente quadrada) de células ocultas.
- Algumas dessas células contêm minas, outras estão vazias.

### Objetivo
- Revelar todas as células que não contêm minas.
- Se você revelar todas as células seguras, você vence o jogo.

### Como jogar
- O jogador clica em uma célula para revelá-la.
- Se a célula contiver uma mina, o jogo termina e o jogador perde.
- Se a célula estiver vazia, um número pode aparecer, indicando quantas minas existem nas células adjacentes (horizontais, verticais e diagonais).
- Se a célula não tiver minas ao redor (número 0), todas as células vizinhas são automaticamente reveladas.

### Marcando minas
- O jogador pode marcar células onde acredita que há minas usando uma bandeira.
- Isso ajuda a evitar cliques acidentais em minas.

### Vitória e Derrota
- **Vitória**: O jogador vence ao revelar todas as células seguras, sem tocar em nenhuma mina.
- **Derrota**: O jogo termina imediatamente se o jogador clicar em uma mina.

### Dicas e Estratégias
- O primeiro clique nunca será uma mina.
- Use os números revelados para deduzir onde estão as minas.
- Marque as minas suspeitas com bandeiras para não esquecê-las.
- Se houver incerteza, tente minimizar os riscos ao escolher uma célula para revelar.


### Visualização em profundidade (quando a célula é 0):
- Esse processo é chamado de expansão em profundidade ou flood fill.
- A célula 0 é revelada.
- Todas as células adjacentes (8 ao redor) também são reveladas.
- Se uma dessas também for 0, o processo se repete: revela ela e os vizinhos dela.
- Se uma dessas for um número (1 a 8), ela é revelada, mas não gera nova expansão.

Antes do clique:
? ? ? ? ?
? ? ? ? ?
? ? 0 ? ?
? ? ? ? ?
? ? ? ? ?

Depois do clique no "0":
1 1 1
1 0 1
1 1 1

---

## Compilação do projeto

Para compilar múltiplos arquivos `.cpp` ao mesmo tempo, use o comando:

```bash
g++ *.cpp -o campoMinado
g++ arquivo1.cpp arquivo2.cpp arquivo3.cpp -o campoMinado
./campoMinado




