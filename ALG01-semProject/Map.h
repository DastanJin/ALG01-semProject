#pragma once
#include "Point.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
/// <summary>
/// Map class used for load, store and return path find results
/// </summary>
class Map
{
private:
	std::vector<Point*> mapArray;
	Point* start = nullptr;
	Point* finish = nullptr;
	int rows;
	int cols;
	Point* ProcessPoint(Point* actual, Point* next);
public:
	Map(int rows, int cols);
	~Map();
	Point* GetStart();
	Point* GetFinish();
	void AddPoint(Point* point);
	Point* GetPoint(int x, int y);
	std::string PrintMap();
	void CalculatePath();
	std::vector<Point*> GetPath();
	static Map* LoadFromFile(const std::string& filename);


};