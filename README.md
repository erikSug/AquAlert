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
### Conexão entre o Dispositivo e o Software
- Linux Ubuntu dentro de uma Máquina Virtual Cloud;
- Docker;
- FIWARE e seus componentes;
### Software
- React.js + Vite;
- NPM;
- axios;
## Integrantes
- Erik Kaiyu Suguiyama
- Lucas Guerreiro
- Guilherme Vital
