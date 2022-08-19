# Sexo Language
_A basic and hot programming language, created just for fun. **Note: is under development, so it contains several bugs.**_ 

## Contents
- [Installation](#installation) 
  - [Steps on Linux](#steps-on-linux) 
  - [Steps on Termux (Android OS)](#steps-on-termux-android-os) 
  - [Steps on Windows](#steps-on-windows) 
- [Getting Started](#getting-started) 
  - [Hello Sexo](#hello-sexo) 
  - [Examples](#examples) 
    - [Printing](#printing) 
    - [Store Values](#store-values) 
    - [Comments](#comments) 
- [Data Types](#data-types) 
- [Sex Mode (Interactive)](#sex-mode-interactive) 
- [Built-in Functions](#built-in-functions) 

##

## Installation

To install, you need a C/C++ compiler, CMake and a build tool

`Compilers:`
* **[GCC](https://gcc.gnu.org/)**
* **[Clang](https://clang.llvm.org/)**
* **[MSVC (Visual Studio)](https://visualstudio.microsoft.com//downloads/)**

`Build Tools:`
* **[GNU Make](https://www.gnu.org/software/make/)**
* **[Ninja](https://ninja-build.org/)**

`CMake:`
* **[CMake](https://cmake.org/)**

##

**Clone this repository with the command:**
```
git clone https://github.com/1Leep/sexo-language.git
```
**Enter in the repository folder:**
```
cd sexo-language/
``` 

### Steps on Linux 

- **compiling with Clang or GCC**
```
cmake -S . -B build 
cmake --build build  
cmake --install build 
```

### Steps on Termux (Android OS) 

- **compiling with Clang or GCC**
```
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=/data/data/com.termux/files/usr
cmake --build build 
cmake --install build 
```

### Steps on Windows

- **compiling with MSVC**
```
cmake -S . -B build 
cmake --build build --config Release
cmake --install build 
```

- **compiling with Clang or GCC**
```
cmake -S . -B build 
cmake --build build 
cmake --install build 
```

- **configuring environment variable**

1. Open the Start Search, type in “env”, and choose “Edit the system environment variables”: 
![img](https://www.architectryan.com/static/start_menu-91c0473bae32fa3862658e4d6e62d75c-2facb.png) 

2. Click the “Environment Variables…” button.
![img](https://www.architectryan.com/static/system_properties-f3a4f86cdd178c48ed9d8398743f85df-39c95.png) 

3. Under the “System Variables” section (the lower half), find the row with “Path” in the first column, and click edit. 
![img](https://www.architectryan.com/static/select_row_and_edit-48423a2a0724e226bd3f69468d9eaabd-70c4b.png) 

4. The “Edit environment variable” UI will appear. Here, you can click “New” and type the Sexo Lang Installation directory:
`C:\Program Files (x86)\sexo\bin`

5. Click on the 'OK' button to save the changes and restart the terminal. 

##

## Getting Started

### Hello Sexo
After installing the interpreter, we will create our first program in Sexo Lang. 
As in other programming languages, it's essential to start with a simple program that prints a hello world on the screen, that's exactly what we're going to do now! 

**Create a file with the extension `.sexo` (which is the extension used for Sexo Lang codes)
and put the code to print the text on the screen:**
```py
cumshot("Hello Sexo") 
```
**and run the command for the interpreter to read the code:**
```
sexo file.sexo
```
```
output: Hello Sexo 
```

**Congratulations, you just created your first program in Sexo Lang!**

##

## Examples
Some examples are available in the [examples folder](https://github.com/1Leep/sexo-language/tree/main/examples) 

### Printing
To print things on the screen, you must use the 'cumshot' function 
```py
cumshot("Oh", "Yeah", 69) 
```
_multiple values can be added using commas_

##

### Store Values
To store values, you must use variables. Use the keyword 'dick' to declare variables. 
```py
dick leep = 69
```
_a variable can storage any data type as value_

##

### Comments
A comment is used to document the code and help programmers. 
```py
# that's a comment 
```
_to write a comment, add the # symbol before the content you want to be ignored by the interpreter_

##

## Data Types
Programming languages have data types as String, Numbers and more... 
Sexo Lang is no different, check out the list of language data types:

Type      |     Description      |  Example
----------|----------------------|----------------
Number    | any number type      | `6.9`
String    | texts and characters | `"Hello Sexo"`
Boobslean | boolean values       | `boobs` / `no_boobs`

##

## Sex Mode (Interactive) 
In some languages, such as Python, interactive mode is used for you to be able to execute commands directly in the terminal, without the need to create a file. 

**To enter in Sexo Lang interactive mode, simply run the command:** `sexo`

![img](https://media.discordapp.net/attachments/802215195959230566/1008234306491138078/Screenshot_20220814-014215_Termux.png) 

##

## Built-in Functions

### `cumshot(args)`

- _~~cums~~ print some value on the screen._

Parameter | Type    | Optional |  Description      |
----------|---------|----------|-------------------|
args      | Any     |  ✅      | any value to show |

Returns: **void**

> Example:
```py
cumshot('Leep', 69)
```
