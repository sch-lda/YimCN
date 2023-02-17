#pragma once
#include "gta/joaat.hpp"

namespace big
{
	// Add new values to the bottom
	enum class Infraction
	{
		DESYNC_PROTECTION,
		BREAKUP_KICK_DETECTED,
		LOST_CONNECTION_KICK_DETECTED,
		SPOOFED_ROCKSTAR_ID,
		TRIGGERED_ANTICHEAT,
		TRIED_CRASH_PLAYER,
		TRIED_KICK_PLAYER,
		BLAME_EXPLOSION_DETECTED,
		ATTACKING_WITH_GODMODE
	};

    inline std::unordered_map<Infraction, const char*> infraction_desc =
	{
		{Infraction::DESYNC_PROTECTION, "使用了取消同步踢防护"},
		{Infraction::BREAKUP_KICK_DETECTED, "使用了分离踢"},
		{Infraction::LOST_CONNECTION_KICK_DETECTED, "使用过失去连踢"},
		{Infraction::SPOOFED_ROCKSTAR_ID, "Had spoofed RID"},
		{Infraction::TRIGGERED_ANTICHEAT, "触发了Rockstar反作弊"},
		{Infraction::TRIED_CRASH_PLAYER, "试图崩溃你"},
		{Infraction::TRIED_KICK_PLAYER, "试图踢出你"},
		{Infraction::BLAME_EXPLOSION_DETECTED, "试图陷害某人全局爆炸"},
		{Infraction::ATTACKING_WITH_GODMODE, "在无敌状态攻击玩家"}
	};
}