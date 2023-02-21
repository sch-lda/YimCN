#include "views/view.hpp"
#include "pointers.hpp"

namespace big
{
	void view::model_swapper()
	{
		ImGui::Text("已经创建的模型不会受到影响");
		ImGui::Text("十六进制哈希值的前缀为0x");
		ImGui::Text("你可以使用X键快捷菜单复制实体的哈希值");

		static char dst_text[256];
		static char src_text[256];
		static size_t selected_index = -1;
		static float width = *g_pointers->m_resolution_x / 5.0;

		ImGui::SetNextItemWidth(width);
		ImGui::InputText("原模型", dst_text, IM_ARRAYSIZE(dst_text)); ImGui::SameLine();
		ImGui::SetNextItemWidth(width);
		ImGui::InputText("替换为", src_text, IM_ARRAYSIZE(src_text)); ImGui::SameLine();

		if (ImGui::Button("添加\\修改"))
		{
			std::lock_guard lock(g.world.model_swapper.m);
			if (dst_text[0] == '\0' || src_text[0] == '\0')
			{
				g_notification_service->push_error("模型交换器", "输入有误");
				return;
			}
			std::string str = dst_text;
			transform(str.begin(), str.end(), str.begin(), ::tolower);
			size_t i = 0;
			for (; i < g.world.model_swapper.models.size(); i++)
			{
				std::string tmp = g.world.model_swapper.models[i].first;
				transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
				if (str == tmp)
				{
					g.world.model_swapper.models[i].first = dst_text;
					g.world.model_swapper.models[i].second = src_text;
					break;
				}
			}
			if (i == g.world.model_swapper.models.size())
				g.world.model_swapper.models.push_back(std::make_pair(dst_text, src_text));
			g.world.model_swapper.update = true;
		} ImGui::SameLine();
		if (ImGui::Button("删除"))
		{
			std::lock_guard lock(g.world.model_swapper.m);
			if (!g.world.model_swapper.models.size() || selected_index < 0 || selected_index >= g.world.model_swapper.models.size())
			{
				g_notification_service->push_error("模型交换器", "Invalid index");
				return;
			}
			g.world.model_swapper.models.erase(std::begin(g.world.model_swapper.models) + selected_index);
			g.world.model_swapper.update = true;
		} ImGui::SameLine();
		if (ImGui::Button("清空"))
		{
			std::lock_guard lock(g.world.model_swapper.m);
			g.world.model_swapper.models.clear();
			g.world.model_swapper.update = true;
		}

		ImGui::SetNextItemWidth(width);
		if (ImGui::BeginListBox("Dst##model_swapper_dst"))
		{
			for (size_t i = 0; i < g.world.model_swapper.models.size(); i++)
			{
				if (ImGui::Selectable(g.world.model_swapper.models[i].first.c_str(), selected_index == i))
				{
					selected_index = i;
					strcpy_s(dst_text, sizeof(dst_text), g.world.model_swapper.models[i].first.c_str());
					strcpy_s(src_text, sizeof(src_text), g.world.model_swapper.models[i].second.c_str());
				}

				if (selected_index == i)
					ImGui::SetItemDefaultFocus();
			}
			ImGui::EndListBox();
		} ImGui::SameLine();
		ImGui::SetNextItemWidth(width);
		if (ImGui::BeginListBox("Src##model_swapper_src"))
		{
			for (size_t i = 0; i < g.world.model_swapper.models.size(); i++)
			{
				if (ImGui::Selectable(g.world.model_swapper.models[i].second.c_str(), selected_index == i))
				{
					selected_index = i;
					strcpy_s(dst_text, sizeof(dst_text), g.world.model_swapper.models[i].first.c_str());
					strcpy_s(src_text, sizeof(src_text), g.world.model_swapper.models[i].second.c_str());
				}

				if (selected_index == i)
					ImGui::SetItemDefaultFocus();
			}
			ImGui::EndListBox();
		}
	}
}