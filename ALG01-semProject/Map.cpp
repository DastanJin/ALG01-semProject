#include "Map.h"
#include <iostream>
#include <queue>
/// <summary>
/// Map object constructor for specified size
/// </summary>
/// <param name="rows">Row count</param>
/// <param name="cols">Column count</param>
Map::Map(int rows, int cols) : rows(rows), cols(cols)
{
  this->mapArray = std::vector<Point*>();
}

/// <summary>
/// Destructor for deleting all objects in map object
/// </summary>
Map::~Map()
{
  for (int i = 0; i < this->rows * this->cols; i++)
  {
    for (auto ptr : mapArray) {
      delete ptr;
    }
    mapArray.clear();
    start = nullptr;
    finish = nullptr;
  }
}

/// <summary>
/// Start point getter
/// </summary>
/// <returns>start point</returns>
Point* Map::GetStart()
{
  return this->start;
}

/// <summary>
/// End point getter
/// </summary>
/// <returns>finish point</returns>
Point* Map::GetFinish()
{
  return this->finish;
}

/// <summary>
/// Loads point into map
/// </summary>
/// <param name="point">point to be added</param>
void Map::AddPoint(Point* point)
{
  if (point->PrintLevel() == 'S')
  {
    start = point;
  }
  if (point->PrintLevel() == 'E')
  {
    finish = point;
  }
  mapArray.push_back(point);
}
/// <summary>
/// Getting point from map
/// </summary>
/// <param name="x">column index in map</param>
/// <param name="y">row index in map</param>
/// <returns>selected point from map</returns>
Point* Map::GetPoint(int x, int y)
{
  if (x * y > mapArray.size() || x >= cols || y >= rows || x < 0 || y < 0)
  {
    return nullptr;
  }
  return mapArray[x + (y * cols)];
}


/// <summary>
/// Print actual state of Map
/// </summary>
/// <returns>console printable string</returns>
std::string Map::PrintMap()
{
  std::string mapString;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      Point* point = GetPoint(x, y);

      if (point == nullptr) {
        mapString += ' ';
      }
      else {
        mapString += point->PrintLevel();
      }
    }
    mapString += '\n';
  }
  return mapString;
}

/// <summary>
/// Processing two neighbour points
/// </summary>
/// <param name="actual">actually used point</param>
/// <param name="next">potentially accessable point</param>
/// <returns>next point to process only if it is not already processed</returns>
Point* Map::ProcessPoint(Point* actual, Point* next) {
  if (next != nullptr && next->GetDistance() == 2147483647 && (next->GetLevel() == actual->GetLevel() || next->GetLevel() == (actual->GetLevel() + 1)))
  {
    next->AddPrevious(actual);
    next->SetDistance(actual->GetDistance() + 1);
    return next;
  }
  return nullptr;
}
/// <summary>
/// Calculating shortest path
/// Implementation Breadth-first search for each neighbour
/// Ends when reach end or check all points
/// </summary>
void Map::CalculatePath() {
  start->SetDistance(0);
  std::queue<Point*> queue;
  queue.push(start);

  while (queue.size() > 0)
  {
    Point* actualPoint = queue.front();
    Point* up = ProcessPoint(actualPoint, GetPoint(actualPoint->GetX(), actualPoint->GetY() - 1));
    if (up != nullptr)
    {
      if (up == finish)
      {
        break;
      }
      queue.push(up);
    }
    Point* right = ProcessPoint(actualPoint, GetPoint(actualPoint->GetX() + 1, actualPoint->GetY()));
    if (right != nullptr)
    {
      if (right == finish)
      {
        break;
      }
      queue.push(right);
    }
    Point* down = ProcessPoint(actualPoint, GetPoint(actualPoint->GetX(), actualPoint->GetY() + 1));
    if (down != nullptr)
    {
      if (down == finish)
      {
        break;
      }
      queue.push(down);
    }
    Point* left = ProcessPoint(actualPoint, GetPoint(actualPoint->GetX() - 1, actualPoint->GetY()));
    if (left != nullptr)
    {
      if (left == finish)
      {
        break;
      }
      queue.push(left);
    }

    queue.pop();
  }
}
/// <summary>
/// Return results from calculated path
/// </summary>
/// <returns>array of Points from start to end</returns>
std::vector<Point*> Map::GetPath() {
  std::vector<Point*> result;
  if (finish->GetPrevious() == nullptr)
  {
    return result;
  }
  Point* point = finish;
  while (point != nullptr) {
    result.push_back(point);
    point = point->GetPrevious();
  }
  std::reverse(result.begin(), result.end());
  return result;
}
/// <summary>
/// Reading map version from file
/// </summary>
/// <param name="filename">path to file with map input</param>
/// <returns>new Map generated from text</returns>
Map* Map::LoadFromFile(const std::string& filename) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Error opening file!" << std::endl;
    return nullptr;
  }

  std::string line;
  std::getline(file, line);
  int rows = std::stoi(line);
  std::getline(file, line);
  int cols = std::stoi(line);

  Map* map = new Map(rows, cols);

  for (int y = 0; y < rows; y++) {
    std::getline(file, line);
    for (int x = 0; x < cols; x++) {
      Point* point = new Point(x, y, line[x]);
      map->AddPoint(point);
    }
  }

  file.close();

  return map;
}
