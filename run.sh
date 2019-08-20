rm -r ./main.exe
rm -r ./main
rm -r ./main.out

FILE=./data/Player.c
if [ -f "$FILE" ]; then
    echo "$FILE exist"
else 
    echo "$FILE does not exist, creating a new player.c ..."
    echo "void playTurn()
{
    // your code goes here
}" > "$FILE"
fi

gcc main.c ./player/player.c -o main

clear

./main