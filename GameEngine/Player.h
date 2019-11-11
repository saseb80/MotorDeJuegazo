#pragma once
#include "GameObject.h"
class Player :
	public GameObject{
public:
	void Update();
	Player();
	Player(short i);
	~Player();
};

