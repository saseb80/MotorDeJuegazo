#include "pch.h"
#include "Player.h"
#include <string>



Player::Player(){
}


Player::~Player(){
}

void Player::Update(){
	std::cout << _idNum << ": Update Player" << std::endl;
}
