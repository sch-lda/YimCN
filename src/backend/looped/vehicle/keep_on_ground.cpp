#include "natives.hpp"
#include "backend/looped_command.hpp"

namespace big
{
	class keep_on_ground : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			auto model = ENTITY::GET_ENTITY_MODEL(self::veh);

			if (ENTITY::IS_ENTITY_IN_AIR(self::veh) &&
				(VEHICLE::IS_THIS_MODEL_A_CAR(model) ||
				 VEHICLE::IS_THIS_MODEL_A_BIKE(model)))
				VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(self::veh, 5.0);
		}
	};

	keep_on_ground g_keep_on_ground("keeponground", "不会翻车", "让载具的轮子吸在地面上", g.vehicle.keep_on_ground);
}