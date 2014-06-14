# -*- coding:utf-8 -*-
# receive.inoからリモコンの赤外線信号を取得

from serial import Serial

com = Serial('/dev/cu.usbmodem14211', 57600)

while True:
    print com.readline()
