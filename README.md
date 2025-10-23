🚦 Projeto Semáforo Inteligente com Sensores – Arduino

Este projeto implementa um sistema de controle de semáforos inteligentes usando um Arduino.
O código gerencia dois cruzamentos (Semáforo 1 e Semáforo 2) com LEDs representando as luzes verde, amarela e vermelha, além de utilizar sensores de presença para detectar o fluxo de veículos e ajustar o comportamento do semáforo em tempo real.

🧠 Lógica do Sistema

O sistema possui dois modos de funcionamento principais:

1. Modo Automático (sem sensores acionados)

Quando ambos os sensores estão ativados (HIGH), o sistema executa um ciclo temporizado fixo:

Ciclo	Tempo (ms)	Semáforo 1	Semáforo 2
1	0 – 5000	Verde	Vermelho
2	5000 – 6000	Amarelo	Vermelho
3	6000 – 9000	Vermelho	Verde
4	9000 – 10000	Vermelho	Amarelo

Após 10 segundos, o ciclo é reiniciado automaticamente.

2. Modo Sensores (tráfego dinâmico)

Quando um dos sensores detecta um veículo (HIGH) e o outro não (LOW), o semáforo correspondente recebe prioridade:

🚗 Sensor 1 ativo (Semáforo 1 = HIGH / Semáforo 2 = LOW)

Semáforo 1 → Verde

Semáforo 2 → Vermelho

🚗 Sensor 2 ativo (Semáforo 2 = HIGH / Semáforo 1 = LOW)

Semáforo 2 → Verde

Semáforo 1 → Vermelho

Se o outro semáforo estiver verde, o código aciona a transição amarela (amarelo1() ou amarelo2()) antes de mudar para vermelho, garantindo uma troca segura.

⚙️ Componentes Utilizados
Componente	Quantidade	Pinos Arduino
LED Verde Semáforo 1 (com resistor embutido)	1	3
LED Amarelo Semáforo 1 (com resistor embutido)	1	2
LED Vermelho Semáforo 1 (com resistor embutido)	1	4
LED Verde Semáforo 2 (com resistor embutido)	1	11
LED Amarelo Semáforo 2 (com resistor embutido)	1	10
LED Vermelho Semáforo 2 (com resistor embutido)	1	9
Sensor de presença (Semáforo 1)	1	8
Sensor de presença (Semáforo 2)	1	7
Arduino UNO (ou similar)	1	—
Protoboard e jumpers	—	—

💡 Observação: Os LEDs utilizados possuem resistores integrados, portanto não é necessário adicionar resistores externos no circuito.

🔄 Funções Principais

apagarTodos()
Desliga todos os LEDs antes de acender o próximo conjunto.

amarelo1() / amarelo2()
Realiza a transição segura (verde → amarelo → vermelho), com delay(2000) para o tempo do sinal amarelo.

Controle de tempo (millis())
Gerencia o tempo de cada fase do ciclo automático sem travar o código principal.

💡 Como Usar

Monte o circuito conforme a tabela de pinos.

Carregue o código no Arduino.

Abra o Monitor Serial (9600 baud) para observar o estado dos sensores.

Ative/desative os sensores manualmente (ou aproxime objetos, caso use sensores IR).

Observe a mudança dos LEDs conforme o modo de operação.
