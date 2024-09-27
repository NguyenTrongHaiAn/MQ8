
const int AOUTpin = 0; // Chân AOUT của cảm biến hydrogen nối vào chân analog A0
const int DOUTpin = 8; // Chân DOUT của cảm biến hydrogen nối vào chân digital D8
const int BUZZER = 2;  // Buzzer nối vào chân digital D2

int limit;
int value;

void setup() {
  Serial.begin(115200);    // Cài đặt tốc độ truyền Serial
  pinMode(DOUTpin, INPUT); // Cài đặt chân DOUT là đầu vào của Arduino
  pinMode(BUZZER, OUTPUT); // Cài đặt chân BUZZER là đầu ra cho buzzer
}

void loop() {
  value = analogRead(AOUTpin); // Đọc giá trị analog từ chân AOUT của cảm biến hydrogen
  limit = digitalRead(DOUTpin); // Đọc giá trị digital từ chân DOUT của cảm biến

  Serial.print("Giá trị Hydrogen: ");
  Serial.println(value); // In giá trị hydrogen ra Serial Monitor
  Serial.print("Ngưỡng: ");
  Serial.println(limit); // In giá trị ngưỡng (LOW hoặc HIGH)

  delay(100);

  if (limit == HIGH) {
    digitalWrite(BUZZER, HIGH); // Nếu vượt ngưỡng, bật buzzer
  } else {
    digitalWrite(BUZZER, LOW);  // Nếu không vượt ngưỡng, tắt buzzer
  }
}
