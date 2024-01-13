#pragma once
#include <iostream>
#include <vector>
#include <cmath>

std::vector< std::vector<int> > table_construct (int n, std::vector<int> &vec);

int RMQ (int a, int b, std::vector< std::vector<int> > vec2D);