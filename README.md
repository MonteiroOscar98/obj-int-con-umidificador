# Objetos Inteligentes Conectados - Umidificador automatico com Arudino UNO

Projeto para Universidade Presbiteriana Mackenzie {TURMA 05A} 2023/2
<br>
Leticia Helena Trevizan da Silva, Oscar Balestero Monteiro, orientador Marcelo Teixeira De Azevedo.
<br>
Resumo.
Em busca de uma solução para mitigar os extremos da umidade relativa do ar, que, quando excessivamente alta, propicia o surgimento de fungos, mofo, ácaros e outros poluentes do ar, enquanto, quando excessivamente baixa, pode desencadear alergias, como rinite e asma, este projeto visa desenvolver um sistema autônomo de umidificação. O objetivo é monitorar a umidade do ar em um ambiente controlado em escala reduzida, corrigindo e mantendo a umidade relativa dentro de uma faixa pré-estabelecida.
<br>
O projeto é implementado no contexto doméstico, aproveitando a versatilidade da plataforma Arduino e a precisão dos sensores e hardwares de suporte. O sistema é projetado para operar de maneira inteligente, com sensores constantemente monitorando a taxa de umidade. Quando a umidade relativa ultrapassa o valor máximo estabelecido, o sistema desliga automaticamente o umidificador, economizando energia. Da mesma forma, quando a umidade cai abaixo do limite aceitável, o sistema é acionado para restaurar as condições de umidade ideais no ambiente.
<br>
O cerne do sistema é o sensor de umidade, que fornece feedback em tempo real ao Arduino. O Arduino analisa as medições e as compara com os parâmetros definidos no código do projeto. Ele ativa o umidificador quando necessário, mantendo o ambiente dentro da faixa de umidade desejada, proporcionando, assim, um ambiente saudável e confortável. Este projeto demonstra como a tecnologia e a automação podem melhorar a qualidade de vida e a saúde ao lidar com a umidade do ar de maneira eficaz e econômica.
<br>
<b>Bibliotecas utilizadas:</b> ESP8266WiFi, Adafruit_MQTT, Adafruit_MQTT_Client, SoftwareSerial, DHT.
<br>
<br>
<b>Passo a passo do projeto:</b>  
<br>
<b>Tarefa 1:</b> Montagem do Sistema e componentes.
<br>
<b>Tarefa 2:</b> Desenvolvimento dos códigos arduino para o controlador (Arduino Uno e ESP8266 (wifi).
<br>
<b>Tarefa 3:</b> Coleta de dados com um sensor de umidade DHT22 e acionamento do rele shield, acionando Umidificador para controle.
<br>
<b>Tarefa 4:</b> Comunicação MTQQ com o Adafruit.io para coleta dos dados e monitoramento do sistema.
<br>
<b>Adafruit:</b> [Adafruit.IO](https://io.adafruit.com/)
<br>
<b>Projeto Fritzing:</b> [Projeto Montagem Fritzing](https://github.com/MonteiroOscar98/obj-int-con-umidificador/blob/main/Projeto.fzz)
<br>
<b>Código Arduino:</b> [Código Arduino Uno](https://github.com/MonteiroOscar98/obj-int-con-umidificador/blob/main/dht22.ino)
<br>
<b>Código ESP:</b> [Código ESP8266](https://github.com/MonteiroOscar98/obj-int-con-umidificador/blob/main/sketch_esp.ino)
<br>
<br>
# Montagem do Projeto 
![1](https://github.com/MonteiroOscar98/obj-int-con-umidificador/blob/main/Montagem%20Arduino.jpeg)
<br>
<br>
![2](https://github.com/MonteiroOscar98/obj-int-con-umidificador/blob/main/Projeto%20Montagem.jpg)
<br>
