# Number Guessing Game 🎮

A C++ console-based number guessing game where the player competes against the computer by guessing a randomly generated number.

## Features

- Generate a random number between **1 and 1000**
- Interactive guessing with hints (too high / too low)
- Count the number of attempts
- Evaluate player performance using a 5-level scoring system
- Compare the player's average score with a simulated global average
- Display encouraging or humorous feedback based on the final result
- Support multiple game rounds

## Scoring System

| Attempts | Level | Performance |
|----------|------:|-------------|
| 1 | 5 | Excellent |
| 2 | 4 | Very Good |
| 3 | 3 | Good |
| 4 | 2 | Average |
| 5 or more | 1 | Poor |

## Concepts Used

- C++
- Functions
- Loops (`do...while`)
- Conditional Statements
- `switch`
- Random Number Generation (`rand`)
- Performance Analysis
- Console-Based Game Development

## How to Run

Compile the program:

```bash
g++ main.cpp -o GuessGame
```

Run the executable:

```bash
./GuessGame
```

## Project Purpose

This project was developed to practice C++ programming fundamentals, including loops, functions, conditional statements, random number generation, and designing interactive console applications.
