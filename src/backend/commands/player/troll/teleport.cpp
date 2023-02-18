#include "backend/player_command.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "util/teleport.hpp"

namespace big
{
	class teleport_to_player : player_command
	{
		using player_command::player_command;

		virtual void execute(player_ptr player, const std::vector<std::uint64_t>& _args, const std::shared_ptr<command_context> ctx)
		{
			teleport::to_player(player->id());
		}
	};
	
	teleport_to_player g_teleport_to_player("playertp", "传送到玩家", "传送自己到玩家当前的位置", 0, false);
}