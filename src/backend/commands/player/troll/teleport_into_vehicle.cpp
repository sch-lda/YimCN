#include "backend/player_command.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "util/teleport.hpp"

namespace big
{
	class teleport_into_vehicle : player_command
	{
		using player_command::player_command;

		virtual void execute(player_ptr player, const std::vector<std::uint64_t>& _args, const std::shared_ptr<command_context> ctx)
		{
			Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_player_service->get_selected()->id()), false);

			teleport::into_vehicle(veh);
		}
	};

	teleport_into_vehicle g_teleport_into_vehicle("playervehtp", "传送进载具", "传送进玩家所在的载具.建议先使用观战确认玩家是否在载具内或者载具是否有空座", 0, false);
}