del ".\main.exe" /s /f /q

if exist .\data\Player.c (
    echo ".\profile\Play.c  exists"
) else (
    echo ".\profile\Play.c  doesn't exist, creating a new Player.c ..."
    @echo off
    (
    echo void playTurn(^)
    echo {
    echo     // your code goes here
    echo }
    ) >.\data\Player.c 
)

gcc main.c .\player\player.c -o main

REM cls

.\main