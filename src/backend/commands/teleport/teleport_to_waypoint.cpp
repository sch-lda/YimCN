#include "backend/command.hpp"
#include "natives.hpp"
#include "util/teleport.hpp"

namespace big
{
	class teleport_to_waypoint : command
	{
		using command::command;

		virtual void execute(const std::vector<std::uint64_t>&, const std::shared_ptr<command_context> ctx)
		{
			teleport::to_waypoint();
		}
	};

	teleport_to_waypoint g_teleport_to_waypoint("waypointtp", "传送到导航点", "传送自己到地图上手动标记的导航点", 0);
}