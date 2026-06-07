#pragma once
#include <unordered_map>

namespace MapUtils
{
	template<typename Map, typename Value>
	void fill(Map& map, const Value& value)
	{
		for (auto& [key, v] : map)
		{
			v = value;
		}
	}

	template<typename K, typename V>
	V getValueOrDefault(const std::unordered_map<K, V>& map,
		const K& key,
		const V& defaultValue)
	{
		auto it = map.find(key);
		return it != map.end() ? it->second : defaultValue;
	}
}