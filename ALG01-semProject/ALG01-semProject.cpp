#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
/// <summary>
/// Function for printing path result
/// </summary>
/// <param name="path"></param>
static void PrintResult(std::vector<Point*> path) {
  if (path.empty())
  {
    std::cout << "There is not path" << std::endl;
  }
  else
  {
    for (size_t i = 0; i < path.size(); i++)
    {
      std::cout << "[" << path[i]->GetX() << "," << path[i]->GetY() << "]" << " level " << path[i]->PrintLevel() << std::endl;
    }
    std::cout << "Total path length: " << path.back()->GetDistance() << std::endl;
  }
}
/// <summary>
/// Solution for shortest-path find
/// </summary>
/// <returns></returns>
int main()
{
  Map* map = Map::LoadFromFile("input.txt");
  map->CalculatePath();
  std::vector<Point*> path = map->GetPath();

  PrintResult(path);
  std::cout << map->PrintMap() << std::endl;

  delete map;
  return 0;
}
