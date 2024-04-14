#include "Point.h"

Point::Point(int x, int y, char level) : x(x), y(y), level(level)
{}

Point::~Point()
{
  this->previous = nullptr;
}

int Point::GetX()
{
    return x;
}

int Point::GetY()
{
  return y;
}

int Point::GetDistance()
{
  return distance;
}

char Point::GetLevel()
{
  if (level == 'S')
  {
    return 'a';
  }  
  if (level == 'E')
  {
    return 'z';
  }
  return level;
}
char Point::PrintLevel()
{
  return level;
}

void Point::SetDistance(int distance)
{
  this->distance = distance;
}

void Point::AddPrevious(Point* point)
{
  this->previous = point;
}

Point* Point::GetPrevious()
{
  if (this->previous == nullptr)
  {
    return nullptr;
  }
  return this->previous;
}


