# Bluetooth Communication Demo using HAL Library on NUCLEOF401RE <img height="32" width="32" src="https://unpkg.com/simple-icons@v6/icons/stmicroelectronics.svg" />

<p align="center">
  <img src="sources/stm32_bt_demo.gif" alt="animated" />
</p>

- LED ON|OFF application was made on this repo by using STM32F4 series MCU and HC05 Bluetooth module.

- Data received by UART receive interrupt. The received data has been sent back. (echo)

## Cloning the Repo
```bash
$ git clone https://github.com/fevz10/roiSelector.git
```

## Wiring

<p align="center">
  <img src="sources/wiring.png"/>
</p>

| NUCLEO PIN    | HC05 PIN       |
| --------------|----------------|
| 5V            | VCC            |
| GND           | GND            |
| PC6(USART6-TX)| RXD            |
| PC7(USART6-RX)| TXD            |





