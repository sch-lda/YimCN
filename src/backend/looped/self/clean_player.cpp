#include "natives.hpp"
#include "backend/looped_command.hpp"
#include "util/entity.hpp"

namespace big
{
	class clean_player_looped : looped_command
	{
		using looped_command::looped_command;

		virtual void on_tick() override
		{
			entity::clean_ped(self::ped);
		}
	};

	clean_player_looped g_clean_player_looped("cleanloop", "保持清洁", "让自己始终没有弹孔和水渍", g.self.clean_player);
}
