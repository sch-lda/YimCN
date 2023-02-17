#include "backend/player_command.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "core/scr_globals.hpp"

namespace big
{
	class null_function_kick : player_command
	{
		using player_command::player_command;

		virtual CommandAccessLevel get_access_level()
		{
			return CommandAccessLevel::TOXIC;
		}

		virtual void execute(player_ptr player, const std::vector<std::uint64_t>& _args, const std::shared_ptr<command_context> ctx)
		{
			const size_t arg_count = 15;
			int64_t args[arg_count] =
			{
				(int64_t)eRemoteEvent::InteriorControl,
				(int64_t)self::id,
				(int64_t)(int)-1
			};

			g_pointers->m_trigger_script_event(1, args, arg_count, 1 << player->id());
		}
	};

	null_function_kick g_null_function_kick("nfkick", "无效函数踢", "这可能需要等待十秒钟才能彻底移除玩家", 0);
}