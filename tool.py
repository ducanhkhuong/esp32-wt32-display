import tkinter as tk
import serial
import threading
import requests
import time
import random

# Kết nối serial tới ESP32
esp32 = serial.Serial(port='COM4', baudrate=115200, timeout=1)

def send_to_esp32():
    """Gửi request đến web server và chuyển phản hồi dưới dạng hex bytes xuống ESP32 mỗi 300 ms nếu dữ liệu thay đổi."""
    previous_response = None  

    while True:
        try:
            url = "http://localhost:3030/sign"
            response = requests.get(url)
            
            if response.status_code == 200:
                server_response = response.text.strip()  
                
                if server_response != previous_response:
                    print(f"Server Response: {server_response}")
                    
                    hex_data = bytes.fromhex(server_response)
                    
                    esp32.write(hex_data)
                    print(f"Sent to ESP32: {hex_data}")
                    
                    previous_response = server_response
                else:
                    print("No change in data, not sending to ESP32.")
            else:
                print(f"Server Error: {response.status_code}")
        except requests.exceptions.RequestException as e:
            print(f"Request Failed: {e}")
        except ValueError as e:
            print(f"Invalid Hex Data: {e}")
        
        time.sleep(0.3)
        

def read_from_esp32():
    """Liên tục đọc dữ liệu từ ESP32 và hiển thị trên terminal."""
    while True:
        if esp32.in_waiting > 0:  
            data = esp32.readline().decode().strip()
            print(f"Received from ESP32: {data}")

def periodic_random_send():
    """Gửi bản tin ngẫu nhiên mỗi 5 giây với byte đầu tiên là 0x26 và byte thứ hai là giá trị ngẫu nhiên từ 0x00 đến 0x82."""
    while True:
        try:
            # Byte đầu tiên cố định là 0x26
            byte1 = 0x26
            # Byte thứ hai là giá trị ngẫu nhiên từ 0x00 đến 0x82
            byte2 = random.randint(0x00, 0x82)

            # Tạo dữ liệu và gửi xuống ESP32
            data = bytes([byte1, byte2])
            esp32.write(data)
            print(f"Periodic Send to ESP32: {data}")
        
        except Exception as e:
            print(f"Error in periodic random send: {e}")

        time.sleep(10)

# Tạo giao diện chính
root = tk.Tk()
root.title("UART Communication with ESP32 and Web Server")

# Tạo các thread cho từng chức năng
send_thread = threading.Thread(target=send_to_esp32, daemon=True)
send_thread.start()

read_thread = threading.Thread(target=read_from_esp32, daemon=True)
read_thread.start()

periodic_thread = threading.Thread(target=periodic_random_send, daemon=True)
periodic_thread.start()

# Chạy giao diện
root.mainloop()
