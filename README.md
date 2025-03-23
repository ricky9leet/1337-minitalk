<h1 align="center">📡 1337 Project: Minitalk</h1>

<p align="center">
  <b><i>Development repository for the 42cursus' Minitalk project</i></b><br>
  For more about 1337 Coding School and its projects, feel free to connect with me on <a href="https://www.linkedin.com/in/tellat-ilyas/"><b>LinkedIn</b></a>.
</p>

<h3 align="center">
  <a href="#-about">📖 About</a>
  <span> · </span>
  <a href="#-usage">🛠 Usage</a>
  <span> · </span>
  <a href="#-useful-links">🔗 Useful Links</a>
</h3>

---

## 🏆 Project Score
✅ **I achieved a perfect score of 125/100 on this project!** 🎯

---

## 📖 About

Minitalk is a project that explores **inter-process communication (IPC)** using **UNIX signals**. The goal is to create a simple messaging system where one process (the **client**) sends a message to another process (the **server**) using `SIGUSR1` and `SIGUSR2` signals.

### 📌 Key Concepts
- **Signals**: Minitalk uses `SIGUSR1` and `SIGUSR2` to encode and transmit data.
- **Bitwise Operations**: Each character of the message is sent **bit by bit** using signals.
- **Signal Handling**: The server catches and decodes signals to reconstruct the original message.
- **Real-time Communication**: Ensuring signals are processed in the correct order without loss.

---

## 🛠 Usage

### 🔹 Compilation
To compile the project, use:
```sh
make
```
This will generate two executables:
- `server`
- `client`

To compile both the **mandatory** and **bonus** parts:
```sh
make bonus
```

To clean up object files:
```sh
make clean
```
To remove executables and object files:
```sh
make fclean
```
To recompile everything from scratch:
```sh
make re
```

### 🔹 Running the Server
Start the server first:
```sh
./server
```
The server will print its **PID (Process ID)**, which you’ll need for the client.

### 🔹 Sending a Message
Use the **client** to send a message to the **server**, replacing `<PID>` with the server’s actual PID:
```sh
./client <PID> "Hello, World!"
```
The server will receive and print the message.

### 🔹 Bonus Features
The bonus version includes:
- **Unicode Character Support**
- **Message Acknowledgment from Server to Client**
- **Handling Very Large Messages**

To test the bonus part, run:
```sh
./server 
./client <PID> "This is the bonus part! 🚀"
```

---

## 📌 Useful Links

📚 **Documentation & References**
- [Signal Handling in C](https://man7.org/linux/man-pages/man2/signal.2.html)
- [UNIX Signals Explained](https://www.gnu.org/software/libc/manual/html_node/Signal-Handling.html)
- [Bitwise Operations in C](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)

🛠 **Technical Articles & Guides**
- [Inter-Process Communication](https://www.tldp.org/LDP/tlk/ipc/ipc.html)
- [How to Use Signals in C](https://www.ibm.com/docs/en/i/7.3?topic=ssw_ibm_i_73/rzab6/pthsig.htm)

Happy coding! 🚀

