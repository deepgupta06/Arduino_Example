#include <CoinMarketCapApi.h>

/*******************************************************************
 *  An example of getting ticker info from coinmarketcap.com       *
 *                                                                 *
 *  Written by Brian Lough                                         *
 *******************************************************************/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

//------- Install From Library Manager -------
#include <ArduinoJson.h>


//------- Replace the following! ------
char ssid[] = "Hi3d3n";       // your network SSID (name)
char password[] = "janinaja";  // your network key
LiquidCrystal_I2C lcd(0x27, 16, 2);


WiFiClientSecure client;
CoinMarketCapApi api(client);

// CoinMarketCap's limit is "no more than 10 per minute"
// Make sure to factor in if you are requesting more than one coin.
unsigned long api_mtbs = 60000; //mean time between api requests
unsigned long api_due_time = 0;

void setup() {

  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  lcd.clear();
  lcd.print("Connecting Wifi");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    for(int i=0; i<=14; i++)
    {
    lcd.setCursor(i,1);
    lcd.println(".");
    delay(200);
    }
  }
  Serial.println("");
  Serial.println("WiFi connected");
  delay(500);
  lcd.clear();
  lcd.print("Wifi Connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
}

void printTickerData(String ticker) {
  Serial.println("---------------------------------");
  Serial.println("Getting ticker data for " + ticker);


  // Ticker unfortunately is not the symbol for some reason.
  // Go to CoinMarketCap.com and select the coin you would like to check
  // The ticker name makes up the last part of the URL
  // e.g: http://coinmarketcap.com/currencies/bitcoin/ , "bitcoin" is the ticker value

  // Currency is optional, so you can pass only ticker if you want.
  // Check out the currency drop down on CoinMarketCap.com to get available values
  CMCTickerResponse response = api.GetTickerInfo(ticker, "eur");
  if (response.error == "") {
    Serial.print("ID: ");
    Serial.println(response.id);
    Serial.print("Name: ");
    Serial.println(response.name);
    lcd.clear();
    lcd.print(response.name);
    Serial.print("Symbol: ");
    Serial.println(response.symbol);

    Serial.print("Rank: ");
    Serial.println(response.rank);

    Serial.print("Price in USD: ");
    lcd.setCursor(0,1);
    lcd.print("$");
    lcd.print(response.price_usd);
    Serial.println(response.price_usd);
    Serial.print("Price in BTC: ");
    Serial.println(response.price_btc);

    Serial.print("24h Volume USD: ");
    Serial.println(response.volume_usd_24h);
    Serial.print("Market Cap USD: ");
    Serial.println(response.market_cap_usd);

    Serial.print("Available Supply: ");
    Serial.println(response.available_supply);
    Serial.print("Total Supply: ");
    Serial.println(response.total_supply);

    Serial.print("Percent Change 1h: ");
    Serial.println(response.percent_change_1h);
    Serial.print("Percent Change 24h: ");
    lcd.setCursor(9,0);
    lcd.print(response.percent_change_24h);
    lcd.print("%");
    Serial.println(response.percent_change_24h);
    Serial.print("Percent Change 7d: ");
    Serial.println(response.percent_change_7d);
    Serial.print("Last Updated: ");
    Serial.println(response.last_updated);

    // These fields will not come back if you do not request a currency
    Serial.print("Price in requested currecy: ");
    Serial.println(response.price_currency);
    Serial.print("24h Volume in requested currency: ");
    Serial.println(response.volume_currency_24h);
    Serial.print("Market Cap in requested currency: ");
    Serial.println(response.market_cap_currency);


  } else {
    Serial.print("Error getting data: ");
    Serial.println(response.error);
  }
  Serial.println("---------------------------------");
}

void loop() {
  unsigned long timeNow = millis();
  if ((timeNow > api_due_time))  {
    printTickerData("bitcoin");
    delay(5000);
    printTickerData("ethereum");
    delay(5000);
    printTickerData("ripple");
    delay(5000);
   
  }
}
