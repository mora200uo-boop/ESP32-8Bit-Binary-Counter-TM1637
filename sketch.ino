#include <Arduino.h>
#include <TM1637Display.h>

// 1. تعريف بنوز شاشة TM1637
#define CLK_PIN 32
#define DIO_PIN 33

TM1637Display display(CLK_PIN, DIO_PIN);

// 2. بنوز الليدات الـ 8 بالترتيب من البت الأصغر (Bit 0) للبت الأكبر (Bit 7)
const int ledPins[] = {23, 22, 21, 19, 18, 5, 17, 16};
const int numBits = 8;

// 3. بن البوش بوتن
const int buttonPin = 4;

int count = 0;              // قيمة العداد الحالية (0 لـ 255)
bool countUp = true;        // اتجاه العد (true = Up / false = Down)
int lastButtonState = HIGH;

unsigned long lastCountTime = 0;
const long countInterval = 300; // سرعة العد بالميلي ثانية

void setup() {
  // تهيئة أرجل الليدات
  for (int i = 0; i < numBits; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  // تهيئة رجل البوتن مع المقاومة الداخلية
  pinMode(buttonPin, INPUT_PULLUP);

  // تشغيل الشاشة وضبط الإضاءة
  display.setBrightness(0x0f); // أعلى شدة إضاءة
  display.showNumberDec(count, false);
}

void loop() {
  // أ) قراءة البوش بوتن لعكس الاتجاه عند الضغط
  int currentButtonState = digitalRead(buttonPin);
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    countUp = !countUp; // عكس الاتجاه
    delay(50);          // Debounce لمنع الاهتزاز
  }
  lastButtonState = currentButtonState;

  // ب) تحديث العداد والليدات والشاشة كل فترة زمنية
  if (millis() - lastCountTime >= countInterval) {
    lastCountTime = millis();

    // 1. عرض القيمة العشرية على الشاشة الـ TM1637
    display.showNumberDec(count, false);

    // 2. إخراج القيمة الثنائية (Binary) على الليدات الـ 8
    for (int bit = 0; bit < numBits; bit++) {
      int bitValue = (count >> bit) & 1; // استخراج قيمة البت
      digitalWrite(ledPins[bit], bitValue);
    }

    // 3. زيادة أو نقصان العداد حسب الاتجاه
    if (countUp) {
      count++;
      if (count > 255) count = 0; // إعادة للصفر بعد 255
    } else {
      count--;
      if (count < 0) count = 255; // للـ 255 إذا قل عن 0
    }
  }
}