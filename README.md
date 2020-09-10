# Voicemask Arduino

Con el tema del covid las mascarillas se han echo practicamente obligadas en nuestro día a día, en esta mini guia muestro como podemos hacer una algo mas personalizada, que muestre nuestra boca mientras hablamos de una forma un tanto peculiar. Este proyecto es un prototipo de mascarilla con arduino programado, que imprime en una matriz de leds una representacion de la boca segun la intensidad de un sonido. Codigo basado y modificado de TylerGlaiel.


# Electrónica
|   |   |   |   |
|---|---|---|---|
| Arduino nano|<img src="img/arduino/arduino-nano.jpg" width="50%"/>|[<img src="img/icos/carrito.png" width="20%"/>](https://es.aliexpress.com/item/32844537084.html?spm=a2g0s.9042311.0.0.7bf663c0i7hGtf)| Será el cerebro de nuestra mascarilla. Se encarga de alimentar el resto de modulos, leer la intensidad del sonido y pintar los leds correspondientes.|
| Matriz leds 8x8 |<img src="img/arduino/matrix-led.jpg" width="50%"/>  |[<img src="img/icos/carrito.png" width="20%"/>](https://www.ebay.es/itm/Arduino-8x8-RGB-LED-Flexible-Matrix-Dream-Color-Individually-Addressable-LED/392684589504?_trkparms=aid%3D111001%26algo%3DREC.SEED%26ao%3D1%26asc%3D20160908105057%26meid%3Df6e0241a0aa64f5dacaecf50fd9b07ce%26pid%3D100675%26rk%3D1%26rkt%3D11%26mehot%3Dnone%26sd%3D392684589504%26itm%3D392684589504%26pmt%3D0%26noa%3D1%26pg%3D2380057%26brand%3DArduino&_trksid=p2380057.c100675.m4236&_trkparms=pageci%3A68bb662a-c390-11ea-94fe-0610a2e74a40%7Cparentrq%3A3ea0496b1730a69c2188ec3dffe8ee3c%7Ciid%3A1)| Es la parte que se ve, mostrara los leds con forma de boca correspondientes al sonido emitido.  |
| Sensor de sonido |<img src="img/arduino/microphone.jpg" width="50%"/>  |[<img src="img/icos/carrito.png" width="20%"/>](https://es.aliexpress.com/item/4000127143653.html?spm=a2g0o.productlist.0.0.2fa26d9cqUUiMC&s=p&ad_pvid=2020071109070012799267761969720002604467_3&algo_pvid=6ad7a32e-416e-41be-981c-153ca44f31d3&algo_expid=6ad7a32e-416e-41be-981c-153ca44f31d3-2&btsid=0b0a187915944836207366658ee071&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)| Captura la onda de sonido que emitimos al hablar y la transforma en un valor numérico.|
| Conversor de voltaje |<img src="img/arduino/converter.jpg" width="50%"/>  |[<img src="img/icos/carrito.png" width="20%"/>](https://www.amazon.es/gp/product/B07MY3NZ18/ref=ppx_yo_dt_b_asin_image_o00_s00?ie=UTF8&psc=1)| Nos permite modular el voltaje que da la bateria al necesario para alimentar el Arduino.|

# +Materiales
|   |   |   |   |
|---|---|---|---|
| mascarilla |<img src="img/material/mask.jpg" width="20%"/>  ||Vale cualquiera, recomiendo hacerla con tela y luego meterle un filtro de por medio.|
| interruptor |<img src="img/material/interruptor.jpg" width="20%"/>  || Un interruptor para poder apagar y encender la mascarilla.|
| cable para soldar  |<img src="img/material/cable.jpg" width="20%"/>|[<img src="img/icos/carrito.png" width="20%"/>](https://www.amazon.es/TUOFENG-carretes-diferentes-colores%EF%BC%89-conexi%C3%B3n/dp/B07V5FVSYL/ref=sr_1_7?__mk_es_ES=%C3%85M%C3%85%C5%BD%C3%95%C3%91&dchild=1&keywords=cable+para+soldar&qid=1594483850&sr=8-7)|Cable para conectar los componentes.|
| bateria 3.7v |<img src="img/material/b3.7v.jpg" width="20%"/>  |[<img src="img/icos/carrito.png" width="20%"/>](https://es.aliexpress.com/item/32282296432.html?spm=a2g0o.productlist.0.0.7b1b29664p2c87&s=p&ad_pvid=2020071109091912316291376136950002607790_3&algo_pvid=7e60b770-aaea-4d23-89cc-3a9b14d033a3&algo_expid=7e60b770-aaea-4d23-89cc-3a9b14d033a3-2&btsid=0b0a0ad815944837595817386e2a28&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)|Necesitamos una bateria pequeña para que no sea muy intrusiva, yo elegi esta por su tamaño, pero vale cualquier otra, el voltaje lo convertiremos a 5.5v posteriormente.|
| cable mini-usb  |<img src="img/material/mini-usb.jpg" width="20%"/>|[<img src="img/icos/carrito.png" width="20%"/>](https://es.aliexpress.com/item/32790483330.html?spm=a2g0o.productlist.0.0.66ac7bc4Fivdyj&s=p&ad_pvid=202007110910001016621252267080002609298_1&algo_pvid=237165c9-52b6-4fdc-aa4c-d353c46cabe1&algo_expid=237165c9-52b6-4fdc-aa4c-d353c46cabe1-0&btsid=0b0a050b15944838003869000e89ee&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)|Necesario para poder flashear el codigo al arduino nano.|

# Herramientas
|   |   |   |
|---|---|---|
| PC + Arduino IDE  |<img src="img/tool/pc.jpg" width="20%"/> | Necesitaremos el ide de Aduino:  <a href="https://www.arduino.cc/en/main/software">descarga</a> y un Pc al que conectarlo. |
| estaño para soldar |<img src="img/tool/tin.jpg" width="20%"/> | Lo usaremos para soldar los componentes.  |
| soldador de estaño |<img src="img/tool/welder.jpg" width="20%"/>  | Vale cualquier soldador, aunque recomiendo la marca JBC.  |

# Diagrama

La esctructura de la mascarilla sigue el siguiente diagrama, solo tenemos que seguirlo para que funcione correctamente.

<img src="img/process/diagrama.jpg" width="70%"/>

# Proceso

El proceso que yo segui es el siguiente:
|   |   |   |
|---|---|---|
|  1  |<img src="img/process/step1.jpg" width="40%"/> | Quite los cables de la matriz de led que venian e hice un puente entre 5v y GND (tierra).  |
| 2 |<img src="img/process/step2.jpg" width="40%"/> | Siguiendo el diagrama, de la matriz de leds sale Din (cable verde) que va al pin D3. Cable negro que va a GND y G del sensor de sonido, y cable rojo que va a 3v3 y + del sensor de sonido. Ademas del sensor de sonido conectamos A0 a A0 |
| 3 |<img src="img/process/step4.jpg" width="40%"/> | Soldamos el consersor a GND y VCC. Ajustamos el voltaje con el regulador a 5.5v. Tambien añadimos el interruptor y la bateria. |
| 4 |<img src="img/process/end.png" width="40%"/> | Haciendo algunas pruebas, hice algunos ajustes con una placa pcb que ocupa menos y realice algunas soldaduras un poco mejor. Requiere un poco de practica para que el resultado sea perfecto. |

# Pruebas

Dejo algunos videos de prueba mientras hice el proyecto, espero que os guste!

|   |   |   |
|---|---|---|
|[<img src="img/icos/youtube.png" width="10%"/>](https://youtu.be/aRlW_2RHrB4 "voicemask - test 1")|[<img src="img/icos/youtube.png" width="10%"/>](https://youtu.be/I8l_C90OtqM "voicemask - test 2")|[<img src="img/icos/youtube.png" width="10%"/>](https://youtu.be/xzhOVCTkhy0 "voicemask - resultado")|


# Enlaces de interes

En estos enlaces podemos ver algunos proyectos similares

* https://www.kickstarter.com/projects/jabbermask/jabbermask
* https://www.youtube.com/watch?v=qnmPe6RFjsY

## ¡ Si la construyes no te olvides comentarlo !

[![N|Solid](https://i.imgur.com/DOMgrz2.png)](https://twitter.com/d4nijerez) 