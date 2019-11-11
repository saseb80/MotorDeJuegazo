#include "pch.h"
#include "Player.h"



Player::Player(){
}

Player::Player(short i) : GameObject(i){

}

Player::~Player(){
}

void Player::Update(){
	std::cout << id << ": Update Player" << std::endl;
}
