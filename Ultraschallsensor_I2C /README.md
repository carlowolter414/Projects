bplist00�_WebMainResource�	
_WebResourceTextEncodingName_WebResourceData_WebResourceMIMEType_WebResourceFrameName^WebResourceURLUutf-8O
�<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
  <meta http-equiv="Content-Style-Type" content="text/css">
  <title></title>
  <meta name="Generator" content="Cocoa HTML Writer">
  <meta name="CocoaVersion" content="2487.5">
  <style type="text/css">
    p.p1 {margin: 0.0px 0.0px 0.0px 0.0px; font: 13.0px '.AppleSystemUIFontMonospaced'; color: #502a18}
    p.p2 {margin: 0.0px 0.0px 0.0px 0.0px; font: 13.0px '.AppleSystemUIFontMonospaced'; color: #000000; min-height: 16.0px}
    p.p3 {margin: 0.0px 0.0px 0.0px 0.0px; font: 13.0px '.AppleSystemUIFontMonospaced'; color: #000000}
    span.s1 {color: #1400c4}
  </style>
</head>
<body>
<p class="p1"># STM32 Ultraschallsensor-Projekt</p>
<p class="p2"><br></p>
<p class="p1">## Projektbeschreibung</p>
<p class="p2"><br></p>
<p class="p3">Dieses Projekt demonstriert die Implementierung einer Abstandsmessung mit einem Ultraschallsensor auf einem STM32-Board. Die gemessenen Daten werden über eine I2C-Verbindung an ein zweites STM32-Board gesendet, das die Daten in Echtzeit als Abstand in Zentimetern anzeigt.</p>
<p class="p2"><br></p>
<p class="p1">## Funktionen</p>
<p class="p2"><br></p>
<p class="p3"><span class="s1">- </span>**Ultraschallsensor-Integration:** Der Ultraschallsensor ist an das STM32-Board angeschlossen und wird über Timer abgefragt, um präzise Abstandsmessungen durchzuführen.</p>
<p class="p3"><span class="s1">- </span>**Datenverarbeitung:** Die rohen Sensordaten werden in eine verständliche Einheit (Zentimeter) umgerechnet.</p>
<p class="p3"><span class="s1">- </span>**I2C-Kommunikation:** Die umgerechneten Abstandsdaten werden über eine I2C-Verbindung an ein zweites STM32-Board gesendet, das die Daten empfängt und den Live-Abstand anzeigt.</p>
<p class="p2"><br></p>
<p class="p1">## Technische Details</p>
<p class="p2"><br></p>
<p class="p3"><span class="s1">- </span>**Programmiersprache:** C</p>
<p class="p3"><span class="s1">- </span>**Entwicklungsumgebung:** STM32CubeIDE</p>
<p class="p3"><span class="s1">- </span>**Hardware:** STM32 Mikrocontroller-Board, Ultraschallsensor, I2C-Kommunikationsschnittstelle</p>
<p class="p2"><br></p>
<p class="p1">## Besondere Herausforderungen</p>
<p class="p2"><br></p>
<p class="p3"><span class="s1">- </span>**Timer-Konfiguration:** Die präzise Konfiguration der Timer zur genauen Abfrage des Ultraschallsensors und zur Umrechnung der Signale in Abstandsmaße.</p>
<p class="p3"><span class="s1">- </span>**I2C-Integration:** Die Implementierung einer stabilen I2C-Verbindung zur Datenübertragung zwischen den beiden STM32-Boards.</p>
</body>
</html>
Ytext/htmlP_file:///index.html    ( F X n � � �BLM                           b