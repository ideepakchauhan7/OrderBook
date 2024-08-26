#pragma once

#include <limits>

#include "using.h"

struct constants
{
    static const Price InvalidPrice = std::numeric_limits<Price>::quiet_NaN();
};
