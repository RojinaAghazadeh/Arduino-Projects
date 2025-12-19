#Arduino-based Digital Code Lock
Arduino-based Digital Code Lock is a simple keypad-controlled door lock system built using Arduino, a 4×4 keypad, an LCD display, and a relay. The system verifies a user-entered password and controls access by activating a relay when the correct code is entered.

How It Works?
The user enters a 4-digit password using the keypad.
Each key press is masked on the LCD with * for security.

When the = key is pressed:

If the password is correct (1,2,3,4 in this case), the relay is activated, indicating the door is unlocked for 5 seconds.

If the password is incorrect, an error message is displayed.

The C key resets the input and locks the system again.

Status LEDs show whether the door is locked or unlocked.