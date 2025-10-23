🚦 Projeto: Semáforo Inteligente com Sensores – Arduino

Este projeto simula um sistema de semáforo inteligente utilizando o Arduino.
O sistema controla dois semáforos e utiliza sensores digitais para detectar a presença de veículos, alternando automaticamente o fluxo conforme a demanda de tráfego.

Quando nenhum sensor é acionado, o sistema funciona em modo automático com tempos pré-definidos.
Quando um dos sensores detecta veículo, ele prioriza o respectivo semáforo.

📋 Descrição

O sistema é composto por dois conjuntos de LEDs representando os semáforos e dois sensores digitais que simulam a detecção de veículos.

Semáforo 1:

Verde1 (pino 3)

Amarelo1 (pino 2)

Vermelho1 (pino 4)

Semáforo 2:

Verde2 (pino 11)

Amarelo2 (pino 10)

Vermelho2 (pino 9)

Sensores:

Sensor Semáforo 1 (pino 8)

Sensor Semáforo 2 (pino 7)

⚙️ Lógica de Funcionamento

O sistema opera em dois modos:

🚗 Modo com Sensores (Controle Dinâmico)

Sensor 1 ativo (HIGH) e Sensor 2 inativo (LOW) →
Semáforo 1 Verde, Semáforo 2 Vermelho

Sensor 2 ativo (HIGH) e Sensor 1 inativo (LOW) →
Semáforo 2 Verde, Semáforo 1 Vermelho

Troca de estado:
Antes de mudar de verde para vermelho, o semáforo passa 2 segundos no amarelo para garantir a segurança.

⏱️ Modo Automático (Sem Acionamento dos Sensores)

Quando ambos os sensores estão ativos (HIGH), o sistema segue um ciclo temporizado:

Ciclo	Tempo (ms)	Semáforo 1	Semáforo 2
1	0 – 5000	Verde	Vermelho
2	5000 – 6000	Amarelo	Vermelho
3	6000 – 9000	Vermelho	Verde
4	9000 – 10000	Vermelho	Amarelo

Após 10 segundos, o ciclo é reiniciado automaticamente.

🔌 Componentes Utilizados

1x Arduino Uno (ou compatível)

6x LEDs (2 verdes, 2 amarelos, 2 vermelhos – com resistores embutidos)

2x Sensores digitais (simulando sensores de presença)

Jumpers

Protoboard

💡 Observação: Os LEDs utilizados possuem resistores integrados, portanto não é necessário adicionar resistores externos no circuito.

🔧 Ligações dos Componentes
Pino Arduino	Componente
2	LED Amarelo - Semáforo 1
3	LED Verde - Semáforo 1
4	LED Vermelho - Semáforo 1
7	Sensor Semáforo 2
8	Sensor Semáforo 1
9	LED Vermelho - Semáforo 2
10	LED Amarelo - Semáforo 2
11	LED Verde - Semáforo 2
🧩 Funções do Código

apagarTodos() → Desliga todos os LEDs antes de ativar o próximo conjunto.

amarelo1() / amarelo2() → Realizam a transição segura (verde → amarelo → vermelho).

Controle com millis() → Permite medir o tempo dos ciclos sem travar o programa (diferente de delay()).

💡 Como Utilizar

Monte o circuito conforme a tabela acima.

Carregue o código no Arduino.

Abra o Monitor Serial (9600 baud) para acompanhar o estado dos sensores.

Ative os sensores manualmente (ou aproxime um objeto, caso use sensores IR).

Observe a mudança automática dos LEDs conforme o modo de operação.

👤 Autores

Thomas Adrian
🔗 GitHub

<p align="left"> <a href="https://www.linkedin.com/in/thomas-adrian" target="blank"> <img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="https://www.linkedin.com/in/thomas-adrian" height="30" width="40" /> </a> </p>

Samuel Amate
🔗 GitHub

<p align="left"> <a href="https://linkedin.com/in/samuel-amate" target="blank"> <img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="https://linkedin.com/in/samuel-amate" height="30" width="40" /> </a> </p>
