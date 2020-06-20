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
  updateCharacterStanding,
  updateCharacterRunning,
  updateCharacterJumping,
  updateCharacterDucking,
};

CharacterState characterState = CharacterState::updateCharacterStanding;

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
  switch(characterState)
  {
    case CharacterState::updateCharacterStanding:
      updateStanding();
      break;
    case CharacterState::updateCharacterJumping:
      updateJumping();
      break;
    case CharacterState::updateCharacterRunning:
      updateRunning();
      break;
    case CharacterState::updateCharacterDucking:
      updateDucking();
      break;
  }
  arduboy.display();

  if(arduboy.pressed(UP_BUTTON)) {
    characterState = CharacterState::updateCharacterJumping;
  }else if(arduboy.pressed(RIGHT_BUTTON)) {
    characterState = CharacterState::updateCharacterRunning;
  }else if(arduboy.pressed(DOWN_BUTTON)) {
    characterState = CharacterState::updateCharacterDucking;
  } else {
    characterState = CharacterState::updateCharacterStanding;
  }
}

//CharacterState
void updateStanding()
{
  arduboy.print(F("Standing"));
  arduboy.display();
}

void updateJumping()
{
  arduboy.print(F("Jumping"));
  arduboy.display();
}

void updateRunning()
{
  arduboy.print(F("Running"));
  arduboy.display();
}

void updateDucking()
{
  arduboy.print(F("Ducking"));
  arduboy.display();
}
