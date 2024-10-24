## Comprehensive Calculator Using C++ </>





Welcome to the **Comprehensive Calculator**! This charming program helps you with various calculations in chemistry, biology, finance, physics, programming, and even fetches real-time currency exchange rates! 🌍✨

## 🌟 Features

- **Chemistry:** 
  - Molecular Weight
  - Stoichiometry
  - Molarity
  - Reaction Rate

- **Thermodynamics:** 
  - Gibbs Free Energy

- **Electrochemistry:** 
  - Nernst Equation

- **Bio Lab:** 
  - Body Mass Index (BMI)

- **Finance:** 
  - Compound Interest

- **Programming:** 
  - Decimal to Binary
  - ASCII to Char
  - Char to ASCII

- **Physics:** 
  - Kinetic Energy

- **Currency Exchange:** 
  - Get live rates with a fun API!

## 📋 Requirements

### Windows:
- C++ Compiler (MinGW, MSVC)
- `libcurl` Library

### Linux:
- C++ Compiler (g++)
- `libcurl` Library

## 🚀 Setup Instructions

### Windows

```bash
1. Install MinGW: Download from [MinGW website](https://sourceforge.net/projects/mingw/).
2. Install `libcurl`: Get the Windows binaries from [curl official website](https://curl.se/windows/).
3. Add `libcurl`: Copy headers and libraries to MinGW folders.
4. Compile and Run:
   g++ -o calculator calculator.cpp -lcurl
   ./calculator.exe
```

### Linux

```bash
1. Install Dependencies:
   sudo apt-get update
   sudo apt-get install g++ libcurl4-openssl-dev

2. Compile and Run:
   g++ -o calculator calculator.cpp -lcurl
   ./calculator
```

## 🎉 How to Use

Simply run the program and select your desired calculator from the menu:

```
--- Comprehensive Calculator ---
1. Molecular Weight
2. Stoichiometry
3. Molarity
4. Reaction Rate
5. Gibbs Free Energy
6. Nernst Equation
7. Body Mass Index
8. Compound Interest
9. Kinetic Energy
10. Decimal to Binary
11. ASCII to Char
12. Char to ASCII
13. Currency Exchange Rate
14. Copyright Info
15. Exit
Select an option (1-15):
```

Just pick a number and hit Enter! It’s that simple! 🎈

## 🌐 API Integration

Access real-time currency rates using `libcurl` from `exchangerate-api.com`. Make sure you're connected to the internet! 💻🌐

## 📝 License

Developed by Kaizenn-me. All rights reserved © 2024. For educational and personal use only. Enjoy calculating! 🎉
```

### Key Features:
- Added a cute title at the top.
- Tutorial instructions are clearly boxed for better visibility.
- Retained the friendly tone and essential information.
