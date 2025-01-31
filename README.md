# Semáforo com Raspberry Pi Pico

Este projeto implementa um semáforo simples utilizando um Raspberry Pi Pico. O código controla três LEDs (vermelho, amarelo e verde) que simulam o funcionamento de um semáforo de trânsito.

## Descrição do Projeto

O semáforo alterna entre três estados:
1. **Vermelho**: LED vermelho aceso.
2. **Verde**: LED verde aceso.
3. **Amarelo**: LED amarelo aceso.

A transição entre os estados é feita automaticamente a cada 3 segundos, utilizando um temporizador.

## Componentes Necessários

- Raspberry Pi Pico
- 1 LED vermelho
- 1 LED amarelo
- 1 LED verde
- 3 resistores (220Ω)
- Jumpers e protoboard

## Esquema de Conexão

- **LED Vermelho**: Conectado ao pino GP11.
- **LED Amarelo**: Conectado ao pino GP12.
- **LED Verde**: Conectado ao pino GP13.
- **Resistores**: Conectados em série com cada LED para limitar a corrente.

## Como Compilar e Executar

1. **Configuração do Ambiente**:
   - Certifique-se de ter o ambiente de desenvolvimento configurado para o Raspberry Pi Pico. Isso inclui o SDK do Pico e o compilador `gcc-arm-none-eabi`.

2. **Clonar o Repositório**:
   ```bash
   git clone https://github.com/seu-usuario/semaforo-pico.git
   cd semaforo-pico