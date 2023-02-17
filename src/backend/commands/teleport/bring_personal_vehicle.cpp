#include "backend/command.hpp"
#include "natives.hpp"
#include "util/vehicle.hpp"
#include "util/mobile.hpp"

namespace big
{
	class bring_personal_vehicle : command
	{
		using command::command;

		virtual void execute(const std::vector<std::uint64_t>&, const std::shared_ptr<command_context> ctx)
		{
			Vehicle veh = mobile::mechanic::get_personal_vehicle();
			vehicle::bring(veh, self::pos);
		}
	};

	bring_personal_vehicle g_bring_personal_vehicle("bringpv", "带来个人载具", "将个人载具传送到附近并进入驾驶座位", 0);
}