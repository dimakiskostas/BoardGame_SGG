#include "game.h"
#include "defines.h"
#include<sgg/graphics.h>
#include <string>

/*
11 -> shark
12 -> whale
13 -> swordfish
14 -> squid
15 -> octopus
*/

void Game::draw() {
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);


	//draw start screen
	if (m_state == STATE_INIT) {

		graphics::playMusic(std::string(ASSET_PATH) + "Pirates_Of_The_Caribbean_Theme_Song.mp3", 0.2f, true, 3000);


		graphics::Brush br;


		br.fill_opacity = 1.5f;
		br.fill_color[0] = 1.0;

		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 1.0f;

		br.texture = ASSET_PATH + std::string("start.png");
		br.outline_opacity = 0.0f;

		float offset = 1.2f * sinf(graphics::getGlobalTime() / 10.0f) / 3;

		graphics::drawRect((CANVAS_WIDTH / 2), (CANVAS_HEIGHT / 2), CANVAS_WIDTH, CANVAS_HEIGHT, br);

		br.fill_opacity = 6.3f;
		br.fill_color[0] = 0.0f;

		br.fill_color[1] = 0.0f;
		br.fill_color[2] = 1.0f;

		graphics::setFont("OpenSans-Bold.ttf");
		graphics::drawText(CANVAS_WIDTH / 2.6f, CANVAS_HEIGHT / 4, 1.0f, "FISH WORLD", br);



		br.fill_opacity = 3.0f;
		br.fill_color[0] = 0.0;

		br.fill_color[1] = 0.0f;
		br.fill_color[2] = 1.0f;

		graphics::setFont("OpenSans-Bold.ttf");

		//The instructions are appeared on the starting screen
		if (graphics::getKeyState(graphics::SCANCODE_RETURN))
		{
			graphics::playSound(std::string(ASSET_PATH) + "buttonClick.mp3", 0.2f, false);
			graphics::drawText(CANVAS_WIDTH / 5.2f, CANVAS_HEIGHT / 2.0f, 1.3f, ">>> Press [ENTER] to play <<<", br);

		}
		else {
			graphics::drawText(CANVAS_WIDTH / 3.8f, CANVAS_HEIGHT / 2.0f, 1.0f, ">>> Press [ENTER] to play <<<", br);

		}

		if (graphics::getKeyState(graphics::SCANCODE_ESCAPE)) {
			graphics::playSound(std::string(ASSET_PATH) + "buttonClick.mp3", 0.2f, false);

			graphics::drawText(CANVAS_WIDTH / 4.5f, CANVAS_HEIGHT / 1.6f, 1.3f, ">>> Press [ESC] to quit <<<", br);
		}
		else {
			graphics::drawText(CANVAS_WIDTH / 3.5f, CANVAS_HEIGHT / 1.6f, 1.0f, ">>> Press [ESC] to quit <<<", br);

		}

		if (graphics::getKeyState(graphics::SCANCODE_RETURN))
		{


			m_state = STATE_LOADING;

		}
		else if (graphics::getKeyState(graphics::SCANCODE_ESCAPE)) {
			m_state == STATE_EXIT;
		}

		return;
	}

	//draw backgoud
	br.outline_opacity = 0.0f;

	br.texture = ASSET_PATH + std::string("backround.png");

	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);


	graphics::Brush sq;
	sq.outline_opacity = 0.2f;
	sq.fill_opacity = 0.0f;
	for (int i = 0; i < CANVAS_WIDTH / PLAYER_SIZE; i++) {
		for (int j = 0; j < CANVAS_WIDTH / PLAYER_SIZE; j++) {
			float x = (i + 0.5f) * PLAYER_SIZE;
			float y = (j + 0.5f) * PLAYER_SIZE;
			

			//draw the board
			graphics::drawRect(x, y, PLAYER_SIZE, PLAYER_SIZE, sq);
		}
	}


	//moving range for each player
	graphics::Brush reticle;
	if (m_state == STATE_MOVING) {

		if (m_active_player->getName() == 11) {
			SETCOLOR(reticle.fill_color, 0.0f, 0.0f, 0.0f);
			reticle.fill_opacity = 0.3f;
			reticle.outline_opacity = 0.7f;
			SETCOLOR(reticle.outline_color, 0.0f, 0.0f, 0.0f);
			graphics::drawDisk(m_init_pos_x, m_init_pos_y, PLAYER_MOTION_RANGE_SHARK, reticle);

		}
		if (m_active_player->getName() == 12) {
			SETCOLOR(reticle.fill_color, 0.0f, 0.0f, 0.0f);
			reticle.fill_opacity = 0.3f;
			reticle.outline_opacity = 0.7f;
			SETCOLOR(reticle.outline_color, 0.0f, 0.0f, 0.0f);
			graphics::drawDisk(m_init_pos_x, m_init_pos_y, PLAYER_MOTION_RANGE_FALAINA, reticle);

		}

		if (m_active_player->getName() == 13) {
			SETCOLOR(reticle.fill_color, 0.0f, 0.0f, 0.0f);
			reticle.fill_opacity = 0.3f;
			reticle.outline_opacity = 0.7f;
			SETCOLOR(reticle.outline_color, 0.0f, 0.0f, 0.0f);
			graphics::drawDisk(m_init_pos_x, m_init_pos_y, PLAYER_MOTION_RANGE_XIFIAS, reticle);

		}

		if (m_active_player->getName() == 14) {
			SETCOLOR(reticle.fill_color, 0.0f, 0.0f, 0.0f);
			reticle.fill_opacity = 0.3f;
			reticle.outline_opacity = 0.7f;
			SETCOLOR(reticle.outline_color, 0.0f, 0.0f, 0.0f);
			graphics::drawDisk(m_init_pos_x, m_init_pos_y, PLAYER_MOTION_RANGE_SQUID, reticle);

		}


		if (m_active_player->getName() == 15) {
			SETCOLOR(reticle.fill_color, 0.0f, 0.0f, 0.0f);
			reticle.fill_opacity = 0.3f;
			reticle.outline_opacity = 0.7f;
			SETCOLOR(reticle.outline_color, 0.0f, 0.0f, 0.0f);
			graphics::drawDisk(m_init_pos_x, m_init_pos_y, PLAYER_MOTION_RANGE_XTAPODI, reticle);

		}

	}

	//attacking range for each player
	else if (m_state == STATE_ATTACKING) {

		if (m_active_player->getName() == 11) {
			SETCOLOR(reticle.fill_color, 1.0f, 0.0f, 0.0f);
			reticle.fill_opacity = 0.3f;
			reticle.outline_opacity = 0.7f;
			SETCOLOR(reticle.outline_color, 1.0f, 0.0f, 0.0f);
			graphics::drawDisk(m_init_pos_x, m_init_pos_y, PLAYER_ATTACK_RANGE_SHARK, reticle);
		}
		if (m_active_player->getName() == 12) {
			SETCOLOR(reticle.fill_color, 1.0f, 0.0f, 0.0f);
			reticle.fill_opacity = 0.3f;
			reticle.outline_opacity = 0.7f;
			SETCOLOR(reticle.outline_color, 1.0f, 0.0f, 0.0f);
			graphics::drawDisk(m_init_pos_x, m_init_pos_y, PLAYER_ATTACK_RANGE_FALAINA, reticle);
		}
		if (m_active_player->getName() == 13) {
			SETCOLOR(reticle.fill_color, 1.0f, 0.0f, 0.0f);
			reticle.fill_opacity = 0.3f;
			reticle.outline_opacity = 0.7f;
			SETCOLOR(reticle.outline_color, 1.0f, 0.0f, 0.0f);
			graphics::drawDisk(m_init_pos_x, m_init_pos_y, PLAYER_ATTACK_RANGE_XIFIAS, reticle);
		}
		if (m_active_player->getName() == 14) {
			SETCOLOR(reticle.fill_color, 1.0f, 0.0f, 0.0f);
			reticle.fill_opacity = 0.3f;
			reticle.outline_opacity = 0.7f;
			SETCOLOR(reticle.outline_color, 1.0f, 0.0f, 0.0f);
			graphics::drawDisk(m_init_pos_x, m_init_pos_y, PLAYER_ATTACK_RANGE_SQUID, reticle);
		}
		if (m_active_player->getName() == 15) {
			SETCOLOR(reticle.fill_color, 1.0f, 0.0f, 0.0f);
			reticle.fill_opacity = 0.3f;
			reticle.outline_opacity = 0.7f;
			SETCOLOR(reticle.outline_color, 1.0f, 0.0f, 0.0f);
			graphics::drawDisk(m_init_pos_x, m_init_pos_y, PLAYER_ATTACK_RANGE_XTAPODI, reticle);
		}

	}



	for (auto player : m_players) {
		player->draw();
	}


	for (auto ev : m_events) {
		ev->draw();
	}
}

