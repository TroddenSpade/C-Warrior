rm -r ./data/*

echo "void player_turn()
{
    // your code goes here
}" > "./data/player.c"

gcc main.c ./player/player.c -o main