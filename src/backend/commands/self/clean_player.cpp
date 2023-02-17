#include "backend/command.hpp"
#include "natives.hpp"
#include "util/entity.hpp"

namespace big
{
	class clean_player : command
	{
		using command::command;

		virtual void execute(const std::vector<std::uint64_t>&, const std::shared_ptr<command_context> ctx)
		{
			entity::clean_ped(self::ped);
		}
	};

	clean_player g_clean_player("clean", "清洁玩家", "Cleans the player of wetness and decals", 0);
}