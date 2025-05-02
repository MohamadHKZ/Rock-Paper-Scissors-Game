# Rock-Paper-Scissors Console Game

This is a **C++ console-based Rock-Paper-Scissors Game** where the player competes against the computer in multiple rounds. The game includes visual feedback, real-time results, and an option to replay after finishing.

## Features

- **Interactive Gameplay**:
  - Choose how many rounds to play (1 to 10).
  - Play each round by selecting Stone (Rock), Paper, or Scissors.
  - The computer randomly selects its move each round.

- **Immediate Round Feedback**:
  - Color-coded feedback:
    - Green: Player wins the round
    - Red: Computer wins the round
    - Yellow: Draw
  - Sound alert (`\a`) on computer win

- **Detailed Summary**:
  - At the end of the game, a report is shown:
    - Total number of rounds
    - Player wins, Computer wins, Draws
    - Final winner based on overall results

- **Replay Option**:
  - Option to play the game again after the final result

## Enum-Based Game Logic

- Uses an `enum` for player and computer choices:
  - 1: Stone
  - 2: Paper
  - 3: Scissors

## Utility Features

- **Input Validation**:
  - Ensures the user provides valid choices using a validation function.

## Note

This game uses Windows-specific functions (`system("cls")`, `system("color")`, `Sleep()`, etc.), and will not run as expected on Linux/macOS without modification.