void Game::update()
{

	if (m_state == STATE_INIT) {
		return;
	}

	if (m_state == STATE_LOADING) {
		init();
		m_state = STATE_IDLE;
		return;
	}

	if (m_state == STATE_EXIT)
	{
		endScreen();

	}


	processEvents();

	//when the game needs to end
	for (auto player : m_players) {
		player->update();
	}

	sum1 = 0;
	for (auto player : m_players)
	{
		if (player->getIteamId() == 1) {
			sum1 = 1;
		}
	}

	sum2 = 0;
	for (auto player : m_players)
	{
		if (player->getIteamId() == 2) {
			sum2 = 1;
		}
	}

	if (sum1 == 0 || sum2 == 0)
		m_state = STATE_EXIT;

	graphics::MouseState ms;
	graphics::getMouseState(ms);

	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);


	Player* cur_player = nullptr;
	for (auto player : m_players) {
		if (player->contains(mx, my)) {
			player->setHighlight(true);
			cur_player = player;
		}
		else {
			player->setHighlight(false);
		}
	}


	//active player
	if (ms.button_left_pressed && cur_player) {
		m_active_player = cur_player;
		m_active_player->setActive(true);
		for (auto player : m_players) {
			if (player != m_active_player) {
				player->setActive(false);
			}
		}

		m_init_pos_x = m_active_player->getPosX();
		m_init_pos_y = m_active_player->getPosY();

	}


	//otan kineitai
	m_valid_action = false;
	if (ms.dragging && m_active_player) {
		m_state = STATE_MOVING;

		//Different motion range for each player (depends on his name)

		if (m_active_player->getName() == 11) {
			if (distance(m_init_pos_x, m_init_pos_y, mx, my) < PLAYER_MOTION_RANGE_SHARK) {

				mx = PLAYER_SIZE * (0.5f + (int)(mx / PLAYER_SIZE));
				my = PLAYER_SIZE * (0.5f + (int)(my / PLAYER_SIZE)); //o paikth paei se sigekrimena koytakia



				m_active_player->setPosX(mx);
				m_active_player->setPosY(my);
			}
			m_valid_action = true;
		}

		if (m_active_player->getName() == 14) {
			if (distance(m_init_pos_x, m_init_pos_y, mx, my) < PLAYER_MOTION_RANGE_SQUID) {

				mx = PLAYER_SIZE * (0.5f + (int)(mx / PLAYER_SIZE));
				my = PLAYER_SIZE * (0.5f + (int)(my / PLAYER_SIZE)); //o paikth paei se sigekrimena koytakia



				m_active_player->setPosX(mx);
				m_active_player->setPosY(my);
			}
			m_valid_action = true;
		}

		if (m_active_player->getName() == 13) {
			if (distance(m_init_pos_x, m_init_pos_y, mx, my) < PLAYER_MOTION_RANGE_XIFIAS) {

				mx = PLAYER_SIZE * (0.5f + (int)(mx / PLAYER_SIZE));
				my = PLAYER_SIZE * (0.5f + (int)(my / PLAYER_SIZE)); //o paikth paei se sigekrimena koytakia



				m_active_player->setPosX(mx);
				m_active_player->setPosY(my);
			}
			m_valid_action = true;
		}

		if (m_active_player->getName() == 15) {
			if (distance(m_init_pos_x, m_init_pos_y, mx, my) < PLAYER_MOTION_RANGE_XTAPODI) {

				mx = PLAYER_SIZE * (0.5f + (int)(mx / PLAYER_SIZE));
				my = PLAYER_SIZE * (0.5f + (int)(my / PLAYER_SIZE)); //o paikth paei se sigekrimena koytakia



				m_active_player->setPosX(mx);
				m_active_player->setPosY(my);
			}
			m_valid_action = true;
		}

		if (m_active_player->getName() == 12) {
			if (distance(m_init_pos_x, m_init_pos_y, mx, my) < PLAYER_MOTION_RANGE_FALAINA) {

				mx = PLAYER_SIZE * (0.5f + (int)(mx / PLAYER_SIZE));
				my = PLAYER_SIZE * (0.5f + (int)(my / PLAYER_SIZE)); //o paikth paei se sigekrimena koytakia



				m_active_player->setPosX(mx);
				m_active_player->setPosY(my);
			}
			m_valid_action = true;
		}


		m_target_player = nullptr;
		for (auto p : m_players) {
			if (p == m_active_player)
				continue;
			if (p->intersect(m_active_player)) {

				m_state = STATE_ATTACKING;
				m_target_player = p;

			}

		}

		//attacking
		//Different attack range for each player
		if (m_state == STATE_ATTACKING) {
			if (m_active_player->getName() == 11) {
				if (m_target_player != nullptr && distance(m_target_player->getPosX(), m_target_player->getPosY(), m_init_pos_x, m_init_pos_y) < PLAYER_ATTACK_RANGE_SHARK) {
					if (m_active_player->getIteamId() != m_target_player->getIteamId()) {
						m_valid_action = true;
					}
					else {
						m_valid_action = false;
					}
				}
				else {
					m_valid_action = false;
				}
			}

			if (m_active_player->getName() == 12) {
				if (m_target_player != nullptr && distance(m_target_player->getPosX(), m_target_player->getPosY(), m_init_pos_x, m_init_pos_y) < PLAYER_ATTACK_RANGE_FALAINA) {
					if (m_active_player->getIteamId() != m_target_player->getIteamId()) {
						m_valid_action = true;
					}
					else {
						m_valid_action = false;
					}
				}
				else {
					m_valid_action = false;
				}
			}

			if (m_active_player->getName() == 13) {
				if (m_target_player != nullptr && distance(m_target_player->getPosX(), m_target_player->getPosY(), m_init_pos_x, m_init_pos_y) < PLAYER_ATTACK_RANGE_XIFIAS) {
					if (m_active_player->getIteamId() != m_target_player->getIteamId()) {
						m_valid_action = true;
					}
					else {
						m_valid_action = false;
					}
				}
				else {
					m_valid_action = false;
				}
			}

			if (m_active_player->getName() == 14) {
				if (m_target_player != nullptr && distance(m_target_player->getPosX(), m_target_player->getPosY(), m_init_pos_x, m_init_pos_y) < PLAYER_ATTACK_RANGE_SQUID) {
					if (m_active_player->getIteamId() != m_target_player->getIteamId()) {
						m_valid_action = true;
					}
					else {
						m_valid_action = false;
					}
				}
				else {
					m_valid_action = false;
				}
			}

			if (m_active_player->getName() == 15) {
				if (m_target_player != nullptr && distance(m_target_player->getPosX(), m_target_player->getPosY(), m_init_pos_x, m_init_pos_y) < PLAYER_ATTACK_RANGE_XTAPODI) {
					if (m_active_player->getIteamId() != m_target_player->getIteamId()) {
						m_valid_action = true;
					}
					else {
						m_valid_action = false;
					}
				}
				else {
					m_valid_action = false;
				}
			}

			if (m_valid_action)
			{
				graphics::playSound(std::string(ASSET_PATH) + "bite.mp3", 0.2f, false);//bitting sound effect
			}

		}

	}

	if (ms.button_left_released && m_active_player) {

		if (!m_valid_action) {


			//getting the position before each move so if it's not valid then it returns on his original position
			float x_in = m_active_player->getPosX();
			float y_in = m_active_player->getPosY();

			float x_out = m_init_pos_x;
			float y_out = m_init_pos_y;

			addEvent(new PlayerMotionEvent(x_in, y_in, x_out, y_out, m_active_player));

		}

		m_state = STATE_IDLE;

		if (m_valid_action && m_target_player) {
			Player* tgt = m_target_player;
			m_players.remove_if([tgt](Player* pl) {return pl == tgt; });
			delete m_target_player;
		}


		m_target_player = nullptr;
		m_active_player->setActive(false);
		m_active_player = nullptr;

	}

	for (auto player : m_players) {
		player->update();
	}




}

