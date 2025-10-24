# 🚦 Semáforo Inteligente com Sensores – Arduino / Intelligent Traffic Light with Sensors – Arduino

---

## 🇧🇷 Português (PT-BR)

Sistema inteligente que controla dois semáforos utilizando sensores digitais para detectar veículos, alternando o fluxo de trânsito conforme a demanda.

Quando nenhum sensor é acionado, funciona em modo automático com tempos pré-definidos. Se um sensor detectar veículo, prioriza o semáforo correspondente.

### 📋 Descrição

O sistema conta com dois conjuntos de LEDs para os semáforos e dois sensores digitais simulando detecção de veículos.

#### Semáforo 1

| Componente | Pino Arduino |
|------------|--------------|
| Verde1     | 3            |
| Amarelo1   | 2            |
| Vermelho1  | 4            |

#### Semáforo 2

| Componente | Pino Arduino |
|------------|--------------|
| Verde2     | 11           |
| Amarelo2   | 10           |
| Vermelho2  | 9            |

#### Sensores

| Componente        | Pino Arduino |
|------------------|--------------|
| Sensor Semáforo 1 | 8            |
| Sensor Semáforo 2 | 7            |

---

### ⚙️ Lógica de Funcionamento

#### 🚗 Modo com Sensores (Controle Dinâmico)

- Sensor 1 ativo (HIGH) e Sensor 2 inativo (LOW):  
  🔴 Semáforo 2 vermelho | 🟢 Semáforo 1 verde  
- Sensor 2 ativo (HIGH) e Sensor 1 inativo (LOW):  
  🔴 Semáforo 1 vermelho | 🟢 Semáforo 2 verde  

**Transição:** antes de trocar verde para vermelho, semáforo fica 2 segundos amarelo para segurança.

#### ⏱️ Modo Automático (Sem Acionamento dos Sensores)

Quando ambos os sensores estão ativos (HIGH), o ciclo segue:

| Ciclo | Tempo (ms) | Semáforo 1 | Semáforo 2 |
|-------|------------|------------|------------|
| 1     | 0 – 5000   | 🟢 Verde   | 🔴 Vermelho|
| 2     | 5000 – 6000| 🟡 Amarelo | 🔴 Vermelho|
| 3     | 6000 – 9000| 🔴 Vermelho| 🟢 Verde   |
| 4     | 9000 – 10000| 🔴 Vermelho| 🟡 Amarelo |

Ciclo reinicia automaticamente após 10 segundos.

---

### 🔌 Componentes Utilizados

- Arduino Uno (ou compatível)  
- 6 LEDs (2 verdes, 2 amarelos, 2 vermelhos com resistores embutidos)  
- 2 sensores digitais (simulando sensores de presença)  
- Jumpers  
- Protoboard  

> 💡 Observação: LEDs já possuem resistores embutidos — sem necessidade de resistores externos.

---

### 🔧 Ligações dos Componentes

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

### 🧩 Funções do Código

- `apagarTodos()` → Desliga todos os LEDs antes de ativar o próximo conjunto.  
- `amarelo1()` / `amarelo2()` → Transição segura (verde → amarelo → vermelho).  
- Controle com `millis()` → Mede tempo dos ciclos sem travar o programa (evita `delay()`).

---

### 💡 Como Usar

1. Monte o circuito conforme a tabela acima.  
2. Carregue o código no Arduino.  
3. Abra o Monitor Serial (9600 baud) para acompanhar sensores.  
4. Acione os sensores manualmente (ou aproxime objeto para sensores IR).  
5. Observe a mudança automática dos LEDs conforme o modo escolhido.

---

### 👤 Autores

