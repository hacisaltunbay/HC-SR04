int trig = 13;  //sensör ve ledlerin hangi pinlerde olduğu tanımlanır. 
int echo = 12;
long sure,mesafe;
int led_k = 5;
int led_y = 6;

void setup() {
  pinMode(trig, OUTPUT);   //pinlerin giriş-çıkış olduğu belirtilir.
  pinMode(echo, INPUT);
  pinMode(led_k, OUTPUT);
  pinMode(led_y, OUTPUT);
 }

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);   //10 mikrosaniyelik ses dalgası göndermek için trig pini aktifleştirilir.
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  sure = pulseIn(echo, HIGH);
  mesafe = sure/58;         //ses hızının sıcaklığa bağlı olarak cm/ms cinsinden hesaplama formülü
  delay(100);

  if (mesafe<25){          //mesafe 25 cm'den küçükse kırmızı değilse yeşil led yanar.
    digitalWrite(led_k, HIGH);
    digitalWrite(led_y, LOW);
    }
    else {
      digitalWrite(led_k, LOW);
      digitalWrite(led_y, HIGH);
      }
}
