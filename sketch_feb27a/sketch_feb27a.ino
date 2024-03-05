// Morse code
#define DOT true
#define LINE false

void toggle_all(const bool state) {
  digitalWrite(D6, state);
  digitalWrite(D5, state);
  digitalWrite(D3, state);
}

void morse(const bool unit) {
  toggle_all(HIGH);
  delay(unit == DOT ? 500 : 1500);
  toggle_all(LOW);
  delay(250);
}

// Program
void setup() {
  pinMode(D6, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D3, OUTPUT);
}

void loop() {
  // f
  morse(DOT);
  morse(DOT);
  morse(LINE);
  morse(DOT);
  delay(500);

  // R
  morse(DOT);
  morse(LINE);
  morse(DOT);
  delay(500);
  
  // E

  morse(DOT);
  delay(500);
  
  // D
  morse(LINE);
  morse(DOT);
  morse(DOT);
  
  delay(1500);
}
