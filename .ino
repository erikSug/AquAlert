#include <WiFi.h>
#include <PubSubClient.h>

// CONFIGURAÇÕES
#define NIVEL_AMARELO 200 // Define que nivel tem que estar abaixo para acionar o alerta amarelo
#define NIVEL_VERMELHO 100 // Define que nivel tem que estar abaixo para acionar o alerta vermelho

// PINOS
#define PIN_TRIGGER 12
#define PIN_ECHO 15
#define BUZZER_PIN 14

int buzzer_flag = 1;
int distance = 0;

// Configurações - variáveis editáveis
const char* default_SSID = "Wokwi-GUEST"; // Nome da rede Wi-Fi (No caso utilizando o Wi-Fi do simulador)
const char* default_PASSWORD = ""; // Senha da rede Wi-Fi (No caso utilizando o Wi-Fi do simulador)
const char* default_BROKER_MQTT = "52.237.23.203"; // IP do Broker MQTT
const int default_BROKER_PORT = 1883; // Porta do Broker MQTT
const char* default_TOPICO_PUBLISH_1 = "/TEF/water001/attrs/m"; // Tópico MQTT de envio de informações para Broker LUZ
const char* default_TOPICO_PUBLISH_2 = "/TEF/water001/attrs/v"; // Tópico MQTT de envio de informações para Broker TEMPERATURA
const char* default_ID_MQTT = "fiware_001"; // ID MQTT


char* SSID = const_cast<char*>(default_SSID);
char* PASSWORD = const_cast<char*>(default_PASSWORD);
char* BROKER_MQTT = const_cast<char*>(default_BROKER_MQTT);
int BROKER_PORT = default_BROKER_PORT;
char* TOPICO_PUBLISH_1 = const_cast<char*>(default_TOPICO_PUBLISH_1);
char* TOPICO_PUBLISH_2 = const_cast<char*>(default_TOPICO_PUBLISH_2);
char* ID_MQTT = const_cast<char*>(default_ID_MQTT);

WiFiClient espClient;
PubSubClient MQTT(espClient);
char EstadoSaida = '0';

void initWiFi() {
    delay(10);
    Serial.println("------Conexao WI-FI------");
    Serial.print("Conectando-se na rede: ");
    Serial.println(SSID);
    Serial.println("Aguarde");
    reconectWiFi();
}

void initMQTT() {
    MQTT.setServer(BROKER_MQTT, BROKER_PORT);
}
void VerificaConexoesWiFIEMQTT() {
    if (!MQTT.connected())
        reconnectMQTT();
    reconectWiFi();
}
void reconectWiFi() {
    if (WiFi.status() == WL_CONNECTED)
        return;
    WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(100);
        Serial.print(".");
    }
    Serial.println();
    Serial.println("Conectado com sucesso na rede ");
    Serial.print(SSID);
    Serial.println("IP obtido: ");
    Serial.println(WiFi.localIP());
}

void reconnectMQTT() {
    while (!MQTT.connected()) {
        Serial.print("* Tentando se conectar ao Broker MQTT: ");
        Serial.println(BROKER_MQTT);
        if (MQTT.connect(ID_MQTT)) {
            Serial.println("Conectado com sucesso ao broker MQTT!");
        } else {
            Serial.println("Falha ao reconectar no broker.");
            Serial.println("Haverá nova tentativa de conexão em 2s");
            delay(2000);
        }
    }
}


int lerDistancia(){
  digitalWrite(PIN_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER, LOW);

  int distance_read = pulseIn(PIN_ECHO, HIGH)/58;
  return distance_read;
  // Serial.print("Distance in CM: ");
  // Serial.println(duration / 58);
  // Serial.print("Distance in inches: ");
  // Serial.println(duration / 148);
}

void mandarDistancia(int distance_package){
  String mensagem = String(distance_package);
  MQTT.publish(TOPICO_PUBLISH_2, mensagem.c_str());
}

void mandarAlerta(String message_package){
  MQTT.publish(TOPICO_PUBLISH_1, message_package.c_str());
}

void acionarBuzzer(){
  buzzer_flag = buzzer_flag * -1;
  if (buzzer_flag == -1){
    digitalWrite(BUZZER_PIN, HIGH);
  } else{
    digitalWrite(BUZZER_PIN, LOW);
  }
  
}

void setup(){
  initWiFi();
  initMQTT();
  Serial.begin(115200);
  pinMode(PIN_TRIGGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop(){
  VerificaConexoesWiFIEMQTT();
  distance = lerDistancia();
  mandarDistancia(distance);
  if(distance <= NIVEL_VERMELHO){
    mandarAlerta("vermelho");
    acionarBuzzer();
  }
  else if(distance <= NIVEL_AMARELO){
    mandarAlerta("amarelo");
    acionarBuzzer();
  }
  else{
    mandarAlerta("verde");
  }
  Serial.println(distance);
  delay(1000);
  MQTT.loop();
}