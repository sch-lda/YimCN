#include "views/view.hpp"
#include "fiber_pool.hpp"

namespace big
{
	void view::heading()
	{
		ImGui::SetNextWindowSize({ 300.f, 80.f });
		ImGui::SetNextWindowPos({ 10.f, 10.f });
		if (ImGui::Begin("menu_heading", nullptr, window_flags | ImGuiWindowFlags_NoScrollbar))
		{
			ImGui::BeginGroup();
			ImGui::Text("非官方版本20230221");
			ImGui::Text("出现任何问题不得向YIMMENU官方反馈");
			ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.172f, 0.380f, 0.909f, 1.f));
			ImGui::PopStyleColor();
			ImGui::EndGroup();
			ImGui::SameLine();
			ImGui::SetCursorPos({ 300.f - ImGui::CalcTextSize("UNLOAD"_T.data()).x - ImGui::GetStyle().ItemSpacing.x, ImGui::GetStyle().WindowPadding.y / 2 + ImGui::GetStyle().ItemSpacing.y + (ImGui::CalcTextSize("W").y / 2) });
			ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.69f, 0.29f, 0.29f, 1.00f));
			if (components::nav_button("UNLOAD"_T))
			{
				g_fiber_pool->queue_job([]
				{
					for (auto& command : g_looped_commands)
						if (command->is_enabled())
							command->on_disable();

					g_running = false;
				});
			}
			ImGui::PopStyleColor();
		}
	}
}
