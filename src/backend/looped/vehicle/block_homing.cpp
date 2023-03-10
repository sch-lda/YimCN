#include "natives.hpp"
#include "backend/looped_command.hpp"
#include "gta/enums.hpp"

namespace big
{
	class block_homing : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			if (g_local_player && g_local_player->m_vehicle)
				g_local_player->m_vehicle->m_is_targetable = false;
		}

		virtual void on_disable() override
		{
			if (g_local_player && g_local_player->m_vehicle)
				g_local_player->m_vehicle->m_is_targetable = true;
		}
	};

	block_homing g_block_homing("blockhoming", "不会被飞弹锁定", "追踪导弹将无法锁定你的载具", g.vehicle.block_homing);
}
