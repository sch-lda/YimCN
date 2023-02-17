#include "backend/player_command.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "util/globals.hpp"
#include "services/pickups/pickup_service.hpp"

namespace big
{
	class give_armor : player_command
	{
		using player_command::player_command;

		virtual CommandAccessLevel get_access_level()
		{
			return CommandAccessLevel::FRIENDLY;
		}

		virtual void execute(player_ptr player, const std::vector<std::uint64_t>& _args, const std::shared_ptr<command_context> ctx)
		{
			g_pickup_service->give_player_health(player->id());
		}
	};

	give_armor g_give_armor("givearmor", "给与防弹衣", "给与玩家一些防弹衣", 0);
}