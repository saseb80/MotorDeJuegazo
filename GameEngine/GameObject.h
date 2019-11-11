#pragma once
#include<iostream>

class GameObject {
	public:
		short id;
		virtual void Update();
		GameObject(){}
		GameObject(short i) : id(i) {}
		~GameObject() {}
};