**Thomas Adrian**  
🔗 [GitHub](https://github.com/Thomas-Adrian-Soler-Nilsson)  
<a href="https://www.linkedin.com/in/thomas-adrian" target="_blank">  
  <img src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="LinkedIn" width="30" />  
</a>  

**Samuel Amate**  
🔗 [GitHub](https://github.com/SamuelAmate)  
<a href="https://linkedin.com/in/samuel-amate" target="_blank">  
  <img src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="LinkedIn" width="30" />  
</a>

---

## 🇺🇸 English (EN)

Smart system that controls two traffic lights using digital sensors to detect vehicles, automatically adjusting traffic flow according to demand.

When no sensor is triggered, it operates in automatic mode with predefined timings. If a sensor detects a vehicle, it prioritizes the corresponding traffic light.

### 📋 Description

The system consists of two sets of LEDs representing the traffic lights and two digital sensors simulating vehicle detection.

#### Traffic Light 1

| Component | Arduino Pin |
|-----------|-------------|
| Green1    | 3           |
| Yellow1   | 2           |
| Red1      | 4           |

#### Traffic Light 2

| Component | Arduino Pin |
|-----------|-------------|
| Green2    | 11          |
| Yellow2   | 10          |
| Red2      | 9           |

#### Sensors

| Component            | Arduino Pin |
|---------------------|-------------|
| Traffic Light 1 Sensor | 8         |
| Traffic Light 2 Sensor | 7         |

---

### ⚙️ Operation Logic

#### 🚗 Sensor Mode (Dynamic Control)

- Sensor 1 HIGH and Sensor 2 LOW:  
  🔴 Traffic Light 2 Red | 🟢 Traffic Light 1 Green  
- Sensor 2 HIGH and Sensor 1 LOW:  
  🔴 Traffic Light 1 Red | 🟢 Traffic Light 2 Green  

**Transition:** before switching green to red, light stays yellow for 2 seconds for safety.

#### ⏱️ Automatic Mode (No Sensor Triggered)

When both sensors are HIGH, the cycle follows:

| Cycle | Time (ms) | Traffic Light 1 | Traffic Light 2 |
|-------|------------|----------------|----------------|
| 1     | 0 – 5000   | 🟢 Green       | 🔴 Red         |
| 2     | 5000 – 6000| 🟡 Yellow      | 🔴 Red         |
| 3     | 6000 – 9000| 🔴 Red         | 🟢 Green       |
| 4     | 9000 – 10000| 🔴 Red        | 🟡 Yellow      |

Cycle restarts automatically every 10 seconds.

---

### 🔌 Components Used

- Arduino Uno (or compatible)  
- 6 LEDs (2 green, 2 yellow, 2 red with built-in resistors)  
- 2 digital sensors (simulating vehicle detection)  
- Jumpers  
- Breadboard  

> 💡 Note: LEDs already have built-in resistors — no need for external resistors.

---

### 🔧 Wiring

| Arduino Pin | Component                     |
|-------------|-------------------------------|
| 2           | Yellow LED - Traffic Light 1  |
| 3           | Green LED - Traffic Light 1   |
| 4           | Red LED - Traffic Light 1     |
| 7           | Traffic Light 2 Sensor        |
| 8           | Traffic Light 1 Sensor        |
| 9           | Red LED - Traffic Light 2     |
| 10          | Yellow LED - Traffic Light 2  |
| 11          | Green LED - Traffic Light 2   |

---

### 🧩 Code Functions

- `apagarTodos()` → Turns off all LEDs before activating next set.  
- `amarelo1()` / `amarelo2()` → Performs safe transition (green → yellow → red).  
- Millis-based timing → Measures cycle time without blocking the program (avoids `delay()`).

---

### 💡 How to Use

1. Assemble the circuit according to the table above.  
2. Upload the code to Arduino.  
3. Open the Serial Monitor (9600 baud) to monitor sensors.  
4. Manually trigger sensors (or use object for IR sensors).  
5. Observe automatic LED changes according to the mode.

---

### 👤 Authors

**Thomas Adrian**  
🔗 [GitHub](https://github.com/Thomas-Adrian-Soler-Nilsson)  
<a href="https://www.linkedin.com/in/thomas-adrian" target="_blank">  
  <img src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="LinkedIn" width="30" />  
</a>  

**Samuel Amate**  
🔗 [GitHub](https://github.com/SamuelAmate)  
<a href="https://linkedin.com/in/samuel-amate" target="_blank">  
  <img src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="LinkedIn" width="30" />  
</a>
