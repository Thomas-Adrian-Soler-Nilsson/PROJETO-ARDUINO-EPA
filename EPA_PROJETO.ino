// Definição dos LEDs do Semáforo 1
#define Verde1 3
#define Amarelo1 2
#define Vermelho1 4
 
// Definição dos LEDs do Semáforo 2
#define Verde2 11
#define Amarelo2 10
#define Vermelho2 9
 
// Sensores
#define Semaforo1 8 // Sensor 1
#define Semaforo2 7 // Sensor 2
int LeituraSemaforo1 = 0;
int LeituraSemaforo2 = 0;
 
// Controle do piscar amarelo com millis()
unsigned long tempoAnterior = 0;
unsigned long tempoInicial = 0;
unsigned long tempoAtual = 0;
 
 
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
  tempoInicial = millis();
}
void loop() {
  // Leitura dos sensores
  LeituraSemaforo1 = digitalRead(Semaforo1);
  LeituraSemaforo2 = digitalRead(Semaforo2);
  Serial.print("Sensor 1: ");
  Serial.println(LeituraSemaforo1);
  Serial.print("Sensor 2: ");
  Serial.println(LeituraSemaforo2);
  tempoAtual = millis() - tempoInicial;
 
  // Lógica de controle dos semáforos
  if (LeituraSemaforo1 == HIGH && LeituraSemaforo2 == LOW && (digitalRead(Verde2) == HIGH || digitalRead(Amarelo2) == HIGH)) {
    amarelo2();
    apagarTodos();
    digitalWrite(Verde1, HIGH);
    digitalWrite(Vermelho2, HIGH);
  }
 
  else if (LeituraSemaforo1 == LOW && LeituraSemaforo2 == HIGH && (digitalRead(Verde1) == HIGH || digitalRead(Amarelo1) == HIGH)) {
    amarelo1();
    apagarTodos();
    digitalWrite(Vermelho1, HIGH);
    digitalWrite(Verde2, HIGH);
  }
 
  else if (LeituraSemaforo1 == HIGH && LeituraSemaforo2 == LOW) {
    apagarTodos();
    digitalWrite(Verde1, HIGH);
    digitalWrite(Vermelho2, HIGH);
  }
  else if (LeituraSemaforo2 == HIGH && LeituraSemaforo1 == LOW) {
    apagarTodos();
    digitalWrite(Vermelho1, HIGH);
    digitalWrite(Verde2, HIGH);
  }
  //1° ciclo - Semaforo 1 = Verde - Semaforo 2 = Vermelho - 0:00 - 0:05
  else if (LeituraSemaforo1 == HIGH && LeituraSemaforo2 == HIGH && tempoAtual < 5000) {
    apagarTodos();
    digitalWrite(Verde1, HIGH);
    digitalWrite(Vermelho2, HIGH);
  }
  //2° ciclo - Semaforo 1 = Amarelo - Semaforo 2 = Vermelho - 0:05 - 0:06
  else if (LeituraSemaforo1 == HIGH && LeituraSemaforo2 == HIGH && tempoAtual >= 5000 && tempoAtual < 6000) {
    digitalWrite(Verde1, LOW);
    digitalWrite(Amarelo1, HIGH);
  }
  //3° ciclo - Semaforo 1 = Vermelho - Semaforo 2 = Verde - 0:06 - 0:09
  else if (LeituraSemaforo1 == HIGH && LeituraSemaforo2 == HIGH && tempoAtual >= 6000 && tempoAtual < 9000) {
    apagarTodos();
    digitalWrite(Vermelho1, HIGH);
    digitalWrite(Verde2, HIGH);
  }
  //4° ciclo - Semaforo 1 = Vermelho - Semaforo 2 = Verde - 0:09 - 0:10
  else if (LeituraSemaforo1 == HIGH && LeituraSemaforo2 == HIGH && tempoAtual >= 9000 && tempoAtual < 10000) {
    digitalWrite(Verde2, LOW);
    digitalWrite(Amarelo2, HIGH);
  }
  else if (LeituraSemaforo1 == HIGH && LeituraSemaforo2 == HIGH && tempoAtual >= 10000) {
    tempoInicial = millis();
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
 
void amarelo1() {
  digitalWrite(Verde1, LOW);
  digitalWrite(Amarelo1, HIGH);
  delay(2000);
  apagarTodos();
  tempoAtual = millis() - 6000;
}
 
void amarelo2() {
  digitalWrite(Verde2, LOW);
  digitalWrite(Amarelo2, HIGH);
  delay(2000);
  apagarTodos();
  tempoAtual = millis() - 0;
}
