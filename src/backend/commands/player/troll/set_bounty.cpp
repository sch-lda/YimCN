#include "backend/player_command.hpp"
#include "backend/bool_command.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "util/troll.hpp"

namespace big
{
	class set_bounty : player_command
	{
		using player_command::player_command;

		virtual void execute(player_ptr player, const std::vector<std::uint64_t>& _args, const std::shared_ptr<command_context> ctx)
		{
			troll::set_bounty_on_player(player, 10000, g.session.anonymous_bounty);
		}
	};

	set_bounty g_bounty("bounty", "悬赏", "对玩家设置一万元的赏金", 0);
	bool_command g_anonymous_bounty("anonbounty", "匿名悬赏", "悬赏发起人将显示为未知", g.session.anonymous_bounty);
}
