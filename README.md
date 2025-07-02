# Corewar

Corewar is a programming game in which multiple virtual warriors (programs) compete for control of a simulated memory arena. Each warrior tries to overwrite the others and survive as long as possible. This project implements a Corewar virtual machine and visualization in **C** using **CSFML**.

---

## Usage
Run the virtual machine by passing .cor compiled warrior files:
```bash
./corewar player1.cor player2.cor [player3.cor ...]
```
---

You can find simple champions in the **simple_test_champions** directory or you can import custom .s champions files and compile them with the **asm** binary
```bash
./asm champion.s
```
