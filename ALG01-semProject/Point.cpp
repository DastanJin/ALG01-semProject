#include "Point.h"
/// <summary>
/// Creates nnew point
/// </summary>
/// <param name="x"></param>
Point::Point(int x, int y, char level) : x(x), y(y), level(level)
{}

/// <summary>
/// Destroys actual point and its refferences
/// </summary>
Point::~Point()
{
  this->previous = nullptr;
}

/// <summary>
/// Getter for x directory
/// </summary>
/// <returns>index x</returns>
int Point::GetX()
{
  return x;
}

/// <summary>
/// Getter for y directory
/// </summary>
/// <returns>index y</returns>
int Point::GetY()
{
  return y;
}

/// <summary>
/// Getter for distance
/// </summary>
/// <returns>distance as integer</returns>
int Point::GetDistance()
{
  return distance;
}

/// <summary>
/// Getter for level replacing start with 'a' value and end with 'z'
/// </summary>
/// <returns></returns>
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

/// <summary>
/// Getter for level with real char value from map
/// </summary>
/// <returns></returns>
char Point::PrintLevel()
{
  return level;
}

/// <summary>
/// Setter for distance
/// </summary>
/// <param name="distance"></param>
void Point::SetDistance(int distance)
{
  this->distance = distance;
}

/// <summary>
/// Method for adding refference to previous Point
/// </summary>
/// <param name="point"></param>
void Point::AddPrevious(Point* point)
{
  this->previous = point;
}

/// <summary>
/// Getter for actual stored previous Point
/// </summary>
/// <returns>pointer to previous Point</returns>
Point* Point::GetPrevious()
{
  if (this->previous == nullptr)
  {
    return nullptr;
  }
  return this->previous;
}


