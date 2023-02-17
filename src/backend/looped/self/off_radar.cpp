#include "natives.hpp"
#include "backend/looped_command.hpp"
#include "core/scr_globals.hpp"

namespace big
{
	class off_radar : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			*scr_globals::globalplayer_bd.at(PLAYER::GET_PLAYER_INDEX(), scr_globals::size::globalplayer_bd).at(210).as<int*>() = true;
			*script_global(2672505).at(57).as<int*>() = NETWORK::GET_NETWORK_TIME() + 1;
		}

		virtual void on_disable() override
		{
			*scr_globals::globalplayer_bd.at(PLAYER::GET_PLAYER_INDEX(), scr_globals::size::globalplayer_bd).at(210).as<int*>() = false;
		}
	};

	off_radar g_off_radar("otr", "雷达隐匿", "你的光点将从其他玩家的地图上消失", g.self.off_radar);
}
