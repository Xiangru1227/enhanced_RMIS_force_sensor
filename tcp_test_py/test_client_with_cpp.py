import socket

def start_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    host = socket.gethostname()
    port = 9999

    client_socket.connect((host, port))
    
    try:
        while True:
            complete_message = ""
            while True:
                chunk = client_socket.recv(1024).decode('utf-8')
                if not chunk:
                    raise Exception("Connection closed by the server")
                complete_message += chunk
                if "\n" in chunk:
                    break
            
            print(complete_message.strip())
    except Exception as e:
        print("Disconnected: ", str(e))
    finally:
        client_socket.close()

if __name__ == '__main__':
    start_client()

