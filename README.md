# 🚦 Projeto: Semáforo Inteligente com Sensores – Arduino

Sistema inteligente que controla dois semáforos com sensores digitais para detectar veículos, alternando o fluxo de trânsito conforme a demanda.

Quando nenhum sensor é acionado, funciona em modo automático com tempos pré-definidos. Se um sensor detectar veículo, prioriza o semáforo correspondente.

---

## 📋 Descrição

O sistema conta com dois conjuntos de LEDs para os semáforos e dois sensores digitais simulando detecção de veículos.

| **Semáforo 1**        | **Pino Arduino** |
|-----------------------|------------------|
| Verde1                | 3                |
| Amarelo1              | 2                |
| Vermelho1             | 4                |

| **Semáforo 2**        | **Pino Arduino** |
|-----------------------|------------------|
| Verde2                | 11               |
| Amarelo2              | 10               |
| Vermelho2             | 9                |

| **Sensores**          | **Pino Arduino** |
|-----------------------|------------------|
| Sensor Semáforo 1     | 8                |
| Sensor Semáforo 2     | 7                |

---

## ⚙️ Lógica de Funcionamento

### 🚗 Modo com Sensores (Controle Dinâmico)

- Sensor 1 ativo (HIGH) e Sensor 2 inativo (LOW):  
  🔴 Semáforo 2 vermelho | 🟢 Semáforo 1 verde  
- Sensor 2 ativo (HIGH) e Sensor 1 inativo (LOW):  
  🔴 Semáforo 1 vermelho | 🟢 Semáforo 2 verde  

**Transição:** antes de trocar verde para vermelho, semáforo fica 2 segundos amarelo para segurança.

---

### ⏱️ Modo Automático (Sem Acionamento dos Sensores)

Quando ambos os sensores estão ativos (HIGH), o ciclo segue:

| Ciclo | Tempo (ms) | Semáforo 1 | Semáforo 2 |
|-------|------------|------------|------------|
| 1     | 0 – 5000   | 🟢 Verde   | 🔴 Vermelho|
| 2     | 5000 – 6000| 🟡 Amarelo | 🔴 Vermelho|
| 3     | 6000 – 9000| 🔴 Vermelho| 🟢 Verde   |
| 4     | 9000 – 10000| 🔴 Vermelho| 🟡 Amarelo |

Após 10 segundos, o ciclo reinicia.

---

## 🔌 Componentes Utilizados

- Arduino Uno (ou compatível)  
- 6 LEDs (2 verdes, 2 amarelos, 2 vermelhos com resistores integrados)  
- 2 sensores digitais (simulando sensores de presença)  
- Jumpers  
- Protoboard  

> 💡 *Observação:* LEDs já possuem resistores embutidos — sem necessidade de resistores externos.

---

## 🔧 Ligações dos Componentes

| Pino Arduino | Componente                  |
|--------------|-----------------------------|
| 2            | LED Amarelo - Semáforo 1    |
| 3            | LED Verde - Semáforo 1      |
| 4            | LED Vermelho - Semáforo 1   |
| 7            | Sensor Semáforo 2           |
| 8            | Sensor Semáforo 1           |
| 9            | LED Vermelho - Semáforo 2   |
| 10           | LED Amarelo - Semáforo 2    |
| 11           | LED Verde - Semáforo 2      |

---

## 🧩 Funções do Código

- `apagarTodos()`: desliga todos os LEDs antes de ativar o próximo conjunto.  
- `amarelo1()` / `amarelo2()`: fazem a transição segura (verde → amarelo → vermelho).  
- Controle com `millis()`: permite medir tempo dos ciclos sem travar o programa (evita `delay()`).  

---

## 💡 Como Usar

1. Monte o circuito conforme as ligações acima.  
2. Carregue o código no Arduino.  
3. Abra o Monitor Serial (9600 baud) para acompanhar sensores.  
4. Acione os sensores manualmente (ou aproxime objeto para sensores IR).  
5. Veja a mudança automática dos LEDs conforme o modo escolhido.

---

## 👤 Autores

### Thomas Adrian  
🔗 [GitHub](https://github.com/Thomas-Adrian-Soler-Nilsson)  
<a href="https://www.linkedin.com/in/thomas-adrian" target="_blank">  
  <img src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="LinkedIn" width="30" />  
</a>  

---

### Samuel Amate  
🔗 [GitHub](https://github.com/SamuelAmate)  
<a href="https://linkedin.com/in/samuel-amate" target="_blank">  
  <img src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="LinkedIn" width="30" />  
</a>
