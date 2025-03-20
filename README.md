# 433_simple_beacon
simple beacon implementation based on RX470C-V01 (transmitter) and digispark_attiny85 (control device) components

Это попытка создать радио-закладку, которая создает короткий сигнал в диапазоне 433Мгц с интервалом в одну секунду, что может подойти для инструментов (при соотвествующей доработке) тестирования пеленгаторов, а так же устройств проверки на угрозы утечки информации по каналам побочных электромагнитных излучений и наводок.

## step-by-step:
1. Разводка пинов:
1.1 Выводы "+" и "-" передатчика RX470C-V01 к источнику питания 5 В и GND на Digispark ATtiny85. Digispark обычно работает на 5 В, и передатчик также поддерживает это напряжение.
1.2 Вывод EN передатчика к пину ATtiny85 "PB1", который будет управлять включением передатчика. Опционально можете использовать резистор на 330-470 Ом между выходом микроконтроллера и входом EN на передатчике.
1.3 Вывод DAT подключите к пину ATtiny85 "PB2" для передачи данных.
2. Подключите сборку к хосту с которого будете заливать скетч.
3. После успешной компиляции и прошивки Digispark  включите и выключите сборку снова.


This is an attempt to create a radio bookmark, which creates a short signal in the range of 433MHz with an interval of one second, which can be suitable for tools (with the corresponding improvement) testing direction finders, as well as devices to check for threats of information leakage through the channels of collateral electromagnetic emissions and interference.

## step-by-step:
1. Pinout:
1.1Pins “+” and “-” of the RX470C-V01 transmitter to the 5V power supply and GND on the Digispark ATtiny85. The Digispark typically runs at 5V, and the transmitter supports this voltage as well.
1.2 Output EN of the transmitter to the ATtiny85 pin “PB1”, which will control turning the transmitter on. Optionally, you can use a 330-470 ohm resistor between the microcontroller output and the EN input on the transmitter.
1.3 Connect the DAT pin to the ATtiny85 “PB2” pin to transmit data.
2. Connect the assembly to the PC from which you will upload the sketch.
3. After successful compilation and flashing of Digispark, turn the assembly on and off again.
