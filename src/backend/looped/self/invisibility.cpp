#include "backend/looped/looped.hpp"
#include "fiber_pool.hpp"
#include "natives.hpp"
#include "backend/looped_command.hpp"

#include "core/scr_globals.hpp"
#include <script/globals/GlobalPlayerBD.hpp>

namespace big
{
	class invisibility : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			ENTITY::SET_ENTITY_VISIBLE(self::ped, false, 0);

			if (g.self.local_visibility)
				NETWORK::SET_ENTITY_LOCALLY_VISIBLE(self::ped);

			scr_globals::globalplayer_bd.as<GlobalPlayerBD*>()->Entries[self::id].IsInvisible = true;
		}

		virtual void on_disable() override
		{
			ENTITY::SET_ENTITY_VISIBLE(self::ped, true, 0);
			scr_globals::globalplayer_bd.as<GlobalPlayerBD*>()->Entries[self::id].IsInvisible = false;
		}
	};

	invisibility g_invisibility("invis", "隐身", "让自己不可见", g.self.invisibility);
	bool_command g_local_visibility("localvis", "本地可见", "仅对其他玩家隐身", g.self.local_visibility);
}
