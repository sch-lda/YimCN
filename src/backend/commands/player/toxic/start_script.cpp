#include "backend/player_command.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "script.hpp"

#include <script/globals/GPBD_FM_3.hpp>
#include "core/scr_globals.hpp"

namespace big
{
	template <int scriptId, int arg19 = 0>
	class start_script : player_command
	{
		using player_command::player_command;

		virtual CommandAccessLevel get_access_level()
		{
			return CommandAccessLevel::AGGRESSIVE;
		}

		virtual void execute(player_ptr player, const std::vector<std::uint64_t>& _args, const std::shared_ptr<command_context> ctx)
		{
			const size_t arg_count = 25;
			int64_t args[arg_count] =
			{
				(int64_t)eRemoteEvent::StartScriptBegin,
				(int64_t)self::id
			};

			args[2] = scriptId;
			strcpy((char*)&args[2 + 3], "0");
			args[2 + 16] = -1;
			args[2 + 17] = 1337;
			args[2 + 19] = arg19;
			args[24] = scr_globals::gpbd_fm_3.as<GPBD_FM_3*>()->Entries[player->id()].ScriptEventReplayProtectionCounter;

			g_pointers->m_trigger_script_event(1, args, arg_count, 1 << player->id());

			for (int i = 0; i < 2; i++)
			{
				const size_t arg_count_2 = 25;
				int64_t args_2[arg_count_2] =
				{
					(int64_t)eRemoteEvent::StartScriptProceed,
					(int64_t)self::id
				};
				args_2[2 + 17] = 1337;
				g_pointers->m_trigger_script_event(1, args_2, arg_count_2, 1 << player->id());

				script::get_current()->yield(20ms);
			}
		}
	};

	start_script<20> g_start_tutorial("tutorial", "送进新手教程", "显示新手教程的不可跳过的过场动画", 0);
	start_script<193> g_start_golf("golf", "送到高尔夫", "开始高尔夫运动", 0);
	start_script<196> g_start_flight_school("flightschool", "送到飞行学校", "传送玩家到机场并触发飞行学校活动", 0);
	start_script<192> g_start_darts("darts", "开始飞镖游戏", "Starts darts in a Sandy Shores bar", 0);
	start_script<211> g_start_badlands("badlands", "Start Badlands Revenge II", "启动全屏电子游戏 Badlands Revenge II", 0);
	start_script<216> g_start_space_monkey("spacemonkey", "开始太空猴3游戏", "启动全屏电子游戏 Space Monkey 3", 0);
	start_script<216> g_start_wizards_ruin("wizard", "Start The Wizard's Ruin", "启动全屏电子游戏 The Wizard's Ruin", 0);
	start_script<217> g_start_qub3d("qub3d", "开始 Qub3D 游戏", "启动全屏电子游戏 Qub3D", 0);
	start_script<218> g_start_camhedz("camhedz", "Start Camhedz", "启动全屏电子游戏 Camhedz", 0);
}
