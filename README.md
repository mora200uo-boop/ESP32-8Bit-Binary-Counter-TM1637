# ESP32 8-Bit Binary Counter with TM1637 & Push Button

مشروع عداد ثنائي 8-بت باستخدام **ESP32** يعرض القيمة العشرية على شاشة **TM1637 (4-Digit 7-Segment)** والقيمة الثنائية (Binary) عبر **8 ليدات**. يحتوي المشروع على **زرار (Push Button)** لعكس اتجاه العد (تصاعدي/تنازلي).

## 🛠️ المكونات (Hardware Required)
- Microcontroller: **ESP32**
- Display: **TM1637 4-Digit 7-Segment Module**
- LEDs: **8x LEDs** with 220Ω Resistors
- Button: **1x Push Button**
- Wires & Breadboard

## 🔌 مخطط التوصيل (Circuit Diagrams)

### جدول التوصيل (Pinout):
| المكون (Component) | بن الـ ESP32 |
| :--- | :--- |
| **TM1637 CLK** | GPIO 32 |
| **TM1637 DIO** | GPIO 33 |
| **TM1637 VCC / GND** | 3.3V / GND |
| **Push Button** | GPIO 4 & GND |
| **LED 0 (LSB) -> LED 7 (MSB)** | GPIO 23, 22, 21, 19, 18, 5, 17, 16 |
 
![Wiring Diagram](wiring.png)

## 🌐 التجربة عبر Wokwi Simulation
يمكنك تجربة وتعديل المشروع مباشرة عبر المتصفح:
👉 [https://wokwi.com/projects/477050442745271297)

## 💻 طريقة التشغيل
1. قم بتحميل كود `sketch.ino`.
2. قم بتثبيت مكتبة `TM1637Display` في Arduino IDE.
3. اختر بوردة **ESP32 Dev Module** وارفع الكود.
