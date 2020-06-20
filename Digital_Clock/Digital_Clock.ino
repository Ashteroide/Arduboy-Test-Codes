#include <Arduboy2.h>

Arduboy2 arduboy;

int seconds;
int minutes;
int hours;

enum class State
{
  Main,
};

State state = State::Main;

void setup() {
  arduboy.begin();
  arduboy.clear();
  seconds = 0;
  minutes = 0;
  hours = 0;

}

void loop() {
  if(!arduboy.nextFrame()) {
    return;
  }

  arduboy.pollButtons();
  arduboy.clear();

  switch(state)
  {
    case State::Main:
      updateMain();
      drawMain();
  }
  delay(1000);
  ++seconds;
  arduboy.display();

}

void updateMain()
{
  if(seconds == 60) {
    seconds = 0;
    ++minutes;
  }
  if(minutes == 60) {
    minutes = 0;
    ++hours;
  }
}

void drawMain()
{
  arduboy.print(F("Seconds: "));
  arduboy.println(seconds);
  arduboy.print(F("Minutes: "));
  arduboy.println(minutes);
  arduboy.print(F("Hours: "));
  arduboy.println(hours);

  Serial.println(F(""));
  Serial.println(seconds);
  Serial.println(minutes);
  Serial.println(hours);

}
