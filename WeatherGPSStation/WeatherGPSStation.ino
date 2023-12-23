//

#include <TinyGPSPlus.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <dht11.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define DHT11PIN 2

static const uint32_t GPSBaud = 9600;
float lat, lon;
int val = 1;
TinyGPSPlus gps;
TinyGPSCustom totalGPGSVMessages(gps, "GPGSV", 1); // $GPGSV sentence, first element
TinyGPSCustom satNumber[4]; // to be initialized later
dht11 DHT11;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

unsigned long last = 0UL;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(GPSBaud);

  pinMode(LED_BUILTIN, OUTPUT);

  for (int i=0; i<4; ++i)
  {
    satNumber[i].begin(gps, "GPGSV", i);
  }

  pinMode(LED_BUILTIN, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop()
{
  // Dispatch incoming characters
  while (Serial1.available() > 0)
    gps.encode(Serial1.read());
    
    display.clearDisplay();

  if (gps.location.isValid())
  {
    digitalWrite(LED_BUILTIN, HIGH);
    display.setCursor(0, 16);
    display.print("Latitude: ");
    display.println(gps.location.lat(), 6);
    display.setCursor(0, 26);
    display.print("Longitude: ");
    display.println(gps.location.lng(), 6);
  }

  if (gps.date.isValid())
  {
    // Display day, month, and year
    display.setCursor(0, 36);
    display.print("Date: ");
    display.print(gps.date.day());
    display.print("/");
    display.print(gps.date.month());
    display.print("/");
    display.println(gps.date.year());
  }

  if (gps.time.isValid())
  {
    // Display hour, minute, and second
    display.setCursor(0, 46);
    display.print("Time: ");
    if ((gps.time.hour()) < 10) display.print(F("0"));
    display.print(gps.time.hour());
    display.print(":");
    if (gps.time.minute() < 10) display.print(F("0"));
    display.print(gps.time.minute());
    display.print(":");
    if (gps.time.second() < 10) display.print(F("0"));
    display.print(gps.time.second());
  }

  if (totalGPGSVMessages.isValid())
  {
    int no = atoi(satNumber[3].value());
    display.setCursor(0, 56);
    display.print("Views: ");
    display.print(no);
  }

  
  if (gps.satellites.isValid())
  {
    display.setCursor(70, 56);
    display.print("Uses: ");
    display.println(gps.satellites.value());
    if (gps.satellites.value() == 0){
      display.setCursor(0, 16);
      display.print("Connecting ... ");
    }
    else if ((gps.satellites.value() > 0) && (gps.location.isValid() == 0)){
      display.setCursor(0, 16);
      display.print("No Fix ");
    }
  }
  
  if (millis() - last > 1000)
  {
    if (gps.charsProcessed() < 10)
    {
      Serial.println(F("WARNING: No GPS data.  Check wiring."));
      display.setCursor(0, 16);
      display.print("No GPS data");
    }

    last = millis();
    digitalWrite(LED_BUILTIN, LOW);
    
    int chk = DHT11.read(DHT11PIN);
    
    display.setCursor(0, 0);
    display.print("Humidity (%): ");
    display.println((float)DHT11.humidity, 2);
    display.setCursor(0, 8);
    display.print("Temp (C): ");
    display.println((float)DHT11.temperature, 2);
    
    display.display();
  }
}
