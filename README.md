# 🚦 Projeto: Semáforo Inteligente com Arduino

Este projeto simula um **sistema de semáforo inteligente** utilizando o Arduino. Dois sensores detectam a presença de veículos e controlam dois semáforos de forma automática. Quando nenhum sensor detecta veículos, os semáforos piscam em amarelo como forma de alerta.

---

## 📋 Descrição

O sistema conta com dois sensores digitais (um para cada direção) e dois conjuntos de LEDs representando os semáforos:

- **Semáforo 1**: Verde1 (pino 4), Amarelo1 (pino 2), Vermelho1 (pino 3)
- **Semáforo 2**: Verde2 (pino 9), Amarelo2 (pino 10), Vermelho2 (pino 11)

### Lógica:

- 🚗 Sensor 1 ativo, Sensor 2 inativo → Semáforo 1 verde, Semáforo 2 vermelho  
- 🚗 Sensor 2 ativo, Sensor 1 inativo → Semáforo 2 verde, Semáforo 1 vermelho  
- 🚦  Nenhum sensor ativo → ambos amarelos piscando intermitente
- ❌ Ambos sensores ativos → ambos amarelos acesos (alerta)

---

## 🔌 Componentes Utilizados

- 1x Arduino Uno (ou compatível)
- 6x LEDs (2 verdes, 2 amarelos, 2 vermelhos)
- 2x Sensores digitais (simulando sensores de presença)
- Resistores de 220Ω
- Jumpers
- Protoboard

---

## 🔧 Ligações dos Componentes

| Pino Arduino | Componente               |
|--------------|--------------------------|
| 2            | LED Amarelo - Semáforo 1 |
| 3            | LED Vermelho - Semáforo 1|
| 4            | LED Verde - Semáforo 1   |
| 7            | Sensor Semáforo 2        |
| 8            | Sensor Semáforo 1        |
| 9            | LED Verde - Semáforo 2   |
| 10           | LED Amarelo - Semáforo 2 |
| 11           | LED Vermelho - Semáforo 2|

👤 Autores

Thomas Adrian
https://github.com/Thomas-Adrian-Soler-Nilsson
<p align="left">
  <a href="https://www.linkedin.com/in/thomas-adrian" target="blank">
    <img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="https://www.linkedin.com/in/thomas-adrian" height="30" width="40" />
  </a>
</p>

Samuel Amate
https://github.com/SamuelAmate
<p align="left">
  <a href="https://linkedin.com/in/samuel-amate" target="blank">
    <img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="https://linkedin.com/in/samuel-amate" height="30" width="40" />
  </a>
</p>
