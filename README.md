# Sexo Language
_A basic and hot programming language, created just for fun. **Note: is under development, so it contains several bugs.**_ 

## Contents
- [Installation](#installation) 
  - [Steps on Linux](#steps-on-linux) 
  - [Steps on Termux (Android OS)](#steps-on-termux-android-os) 
- [Getting Started](#getting-started) 
  - [Hello Sexo](#hello-sexo) 
  - [Examples](#examples) 
    - [Printing](#printing) 
    - [Store Values](#store-values) 
    - [Comments](#comments) 
- [Data Types](#data-types) 
- [Built-in Functions](#built-in-functions) 

##

## Installation

To install, you need a C compiler and a build tool

`Compilers:`
* **[GCC](https://gcc.gnu.org/)**
* **[Clang](https://clang.llvm.org/)**

`Build Tools:`
* **[GNU Make](https://www.gnu.org/software/make/)**

##

**Clone this repository with the command:**
```
$ git clone https://github.com/1Leep/sexo-language.git
```

### Steps on Linux 

Enter in the repository folder:
```
$ cd sexo-language/
```

And run this commands:
```
$ sudo make install-linux
$ make clean
```

### Steps on Termux (Android OS) 

Enter in the repository folder:
```
$ cd sexo-language/
```

And run this commands:
```
$ make install-termux
$ make clean
```

##

## Getting Started

### Hello Sexo
After installing the interpreter, we will create our first program in Sexo Lang. 
As in other programming languages, it's essential to start with a simple program that prints a hello world on the screen, that's exactly what we're going to do now! 

**Create a file with the extension `.sexo` (which is the extension used for Sexo Lang codes)
and put the code to print the text on the screen:**
```
cumshot("Hello Sexo") 
```
**and run the command for the interpreter to read the code:**
```
$ sexo file.sexo
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
```
cumshot("Oh", "Yeah", 69) 
```
_multiple values can be added using commas_

##

### Store Values
To store values, you must use variables. Use the keyword 'dick' to declare variables. 
```
dick leep = 69
```
_a variable can storage any data type as value_

##

### Comments
A comment is used to document the code and help programmers. 
```
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

## Built-in Functions

- `cumshot(args)`

_~~cums~~ print some value on the screen._

Parameter | Type    | Optional |  Description      |
----------|---------|----------|-------------------|
args      | Any     |  ✅      | any value to show |

Returns: **void**

`Example:`
```
cumshot('Leep', 69)
```
