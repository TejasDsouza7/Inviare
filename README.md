# Inviare

**Inviare** is a simple and lightweight TUI (Text-based User Interface) webhook sender written in C.Inviare lets you send messages to Discord or any webhook endpoint right from your terminal — with style.

> Built with **ncurses** and **libcurl**. Runs on **Linux** and **Windows**.

---

## Features

- Cross-platform (Linux, Windows)
- Easy-to-use TUI interface
- Send messages to any webhook (Discord)
- Custom sender name (`username` support)
- Fast, clean, and dependency-light

---

## Preview

Inviare - Cross-Platform Webhook Sender

Name:  HelloBot

Webhook URL:  https://discord.com/api/webhooks/... 

Message: Hello from Inviare!

[Message sent successfully!]

---

## Installation

### Linux 

```bash
sudo apt install libcurl4-openssl-dev libncurses-dev
gcc inviare.c -o inviare -lcurl -lncurses
```

### Windows (Using MinGW)

```
1. Install PDCurses and libcurl for Windows


2. Compile:



gcc inviare.c -o inviare.exe -lcurl -lpdcurses
```

---

## Usage

```
./inviare

Follow the prompts to:

Enter your name

Paste your webhook URL

Type your message

Hit Enter to send!
```


---
