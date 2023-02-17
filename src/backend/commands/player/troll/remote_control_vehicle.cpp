#include "backend/player_command.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "util/vehicle.hpp"

namespace big
{
	class remote_control_vehicle : player_command
	{
		using player_command::player_command;

		virtual void execute(player_ptr player, const std::vector<std::uint64_t>& _args, const std::shared_ptr<command_context> ctx)
		{
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player->id()), FALSE);
			if (veh == 0)
			{
				if (g.player.spectating)
					g_notification_service->push_warning("远程控制", "玩家不在载具内");
				else
					g_notification_service->push_warning("远程控制", "玩家不在载具内, 请先观看玩家状态");
				return;
			}

			vehicle::remote_control_vehicle(veh);
			g.player.spectating = false;
		}
	};

	remote_control_vehicle g_remote_control_vehicle("rcplayer", "遥控玩家载具", "遥控玩家载具，建议配合观战使用", 0, false);
}