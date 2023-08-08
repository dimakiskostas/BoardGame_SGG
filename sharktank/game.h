#pragma once
#include <list>
#include "player.h"
#include "event.h"

class Game {

public:
	int sum1;
	int sum2;
	bool flag1 = false;;
	bool flag2 = false;
	bool flag = true;
	enum game_state_t { STATE_INIT, STATE_LOADING, STATE_IDLE, STATE_MOVING, STATE_ATTACKING, STATE_START_SCREEN, STATE_EXIT };

	int id = 1;

	static Game* m_instance;

	std::list<Player*> m_players;
	std::list<Event*> m_events;


	Player* m_active_player = nullptr;
	Player* m_target_player = nullptr;
	float m_init_pos_x;
	float m_init_pos_y;
	bool m_valid_action = false;


	game_state_t m_state = STATE_INIT;


	Game() {}




public:
	void draw();
	void update();

	void init();

	~Game();

	static void releaseInstance() { if (m_instance) delete m_instance; m_instance = nullptr; }
	static Game* getInstance();

	void startScreen();

	void endScreen();

	void processEvents();
	void addEvent(Event* evt);

};