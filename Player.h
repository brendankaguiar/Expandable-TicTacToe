#ifndef Player_H
#define Player_H
class Player
{
private:
	char token;
public:
	Player(const char _token);
	Player();
	void setToken(const char _token);
	char getToken() const;
};
#endif // !Player_H
