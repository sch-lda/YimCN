#pragma once

namespace big
{
	struct RegionType 
	{
		uint32_t id;
		const char name[22];
	};

	const RegionType regions[] = 
	{
		{ 0,	"独联体国家" },
		{ 1,	"非洲" },
		{ 2,	"美国东部" },
		{ 3,	"欧洲" },
		{ 4,	"中国" },
		{ 5,	"澳洲" },
		{ 6,	"美国西部" },
		{ 7,	"日本" },
		{ 8,	"未知" },
	};
}