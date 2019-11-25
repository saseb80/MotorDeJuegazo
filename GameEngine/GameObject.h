#pragma once
#include<iostream>

class GameObject {

public:
	int _id;
	short id;
	virtual void Update();
	GameObject(){}
	GameObject(int id) : _id(id) {}
	~GameObject() {}
};

