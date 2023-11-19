// INCLUSÃO DE BIBLIOTECAS
#include "DHT.h"
#include <MicroLCD.h>



// DEFINIÇÕES DE PINOS
#define pinDHT 7
#define pinUmid 8
#define pinDesumid 9

// DEFINIÇÕES
#define UR_MAX 65    // Umidade Relativa Maxima
#define UR_IDEAL 60  // Umidade Alvo
#define UR_MIN 55    // Umidade Relativa Minima

#define INTERVALO_LEITURA 10000  // Intervalo minimo de leitura do DHT22 ~2s \
                                // Intervalo minimo do AdafruitIO ~7s

// INSTANCIANDO OBJETOS
DHT dht(pinDHT, DHT22);
LCD_SSD1306 lcd;  //LCD_SSD1306   //LCD_SH1106   //LCD_PCD8544

// DECLARAÇÃO DE VARIÁVEIS
float umidade = 55.0;
float umidadeAnt = 55.0;

int estado = 0;  // 0 = Ar ideal | -1 = Umidificador ligado | 1 = Ar condicionado Ligado
unsigned long controleLeitura;

void setup() {
  Serial.begin(9600);

  // Configura os pinos como OUTPUT
  pinMode(pinDesumid, OUTPUT);
  pinMode(pinUmid, OUTPUT);

  digitalWrite(pinUmid, LOW);
  digitalWrite(pinDesumid, LOW);

  // Inicializa o Sensor
  dht.begin();

}

void loop() {
  if (millis() - controleLeitura > INTERVALO_LEITURA) {
    float leitura = dht.readHumidity();
    controleLeitura = millis();
    Serial.println(leitura);

    switch (estado) {
      case 0:                    // Leitura Anterior = Indicando Umidade ideal | Umidificador e Ar desligados
        if (umidade < UR_MIN) {  // Se Leitura Atual = Indicando Ar muito Seco
          estado = -1;

          digitalWrite(pinUmid, HIGH);


        } else if (umidade > UR_MAX) {  // Se Leitura Atual = Indicando Ar muito umido
          estado = 1;

          digitalWrite(pinDesumid, HIGH);
        }
        break;

      case -1:                      // Leitura Anterior = Indicando Umidade baixa | Umidificador ligado
        if (umidade >= UR_IDEAL) {  // Se Leitura Atual = Indicando Umidade subiu para o nível ideal
          estado = 0;

          digitalWrite(pinUmid, LOW);

        }
        break;

      case 1:                       // Leitura Anterior = Indicando Umidade alta | Ar ligado
        if (umidade <= UR_IDEAL) {  // Se Leitura Atual = Indicando Umidade abaixou para o nível ideal
          estado = 0;

          digitalWrite(pinDesumid, LOW);
        }
        break;
    }
  }

  // VERIFICA SE HOUVE VARIAÇÃO SIGNIFICATIVA NA LEITURA
  if (umidade != umidadeAnt) {
    
    // ENVIA PARA O ESP AS INFORMAÇÕES ATUAIS VIA MQTT
    Serial.print("Umidade:");
    Serial.print(umidade);
    Serial.print(";");

    delay(5000);  // Ajuste conforme necessário
  }
  umidadeAnt = umidade;
}

