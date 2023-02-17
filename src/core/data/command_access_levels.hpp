#pragma once
#include "core/enums.hpp"

namespace big
{
	inline std::unordered_map<CommandAccessLevel, const char*> COMMAND_ACCESS_LEVELS =
	{
		{ CommandAccessLevel::NONE, "无权限" },
		{ CommandAccessLevel::FRIENDLY, "友好" },
		{ CommandAccessLevel::AGGRESSIVE, "攻击性" },
		{ CommandAccessLevel::TOXIC, "有毒的" },
		{ CommandAccessLevel::ADMIN, "管理员权限" }
	};
}