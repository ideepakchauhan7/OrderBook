#pragma once

#include "using.h"

struct LevelInfo
{
    Price price_;
    Quantity quantity_;
};
using LevelInfos = std::vector<LevelInfo>;