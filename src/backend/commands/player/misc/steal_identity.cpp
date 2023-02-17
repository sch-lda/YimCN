#include "backend/player_command.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "util/ped.hpp"

namespace big
{
	class steal_identity : player_command
	{
		using player_command::player_command;

		virtual void execute(player_ptr player, const std::vector<std::uint64_t>& _args, const std::shared_ptr<command_context> ctx)
		{
			ped::steal_identity(
				PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player->id())
			);
		}
	};

	steal_identity g_steal_identity("copymodel", "复制人物模型", "将玩家的人物模型复制到自己", 0, false); // do we really need this?
}