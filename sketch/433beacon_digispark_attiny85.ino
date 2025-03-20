//Протестировано на модуле приемника RX470C-V01
#include <avr/interrupt.h>

#define EN_PIN 1 //Pin PB1 для включения передатчика
#define DATA_PIN 2 // Pin PB2 для передачи данных

volatile bool transmit = false;

void setup() {
  pinMode(EN_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);

//Настроим таймер с периодом в 1 секунду
  TCCR1 = 0x0B; // Установка таймера на 1 сек
  OCR1A = 15625; // Частота срабатывания (для 1 сек)
  TIMSK |= (1 << OCIE1A); // Включаем прерывание на совпадение
  sei(); // Включаем глобальные прерывания
}

ISR(TIMER1_COMPA_vect) {
  transmit = true; //Устанавливаем флаг для передачи
}

void loop() {
  if (transmit) {
    digitalWrite(EN_PIN, HIGH); //Включаем передатчик
    digitalWrite(DATA_PIN, HIGH); //Передаем импульс
    delay(100); //длительность импульса
    digitalWrite(DATA_PIN, LOW); // Завершаем передачу
    digitalWrite(EN_PIN, LOW); // Выключаем передатчик
    transmit = false; // Сбрасываем флаг передачи
  }
}

