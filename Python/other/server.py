import socket


HOST = '127.0.0.1'
PORT = 9876

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_socket.bind((HOST,PORT))

server_socket.listen(1)

socket_connection, addr = server_socket.accept()

print('{} Connected'.format(addr))

while True:

data = socket_connection.recv(1024)

if not data:
break

print('Received Data: {}, from {}'.format(data.decode('utf-8'), addr))

socket_connection.send(data)

server_socket.close()
