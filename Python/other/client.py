from socket import *

socket_client = socket(AF_INET, SOCK_STREAM)
socket_client.connect(('127.0.0.1', 9876))

print('Connected')
socket_client.send('message from client'.encode('utf-8'))

print('Send Message')

data = socket_client.recv(1024)
print('Received : ', data.decode('utf-8'))

socket_client.close()
