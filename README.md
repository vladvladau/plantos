# 🧪 Setup Guide: ESP32 `plantos` Project with Docker + ESP-IDF v5.4

This guide will help you set up a complete development environment for the ESP32 using Docker and ESP-IDF — no local ESP-specific installations required.

---

## ✅ Prerequisites

- Ubuntu 20.04 or newer
- Internet access
- Admin (sudo) access

---

## 🧰 1. Install Git

```bash
sudo apt update
sudo apt install git -y
```

---

## 🐳 2. Install Docker

```bash
sudo apt install docker.io -y
sudo systemctl enable docker
sudo systemctl start docker
```

Add your user to the `docker` group to avoid using `sudo` every time:

```bash
sudo usermod -aG docker $USER
newgrp docker
```

Test Docker:

```bash
docker run hello-world
```

---

## 📦 3. Clone the project from GitHub

```bash
git clone https://github.com/vladvladau/plantos.git
cd plantos
```

---

## 🚀 4. Start the Docker container

The `run.sh` script launches a container with ESP-IDF v5.4 and mounts your local project inside it.

```bash
./run.sh
```

If it fails, make it executable first:

```bash
chmod +x run.sh
./run.sh
```

---

## 🔌 5. Check if the ESP32 board is connected

Before flashing, verify the serial port:

```bash
ls /dev/ttyUSB* /dev/ttyACM* 2>/dev/null
```

Reconnect the board and rerun the command. Usually it will show `/dev/ttyUSB0`.

Optional:

```bash
dmesg | grep tty
```

---

## ⚙️ 6. Build, Flash, and Monitor

Once inside the container:

```bash
cd plantos-esp32
idf.py set-target esp32
idf.py build
idf.py -p /dev/ttyUSB0 flash
idf.py -p /dev/ttyUSB0 monitor
```

To do it all in one command:

```bash
idf.py -p /dev/ttyUSB0 flash monitor
```

---

## 🧾 Project Structure

```
plantos/
├── README.md            # This guide
├── Dockerfile           # Docker image using ESP-IDF v5.4
├── run.sh               # Script to launch the Docker container
├── .gitignore           # Ignores build artifacts and temp files
└── plantos-esp32/       # ESP-IDF source code
    ├── CMakeLists.txt
    └── main/
        ├── CMakeLists.txt
        └── main.c
```

---

## ℹ️ Notes

- Do not modify files outside `/workspace` inside the container
- You can use your local editor (e.g. VS Code); Docker handles build/flash only
- If you have multiple boards connected, the serial port may vary (`/dev/ttyUSB1`, `/dev/ttyACM0`, etc.)

---

## 🧑‍💻 USB Permissions (optional)

If you get a "Permission denied" error for serial access:

```bash
sudo usermod -a -G dialout $USER
newgrp dialout
```

---

Happy building! 🚀
