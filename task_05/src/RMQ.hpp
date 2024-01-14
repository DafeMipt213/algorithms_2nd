#pragma once
#include <cmath>
#include <iostream>
#include <vector>

std::vector<std::vector<int> > table_construct(int n, std::vector<int> &vec);

int RMQ(int a, int b, std::vector<std::vector<int> > vec2D);