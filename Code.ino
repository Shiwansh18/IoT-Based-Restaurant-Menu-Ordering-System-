#include <Adafruit_GFX.h> // Core graphics library
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
#include <SoftwareSerial.h>
SoftwareSerial bluetoothSerial(0, 11); // RX, TX
int rowIndex = 0;
String msg ;
#define YP A2 // must be an analog pin, use "An" notation!
#define XM A3 // must be an analog pin, use "An" notation!
#define YM 8 // can be a digital pin
#define XP 9 // can be a digital pin
#define TS_MINX 125
#define TS_MINY 85
#define TS_MAXX 965
#define TS_MAXY 905
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
// optional
#define LCD_RESET A4
#define REDBAR_MINX 80
#define GREENBAR_MINX 130
#define BLUEBAR_MINX 180
#define BAR_MINY 30
#define BAR_HEIGHT 250
#define BAR_WIDTH 30
MCUFRIEND_kbv tft;
#define BLACK 0x0000
int BLUE = tft.color565(50, 50, 255);
#define DARKBLUE 0x0010
#define VIOLET 0x8888
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
#define GREY tft.color565(64, 64, 64);
#define GOLD 0xFEA0

#define BROWN 0xA145
#define SILVER 0xC618
#define LIME 0x07E0
void drawHome()
{
tft.fillScreen(WHITE);
tf.drawRoundRect(0, 0, 319, 240, 8, WHITE); //Page border
tft.fillRoundRect(10, 30, 100, 40, 8, GOLD);
tft.drawRoundRect(10, 30, 100, 40, 8, WHITE); //Dish1 
tft.fillRoundRect(10, 80, 100, 40, 8, GOLD);
tft.drawRoundRect(10, 80, 100, 40, 8, WHITE); //Dish2
tft.fillRoundRect(10, 130, 100, 40, 8, GOLD); //Dish3
tft.drawRoundRect(10, 130, 100, 40, 8, WHITE);
tft.fillRoundRect(10, 180, 220, 40, 8, CYAN);
tft.drawRoundRect(10, 180, 220, 40, 8, WHITE); //Call Waiter
tft.fillRoundRect(130, 30, 100, 40, 8, GOLD);
tft.drawRoundRect(130, 30, 100, 40, 8, WHITE); //Dish4
tft.fillRoundRect(130, 80, 100, 40, 8, GOLD);
tft.drawRoundRect(130, 80, 100, 40, 8, WHITE); //Dish5
tft.fillRoundRect(130, 130, 100, 40, 8, GOLD);
tft.drawRoundRect(130, 130, 100, 40, 8, WHITE); //Dish6
tft.fillRoundRect(10, 230, 220, 40, 8, MAGENTA);
tft.drawRoundRect(10, 230, 220, 40, 8, WHITE); //Bill
tft.fillRoundRect(10, 280, 220, 40, 8, GREEN);
tft.drawRoundRect(10, 280, 220, 40, 8, WHITE); //Bill
tft.setCursor(62, 0);
tft.print(" Dish1");
tft.setCursor(15, 87);
tft.print(" Dish2");
tft.setCursor(15, 137);
tft.print(" Dish3");
tft.setCursor(50, 187);
tft.print(" Call Waiter");
tft.setCursor(135, 37);
tft.print(" Dish4");
tft.setCursor(135, 87);
tft.print(" Dish5");
tft.setCursor(135, 137);
tft.print(" Dish6");
tft.setCursor(85, 237);
Serial.println("Ready to take Order ...");
delay(500);
tft.fillScreen(BLACK);
tft.setTextSize(3);
tft.setTextColor(WHITE);
tft.setCursor(50, 140);

tft.print("Loading...");
for (int i; i < 250; i++)
{
tft.fillRect(BAR_MINY - 10, BLUEBAR_MINX, i, 10, RED);
delay(0.000000000000000000000000000000000000000000000000001);
}
tft.fillScreen(BLACK);
drawHome();
pinMode(13, OUTPUT);
}
#define MINPRESSURE 10
#define MAXPRESSURE 1000
void transmit()
{ 
Serial.println(msg);
}
void loop()
{
digitalWrite(13, HIGH);
TSPoint p = ts.getPoint();
digitalWrite(13, LOW);
pinMode(XM, OUTPUT);
pinMode(YP, OUTPUT);
if (p.z > ts.pressureThreshhold)
{
p.x = map(p.x, TS_MAXX, TS_MINX, 0, 320);
p.y = map(p.y, TS_MAXY, TS_MINY, 0, 240);
if (p.x > 220 && p.x < 240 && p.y > 120 && p.y < 160 && p.z > MINPRESSURE && p.z 
< MAXPRESSURE)
{
msg = "Dish1 Ordered";
transmit();
tft.fillRoundRect(10, 30, 100, 40, 8, WHITE);
delay(70);
tft.fillRoundRect(10, 30, 100, 40, 8, GOLD);
tft.drawRoundRect(10, 30, 100, 40, 8, WHITE);
tft.setCursor(15, 37);
tft.println(" Dish1");
delay(1000);
}
if (p.x > 180 && p.x < 200 && p.y > 120 && p.y < 160)
{
msg = "Dish2 Ordered";
transmit();
tft.fillRoundRect(10, 80, 100, 40, 8, WHITE);
delay(70);
15
tft.fillRoundRect(10, 80, 100, 40, 8, GOLD);
tft.drawRoundRect(10, 80, 100, 40, 8, WHITE);
tft.setCursor(15, 87);
tft.println(" Dish2");
delay(1000); 
}
if (p.x > 140 && p.x < 160 && p.y > 120 && p.y < 160)
{
msg = "Dish3 Ordered";
transmit();
tft.fillRoundRect(10, 130, 100, 40, 8, WHITE); //rgb led
delay(70);
tft.fillRoundRect(10, 130, 100, 40, 8, GOLD); //rgb led
tft.drawRoundRect(10, 130, 100, 40, 8, WHITE); //rgb led
tft.setCursor(15, 137);
tft.print(" Dish3");
delay(1000); 
}
if (p.x > 100 && p.x < 120 && p.y > 70 && p.y < 160)
{
msg = "Calling Waiter";
transmit();
tft.fillRoundRect(10, 180, 220, 40, 8, WHITE);
delay(70);
tft.fillRoundRect(10, 180, 220, 40, 8, CYAN);
tft.drawRoundRect(10, 180, 220, 40, 8, WHITE);
tft.setCursor(50, 187);
tft.print(" Call Waiter");
delay(1000);
}
if (p.x > 220 && p.x < 240 && p.y > 70 && p.y < 110)
{
msg = "Dish4 Ordered";
transmit();
tft.fillRoundRect(130, 30, 100, 40, 8, WHITE);
delay(70);
tft.fillRoundRect(130, 30, 100, 40, 8, GOLD);
tft.drawRoundRect(130, 30, 100, 40, 8, WHITE);
tft.setCursor(135, 37);
tft.print(" Dish4");
delay(1000);
}
if (p.x > 180 && p.x < 200 && p.y > 70 && p.y < 110 )
{
msg = "Dish5 Ordered";
transmit();

tft.fillRoundRect(130, 80, 100, 40, 8, WHITE);
delay(70);
tft.fillRoundRect(130, 80, 100, 40, 8, GOLD);
tft.drawRoundRect(130, 80, 100, 40, 8, WHITE);
tft.setCursor(135, 87);
tft.print(" Dish5");
delay(1000);
}
if (p.x > 140 && p.x < 160 && p.y > 70 && p.y < 110)
{
msg = "Dish6 Ordered";
transmit();
tft.fillRoundRect(130, 130, 100, 40, 8, WHITE);
delay(70);
tft.fillRoundRect(130, 130, 100, 40, 8, GOLD);
tft.drawRoundRect(130, 130, 100, 40, 8, WHITE);
tft.setCursor(135, 137);
tft.print(" Dish6");
delay(1000);
}
if (p.x > 60 && p.x < 80 && p.y > 70 && p.y < 160)
{
msg = "Customer Bill";
transmit();
tft.fillRoundRect(10, 230, 220, 40, 8, WHITE);
delay(70);
tft.fillRoundRect(10, 230, 220, 40, 8, MAGENTA);
tft.drawRoundRect(10, 230, 220, 40, 8, WHITE);
tft.setCursor(85, 237);
tft.print(" Bill");
delay(1000);
}
if (p.x > 20 && p.x < 40 && p.y > 70 && p.y < 160)
{
msg = "Water";
transmit();
tft.fillRoundRect(10, 280, 220, 40, 8, WHITE);
delay(70);
tft.fillRoundRect(10, 280, 220, 40, 8, GREEN);
tft.drawRoundRect(10, 280, 220, 40, 8, WHITE);
tft.setCursor(95, 295);
tft.print("Water");
delay(1000);
}
}
}