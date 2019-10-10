rm -r ./main.exe
rm -r ./main
rm -r ./main.out

FILE=./profile/Play.c
if [ -f "$FILE" ]; then
    echo "$FILE exist"
else 
    echo "$FILE does not exist, creating a new player.c ..."
    echo "void playTurn()
{
    // your code goes here
}" > "$FILE"
fi

gcc ./src/Main.c ./src/Logic.c -o main.out

clear

./main.out