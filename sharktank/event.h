#pragma once
#include "sgg/graphics.h"

class Event {

protected:
	float m_pos_x;
	float m_pos_y;

	float m_duration = 1.0f;
	float m_delay = 0.0f;
	float m_elapsed_time = 0.0f;
	float m_elapsed_delay = 0.0f;


	bool m_active = true;


public:
	virtual void draw() {};
	virtual void update();

	Event(float x = 0.0f, float y = 0.0f, float dur = 2.0f, float delay = 0.0f);


	virtual ~Event() {};

	bool active() {
		return m_active;
	}

	void disable() { m_active = false; }
	bool waiting();

};




class PlayerMotionEvent : public Event {

	class Player* m_player;
	float m_start_x;
	float m_start_y;
	float m_stop_x;
	float m_stop_y;

public:
	void update() override;

	PlayerMotionEvent(float start_x, float start_y, float stop_x, float stop_y, class Player* p);

};




