const Calculator = require('./calc.js');

describe('Calculator', () => {
  let calculator;

  beforeEach(() => {
    calculator = new Calculator();
  });

  test('Addition: Adds two numbers correctly', () => {
    expect(calculator.add(2, 3)).toBe(5);
  });

  test('Subtraction: Subtracts one number from another correctly', () => {
    expect(calculator.subtract(5, 3)).toBe(2);
  });

  test('Multiplication: Multiplies two numbers correctly', () => {
    expect(calculator.multiply(2, 3)).toBe(6);
  });

  test('Division: Divides one number by another correctly', () => {
    expect(calculator.divide(10, 2)).toBe(5);
  });

  test('Division by Zero: Throws error when attempting to divide by zero', () => {
    expect(() => calculator.divide(10, 0)).toThrow(
      'Division by zero is not allowed.'
    );
  });
});
