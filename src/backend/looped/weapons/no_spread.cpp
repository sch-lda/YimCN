#include "gta/enums.hpp"
#include "natives.hpp"
#include "backend/looped_command.hpp"

namespace big
{
    class no_spread : looped_command
    {
        using looped_command::looped_command;

		CWeaponInfo* p_modified_weapon = nullptr;
		float og_spread_value = 0.0f;

        virtual void on_tick() override
        {
			if (!g_local_player)
			{
				return;
			}

			auto* const weapon_mgr = g_local_player->m_weapon_manager;
			if (weapon_mgr)
			{
				if (p_modified_weapon != weapon_mgr->m_weapon_info && weapon_mgr->m_weapon_info)
				{
					if (p_modified_weapon)
						p_modified_weapon->m_accuracy_spread = og_spread_value;

					og_spread_value = weapon_mgr->m_weapon_info->m_accuracy_spread;
					p_modified_weapon = weapon_mgr->m_weapon_info;
					weapon_mgr->m_weapon_info->m_accuracy_spread = 0.0f;
				}
			}
        }

		virtual void on_disable() override
		{
			if (g_local_player && p_modified_weapon)
			{
				p_modified_weapon->m_accuracy_spread = og_spread_value;
				p_modified_weapon = nullptr;
			}
		}
    };

    no_spread g_no_spread("nospread", "无扩散", "移除射击时的武器扩散", g.weapons.no_spread);
}