/*
11 -> shark
12 -> whale
13 -> swordfish
14 -> squid
15 -> octopus

*/

void Game::init()
{

	/*
	Each player appears on the board , gets addes on the list m_players, gets a name and also a teamId
	if width >= 2 left
	if width <= 2 right

	if teamId == 1 right
	if teamId == 2 left

	11 -> shark
	12 -> whale
	13 -> swordfish
	14 -> squid
	15 -> octopus

	NextPlayer == xifias
	Player == shark
	Squid
	Whale
	Octopus

	*/
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			Player* p = new Player();
			m_players.push_front(p);
			p->setTeamId(2);
			p->setName(11);
			p->setPosX(CANVAS_WIDTH * (i + 4.73f) / 5.0f);
			p->setPosY(CANVAS_HEIGHT * (j + 1.52f) / 5.0f);
		}
	}

	graphics::preloadBitmaps(ASSET_PATH); //proteimazei ta assets

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			Player* p = new Player();
			m_players.push_front(p);
			p->setTeamId(1);
			p->setName(11);
			p->setPosX(CANVAS_WIDTH * (i + 0.26f) / 5.0f);
			p->setPosY(CANVAS_HEIGHT * (j + 1.52f) / 5.0f);
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			NextPlayer* nxt = new NextPlayer();
			m_players.push_front(nxt);
			nxt->setTeamId(1);
			nxt->setName(13);
			nxt->setPosX(CANVAS_WIDTH * (i + 0.26f) / 5.0f);
			nxt->setPosY(CANVAS_HEIGHT * (j + 0.43f) / 5.0f);
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			NextPlayer* nxt = new NextPlayer();
			m_players.push_front(nxt);
			nxt->setTeamId(1);
			nxt->setName(13);
			nxt->setPosX(CANVAS_WIDTH * (i + 0.26f) / 5.0f);
			nxt->setPosY(CANVAS_HEIGHT * (j + 4.05f) / 5.0f);
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			NextPlayer* nxt = new NextPlayer();
			m_players.push_front(nxt);
			nxt->setTeamId(2);
			nxt->setName(13);
			nxt->setPosX(CANVAS_WIDTH * (i + 4.73f) / 5.0f);
			nxt->setPosY(CANVAS_HEIGHT * (j + 0.43f) / 5.0f);
		}
	}

	
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			NextPlayer* nxt = new NextPlayer();
			m_players.push_front(nxt);
			nxt->setTeamId(2);
			nxt->setName(13);
			nxt->setPosX(CANVAS_WIDTH * (i + 4.73f) / 5.0f);
			nxt->setPosY(CANVAS_HEIGHT * (j + 4.05f) / 5.0f);
		}
	}
	

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			Squid* sq = new Squid();
			m_players.push_front(sq);
			sq->setTeamId(1);
			sq->setName(14);
			sq->setPosX(CANVAS_WIDTH * (i + 0.99f) / 5.0f);
			sq->setPosY(CANVAS_HEIGHT * (j + 0.97f) / 5.0f);
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			Squid* sq = new Squid();
			m_players.push_front(sq);
			sq->setTeamId(1);
			sq->setName(14);
			sq->setPosX(CANVAS_WIDTH * (i + 0.99f) / 5.0f);
			sq->setPosY(CANVAS_HEIGHT * (j + 1.8f) / 5.0f);
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			Squid* sq = new Squid();
			m_players.push_front(sq);
			sq->setTeamId(2);
			sq->setName(14);
			sq->setPosX(CANVAS_WIDTH * (i + 4.02f) / 5.0f);
			sq->setPosY(CANVAS_HEIGHT * (j + 1.8f) / 5.0f);
		}
	}


	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			Squid* sq = new Squid();
			m_players.push_front(sq);
			sq->setTeamId(2);
			sq->setName(14);
			sq->setPosX(CANVAS_WIDTH * (i + 4.02f) / 5.0f);
			sq->setPosY(CANVAS_HEIGHT * (j + 0.97f) / 5.0f);
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			Squid* sq = new Squid();
			m_players.push_front(sq);
			sq->setTeamId(2);
			sq->setName(14);
			sq->setPosX(CANVAS_WIDTH * (i + 4.02f) / 5.0f);
			sq->setPosY(CANVAS_HEIGHT * (j + 2.65f) / 5.0f);
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			Squid* sq = new Squid();
			m_players.push_front(sq);
			sq->setTeamId(2);
			sq->setName(14);
			sq->setPosX(CANVAS_WIDTH * (i + 4.02f) / 5.0f);
			sq->setPosY(CANVAS_HEIGHT * (j + 3.47f) / 5.0f);
		}
	}



	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			Squid* sq = new Squid();
			m_players.push_front(sq);
			sq->setTeamId(1);
			sq->setName(14);
			sq->setPosX(CANVAS_WIDTH * (i + 0.99f) / 5.0f);
			sq->setPosY(CANVAS_HEIGHT * (j + 2.65f) / 5.0f);
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			Squid* sq = new Squid();
			m_players.push_front(sq);
			sq->setName(14);
			sq->setTeamId(1);
			sq->setPosX(CANVAS_WIDTH * (i + 0.99f) / 5.0f);
			sq->setPosY(CANVAS_HEIGHT * (j + 3.47f) / 5.0f);
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			Whale* wh = new Whale();
			m_players.push_front(wh);
			wh->setTeamId(1);
			wh->setName(12);
			wh->setPosX(CANVAS_WIDTH * (i + 0.26f) / 5.0f);
			wh->setPosY(CANVAS_HEIGHT * (j + 2.91f) / 5.0f);
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			Whale* wh = new Whale();
			m_players.push_front(wh);
			wh->setTeamId(2);
			wh->setName(12);
			wh->setPosX(CANVAS_WIDTH * (i + 4.73f) / 5.0f);
			wh->setPosY(CANVAS_HEIGHT * (j + 2.91f) / 5.0f);
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			Oct* oc = new Oct();
			m_players.push_front(oc);
			oc->setTeamId(2);
			oc->setName(15);
			oc->setPosX(CANVAS_WIDTH * (i + 4.02f) / 5.0f);
			oc->setPosY(CANVAS_HEIGHT * (j + 4.3f) / 5.0f);
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			Oct* oc = new Oct();
			m_players.push_front(oc);
			oc->setTeamId(2);
			oc->setName(15);
			oc->setPosX(CANVAS_WIDTH * (i + 4.02f) / 5.0f);
			oc->setPosY(CANVAS_HEIGHT * (j + 0.15f) / 5.0f);
		}
	}


	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			Oct* oc = new Oct();
			m_players.push_front(oc);
			oc->setTeamId(1);
			oc->setName(15);
			oc->setPosX(CANVAS_WIDTH * (i + 0.99f) / 5.0f);
			oc->setPosY(CANVAS_HEIGHT * (j + 4.3f) / 5.0f);
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			Oct* oc = new Oct();
			m_players.push_front(oc);
			oc->setTeamId(1);
			oc->setName(15);
			oc->setPosX(CANVAS_WIDTH * (i + 0.99f) / 5.0f);
			oc->setPosY(CANVAS_HEIGHT * (j + 0.15f) / 5.0f);
		}
	}

}


