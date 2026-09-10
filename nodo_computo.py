import socket, json

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(("0.0.0.0", 5005))
print("Nodo de computo escuchando en el puerto 5005...")

while True:
    data, addr = sock.recvfrom(1024)
    mensaje = json.loads(data.decode())
    print(f"Salon {mensaje['room']}: {mensaje['status']}  (desde {addr[0]})")
