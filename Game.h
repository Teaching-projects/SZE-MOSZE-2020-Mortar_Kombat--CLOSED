#ifndef JSON_H
#define JSON_H

#include <deque>
#include <iostream>
#include <string>

#include "Map.h"
#include "Hero.h"
#include "Monster.h"

struct characterUnit
{
	Character character;
	int posx, posy;
	characterUnit(Character _character, int _posx, int _posy) 
		: character(_character), posx(_posx), posy(_posy) {}
};

class Game
{
private:
	Map field;
	std::deque<characterUnit> heroUnits, monsterUnits;
public:
	Game() : field(Map()) {};
	Game(std::string mapfilename) : field(Map(mapfilename)) {}
	void setMap(Map map);
	void putHero(Hero hero, int x, int y);
	void putMonster(Monster monster, int x, int y);
	class OccupiedException : public std::exception {};
	class AlreadyHasHeroException : public std::exception {};
	class AlreadyHasUnitsException : public std::exception{};
	class NotInitializedException : public std::exception {};
	void run();
private:
	void displayField();
	void moveHero(std::string input);
	void fightOnPos();
};

#endif