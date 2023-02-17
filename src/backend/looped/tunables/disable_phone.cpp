#include "natives.hpp"
#include "backend/looped_command.hpp"
#include "core/scr_globals.hpp"

namespace big
{
	class disable_phone : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			*script_global(20366).as<bool*>() = true;
		}

		virtual void on_disable() override
		{
			*script_global(20366).as<bool*>() = false;
		}
	};

	disable_phone g_disable_phone("nophone", "禁用手机", "禁止打开手机并阻止来电.注意，如果某些重要联系人的电话被阻止，你将无法开启对应的任务", g.tunables.disable_phone);
}
