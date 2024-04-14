#pragma once
class Point
{
private:
	int x;
	int y;
	char level;
	int distance = 2147483647;//int maxvalue
	Point* previous = nullptr;
public:
	Point(int x, int y, char level);
	~Point();
	int GetX();
	int GetY();
	int GetDistance();
	char GetLevel();
	char PrintLevel();
	void SetDistance(int distance);
	void AddPrevious(Point* point);
	Point* GetPrevious();


};