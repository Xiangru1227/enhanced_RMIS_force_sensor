import socket

def start_client():
    # 创建 socket 对象
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # 获取本地主机名
    host = socket.gethostname()
    port = 9999
    # 连接到服务器
    client_socket.connect((host, port))
    # 接收小于 1024 字节的数据
    msg = client_socket.recv(1024)
    client_socket.close()
    print(msg.decode('utf-8'))

if __name__ == '__main__':
    start_client()