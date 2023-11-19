import time

import serial

# Define the serial port and settings
serial_port = serial.Serial('COM5', 115200)

user_input = ""
while user_input == "":
    print("Mode 1: command the microcontroller to enter Bootloader")
    print("Mode 2: Wait for ready command")
    user_input = input("Enter The mode: ")

    if user_input == "1":
        # Command the microcontroller to enter the BootLoader
        while 1:
            response = b""
            while not response.endswith(b"BOOT\n"):
                print("Sending BOOT command")
                serial_port.write(b"BOOT\n")
                response = serial_port.readline()
                print(response)
                # Wait 2 seconds
                time.sleep(2)
            break

        print("Waiting for READY command")
        response = b""
        while not response.endswith(b"READY\n"):
            response = serial_port.readline()
        print("BootLoader started, Flashing")

    elif user_input == "2":
        print("Waiting for READY command")
        response = b""
        while not response.endswith(b"READY\n"):
            response = serial_port.readline()

        print("BootLoader started, Flashing")
    else:
        print("Wrong Input")
        user_input = ""

# Open the hex file for reading
with open("YOUR_HEX_FILE", 'r') as hex_file:
    for line in hex_file:
        # Extract the record type from the line
        record_type = line[7:9]

        # Print the record type and line to be sent
        print(f"Record Type: {record_type}, Sending: {line.strip()}")

        # Send the line to the serial port
        serial_port.write(line.encode('utf-8'))

        # Wait for the "ok" response
        response = b""
        while not response.endswith(b"ok\n"):
            response = serial_port.readline()
            if response != "ok\n":
                print(response)

        # Print the response
        print("Received: " + response.decode('utf-8'))

# Close the serial port
serial_port.close()
