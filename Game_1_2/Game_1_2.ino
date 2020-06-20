#include <Arduboy2.h>

Arduboy2 arduboy;

enum class GameState
{
  TitleScreen,
  GamePlay,
  GameOver,
};

GameState gameState = GameState::TitleScreen;

enum class Character
{
  Standing,
  Running,
  Jumping,
  Ducking,
};

Character character = Character::Standing;


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

  switch(gameState)
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

void updateTitleScreen()
{
  if(arduboy.pressed(A_BUTTON)) {
    gameState = GameState::GamePlay;
  }
}

void drawTitleScreen()
{
  arduboy.print(F("Title Screen"));
  arduboy.setCursor(0, 10);
  arduboy.print("Press A");
}

void updateGamePlay()
{
  if(arduboy.pressed(UP_BUTTON)) {
    character = Character::Jumping;
  }else if(arduboy.pressed(DOWN_BUTTON)) {
    character = Character::Ducking;
  }else if(arduboy.pressed(RIGHT_BUTTON) || arduboy.pressed(LEFT_BUTTON)) {
    character = Character::Running;
  } else {
    character = Character::Standing;
  }
  if(arduboy.pressed(B_BUTTON)) {
    gameState = GameState::GameOver;
  }
}

void drawGamePlay()
{
  switch(character)
  {
    case Character::Standing:
      arduboy.print(F("Standing"));
      break;
    case Character::Jumping:
      arduboy.print(F("Jumping"));
      break;
    case Character::Running:
      arduboy.print(F("Running"));
      break;
    case Character::Ducking:
      arduboy.print(F("Ducking"));
      break;
  }
}

void updateGameOver()
{
  if(arduboy.justPressed(B_BUTTON)) {
    gameState = GameState::TitleScreen;
  }
}

void drawGameOver()
{
  arduboy.print(F("Game Over!"));
}
