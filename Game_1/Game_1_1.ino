#include <Arduboy2.h>

Arduboy2 arduboy;

bool c_run;
bool c_stand;
bool c_jump;
bool c_duck;

enum class GameState
{
  Character,
};

GameState gameState = GameState::Character;

enum class CharacterState
{
  Standing,
  Running,
  Jumping,
  Ducking,
};

CharacterState characterState = CharacterState::Standing;

void reset()
{
  c_run = false;
  c_stand = true;
  c_jump = false;
  c_duck = false;
}

void setup() {
  arduboy.begin();
  arduboy.clear();
  reset();

}

void loop() {
  if(!arduboy.nextFrame()) {
    return;
  }
  arduboy.pollButtons();

  arduboy.clear();

  switch (gameState)
  {
    case GameState::Character:
      CharacterInput();
      CharacterDraw();
      break;
  }
  arduboy.display();

}

void CharacterDraw()
{
  switch(characterState)
  {
  case CharacterState::Standing:
    arduboy.print(F("Standing"));
    break;
    
  case CharacterState::Jumping:
    arduboy.print(F("Jumping"));
    break;
    
  case CharacterState::Ducking:
    arduboy.print(F("Ducking"));
    break;
    
  case CharacterState::Running:
    arduboy.print(F("Running"));
    break;
  }
}


void CharacterInput()
{
  if(arduboy.pressed(UP_BUTTON)) {
    characterState = CharacterState::Jumping;
  } else if (arduboy.pressed(DOWN_BUTTON)) {
    if (characterState != CharacterState::Jumping) {
      characterState = CharacterState::Ducking;
    }
  } else if (arduboy.pressed(RIGHT_BUTTON)|| arduboy.pressed(LEFT_BUTTON)) {
    if (characterState != CharacterState::Jumping) {
      characterState = CharacterState::Running;
    }
  } else {
    characterState = CharacterState::Standing;
  }
}
