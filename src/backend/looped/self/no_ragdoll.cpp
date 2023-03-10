#include "backend/looped/looped.hpp"
#include "fiber_pool.hpp"
#include "natives.hpp"
#include "backend/looped_command.hpp"

namespace big
{
	class no_ragdoll : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			PED::SET_PED_CAN_RAGDOLL(self::ped, false);
		}

		virtual void on_disable() override
		{
			PED::SET_PED_CAN_RAGDOLL(self::ped, true);
		}
	};

	no_ragdoll g_no_ragdoll("noragdoll", "不会摔倒", "又称无布娃娃", g.self.no_ragdoll);
}
