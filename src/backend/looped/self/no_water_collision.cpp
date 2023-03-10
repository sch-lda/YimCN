#include "backend/looped/looped.hpp"
#include "fiber_pool.hpp"
#include "natives.hpp"
#include "backend/looped_command.hpp"

namespace big
{
	class no_water_collision : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			if (g_local_player)
				g_local_player->m_navigation->m_damp->m_water_collision = 0;
		}

		virtual void on_disable() override
		{
			if (g_local_player)
				g_local_player->m_navigation->m_damp->m_water_collision = 1;
		}
	};

	no_water_collision g_no_water_collision("walkunder", "水下行走", "假设不存在水，同时允许水下射击", g.self.no_water_collision);
}
