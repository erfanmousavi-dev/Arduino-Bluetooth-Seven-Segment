# 🔢 Bluetooth Controlled 7-Segment Display

<div align="center">
  
  [**English**](#english) | [**فارسی**](#persian)
  
</div>

---

<a name="english"></a>
## 📖 Description (English)

This project demonstrates a Bluetooth-controlled 7-segment display using Arduino and an HC-05/HC-06 module. You can send digits (1-9) from a smartphone app, and the display shows the corresponding number.

### Features
- Displays digits 1 through 9 via Bluetooth commands.
- Any other character turns the display off (all segments off).
- Simple single-character control.
- Uses common cathode 7-segment display (active LOW).
- SoftwareSerial for Bluetooth to keep hardware serial free for debugging.

### Components Required
- Arduino board (Uno, Nano, etc.)
- Common cathode 7-segment display (or common anode with code modification)
- 7 resistors (220Ω – 330Ω) – one per segment
- HC-05 / HC-06 Bluetooth module
- Jumper wires and breadboard
- Power supply (USB or battery)

### Wiring Diagram

**7-Segment Display Pins (assuming typical pinout):**

| Segment | Arduino Pin |
|---------|-------------|
| a       | 2           |
| b       | 3           |
| c       | 4           |
| d       | 5           |
| e       | 6           |
| f       | 7           |
| g       | 8           |

**Bluetooth Module:**

| Bluetooth Module | Arduino Pin |
|------------------|-------------|
| TX               | 10 (SoftwareSerial RX) |
| RX               | 9 (SoftwareSerial TX) |

> **Important:** The connections are **reversed** compared to standard labeling (module TX → Arduino pin 10, module RX → Arduino pin 9). This matches the SoftwareSerial definition: `SoftwareSerial bt(10,9);` where pin 10 is RX and pin 9 is TX.

### Logic Level
- The code uses **active LOW** logic: `digitalWrite(segment, LOW)` turns the segment ON.
- `allOff()` sets all pins to HIGH (all segments OFF).
- This configuration works with **common cathode** 7‑segment displays. For common anode, you would need to invert the logic (HIGH = ON, LOW = OFF).

### Bluetooth Commands

| Character | Action |
|-----------|--------|
| `1` ... `9` | Display the corresponding digit |
| Any other character | Turn off all segments |

### How to Use
1. **Build the circuit** as per the wiring diagram. Connect each segment pin through a resistor (220‑330Ω) to the Arduino pin.
2. **Upload** the code to Arduino.
3. **Pair** the Bluetooth module (default password: 1234 or 0000).
4. **Install** any Bluetooth terminal app (e.g., "Arduino Bluetooth Controller", "Serial Bluetooth Terminal").
5. **Connect** to the module and send digits `1` to `9`. Send any other character to clear the display.

### Code Structure
- `SoftwareSerial bt(10,9);` – Bluetooth on pins 10 (RX) and 9 (TX).
- `show_num(x)` – turns on the required segments for digit `x` (1‑9). Calls `allOff()` first to clear previous digit.
- `allOff()` – sets all segment pins to HIGH (turns off all segments).
- In `loop()`, when a character is received via Bluetooth, it calls `show_num()` with the digit value, or `allOff()` for any other character.

### Customization
- **Add digit 0:** Modify the `show_num()` function and add a case for `0`.
- **Change to common anode:** Replace every `digitalWrite(pin, LOW)` with `HIGH`, and every `digitalWrite(pin, HIGH)` with `LOW` (in `allOff()` and each case).
- **Use hardware serial for Bluetooth:** Change `SoftwareSerial` to `Serial` and adjust pins, but then you cannot use Serial monitor for debugging simultaneously.

### Troubleshooting
- **Nothing displays:** Check that your 7‑segment display is common cathode. If it's common anode, invert the logic as mentioned above.
- **Wrong digits:** Verify the segment pin mapping. Different displays may have different pin assignments.
- **Bluetooth not connecting:** Ensure you have connected TX→10 and RX→9 (reversed). Also check baud rate (9600) matches both code and Bluetooth module configuration.

### License
MIT License – free to use, modify, and distribute.

---

<a name="persian"></a>
## 📖 توضیحات (فارسی)

این پروژه یک نمایشگر سون سگمنت (۷ بخشی) است که با استفاده از Arduino و ماژول بلوتوث HC-05/HC-06 کنترل می‌شود. با ارسال اعداد ۱ تا ۹ از طریق اپلیکیشن موبایل، عدد مربوطه روی نمایشگر نشان داده می‌شود.

### امکانات
- نمایش ارقام ۱ تا ۹ با دستورات بلوتوث.
- هر کاراکتر دیگری باعث خاموش شدن تمام بخش‌ها می‌شود.
- کنترل با دستورات تک کاراکتری ساده.
- استفاده از سون سگمنت کاتد مشترک (active LOW).
- استفاده از SoftwareSerial برای بلوتوث به منظور آزاد نگه داشتن سریال سخت‌افزاری برای دیباگ.

### قطعات مورد نیاز
- برد Arduino (Uno، Nano یا مشابه)
- نمایشگر ۷ بخشی (سون سگمنت) **کاتد مشترک** (یا آند مشترک با تغییر کد)
- ۷ عدد مقاومت ۲۲۰ تا ۳۳۰ اهم (یکی برای هر بخش)
- ماژول بلوتوث HC-05 یا HC-06
- برد بورد و سیم جامپر
- منبع تغذیه (USB یا باتری)

### نقشه اتصالات

**پین‌های سون سگمنت (با فرض پین‌بندی معمول):**

| بخش (Segment) | پین آردوینو |
|---------------|--------------|
| a             | 2            |
| b             | 3            |
| c             | 4            |
| d             | 5            |
| e             | 6            |
| f             | 7            |
| g             | 8            |

**ماژول بلوتوث:**

| ماژول بلوتوث | پین آردوینو |
|--------------|--------------|
| TX           | 10 (RX نرم‌افزاری) |
| RX           | 9 (TX نرم‌افزاری) |

> **نکته مهم:** اتصالات برعکس نام‌گذاری معمول است (TX ماژول → پین ۱۰ آردوینو، RX ماژول → پین ۹ آردوینو). این مطابق تعریف `SoftwareSerial bt(10,9);` است که پین ۱۰ به عنوان RX و پین ۹ به عنوان TX تعریف شده.

### منطق سطح ولتاژ
- کد از **منطق LOW فعال** استفاده می‌کند: `digitalWrite(segment, LOW)` بخش مورد نظر را روشن می‌کند.
- تابع `allOff()` همه پین‌ها را HIGH می‌کند (همه بخش‌ها خاموش).
- این تنظیمات برای نمایشگرهای **کاتد مشترک** کار می‌کند. برای آند مشترک باید منطق را معکوس کنید (HIGH = روشن، LOW = خاموش).

### دستورات بلوتوث

| کاراکتر | عملیات |
|----------|--------|
| `1` تا `9` | نمایش رقم متناظر |
| هر کاراکتر دیگر | خاموش کردن همه بخش‌ها |

### نحوه استفاده
1. **مدار** را مطابق نقشه ببندید. هر پین سون سگمنت را از طریق یک مقاومت به پین آردوینو متصل کنید.
2. **کد** را روی Arduino آپلود کنید.
3. **ماژول بلوتوث** را جفت‌سازی کنید (رمز پیش‌فرض ۱۲۳۴ یا ۰۰۰۰).
4. **یک اپلیکیشن ترمینال بلوتوث** (مانند "Arduino Bluetooth Controller" یا "Serial Bluetooth Terminal") نصب کنید.
5. **به ماژول متصل شوید** و ارقام ۱ تا ۹ را ارسال کنید. برای پاک کردن صفحه، هر کاراکتر دیگری ارسال کنید.

### ساختار کد
- `SoftwareSerial bt(10,9);` – بلوتوث روی پین‌های ۱۰ (RX) و ۹ (TX).
- `show_num(x)` – بخش‌های مورد نیاز برای رقم `x` (۱‑۹) را روشن می‌کند. ابتدا `allOff()` را صدا می‌زند تا رقم قبلی پاک شود.
- `allOff()` – همه پین‌های سگمنت را HIGH می‌کند (خاموشی کامل).
- در `loop()`، هنگام دریافت کاراکتر از بلوتوث، اگر رقم ۱‑۹ باشد، رقم متناسب نمایش داده می‌شود، در غیر این صورت همه بخش‌ها خاموش می‌شوند.

### سفارشی‌سازی
- **اضافه کردن رقم ۰:** تابع `show_num()` را تغییر داده و یک case برای `0` اضافه کنید.
- **تغییر به آند مشترک:** هر `digitalWrite(pin, LOW)` را به `HIGH` و هر `HIGH` را به `LOW` تبدیل کنید (در `allOff()` و هر case).
- **استفاده از سریال سخت‌افزاری برای بلوتوث:** `SoftwareSerial` را به `Serial` تغییر دهید و پین‌ها را تنظیم کنید، اما در این صورت نمی‌توانید همزمان از مانیتور سریال برای دیباگ استفاده کنید.

### عیب‌یابی
- **چیزی نمایش داده نمی‌شود:** مطمئن شوید سون سگمنت شما از نوع کاتد مشترک است. اگر آند مشترک است، منطق را معکوس کنید.
- **ارقام اشتباه:** نقشه پین‌های سگمنت را بررسی کنید. ممکن است نمایشگرهای مختلف پین‌بندی متفاوتی داشته باشند.
- **بلوتوث وصل نمی‌شود:** اطمینان حاصل کنید که TX→۱۰ و RX→۹ (برعکس) وصل شده باشد. همچنین نرخ بود (۹۶۰۰) را با پیکربندی ماژول بلوتوث بررسی کنید.

### مجوز
مجوز MIT – آزاد برای استفاده، تغییر و توزیع.

---

**Enjoy displaying digits wirelessly! 📟**  
**از نمایش اعداد بی‌سیم لذت ببرید!**
