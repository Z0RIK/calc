# Basic Calc

This calculator app is a simple project created to test the custom functions `guiIntBox()` and `guiFloatBox()` that i added to [raygui.h](https://github.com/raysan5/raygui). The app provides a basic graphical user interface that allows users to perform addition, subtraction, multiplication, and division operations.

## Update

This [app](https://github.com/raysan5/raygui/tree/master/examples/custom_input_box) can now be found in examples folder of raygui.h library.

## Functionality

- Addition: Enter two numbers and click the "+" button to get the result.
- Subtraction: Enter two numbers and click the "-" button to get the result.
- Multiplication: Enter two numbers and click the "*" button to get the result.
- Division: Enter two numbers (numerator and denominator) and click the "/" button to get the result.

## How to build

1. Clone this repo
```bash
git clone https://github.com/Z0RIK/calc.git
```

2. Create and enter build directory:

```bash
cd calc
mkdir build
cd build
```

3. Configure and build the project:

```bash
cmake -S ..
cmake --build . 
```

