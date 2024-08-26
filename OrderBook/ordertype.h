#pragma once

enum class OrderType
{
	GoodTillCancel,
	FillAndKill,
	FillOrKill,
	GoodForDay, // 9 : 15 to 3:30pm 
	Market, // execute directly
};