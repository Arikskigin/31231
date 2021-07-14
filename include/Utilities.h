#pragma once
#include <SFML/Graphics.hpp>
auto const WINDOW_WIDTH = 1360;
auto const WINDOW_HEIGHT = 680;
auto const WINDOW_WIDTH_HELP = 1100;
auto const WINDOW_HEIGHT_HELP = 600;
auto const BOARD_GAME_WIDTH = 1000;
auto const BOARD_MENU_WIDTH = 360;
auto const SIZE_OF_IMAGE = 70;
auto const NUM_OF_LEVEL = 3;
const sf::Vector2f RIGHT_VEC = { 1,0 };
const sf::Vector2f LEFT_VEC = { -1,0 };
const sf::Vector2f UP_VEC = { 0,-1 };
const sf::Vector2f DOWN_VEC = { 0,1 };
const sf::Vector2f STAY_VEC = { 0,0 };
const sf::Vector2f RECTANGLE_HELP_SIZE = { 70,45 };
const sf::Vector2f RECTANGLE_HELP_POSITION = { 70,45 };
auto const VIEW_SPEED = 150.f;
auto const SHOOT_SPEED = 300.f;
auto const MONSTER_SPEED = 50.f;
auto const PRE_LIMIT_VIEW_X = 280;
auto const PRE_LIMIT_VIEW_Y = 420;
auto const LIMIT_VIEW_X = 1580;
auto const LIMIT_VIEW_Y = 1080;
auto const SIZE_CHARACTER = 40.f;
auto const LIMIT_COMMAND_X = 50;
auto const LIMIT_COMMAND_Y = 30;
auto const FRAME_LIMIT = 8;
auto const NUM_OF_SCREEN_HELP = 2;
auto const NUM_OF_OBSERVER_PLAYER = 2;
auto const SECOND_SHOOT_MONSTER = 2;
auto const COLLISION_SHOOT_PLAYER = 6;
auto const SIZE_IMAGE_ANIMATION = 4;
auto const EPSILON = 4;
auto const PLAYER_LIVE = 3;
auto const LEVEL_TIME = 60;
auto const PRITECTED_TIME = 10;



enum ObjectsNames
{
	PLAYER = '@',
	MONSTER = '%',
	WALL = '-',
	GIFT = '+',
	FLOOR = '#',
	EMPTY = ' '
};

enum Objects
{
player_0,
monster_1,
wall_2,
gift_3,
wanted_4
};





enum Direction { RIGHT, DOWN, LEFT, UP, STAY };
