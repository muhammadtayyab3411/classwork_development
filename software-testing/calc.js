// Calculator class
class Calculator {
  // Addition method
  add(a, b) {
    return a + b;
  }

  // Subtraction method
  subtract(a, b) {
    return a - b;
  }

  // Multiplication method
  multiply(a, b) {
    return a * b;
  }

  // Division method
  divide(a, b) {
    if (b === 0) {
      throw new Error('Division by zero is not allowed.');
    }
    return a / b;
  }
}

// Export Calculator class
module.exports = Calculator;
