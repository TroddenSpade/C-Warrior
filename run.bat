@echo off

IF EXIST ".\main.exe" del ".\main.exe" /s /f /q

IF EXIST ".\profile\Play.c" (
    ECHO .\profile\Play.c  exists
) ELSE (
    echo .\profile\Play.c  doesn't exist, creating a new Player.c ..
    @echo off
    (
    echo void playTurn(^)
    echo {
    echo     // your code goes here
    echo }
    ) >.\profile\Play.c
)

gcc ./src/Main.c ./src/Logic.c -o main

cls

.\main