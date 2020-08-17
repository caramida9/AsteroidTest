#include "PlayingState.h"
#include "System.h"
#include "Game.h"

PlayingState::PlayingState()
{
}

PlayingState::~PlayingState()
{
}

void PlayingState::OnActivate(System *system, StateArgumentMap &args)
{
	Game *game = system->GetGame();

	level_ = args["Level"].asInt;
	game->InitialiseLevel(level_);
}

void PlayingState::OnUpdate(System *system)
{
	Game *game = system->GetGame();
	game->Update(system);
	if (game->IsLevelComplete())
	{
		StateArgumentMap args;
		args["Level"].asInt = level_ + 1;
		system->SetNextState("LevelStart", args);
		game->playerHP = 3;
	}
	else if (game->IsGameOver())
	{
		InsertScore(system, game->score);
		game->score = 0;
		game->playerHP = 3;
		system->SetNextState("GameOver");
	}
}

void PlayingState::InsertScore(System* system, int score)
{
	int i = 0;
	while(score < system->highscores[i])
	{
		i++;
	}
	for (int j = 8; j >= i; j--)
	{
		system->highscores[j + 1] = system->highscores[j];
	}
	system->highscores[i] = score;
}

void PlayingState::OnRender(System *system)
{
	Game *game = system->GetGame();
	game->RenderEverything(system->GetGraphics());
}

void PlayingState::OnDeactivate(System *system)
{
}
