void setup() {
  // Setup pins
  pinMode(D6, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D3, OUTPUT);
}

void loop() {
  // Get random integers
  uint16_t a = random(999),
           b = random(999),
           c = random(999),
           d = random(999);

  if (d > a && d > b && d > c) {
    for (uint8_t i = 0; i < 100; i++) {
      // Toggle the lights
      bool is_even = i & 1;
      
      digitalWrite(D6, is_even ? HIGH : LOW);
      digitalWrite(D5, is_even ? HIGH : LOW);
      digitalWrite(D3, is_even ? HIGH : LOW);

      // Sleep for 1/10th of a second, which makes up for the 10 seconds
      delay(100);
    }
  } else {
    // Toggle the lights
     digitalWrite(D6, (a > b || a < c) ? HIGH : LOW);
     digitalWrite(D5, (c > a && a < b) ? HIGH : LOW);
     digitalWrite(D3, (b > c && b > a && c < a) ? HIGH : LOW);

     // Sleep for 10 seconds
     delay(10000);
  }
}
