#pragma once
#include "BaseGameState.h"

/*
	This state describes game over screen which appears when
	player lost all lives. It can probably be merged with
	GameOverLives.

	Screen logic: show "Game Over", wait for 5 seconds, go to
	High Scores screen.
*/
class GameStateGameOverTime : public BaseGameState
{
	float m_timer;

public:
	GameStateGameOverTime()
		: BaseGameState( GAMESTATE_GAME_OVER_TIME )
	{
	}

	void RenderBefore( IRender & render, const IGameContext & context );
	void RenderAfter( IRender & render, const IGameContext & context );
	void Update( float dt, IGameContext & context );

	bool AllowPhysicsUpdate() const { return false; }
	bool AllowGraphicsUpdate() const { return false; }
	bool AllowGraphicsRender() const { return false; }
	bool AllowAIUpdate() const { return false; }

	void OnPush( IGameContext & context );
	void OnRemove( IGameContext & context ) {}
};
