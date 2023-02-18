#include "views/view.hpp"
#include "fiber_pool.hpp"
#include "gta_util.hpp"
#include "core/scr_globals.hpp"
#include "script_local.hpp"
#include "util/scripts.hpp"

namespace big
{
	static bool mission_found = false;

	inline rage::scrThread* check_script(rage::joaat_t hash)
	{
		if (auto thread = gta_util::find_script_thread(hash))
		{
			mission_found = true;
			return thread;
		}

		return nullptr;
	}

	void view::missions()
	{
		mission_found = false;

		components::sub_title("事件启动器");

		ImGui::BeginGroup();
		components::button("移动目标", [] { scripts::start_launcher_script(36); });
		components::button("杀戮名单", [] { scripts::start_launcher_script(37); });
		components::button("检查点", [] { scripts::start_launcher_script(39); });
		components::button("挑战", [] { scripts::start_launcher_script(40); });
		components::button("卡位战", [] { scripts::start_launcher_script(41); });
		ImGui::EndGroup();

		ImGui::SameLine();

		ImGui::BeginGroup();
		components::button("抢手货", [] { scripts::start_launcher_script(43); });
		components::button("城堡之王", [] { scripts::start_launcher_script(45); });
		components::button("刑事破坏", [] { scripts::start_launcher_script(46); });
		components::button("狩猎野兽", [] { scripts::start_launcher_script(47); });
		components::button("商战", [] { scripts::start_launcher_script(114); });
		ImGui::EndGroup();

		ImGui::SameLine();

		ImGui::BeginGroup();
		components::button("单挑死斗", [] { scripts::start_launcher_script(197); });
		components::button("即时竞速", [] { scripts::start_launcher_script(16); });
		components::button("飞行学校", [] { scripts::start_launcher_script(196); });
		components::button("高尔夫", [] { scripts::start_launcher_script(193); });
		components::button("新手教程", [] { scripts::start_launcher_script(20); });
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("仅对正在加入战局的玩家生效");
		ImGui::EndGroup();

		ImGui::SameLine();

		ImGui::BeginGroup();
		components::button("荒地复仇游戏", [] { scripts::start_launcher_script(211); });
		components::button("太空猴3游戏", [] { scripts::start_launcher_script(216); });
		components::button("断袖诅咒游戏", [] { scripts::start_launcher_script(212); });
		components::button("QUB3D游戏", [] { scripts::start_launcher_script(217); });
		components::button("猎头游戏", [] { scripts::start_launcher_script(218); });
		ImGui::EndGroup();

		ImGui::Separator();

		if (check_script(RAGE_JOAAT("am_criminal_damage")))
		{
			components::sub_title("刑事破坏");
			components::button("启动活动##criminal_damage", [] {
				if (scripts::force_host(RAGE_JOAAT("am_criminal_damage")))
					if (auto script = gta_util::find_script_thread(RAGE_JOAAT("am_criminal_damage")))
						*script_local(script->m_stack, scr_locals::am_criminal_damage::broadcast_idx).at(43).as<int*>() = 0;
			});
			ImGui::SameLine();
			components::button("停止活动##criminal_damage", []
			{
				if (scripts::force_host(RAGE_JOAAT("am_criminal_damage")))
					if (auto script = gta_util::find_script_thread(RAGE_JOAAT("am_criminal_damage")))
						*script_local(script->m_stack, scr_locals::am_criminal_damage::broadcast_idx).at(39).as<int*>() = 0;
			});

			components::button("分数最高", []
			{
				if (auto criminal_damage = gta_util::find_script_thread(RAGE_JOAAT("am_criminal_damage")))
					*script_local(criminal_damage->m_stack, scr_locals::am_criminal_damage::score_idx).as<int*>() = 999'999'999;
			});
		}

		if (check_script(RAGE_JOAAT("am_cp_collection")))
		{
			components::sub_title("检查点");

			components::button("启动活动##cp_collection", []
			{
				if (scripts::force_host(RAGE_JOAAT("am_cp_collection")))
					if (auto script = gta_util::find_script_thread(RAGE_JOAAT("am_cp_collection")))
						*script_local(script->m_stack, scr_locals::am_cp_collection::broadcast_idx).at(667).as<int*>() = 0;
			});
			ImGui::SameLine();
			components::button("结束活动##cp_collection", []
			{
				if (scripts::force_host(RAGE_JOAAT("am_cp_collection")))
					if (auto script = gta_util::find_script_thread(RAGE_JOAAT("am_cp_collection")))
						*script_local(script->m_stack, scr_locals::am_cp_collection::broadcast_idx).at(661).as<int*>() = 0;
			});

			components::button("一键获胜", []
			{
				if (auto checkpoints = gta_util::find_script_thread(RAGE_JOAAT("am_cp_collection")))
					*script_local(checkpoints->m_stack, scr_locals::am_cp_collection::player_broadcast_idx).at(checkpoints->m_net_component->m_local_participant_index, 5).at(4).as<int*>() = 999'999'999;

				script::get_current()->yield(1s);

				if (scripts::force_host(RAGE_JOAAT("am_cp_collection")))
				{
					if (auto checkpoints = gta_util::find_script_thread(RAGE_JOAAT("am_cp_collection")))
					{
						*script_local(checkpoints->m_stack, scr_locals::am_cp_collection::broadcast_idx).at(708).as<int*>() = 0;
					}
				}
			});
			ImGui::SameLine();
			components::button("协助玩家通过检查点", []
			{
				std::vector<Vector3> active_player_positions;

				for (auto& plyr : g_player_service->players())
				{
					if (plyr.second->is_valid() && NETWORK::NETWORK_IS_PLAYER_A_PARTICIPANT_ON_SCRIPT(plyr.second->id(), "am_cp_collection", -1))
					{
						active_player_positions.push_back(ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(plyr.second->id()), false));
					}
				}

				if (scripts::force_host(RAGE_JOAAT("am_cp_collection")))
				{
					if (auto checkpoints = gta_util::find_script_thread(RAGE_JOAAT("am_cp_collection")))
					{
						for (int i = 0; i < 100; i++)
						{
							*script_local(checkpoints->m_stack, scr_locals::am_cp_collection::broadcast_idx).at(10).at(i, 5).as<Vector3*>() = active_player_positions[i % active_player_positions.size()];
						}
					}
				}
			});
		}

