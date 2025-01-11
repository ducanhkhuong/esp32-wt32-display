import tkinter as tk
import serial
import threading
import requests
import time

# Khởi tạo kết nối UART với ESP32
esp32 = serial.Serial(port='COM4', baudrate=115200, timeout=1)

def send_to_esp32():
    """Gửi request đến web server và chuyển phản hồi dưới dạng hex bytes xuống ESP32 mỗi 300 ms nếu dữ liệu thay đổi."""
    previous_response = None  # Biến lưu trữ dữ liệu đã nhận lần trước

    while True:
        try:
            # Gửi request GET đến web server local
            url = "http://localhost:3030/sign"
            response = requests.get(url)
            
            if response.status_code == 200:
                server_response = response.text.strip()  # Loại bỏ khoảng trắng hoặc ký tự xuống dòng
                
                # Chỉ gửi dữ liệu nếu khác với dữ liệu lần trước
                if server_response != previous_response:
                    print(f"Server Response: {server_response}")
                    
                    # Chuyển chuỗi nhận được thành hex bytes
                    hex_data = bytes.fromhex(server_response)
                    
                    # Gửi hex bytes xuống ESP32 qua UART
                    esp32.write(hex_data)
                    print(f"Sent to ESP32: {hex_data}")
                    
                    # Cập nhật dữ liệu đã nhận lần trước
                    previous_response = server_response
                else:
                    print("No change in data, not sending to ESP32.")
            else:
                print(f"Server Error: {response.status_code}")
        except requests.exceptions.RequestException as e:
            print(f"Request Failed: {e}")
        except ValueError as e:
            print(f"Invalid Hex Data: {e}")
        
        # Đợi 300 ms trước khi gửi lại request
        time.sleep(0.3)
        

def read_from_esp32():
    """Liên tục đọc dữ liệu từ ESP32 và hiển thị trên terminal"""
    while True:
        if esp32.in_waiting > 0:  # Nếu có dữ liệu trong buffer UART
            data = esp32.readline().decode().strip()
            print(f"Received from ESP32: {data}")

# Tạo giao diện người dùng với tkinter
root = tk.Tk()
root.title("UART Communication with ESP32 and Web Server")

# Chạy thread để tự động gửi request mỗi 1 giây
send_thread = threading.Thread(target=send_to_esp32, daemon=True)
send_thread.start()

# Chạy thread để liên tục đọc dữ liệu từ ESP32
read_thread = threading.Thread(target=read_from_esp32, daemon=True)
read_thread.start()

# # Bắt đầu vòng lặp giao diện
root.mainloop()
