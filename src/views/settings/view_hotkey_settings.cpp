#include "views/view.hpp"
#include "widgets/imgui_hotkey.hpp"
#include "services/hotkey/hotkey_service.hpp"

namespace big
{
	void view::hotkey_settings()
	{
		ImGui::PushItemWidth(350.f);

		if (ImGui::Hotkey("菜单显示隐藏", &g.settings.hotkeys.menu_toggle))
			g.settings.hotkeys.editing_menu_toggle = true; // make our menu reappear

		if (ImGui::Hotkey("传送到导航点", &g.settings.hotkeys.teleport_waypoint))
			g_hotkey_service->update_hotkey("waypoint", g.settings.hotkeys.teleport_waypoint);
		if (ImGui::Hotkey("传送到目标点", &g.settings.hotkeys.teleport_objective))
			g_hotkey_service->update_hotkey("objective", g.settings.hotkeys.teleport_objective);

		if (ImGui::Hotkey("自由移动", &g.settings.hotkeys.noclip))
			g_hotkey_service->update_hotkey("noclip", g.settings.hotkeys.noclip);
		if (ImGui::Hotkey("带来个人载具", &g.settings.hotkeys.bringvehicle))
			g_hotkey_service->update_hotkey("bringpv", g.settings.hotkeys.bringvehicle);
		if (ImGui::Hotkey("玩家隐身", &g.settings.hotkeys.invis))
			g_hotkey_service->update_hotkey("invis", g.settings.hotkeys.invis);
		if (ImGui::Hotkey("恢复生命值", &g.settings.hotkeys.heal))
			g_hotkey_service->update_hotkey("heal", g.settings.hotkeys.heal);
		if (ImGui::Hotkey("补满零食护甲", &g.settings.hotkeys.fill_inventory))
			g_hotkey_service->update_hotkey("fillsnacks", g.settings.hotkeys.fill_inventory);
		if (ImGui::Hotkey("跳过过场动画", &g.settings.hotkeys.skip_cutscene))
			g_hotkey_service->update_hotkey("skipcutscene", g.settings.hotkeys.skip_cutscene);
		if (ImGui::Hotkey("自由视角", &g.settings.hotkeys.freecam))
			g_hotkey_service->update_hotkey("freecam", g.settings.hotkeys.freecam);
		if (ImGui::Hotkey("超级跑", &g.settings.hotkeys.superrun))
			g_hotkey_service->update_hotkey("fastrun", g.settings.hotkeys.superrun);
		if (ImGui::Hotkey("超级跳", &g.settings.hotkeys.superjump))
			g_hotkey_service->update_hotkey("superjump", g.settings.hotkeys.superjump);
		if (ImGui::Hotkey("野兽跳", &g.settings.hotkeys.beastjump))
			g_hotkey_service->update_hotkey("beastjump", g.settings.hotkeys.beastjump);
		if (ImGui::Hotkey("载具隐身", &g.settings.hotkeys.invisveh))
			g_hotkey_service->update_hotkey("invisveh", g.settings.hotkeys.invisveh);
		if (ImGui::Hotkey("载具本地隐身", &g.settings.hotkeys.localinvisveh))
			g_hotkey_service->update_hotkey("localinvisveh", g.settings.hotkeys.localinvisveh);
		if (ImGui::Hotkey("强制退出-自崩", &g.settings.hotkeys.fast_quit))
			g_hotkey_service->update_hotkey("fastquit", g.settings.hotkeys.fast_quit);

		ImGui::PopItemWidth();
	}
}
