# rainbow-gradient

> An Arduino/C++ implementation of a rainbow color gradient for LED strips, with three alternative data structure approaches (array, linked list, vector).

## ✨ TL;DR
Open the sketch in the Arduino IDE and flash it to the board.

## 🚀 Features
- **Three implementations:** Gradient via C array (`rainbow_grad_arr.cpp`), linked list (`rainbow_grad_list.cpp`), and `std::vector` (`rainbow_grad_vec.cpp`).
- **Arduino-compatible:** Compiles and flashes directly via the Arduino IDE.
- **Stream mode:** Additional `stream.ino` sketch for continuous color output.

---

## 🛠️ Installation

### Prerequisites
- Arduino IDE
- Compatible Arduino board (e.g., Arduino Uno/Nano)
- LED strip (e.g., WS2812)

### Steps
1. Clone the repository:
```bash
git clone https://github.com/HuberNicolas/rainbow-gradient
cd rainbow-gradient
```
2. Open `rainbow_gradient.ino` in the Arduino IDE.
3. Select the board and port, then upload the sketch.

---

## 💻 Usage

Open the desired sketch (`rainbow_gradient.ino` or `stream.ino`) in the Arduino IDE and flash it to the board.

---

## 📄 License

This project is licensed under the **GNU General Public License v3 (GPLv3)** – see the [LICENSE](LICENSE) file for details.

**Conditions:**
- The original copyright notice (crediting my name) must be retained in all copies or substantial portions of the software.
- Modifications and derivative works *must* also be released under the GPLv3, and the source code must be made publicly available.
