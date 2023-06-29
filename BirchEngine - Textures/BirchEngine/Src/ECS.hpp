#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
class Component; // прототип класса
class Entity;
using ComponentID = std::size_t; //???

inline ComponentID getComponentID()
{
	static ComponentID lastID = 0;
	return lastID++;
}