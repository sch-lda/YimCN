#include "views/view.hpp"
#include "fiber_pool.hpp"
#include "util/globals.hpp"
#include "util/mobile.hpp"
#include "util/teleport.hpp"
#include "util/vehicle.hpp"

namespace big
{
	void view::teleport()
	{
		ImGui::Text("BLIPS"_T.data());

		components::command_button<"waypointtp">({}, "导航点");
		ImGui::SameLine();
		components::command_button<"objectivetp">({}, "目标点");
		components::command_checkbox<"autotptowp">();

		ImGui::Text("VEHICLES"_T.data());
		components::command_button<"lastvehtp">();
		ImGui::SameLine();
		components::command_button<"bringpv">();
		ImGui::SameLine();
		components::command_button<"pvtp">();
	}
}
