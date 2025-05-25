#define ACCESSKEY "xxXXXXXXXXXX:XXXXXXXXXXX"    // Antares account access key
#define WIFISSID "X282 2G"                      // Wi-Fi SSID to connect to
#define PASSWORD "itssurabaya"                  // Wi-Fi password

#define projectName "LoRa_Gateway"                 // Name of the application created in Antares
#define deviceName "xx:xx:xx:xx:xx:xx"             // DevUI of AMI Module

// Inisialisasi Objek Antares
AntaresESPHTTP antaresHTTP(ACCESSKEY);
AntaresESPMQTT antaresMQTT(ACCESSKEY);

WiFiClient myClient;

void setup(){
antaresMQTT.wifiConnection(WIFISSID, PASSWORD);
antaresMQTT.setMqttServer();
}

void loop(){
antaresMQTT.checkMqttConnection();
antaresMQTT.add("devUI", devUI);
antaresMQTT.add("time_at_device", timeAtDevice);
...
antaresMQTT.add("power_factor", powerFactor);
antaresMQTT.publish(projectName, deviceName);
}