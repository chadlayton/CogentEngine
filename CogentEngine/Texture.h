#pragma once

#include "Constants.h"
#include <d3d12.h>
#include <wrl.h>
#include <cstdint>
#include "DXUtility.h"
#include "DDSTextureLoader.h"

enum TextureType
{
	WIC, DDS
};

class Texture
{
public:
	uint32 CreateTexture(ID3D12Device* device, const std::string& fileName, ID3D12CommandQueue* commandQueue, const DescriptorHeap* textureHeap, TextureType type = WIC);
	ID3D12Resource* GetResource();
	D3D12_CPU_DESCRIPTOR_HANDLE GetCPUHandle();
	D3D12_GPU_DESCRIPTOR_HANDLE GetGPUHandle(uint32_t backBufferIndex);
	void SetGPUHandle(D3D12_GPU_DESCRIPTOR_HANDLE* handles);

	std::string GetName();

private:
	static uint32_t textureIndexTracker;
	Microsoft::WRL::ComPtr<ID3D12Resource> resource;
	D3D12_CPU_DESCRIPTOR_HANDLE textureCPUHandle;
	D3D12_GPU_DESCRIPTOR_HANDLE textureGPUHandle[c_FrameBufferCount];

	uint32_t textureIndex = -1;
	std::string fileName;
};