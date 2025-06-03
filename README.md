# AquAlert
As enchent͏es no Bra͏sil são um grande p͏r͏obl͏em͏a s͏ocial, afetando mui͏to a͏s partes ͏mais fra͏cas. Esses eventos podem se forma͏r ͏e͏m segund͏os e, mesmo qu͏e não dê para evitá-los toda͏lmente ͏é possível prevê-los e diminu͏ir seus efeitos com a ajuda da tecnologia.<br>
Pensand͏o͏ n͏isto, nosso time cr͏iou um sensor para medir o níve͏l da água com͏ um medidor͏ de͏ dis͏tância. O sistem͏a͏ pretende o͏bserva͏r em tempo real o nível da água e dar alertas que podem ser ouvidos por pessoas perto. Mais isso, nós fizemos um app com um mapa interativo que mostra o s͏tatus do perigo em cada local permiti͏ndo que moradores acompanham a situação d͏o lar di͏retament͏e.

## Como funciona?
- O dispositivo vai medir a sua distância em relação a superfície.
- Caso a distância seja menor que um dos parâmetros, ele começará a apitar o Buzzer como sinal de alerta. Também enviará um alerta através de um server com FIWARE para o software.
- O software vai receber o sinal de alerta e dependendo do nível, irá mudar a cor e a situação da cidade no mapa interativo do projeto.

## Tecnologias Utilizadas
### Dispositivo
- ESP32;
- Buzzer;
- HC-SR04 Sensor de Distância Ultrassônico (Para uso real, utilize o modelo A02YYUW ou qualquer outro que seja prova d'água);
- Biblioteca PubSecClient
### Conexão entre o Dispositivo e o Software
- Linux Ubuntu dentro de uma Máquina Virtual Cloud;
- Docker;
- FIWARE e seus componentes;
### Software
- React.js + Vite;
- NPM;
- axios;
## Como instalar?
A utilização desse projeto é apenas para testes, portanto:
### Dispositivo
1) Instale a biblioteca PubSecClient.
2) Monte o dispositivo de acordo com a simulação.
3) Mude o nome e senha do Wi-Fi, assim como o IP do Broker MQTT.
4) Mude as configurações de acordo com a sua preferência.
### Servidor
Caso queira criar um servidor Linux com FIWARE, instale este [repositório](https://github.com/fabiocabrini/fiware) dentro da máquina virtual. Para mais instruções, leia a descrição do repositório mencionado.
### Software
1) Instale o Node.js caso não tenha instalado.
2) Utilize o seguinte comando no terminal.
```bash
npm install
```
3) Após isso, para rodar localmente, utilize o  comando.
```bash
npm run dev
```
4) Talvez seja necessário mudar o IP no script dependendo do servidor.
## Link da Simulação
https://wokwi.com/projects/432041335930039297
![image](https://github.com/user-attachments/assets/11c5bf79-71b8-4132-b603-0cc66f114d93)


## Video de demonstração
Clique [aqui](https://youtu.be/ulPhDBCKn1c) para ver o vídeo demonstrativo
## Considerações Finais
Este projeto é um protótipo de solução para mitigar os impactos de desastres naturais, com potencial para expansão e implementação de novas funcionalidades. Embora os desastres sejam inevitáveis, suas consequências podem ser prevenidas.
## Integrantes
- Erik Kaiyu Suguiyama RM: 559273
- Lucas Guerreiro RM: 560359
- Guilherme Vital RM: 560073
