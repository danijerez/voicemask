# 😷 Voicemask

### 🦠 Ante la situación actual del COVID-19, las mascarillas se han hecho prácticamente obligadas en nuestro día a día. Por ello queremos mostraros esta guía para que puedas hacer tu mascarilla personalizada, mostrando tu boca mientras hablas de una forma diferente.

### 🙏 Este proyecto es un prototipo de mascarilla con arduino, que imprime en una matriz de leds una representación de la boca según la intensidad de la voz. El código está basado y modificado de TylerGlaiel.

# 🖖 [![Twitter Follow](https://img.shields.io/twitter/follow/d4nijerez?style=social)](https://twitter.com/d4nijerez) ![GitHub Followers](https://img.shields.io/github/followers/danijerez?style=social)

## 🗺️ Diagrama
<img src="img/process/diagrama.jpg" width="70%"/>

## 🧩 Componentes

<table style="width:100%">
  <tr>
    <td>
    Arduino Nano
	<a href="https://es.aliexpress.com/item/32844537084.html?spm=a2g0s.9042311.0.0.7bf663c0i7hGtf">
  		<img  src="img/arduino/arduino-nano.jpg">
	</a>
	</td>
        <td>
    Matrix Leds 8x8
	<a href="https://www.ebay.es/itm/Arduino-8x8-RGB-LED-Flexible-Matrix-Dream-Color-Individually-Addressable-LED/392684589504?_trkparms=aid%3D111001%26algo%3DREC.SEED%26ao%3D1%26asc%3D20160908105057%26meid%3Df6e0241a0aa64f5dacaecf50fd9b07ce%26pid%3D100675%26rk%3D1%26rkt%3D11%26mehot%3Dnone%26sd%3D392684589504%26itm%3D392684589504%26pmt%3D0%26noa%3D1%26pg%3D2380057%26brand%3DArduino&_trksid=p2380057.c100675.m4236&_trkparms=pageci%3A68bb662a-c390-11ea-94fe-0610a2e74a40%7Cparentrq%3A3ea0496b1730a69c2188ec3dffe8ee3c%7Ciid%3A1">
  		<img  src="img/arduino/matrix-led.jpg">
	</a>
	</td>
        <td>
    Microfono
	<a href="https://es.aliexpress.com/item/4000127143653.html?spm=a2g0o.productlist.0.0.2fa26d9cqUUiMC&s=p&ad_pvid=2020071109070012799267761969720002604467_3&algo_pvid=6ad7a32e-416e-41be-981c-153ca44f31d3&algo_expid=6ad7a32e-416e-41be-981c-153ca44f31d3-2&btsid=0b0a187915944836207366658ee071&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_">
  		<img  src="img/arduino/microphone.jpg">
	</a>
	</td>
  </tr>
    <tr>
    <td>
    Conversor Voltaje
	<a href="https://www.amazon.es/gp/product/B07MY3NZ18/ref=ppx_yo_dt_b_asin_image_o00_s00?ie=UTF8&psc=1">
  		<img  src="img/arduino/converter.jpg">
	</a>
	</td>
        <td>
    Bateria
	<a>
  		<img  src="img/material/b3.7v.jpg">
	</a>
	</td>
        <td>
    Cable
	<a>
  		<img  src="img/material/cable.jpg">
	</a>
	</td>
  </tr>
      <tr>
    <td>
    Interruptor
	<a>
  		<img  src="img/material/interruptor.jpg">
	</a>
	</td>
        <td>
    Mascarilla
	<a>
  		<img  src="img/material/mask.jpg">
	</a>
	</td>
  </tr>
</table>

## 💿 Programas
[![Source](https://img.shields.io/badge/arduino_ide-008184?style=for-the-badge&logo=cplusplus&logoColor=white&labelColor=101010)](https://www.arduino.cc/en/software)

## 💾 Código
[![Source](https://img.shields.io/badge/flash_mask.ino_with_arduino_ide-999999?style=for-the-badge&logo=github&logoColor=white&labelColor=101010)](https://github.com/danijerez/voicemask/tree/master/mask)

## 🧰 Tutorial
<table style="width:100%">
  <tr>
    <td>
	<a>
  		<img width="300" src="img/process/step1.jpg">
	</a>
	</td>
    <td>
	Quite los cables de la matriz de led que venian e hice un puente entre 5v y GND (tierra)
	</td>
  </tr>
  <tr>
    <td>
	<a>
  		<img width="300" src="img/process/step2.jpg">
	</a>
	</td>
	<td>
	Siguiendo el diagrama, de la matriz de leds sale Din (cable verde) que va al pin D3. Cable negro que va a GND y G del sensor de sonido, y cable rojo que va a 3v3 y + del sensor de sonido. Ademas del sensor de sonido conectamos A0 a A0
	</td>
  </tr>
    <tr>
    <td>
	<a >
  		<img width="300" src="img/process/step4.jpg">
	</a>
	</td>
	<td>
	Soldamos el consersor a GND y VCC. Ajustamos el voltaje con el regulador a 5.5v. Tambien añadimos el interruptor y la bateria
	</td>
  </tr>
    </tr>
    <tr>
    <td>
	<a>
  		<img width="300" src="img/process/end.png">
	</a>
	</td>
	<td>
	Haciendo algunas pruebas, hice algunos ajustes con una placa pcb que ocupa menos y realice algunas soldaduras un poco mejor. Requiere un poco de practica que el resultado sea perfecto
	</td>
  </tr>
</table>

## 🧪 Testing
[![YouTube](https://img.shields.io/badge/sample_1-FF0000?style=for-the-badge&logo=youtube&logoColor=white&labelColor=101010)](https://youtu.be/aRlW_2RHrB4)
[![YouTube](https://img.shields.io/badge/sample_2-FF0000?style=for-the-badge&logo=youtube&logoColor=white&labelColor=101010)](https://youtu.be/I8l_C90OtqM)
[![YouTube](https://img.shields.io/badge/sample_3-FF0000?style=for-the-badge&logo=youtube&logoColor=white&labelColor=101010)](https://youtu.be/xzhOVCTkhy0)



## 💡 Enlaces
* https://www.kickstarter.com/projects/jabbermask/jabbermask
* https://www.youtube.com/watch?v=qnmPe6RFjsY
