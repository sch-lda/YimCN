#include "backend/command.hpp"
#include "natives.hpp"
#include "util/teleport.hpp"

namespace big
{
	class teleport_to_objective : command
	{
		using command::command;

		virtual void execute(const std::vector<std::uint64_t>&, const std::shared_ptr<command_context> ctx)
		{
			teleport::to_objective();
		}
	};

	teleport_to_objective g_teleport_to_objective("objectivetp", "传送到目标点", "传送自己到任务点", 0);
}