# Código de Controle de LED e Botões

## 📄 Descrição

Este código controla um sistema com três LEDs (vermelho, verde e azul) e dois botões (A e B). O comportamento é o seguinte:

- **Ambos os botões pressionados**: Todos os LEDs ficam acesos (cor branca).
- **Apenas o botão A pressionado**: O LED vermelho acende.
- **Apenas o botão B pressionado**: O LED verde acende.
- **Nenhum botão pressionado**: O LED azul acende.

O programa entra em um loop infinito que verifica constantemente o estado dos botões e atualiza o estado dos LEDs conforme necessário.

---


## 🚀 Como Usar

1. **Conexões de Hardware**:  
   Conecte os LEDs e botões aos pinos GPIO definidos nas constantes no início do código.

2. **Compilação e Upload**:  
   Compile o código utilizando o SDK do Raspberry Pi Pico e faça o upload para o dispositivo.

3. **Interação**:  
   Pressione os botões A e/ou B para observar o comportamento dos LEDs.

---

## 🔍 Detalhes da Implementação

- A função `set_leds()` é responsável por atualizar o estado dos LEDs com base nos valores lógicos.
- O **loop principal** verifica o estado dos botões com a função `gpio_get()` e ajusta os LEDs conforme necessário.
- Há um delay de 100 milissegundos em cada iteração do loop para evitar uso excessivo da CPU.

---

## 💡 Exemplo de Comportamento

| Botão A | Botão B | LEDs Acendidos      |
|---------|---------|---------------------|
| Pressionado | Pressionado | Todos os LEDs (Branco) |
| Pressionado | Solto       | LED Vermelho         |
| Solto       | Pressionado | LED Verde            |
| Solto       | Solto       | LED Azul             |

---

## 🧰 Requisitos de Hardware

- **3 LEDs**: Vermelho, Verde e Azul.
- **2 Botões**: Botão A e Botão B.
- **Raspberry Pi Pico**.

---

## 🕹️ Observação

Certifique-se de ajustar os pinos GPIO no código para corresponder ao hardware conectado.

