// Definição dos LEDs do Semáforo 1

#define Verde1 4

#define Amarelo1 2

#define Vermelho1 3

// Definição dos LEDs do Semáforo 2

#define Verde2 9

#define Amarelo2 10

#define Vermelho2 11

// Sensores

#define Semaforo1 8 // Sensor 1

#define Semaforo2 7 // Sensor 2

int LeituraSemaforo1 = 0;

int LeituraSemaforo2 = 0;

// Controle do piscar amarelo com millis()

unsigned long tempoAnterior = 0;

int estadoAmarelo = LOW;  // <- Aqui como no seu modelo original

void setup() {

  Serial.begin(9600);

  // Define os LEDs como saída

  pinMode(Verde1, OUTPUT);

  pinMode(Amarelo1, OUTPUT);

  pinMode(Vermelho1, OUTPUT);

  pinMode(Verde2, OUTPUT);

  pinMode(Amarelo2, OUTPUT);

  pinMode(Vermelho2, OUTPUT);

  // Define os sensores como entrada

  pinMode(Semaforo1, INPUT);

  pinMode(Semaforo2, INPUT);

}

void loop() {

  // Leitura dos sensores

  LeituraSemaforo1 = digitalRead(Semaforo1);

  LeituraSemaforo2 = digitalRead(Semaforo2);

  Serial.print("Sensor 1: ");

  Serial.println(LeituraSemaforo1);

  Serial.print("Sensor 2: ");

  Serial.println(LeituraSemaforo2);
 
  // Lógica de controle dos semáforos

  if (LeituraSemaforo1 == HIGH && LeituraSemaforo2 == LOW) {

    apagarTodos();

    digitalWrite(Verde1, HIGH);

    digitalWrite(Vermelho2, HIGH);

  }

  else if (LeituraSemaforo2 == HIGH && LeituraSemaforo1 == LOW) {

    apagarTodos();

    digitalWrite(Vermelho1, HIGH);

    digitalWrite(Verde2, HIGH);

  }

  else if (LeituraSemaforo1 == HIGH && LeituraSemaforo2 == HIGH) {

    apagarTodos();

    digitalWrite(Amarelo1, HIGH);

    digitalWrite(Amarelo2, HIGH);

  }

  else {

    // Nenhum sensor ativo: piscar os amarelos

    piscarAmareloSimples();

  }

}

// Função para apagar todos os LEDs

void apagarTodos() {

  digitalWrite(Verde1, LOW);

  digitalWrite(Amarelo1, LOW);

  digitalWrite(Vermelho1, LOW);

  digitalWrite(Verde2, LOW);

  digitalWrite(Amarelo2, LOW);

  digitalWrite(Vermelho2, LOW);

}

// Função para piscar os LEDs amarelos sem delay, com int estadoAmarelo

void piscarAmareloSimples() {

  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= 500) { // pisca a cada 500 ms

    tempoAnterior = tempoAtual;

    estadoAmarelo = (estadoAmarelo == LOW) ? HIGH : LOW; // alterna LOW ↔ HIGH
 
    digitalWrite(Amarelo1, estadoAmarelo);

    digitalWrite(Amarelo2, estadoAmarelo);
 
    // Apaga outros LEDs

    digitalWrite(Verde1, LOW);

    digitalWrite(Vermelho1, LOW);

    digitalWrite(Verde2, LOW);

    digitalWrite(Vermelho2, LOW);

  }

}

 
