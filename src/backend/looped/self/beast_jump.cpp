#include "natives.hpp"
#include "backend/looped_command.hpp"
#include "gta/enums.hpp"

namespace big
{

	class beast_jump_looped : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			if (PAD::IS_CONTROL_JUST_PRESSED(0, (int)ControllerInputs::INPUT_JUMP) && !PED::IS_PED_IN_ANY_VEHICLE(self::ped, NULL) && !ENTITY::IS_ENTITY_IN_AIR(self::ped))
			{
				TASK::TASK_JUMP(self::ped, true, true, true);
			}
		}
	};
	
	beast_jump_looped g_beast_jump_looped("beastjump", "野兽跳", "允许你像狩猎野兽活动中的野兽那样跳跃", g.self.beast_jump);
}
