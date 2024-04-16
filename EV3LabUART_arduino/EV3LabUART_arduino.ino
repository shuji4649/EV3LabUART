void setup() {
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(40, INPUT_PULLUP);
  digitalWrite(19, LOW);
  digitalWrite(18, OUTPUT);
  delay(600);
  // put your setup code here, to run once:
  Serial1.begin(2400);
  Serial.begin(9600);
  Serial.println("Hello");


  //Type
  Serial1.write(0b01000000);
  Serial1.write(0b00100111); //Type number is 39
  Serial1.write(0b01000000 ^ 0b00100111 ^ 0xFF);

  //Modes
  Serial1.write(0b01001001);
  Serial1.write(0);
  Serial1.write(0);
  Serial1.write(0b01001001 ^ 0 ^ 0 ^ 0xFF);
  //SPEED
  Serial1.write(0b01010010);
  Serial1.write(0);
  Serial1.write(0b11000010);
  Serial1.write(1);
  Serial1.write(0);
  Serial1.write(0b01010010 ^ 0 ^ 0b11000010 ^ 1 ^ 0 ^ 0xFF);


  //Mode1
  //Name
  Serial1.write(0b10010000);
  Serial1.write(0);
  Serial1.write(0x6F);
  Serial1.write(0x6C);
  Serial1.write(0x6F);
  Serial1.write(0x63);
  Serial1.write(0b10010000 ^ 0 ^ 0x6F ^ 0x6C ^ 0x6F ^ 0x63 ^ 0xFF);
  //RAW
  Serial1.write(0b10011000);
  Serial1.write(1);
  Serial1.write(0);
  Serial1.write(0);
  Serial1.write(0);
  Serial1.write(0);
  Serial1.write(0);
  Serial1.write(255);
  Serial1.write(127);
  Serial1.write(71);
  Serial1.write(0b10011000 ^ 1 ^ 0 ^ 0 ^ 0 ^ 0 ^ 0 ^ 255 ^ 127 ^ 71 ^ 0xFF);
  //SI
  Serial1.write(0b10011000);
  Serial1.write(3);
  Serial1.write(0);
  Serial1.write(0);
  Serial1.write(0);
  Serial1.write(0);
  Serial1.write(0);
  Serial1.write(255);
  Serial1.write(127);
  Serial1.write(71);
  Serial1.write(0b10011000 ^ 3 ^ 0 ^ 0 ^ 0 ^ 0 ^ 0 ^ 255 ^ 127 ^ 71 ^ 0xFF);
  //string
  Serial1.write(0b10011000);
  Serial1.write(4);
  Serial1.write(100);
  Serial1.write(101);
  Serial1.write(103);
  Serial1.write(0);
  Serial1.write(0);
  Serial1.write(0);
  Serial1.write(0);
  Serial1.write(0);
  Serial1.write(0b10011000 ^ 4 ^ 100 ^ 101 ^ 103 ^ 0xFF);
  //FORMAT
  Serial1.write(0b10010000);
  Serial1.write(128);
  Serial1.write(1);
  Serial1.write(0);
  Serial1.write(3);
  Serial1.write(0);
  Serial1.write(0b10010000 ^ 128 ^ 1 ^ 0 ^ 3 ^ 0 ^ 0xFF);

  Serial1.write(0b00000100);

  while (!Serial1.available()) {
  }
  Serial.println(Serial1.read());
  Serial1.begin(115700);
}

void loop() {
  // put your main code here, to run repeatedly:



  if (Serial1.available()) {
    int date = Serial1.read();
    Serial.println(date);
    Serial1.write(0b11000000);
    if (!digitalRead(40)) {
      Serial1.write(0x02);
      Serial1.write(0b11000000 ^ 0x02 ^ 0xFF);
    } else {
      Serial1.write(0x01);
      Serial1.write(0b11000000 ^ 0x01 ^ 0xFF);
    }
  }
}
