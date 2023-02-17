#include "views/view.hpp"
#include "renderer.hpp"

namespace big
{
	void view::gui_settings()
	{
		components::sub_title("SETTINGS_UI_SCALE"_T);
		ImGui::SliderFloat("##gui-scale", &g.window.gui_scale, 1.f, 1.5f, "%.2f");
		ImGui::SameLine();
		if (ImGui::Button("APPLY"_T.data()))
			g_renderer->rescale(g.window.gui_scale);
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("SETTINGS_UI_SCALE_DESCRIPTION"_T.data());

		components::sub_title("SETTINGS_UI_COLOR"_T);
		static ImVec4 col_gui = ImGui::ColorConvertU32ToFloat4(g.window.color);
		if (ImGui::ColorEdit4("SETTINGS_UI_COLOR_PICKER"_T.data(), (float*)&col_gui, ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_NoSidePreview))
		{
			g.window.color = ImGui::ColorConvertFloat4ToU32(col_gui);
		}

		components::sub_title("游戏内悬浮窗");
		ImGui::Checkbox("显示悬浮窗", &g.window.ingame_overlay.opened);
		ImGui::SameLine();
		ImGui::Checkbox("当菜单显示时仍显示悬浮窗", &g.window.ingame_overlay.show_with_menu_opened);

		ImGui::BeginGroup();

		ImGui::Checkbox("显示 FPS", &g.window.ingame_overlay.show_fps);
		ImGui::Checkbox("显示玩家数量", &g.window.ingame_overlay.show_players);
		ImGui::Checkbox("显示系统时间", &g.window.ingame_overlay.show_time);
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("显示系统时间因为存在问题而停用.");

		ImGui::EndGroup();
		ImGui::SameLine();
		ImGui::BeginGroup();

		ImGui::Checkbox("显示实体池信息", &g.window.ingame_overlay.show_replay_interface);
		ImGui::Checkbox("显示游戏版本", &g.window.ingame_overlay.show_game_versions);

		ImGui::EndGroup();
	}

}