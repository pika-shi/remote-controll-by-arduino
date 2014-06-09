# -*- coding:utf-8 -*-

from serial import Serial
import twitter

com = Serial('/dev/cu.usbmodem14211', 57600)

while True:
    print com.readline()
