#!/usr/bin/env python3
import socket               
import time
sock = socket.socket()
host = "192.168.115.165" #ESP32 IP in local network
port = 6677             #ESP32 Server Port  
sock.connect((host, port))  
while True:

    sock.sendall(b"#1099")
    time.sleep(0.1)
    sock.sendall(b"#2050")
    time.sleep(0.1)
    sock.sendall(b"#3160")
    time.sleep(0.1)
    sock.sendall(b"#4001")
    time.sleep(0.1)
    sock.sendall(b"#5100")
    time.sleep(0.1)
    sock.sendall(b"#6001")
    time.sleep(0.1)
