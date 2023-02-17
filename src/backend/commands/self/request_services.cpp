#include "backend/command.hpp"
#include "script_global.hpp"
#include "util/mobile.hpp"

namespace big
{
	class boat_pickup : command
	{
		using command::command;

		virtual void execute(const std::vector<std::uint64_t>&, const std::shared_ptr<command_context> ctx)
		{
			mobile::merry_weather::request_boat_pickup();
		}
	};

	class ballistic_armor : command
	{
		using command::command;

		virtual void execute(const std::vector<std::uint64_t>&, const std::shared_ptr<command_context> ctx)
		{
			mobile::ceo_abilities::request_ballistic_armor();
		}
	};

	boat_pickup g_boat_pickup("boatpickup", "请求船只接送", "Request a boat pickup", 0);
	ballistic_armor g_ballistic_armor("ballisticarmor", "请求重甲", "请求空投重型防弹装甲和火神机枪", 0);
}