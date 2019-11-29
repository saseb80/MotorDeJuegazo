#pragma once
#include <iostream>
#include <string>

class GameObject {

public:
	std::string _idStr;
	long _idNum = 0;
	int colisionIndex = 0;
	virtual void Update();
	GameObject(){}
	GameObject(std::string idStr,long idNum){
		_idNum = idNum;
		_idStr = idStr;

	}
	~GameObject() {}
};

