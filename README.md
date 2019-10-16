# C Warrior

This is a game designed to teach the C language and artificial intelligence in a fun, interactive way.

You play as a warrior climbing a tall tower to save a _prinCess_ at the top level. On each floor you need to write a C script to instruct the warrior to battle enemies, rescue captives, and reach the stairs. You have some idea of what each floor contains, but you never know for certain what will happen. You must give the Warrior enough artificial intelligence up-front to find his own way.

## Getting Started

### Prerequisites

GNU Compiler Collection (GCC)

- Linux

```
sudo apt install gcc
```

- MacOs

```
brew install gcc
```

- Others [GCC website](https://gcc.gnu.org/install/binaries.html)

Assign execute permission to run.sh (for Linux and MacOs)

```
chmod +x run.sh
```

### How to Play !

First download this [repo](https://github.com/TroddenSpade/C-Warrior/archive/master.zip)

Then run the following command

- Terminal

```
./run.sh
```

- CMD

```
run
```

Choose a Tower and then setup your profile.
This will create a profile directory in your current location where you can see `Play.c` that contains :

```
void playTurn(Warrior *warrior)
{
    // your code goes here
}

```

Your objective is to fill this “playTurn” function with commands to instruct the warrior what to do. With each level your abilities will grow along with the difficulty. See the `README.md` in profile's directory for details on what abilities your warrior has available on the current level.

Here is a simple example which will instruct the warrior to walk forward.

```
void playTurn(Warrior *warrior)
{
    warrior->walk();
}

```

Once you are done editing `Play.c`, save the file and run the `run.sh` again to start playing the level. The play happens through a series of turns. On each one, your `playTurn` function is called along with any enemy's.

You cannot change your code in the middle of a level. You must take into account everything that may happen on that level and give your warrior the proper instructions from the start.

Losing all of your health will cause you to fail the level. You are not punished by this, you simply need to go back to your `Play.c`, improve your code, and try again.

Once you pass a level (by reaching the stairs), the profile `README.md` will be updated for the next level. Alter the `Play.c` file and run `run.sh` again to play the next level.

## Commands

### Actions

```
warrior->walk()
  Move in given direction (forward by default).

warrior->attack()
  Attack the unit in given direction (forward by default).

warrior->rest()
  Gain 10% of max health back, but do nothing more.

warrior->bind()
  Bind unit in given direction to keep him from moving (forward by default).

warrior->rescue()
  Rescue a captive from his chains (earning 50 points) in given direction (forward by default).
```

### Sense

```
warrior->feel
  Returns a Space for the given direction (forward by default).

warrior->health()
  Returns an integer representing your health.

warrior->maxHealth()
  Returns an integer representing your health.

warrior->distance()
  Returns the number of spaces the stairs are away.

warrior->listen()
  Returns an array of all spaces which have units in them.

```

### Feel

```
feel->empty()
  If true, this means that nothing (except maybe stairs) is at this location and you can walk here.

feel->stairs()
  Determine if stairs are at that location

feel->enemy()
  Determine if an enemy unit is at this location.

feel->captive()
  Determine if a captive is at this location.

feel->wall()
  Returns true if this is the edge of the level. You can't walk here.

feel->ticking()
  Returns true if this space contains a bomb which will explode in time.

feel->golem()
  Returns true if a golem is occupying this space.
```

## Epic Mode

Once you reach the top of the tower, you will enter epic mode. When running rubywarrior again it will run your current player.rb through all levels in the tower without stopping.

Your warrior will most likely not succeed the first time around, so use the -l option on levels you are having difficulty or want to fine-tune the scoring.

```
rubywarrior -l 3
```

Once your warrior reaches the top again you will receive an average grade, along with a grade for each level. The grades from best to worst are S, A, B, C, D and F. Try to get S on each level for the ultimate score.

Note: I'm in the process of fine-tuning the grading system. If you find the “S” grade to be too easy or too difficult to achieve on a given level, please add an issue for this on GitHub.

## Create a New Tower

```
- towers
    - baby-steps
        - actions.C
        - index.c
        - warrior.c
        - rm1
        .
        .
        .

    - YOUR_TOWER
    .
    .
    .

    - list.c
```

### actions.c

Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.

### warrior.c

Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.

### index.c

Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.

### rm

Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.

## Contributing

Please read [CONTRIBUTING](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Authors

- **Parsa Samadnejad** - _Initial work_

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

## Acknowledgments

- Credits for the original idea go to [Ryan Bates](https://github.com/ryanb) - [ruby-warrior](https://github.com/ryanb/ruby-warrior).
- Inspired By [warriorjs](https://github.com/olistic/warriorjs) - [Matías Olivera](https://github.com/olistic)
