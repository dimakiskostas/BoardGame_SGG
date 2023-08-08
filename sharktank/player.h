#pragma once


class Player {

public:
	float m_pos[2];
	float m_color[3];

	bool m_highlighted = false;
	bool m_active = false;

	int name = 0;
	
	int teamID = 0;

public:
	virtual void draw();
	void update();

	Player();

	float getPosX() { return m_pos[0]; }
	float getPosY() { return m_pos[1]; }
	void setPosX(float x) { m_pos[0] = x; }
	void setPosY(float y) { m_pos[1] = y; }


	void setHighlight(bool h) { m_highlighted = h; }

	void setActive(bool a) { m_active = a; }

	bool contains(float x, float y);

	void setTeamId(int x) { teamID = x; }

	void setName(int a) { name = a; }

	int getName() { return name; }

	int getIteamId() { return teamID; }

	virtual bool intersect(Player* tgt);
};


class NextPlayer : public Player { //xifias

public:
	void draw() override;
	
	NextPlayer();

};

class Squid : public Player {

public:
	void draw() override;


	Squid();

};

class Whale : public Player {

public:
	void draw() override;

	Whale();
};

class Oct : public Player {

public:
	void draw() override;


	Oct();

};



