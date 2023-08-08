#include "player.h"
#include "sgg/graphics.h"
#include "defines.h"
#include <string>

void Player::draw()
{
	graphics::Brush br;

	float h = 1.0 * m_highlighted;

	SETCOLOR(br.fill_color, h, h, h);
	br.outline_opacity = 5.0f * m_active;
	graphics::drawDisk(m_pos[0], m_pos[1], PLAYER_SIZE * 0.55f, br);


	SETCOLOR(br.fill_color, m_color[0], m_color[1], m_color[2]);
	br.texture = ASSET_PATH + std::string("7a1f9eba0c05a6e6d88fed35568ab03d-modified.png");
	br.outline_opacity = 0.0f;
	graphics::drawRect(m_pos[0], m_pos[1], PLAYER_SIZE, PLAYER_SIZE, br);

}

void Player::update()
{
}

Player::Player()
{
	SETCOLOR(m_color, 1.0f, 1.0f, 1.0f);

}

bool Player::contains(float x, float y)
{
	return distance(x, y, m_pos[0], m_pos[1]) < PLAYER_SIZE * 0.6f;
}

bool Player::intersect(Player* tgt)
{
	return distance(m_pos[0], m_pos[1], tgt->m_pos[0], tgt->m_pos[1]) < PLAYER_SIZE * 0.55f * 1.0f;

}

void NextPlayer::draw()
{
	graphics::Brush brs;

	float h = 1.0 * m_highlighted;

	SETCOLOR(brs.fill_color, h, h, h);
	brs.outline_opacity = 5.0f * m_active;
	graphics::drawDisk(m_pos[0], m_pos[1], PLAYER_SIZE * 0.55f, brs);


	SETCOLOR(brs.fill_color, m_color[0], m_color[1], m_color[2]);
	brs.texture = ASSET_PATH + std::string("F_SUM21_swordfish_opener-modified.png");
	brs.outline_opacity = 0.0f;
	graphics::drawRect(m_pos[0], m_pos[1], PLAYER_SIZE, PLAYER_SIZE, brs);

}



NextPlayer::NextPlayer()
{
	SETCOLOR(m_color, 1.0f, 1.0f, 1.0f);

}


void Squid::draw()
{
	graphics::Brush brs;

	float h = 1.0 * m_highlighted;

	SETCOLOR(brs.fill_color, h, h, h);
	brs.outline_opacity = 5.0f * m_active;
	graphics::drawDisk(m_pos[0], m_pos[1], PLAYER_SIZE * 0.55f, brs);


	SETCOLOR(brs.fill_color, m_color[0], m_color[1], m_color[2]);
	brs.texture = ASSET_PATH + std::string("IMG_8948_m_DMedit-modified.png");
	brs.outline_opacity = 0.0f;
	graphics::drawRect(m_pos[0], m_pos[1], PLAYER_SIZE, PLAYER_SIZE, brs);

}

Squid::Squid()
{
	SETCOLOR(m_color, 1.0f, 1.0f, 1.0f);

}

void Whale::draw()
{
	graphics::Brush brs;

	float h = 1.0 * m_highlighted;

	SETCOLOR(brs.fill_color, h, h, h);
	brs.outline_opacity = 5.0f * m_active;
	graphics::drawDisk(m_pos[0], m_pos[1], PLAYER_SIZE * 0.55f, brs);


	SETCOLOR(brs.fill_color, m_color[0], m_color[1], m_color[2]);
	brs.texture = ASSET_PATH + std::string("screen-4-modified.png");
	brs.outline_opacity = 0.0f;
	graphics::drawRect(m_pos[0], m_pos[1], PLAYER_SIZE, PLAYER_SIZE, brs);

}


Whale::Whale()
{
	SETCOLOR(m_color, 1.0f, 1.0f, 1.0f);

}

void Oct::draw()
{
	graphics::Brush brs;

	float h = 1.0 * m_highlighted;

	SETCOLOR(brs.fill_color, h, h, h);
	brs.outline_opacity = 5.0f * m_active;
	graphics::drawDisk(m_pos[0], m_pos[1], PLAYER_SIZE * 0.55f, brs);


	SETCOLOR(brs.fill_color, m_color[0], m_color[1], m_color[2]);
	brs.texture = ASSET_PATH + std::string("artworks-000595056471-c353us-t500x500-modified.png");
	brs.outline_opacity = 0.0f;
	graphics::drawRect(m_pos[0], m_pos[1], PLAYER_SIZE, PLAYER_SIZE, brs);

}

Oct::Oct()
{
	SETCOLOR(m_color, 1.0f, 1.0f, 1.0f);
}




