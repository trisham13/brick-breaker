# Instructions

---

## Set-Up

In order to set up brick breaker on your device, you should have the following installed:

* CLion (or other C++ IDE)
* Cinder (a C++ graphics library)

You can play the game by selecting the brick-breaker configuration from the drop-down next to the run button, or run
from the cinder_app_main.cc file in the apps directory. Another window should pop up in your desktop which will hold the
game graphics. Simply press the spacebar and you are good to go!

## Learn to Play!

The objective of the game is to break all the bricks on the screen (as the name of the game suggests!) with a movable
paddle, which is controlled with the left and right keys. If the ball passes the paddle, the ball will leave the
container and you will lose a life. It will return the ball and paddle to the initial position and will allow you to
restart the play. You will start with 5 lives and there are 3 levels. You must break all the bricks in each level
without losing all your lives in order to win the game. Each time you progress to a new level, you will gain an extra
life. The bricks may be of different types, each one having a different number of hits required to break and a different
score for for each hit. If you lose all your lives before finishing the levels, the game will be over.

### Brick Types

There are three types of bricks within the game:

* Strong Brick
* Cracked Brick
* Unbreakable Brick

The Unbreakable brick is just that: unbreakable. Your ball will bounce off of them with no change to score or the brick
itself. The Strong brick requires 2 hits to break, the first hit will reward you 20 points. It is portrayed as a darker
pink color. After the first hit, it turns into a Cracked brick. The Cracked brick requires only one hit to break and
will reward you 50 points. It is portrayed as a lighter pink color.