Game::~Game()
{
	for (auto p : m_players) {
		delete p;
	}
	m_players.clear();
}

Game* Game::getInstance()
{
	if (!m_instance)
		m_instance = new Game();
	return m_instance;
}

void Game::processEvents()
{
	for (auto e : m_events) {
		e->update();
	}

	m_events.remove_if([](Event* ev) {return !ev->active(); });

}

void Game::addEvent(Event* evt)
{
	m_events.push_front(evt);
}

void Game::startScreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_RETURN)) //ENTER
	{
		m_state = STATE_LOADING;
	}
}

void Game::endScreen()
{
	/*
	* When the game ends, it stops and the winners pops up
	*/
	graphics::Brush br;
	graphics::stopMusic(1);

	br.fill_opacity = 1.5f;
	br.fill_color[0] = 1.0;

	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;

	br.texture = ASSET_PATH + std::string("start.png");
	br.outline_opacity = 0.0f;

	float offset = -1 * sinf(graphics::getGlobalTime() / 900.0f) / 6;

	graphics::drawRect((CANVAS_WIDTH / 2), (CANVAS_HEIGHT / 2), CANVAS_WIDTH, CANVAS_HEIGHT, br);

	br.fill_opacity = 10.3f;
	br.fill_color[0] = 2.0f;

	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;

	graphics::playSound(std::string(ASSET_PATH) + "winner_sound.mp3", 1.0f, false);

	if (sum1 == 0)
	{
		br.fill_opacity = 10.3f;
		br.fill_color[0] = 1.0f;

		br.fill_color[1] = 2.0f;
		br.fill_color[2] = 1.0f;

		graphics::setFont("OpenSans-Bold.ttf");
		graphics::drawText(CANVAS_WIDTH / 4.4f, CANVAS_HEIGHT / 4, 1.2f, "THE  WINNER  IS  PLAYER  2!", br);
	}
	else {

		br.fill_opacity = 10.3f;
		br.fill_color[0] = 1.0f;

		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 1.0f;

		graphics::setFont("OpenSans-Bold.ttf");
		graphics::drawText(CANVAS_WIDTH / 4.4f, CANVAS_HEIGHT / 4, 1.2f, "THE  WINNER  IS  PLAYER  1!", br);

	}

	graphics::setFont("OpenSans-Bold.ttf");
	graphics::drawText(CANVAS_WIDTH / 4.4f, CANVAS_HEIGHT / 2, 1.4f, "THANKS  FOR  PLAYING", br);

	graphics::stopMessageLoop();
}

Game* Game::m_instance = nullptr;