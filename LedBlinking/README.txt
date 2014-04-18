Task 1 (watch): I give you a complete design with a C file and a DSN file. Watch how I build and simulate this design. We will use two tools, namely, MPLABX and Proteus-ISIS. In this design all LEDs blink.

Task 2 (watch): I will modify the design by adding a switch connected to E0 (sw1). Pushing the switch makes B LEDs out-of-phase. Watch how I do the modifications.

Task 3 (do): Delete LEDs B6, B7, C6, C7, D6, D7. Add a second switch and connect it to B6 (sw2). Switches sw1,sw2 form a 2-bit number. A=00, B=01, C=10, D=11. The corresponding row of LEDs become out-of-phase.

Task 4 (do): In this one, switch sw2 acts as an "enter". Switch sw1 lets us enter 0 or 1 at a time. It is a serial line. If we enter 010011, it means 010=2 011=3. 010 is B (A=001, C=011, D=100). 010 011 means B3. As a result B3  starts blinking.

Task 5 (do): Put what is in Task 4 on to the board. Make it work. Pay attention to jumpers/config. switches and the bounce problem.
