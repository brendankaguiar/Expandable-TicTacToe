#include "Player.h"

Player::Player(const char _token) :token(_token){}
Player::Player() {}
void Player::setToken(const char _token)
{
	token = _token;
}
char Player::getToken() const
{
	return token;
}
