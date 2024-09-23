#include "TextureHolder.h"
#include <assert.h>
TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder()
{
	//assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

// check if a texture is already loaded!
Texture& TextureHolder::GetTexture(string const& filename)
{
	auto& m = m_s_Instance->m_Textures;
	auto keyValuePair = m.find(filename);
	// Did we find a match?
	if (keyValuePair != m.end())
	{
		return keyValuePair->second;
	}
	else
	{
		auto& texture = m[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}