#include "natives.hpp"
#include "backend/looped_command.hpp"
#include "util/vehicle.hpp"

namespace big
{
	class keep_vehicle_repaired : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			if (VEHICLE::GET_DOES_VEHICLE_HAVE_DAMAGE_DECALS(self::veh))
				vehicle::repair(self::veh);
		}
	};

	keep_vehicle_repaired g_keep_vehicle_repaired("keepfixed", "保持修复", "Keeps your vehicle free of wear and tear", g.vehicle.keep_vehicle_repaired);
}
