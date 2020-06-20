#include <Arduboy2.h>

Arduboy2 arduboy;


enum class GameState
{
  TitleScreen,
  GamePlay,
  GameOver,
};

GameState gameState = GameState::TitleScreen;

enum class CharacterState
{
  Standing,
  Running,
  Jumping,
  Ducking,
};

CharacterState characterState = CharacterState::Standing;

void setup() {
  arduboy.begin();
  arduboy.clear();

}

void loop() {
  if(!arduboy.nextFrame()) {
    return;
  }

  arduboy.pollButtons();
  
  arduboy.clear();

  switch (gameState)
  {
    case GameState::TitleScreen:
      updateTitleScreen();
      drawTitleScreen();
      break;
    case GameState::GamePlay:
      updateGamePlay();
      drawGamePlay();
      break;
    case GameState::GameOver:
      updateGameOver();
      drawGameOver();
      break;
  }
  arduboy.display();
}

//TitleScreen
void updateTitleScreen()
{
  if(arduboy.pressed(A_BUTTON)) {
    gameState = GameState::GamePlay;
  }
}

void drawTitleScreen()
{
  arduboy.print(F("Title Screen"));
  arduboy.setCursor(0,10);
  arduboy.print(F("Press A"));
}

//GamePlay Update & Draw
void updateGamePlay()
{
  updateCharacter();
}

void drawGamePlay()
{
  
}

//GameOver
void updateGameOver()
{
  
}

void drawGameOver()
{
  
}

//Character
void updateCharacter()
{
  if(arduboy.pressed(UP_BUTTON)) {
    characterState = CharacterState::Jumping;
  }else if(arduboy.pressed(RIGHT_BUTTON)) {
    characterState = CharacterState::Running;
  }else if(arduboy.pressed(DOWN_BUTTON)) {
    characterState = CharacterState::Ducking;
  } else {
    characterState = CharacterState::Standing;
  }
  switch(characterState)
  {
    case CharacterState::Jumping:
      updateCharacterJumping();
      break;
    case CharacterState::Standing:
      updateCharacterStanding();
      break;
    case CharacterState::Running:
      updateCharacterRunning();
      break;
    case CharacterState::Ducking:
      updateCharacterDucking();
      break;
  }
}

//CharacterState
void updateCharacterStanding()
{
  arduboy.print(F("Standing"));
}

void updateCharacterJumping()
{
  arduboy.print(F("Jumping"));
}

void updateCharacterRunning()
{
  arduboy.print(F("Running"));
}

void updateCharacterDucking()
{
  arduboy.print(F("Ducking"));
}
