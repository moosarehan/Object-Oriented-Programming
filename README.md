<h1 align="center">📚 Object-Oriented Programming — C++</h1>

<p align="center">
  A structured collection of C++ programs written during an Object-Oriented Programming course.<br/>
  Covers pointers, dynamic memory, structures, classes, inheritance, polymorphism, and more.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
  <img src="https://img.shields.io/badge/Course-OOP-blueviolet?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Status-Active-success?style=for-the-badge"/>
</p>

---

## 📂 Repository Structure

```
Object-Oriented-Programming/
│
├── OOP-Pointers-and-Structures/     ← Pointers, dynamic memory & structs
│   ├── StudentStruct.cpp
│   ├── EmployeManagementSystem.cpp
│   ├── matrixtranpose.cpp
│   ├── reversearray.cpp
│   ├── captilizesentences.cpp
│   └── inventoryManagementSystem.cpp
│
├── OOP-Classes-and-Inheritance/     ← Classes, const-correctness, static members & inheritance
│   ├── ObjectCounter.cpp
│   ├── ConstStaticDemo.cpp
│   ├── StudentSectionManager.cpp
│   ├── JaggedArray.cpp
│   ├── TollboothSimulation.cpp
│   ├── TimeAddition.cpp
│   ├── CarInfo.cpp
│   └── ScientistChemist.cpp
│
└── README.md
```

> 🗂️ New topic folders will be added here as the course progresses.

---

## 📦 Modules

### 1. 🔷 Pointers and Structures

> **Folder:** [`OOP-Pointers-and-Structures/`](./OOP-Pointers-and-Structures)

Covers the fundamentals of C++ pointers, pointer arithmetic, dynamic memory allocation (`new` / `delete`), and user-defined `struct` types.

| File | Description |
|------|-------------|
| [`StudentStruct.cpp`](./OOP-Pointers-and-Structures/StudentStruct.cpp) | Defines `Student` and nested `Date` structs; demonstrates struct copying and pass-by-value |
| [`EmployeManagementSystem.cpp`](./OOP-Pointers-and-Structures/EmployeManagementSystem.cpp) | Full CRUD employee system using a dynamic heap array of structs and member functions |
| [`matrixtranpose.cpp`](./OOP-Pointers-and-Structures/matrixtranpose.cpp) | Allocates a 2D matrix on the heap using `int**`, performs in-place transpose with pointer arithmetic |
| [`reversearray.cpp`](./OOP-Pointers-and-Structures/reversearray.cpp) | Generic array reversal via `void*` and type casting for `int`, `char`, and `bool` arrays |
| [`captilizesentences.cpp`](./OOP-Pointers-and-Structures/captilizesentences.cpp) | Capitalizes each word using `char**` double pointers and a dynamic 2D char array |
| [`inventoryManagementSystem.cpp`](./OOP-Pointers-and-Structures/inventoryManagementSystem.cpp) | *(In progress)* Inventory management system using structs and pointers |

**Key concepts practiced:**
- Single, double, and void pointers
- Pointer arithmetic and dereferencing
- Dynamic memory with `new[]` / `delete[]`
- Nested structs and struct member functions
- Pass-by-pointer and pass-by-reference

---

### 2. 🔶 Classes and Inheritance

> **Folder:** [`OOP-Classes-and-Inheritance/`](./OOP-Classes-and-Inheritance)

Covers class design fundamentals — const-correctness, static members, dynamic memory inside classes, copy constructors, operator/method chaining, and single inheritance.

| File | Description |
|------|-------------|
| [`ConstStaticDemo.cpp`](./OOP-Classes-and-Inheritance/ConstStaticDemo.cpp) | Demonstrates why `const` member functions can't modify state, and why `static` member functions can only access `static` data |
| [`ObjectCounter.cpp`](./OOP-Classes-and-Inheritance/ObjectCounter.cpp) | A self-counting class using a `static` member to track how many instances have been created |
| [`StudentSectionManager.cpp`](./OOP-Classes-and-Inheritance/StudentSectionManager.cpp) | `Student` and `Section` classes managing multiple sections of students with add/update/print functionality |
| [`JaggedArray.cpp`](./OOP-Classes-and-Inheritance/JaggedArray.cpp) | Dynamically allocated jagged (ragged) 2D array using `int**`; supports method chaining |
| [`TollboothSimulation.cpp`](./OOP-Classes-and-Inheritance/TollboothSimulation.cpp) | Tollbooth simulation tracking paying/non-paying cars and cash collected using `static` members |
| [`TimeAddition.cpp`](./OOP-Classes-and-Inheritance/TimeAddition.cpp) | `ClockTime` class that adds two time objects together with hour/minute/second rollover |
| [`CarInfo.cpp`](./OOP-Classes-and-Inheritance/CarInfo.cpp) | `Car` class demonstrating a user-defined copy constructor |
| [`ScientistChemist.cpp`](./OOP-Classes-and-Inheritance/ScientistChemist.cpp) | `Scientist`/`Chemist` inheritance example demonstrating member function name hiding, resolved with the scope resolution operator |

**Key concepts practiced:**
- `const` member functions and const-correctness
- `static` data members and `static` member functions
- Dynamic memory management inside a class (constructor/destructor pairs)
- Copy constructors and deep vs. shallow copying
- Method chaining via reference-returning functions
- Single inheritance and function name hiding

---

<!-- ═══════════════════════════════════════════════════════════
     ADD NEW MODULE SECTIONS BELOW AS NEW FOLDERS ARE PUSHED
     Copy the template above and fill in the details.
     ════════════════════════════════════════════════════════ -->

---

## 🛠️ How to Compile & Run

All programs use standard C++11 (or later). Compile any file with:

```bash
# Using g++
g++ -std=c++11 -o output filename.cpp
./output

# Using MSVC (Visual Studio Developer Command Prompt)
cl filename.cpp
filename.exe
```

---

## 📋 Topics Roadmap

| # | Topic | Status |
|---|-------|--------|
| 1 | Pointers & Structures | ✅ Done |
| 2 | Classes & Objects | ✅ Done |
| 3 | Constructors & Destructors | ✅ Done |
| 4 | Inheritance | ✅ Done |
| 5 | Polymorphism & Virtual Functions | 🔜 Coming soon |
| 6 | Operator Overloading | 🔜 Coming soon |
| 7 | Templates | 🔜 Coming soon |
| 8 | File I/O | 🔜 Coming soon |

---

## 👨‍💻 Author

**Moosa Rehan**  
BS Computer Science — OOP Coursework  
[github.com/moosarehan](https://github.com/moosarehan)

---

<p align="center">⭐ Star this repo if you find it useful!</p>
