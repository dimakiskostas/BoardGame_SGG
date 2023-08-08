#include "event.h"
#include "sgg/graphics.h"
#include "defines.h"
#include "player.h"


void Event::update()
{
	if (!m_active) {
		return;
	}

	if (waiting()) {
		m_elapsed_delay += graphics::getDeltaTime() / 1000.0f;
		return;
	}

	m_elapsed_time += graphics::getDeltaTime() / 1000.0f;
	if (m_elapsed_time > m_duration) {
		m_active = false;
	}
}

Event::Event(float x, float y, float dur, float del)
	:m_pos_x(x), m_pos_y(y), m_duration(dur), m_delay(del)
{

}

bool Event::waiting()
{
	return m_elapsed_delay < m_delay;
}



void PlayerMotionEvent::update()
{
	Event::update();
	if (!m_player) {
		m_active = false;
		return;
	}

	if (waiting()) {
		return;
	}

	float s = m_elapsed_time / m_duration;
	float x = m_start_x * (1.0f - s) + m_stop_x * s;
	float y = m_start_y * (1.0f - s) + m_stop_y * s;

	m_player->setPosX(x);
	m_player->setPosY(y);



}

PlayerMotionEvent::PlayerMotionEvent(float start_x, float start_y, float stop_x, float stop_y, Player* p)
	:Event(0.0f, 0.0f, 1.0f, 0.0f), m_start_x(start_x), m_stop_x(stop_x), m_start_y(start_y), m_stop_y(stop_y),
	m_player(p)
{

}