		if (check_script(RAGE_JOAAT("am_king_of_the_castle")))
		{
			components::sub_title("城堡之王");
			components::button("完成活动##kotc", []
			{
				if (scripts::force_host(RAGE_JOAAT("am_king_of_the_castle")))
					if (auto script = gta_util::find_script_thread(RAGE_JOAAT("am_king_of_the_castle")))
						*script_local(script->m_stack, scr_locals::am_king_of_the_castle::broadcast_idx).at(1).at(1).as<int*>() = 0;
			});
			ImGui::SameLine();
			components::button("活动过期(如果可能)##kotc", []
			{
				if (scripts::force_host(RAGE_JOAAT("am_king_of_the_castle")))
					if (auto script = gta_util::find_script_thread(RAGE_JOAAT("am_king_of_the_castle")))
						*script_local(script->m_stack, scr_locals::am_king_of_the_castle::broadcast_idx).at(1).at(3).as<int*>() = 0;
			});

			components::button("成为城堡之王##kotc", []
			{
				if (scripts::force_host(RAGE_JOAAT("am_king_of_the_castle")))
				{
					if (auto kotc = gta_util::find_script_thread(RAGE_JOAAT("am_king_of_the_castle")))
					{
						*script_local(kotc->m_stack, scr_locals::am_king_of_the_castle::broadcast_idx).at(6).at(0, 204).at(74).at(0, 4).as<int*>() = 0;
						*script_local(kotc->m_stack, scr_locals::am_king_of_the_castle::broadcast_idx).at(6).at(0, 204).at(74).at(0, 4).at(1).as<int*>() = self::id;
						*script_local(kotc->m_stack, scr_locals::am_king_of_the_castle::broadcast_idx).at(6).at(0, 204).at(74).at(0, 4).at(2).as<int*>() = self::id;
						*script_local(kotc->m_stack, scr_locals::am_king_of_the_castle::broadcast_idx).at(6).at(0, 204).at(74).at(0, 4).at(3).as<float*>() = 999999999.0f;
					}
				}
			});
			ImGui::SameLine();
			components::button("夺取位置##kotc", []
			{
				if (scripts::force_host(RAGE_JOAAT("am_king_of_the_castle")))
				{
					if (auto kotc = gta_util::find_script_thread(RAGE_JOAAT("am_king_of_the_castle")))
					{
						for (int i = 0; i < *script_local(kotc->m_stack, scr_locals::am_king_of_the_castle::broadcast_idx).at(6).at(0, 204).at(74).as<int*>(); i++)
						{
							*script_local(kotc->m_stack, scr_locals::am_king_of_the_castle::broadcast_idx).at(6).at(0, 204).at(74).at(i, 4).as<int*>() = -1;
							*script_local(kotc->m_stack, scr_locals::am_king_of_the_castle::broadcast_idx).at(6).at(0, 204).at(74).at(i, 4).at(1).as<int*>() = -1;
							*script_local(kotc->m_stack, scr_locals::am_king_of_the_castle::broadcast_idx).at(6).at(0, 204).at(74).at(i, 4).at(2).as<int*>() = -1;
							*script_local(kotc->m_stack, scr_locals::am_king_of_the_castle::broadcast_idx).at(6).at(0, 204).at(74).at(i, 4).at(3).as<float*>() = -1.0f;
						}
					}
				}
			});
		}


		if (!mission_found)
		{
			ImGui::Text("当前战局无进行中的任务");
		}
	}
}