#include "backend/looped/looped.hpp"
#include "fiber_pool.hpp"
#include "natives.hpp"
#include "backend/looped_command.hpp"

namespace big
{
	class vehinvisibility : looped_command
	{
		using looped_command::looped_command;

		bool last_driving = false;

		virtual void on_tick() override
		{
			if (!PED::GET_PED_CONFIG_FLAG(self::ped, 62, false))
			{
				if (last_driving)
				{
					ENTITY::SET_ENTITY_VISIBLE(self::veh, true, 0);
				}

				last_driving = false;
				return;
			}

			last_driving = true;

			ENTITY::SET_ENTITY_VISIBLE(self::veh, false, 0);

			if (g.vehicle.localveh_visibility)
				NETWORK::SET_ENTITY_LOCALLY_VISIBLE(self::veh);
		}

		virtual void on_disable() override
		{
			ENTITY::SET_ENTITY_VISIBLE(self::veh, true, 0);
		}
	};

	vehinvisibility g_vehinvisibility("invisveh", "载具隐身", "让载具不可见", g.vehicle.vehinvisibility);
	bool_command g_localveh_visibility("localinvisveh", "本地可见", "让载具对自己可见，对其他玩家隐身", g.vehicle.localveh_visibility);
}
