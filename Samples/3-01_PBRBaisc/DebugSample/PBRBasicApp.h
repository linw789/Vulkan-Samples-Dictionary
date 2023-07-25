#pragma once
#include "../../3-00_SharedLibrary/Application.h"

VK_DEFINE_HANDLE(VmaAllocation);

namespace SharedLib
{
    class Camera;
}

class PBRBasicApp : public SharedLib::GlfwApplication
{
public:
    PBRBasicApp();
    ~PBRBasicApp();

    virtual void AppInit() override;

    void UpdateCameraAndGpuBuffer();

    VkFence GetFence(uint32_t i) { return m_inFlightFences[i]; }

    VkPipelineLayout GetPipelineLayout() { return m_pipelineLayout; }

    VkDescriptorSet GetCurrentFrameDescriptorSet0() 
        { return m_pipelineDescriptorSet0s[m_currentFrame]; }

    VkPipeline GetPipeline() { return m_pipeline; }

    void GetCameraData(float* pBuffer);

    void SendCameraDataToBuffer(uint32_t i);

private:
    void InitPipeline();
    void InitPipelineDescriptorSetLayout();
    void InitPipelineLayout();
    void InitShaderModules();
    void InitPipelineDescriptorSets();

    void InitSphereUboObjects(); // Create buffers and put data into the buffer.
    void ReadInSphereData();
    void DestroySphereUboObjects();

    void InitCameraUboObjects();
    void DestroyCameraUboObjects();

    SharedLib::Camera*           m_pCamera;
    std::vector<VkBuffer>        m_cameraParaBuffers;
    std::vector<VmaAllocation>   m_cameraParaBufferAllocs;

    std::vector<VkDescriptorSet> m_pipelineDescriptorSet0s;

    VkShaderModule        m_vsShaderModule;
    VkShaderModule        m_psShaderModule;
    VkDescriptorSetLayout m_pipelineDesSet0Layout;
    VkPipelineLayout      m_pipelineLayout;
    VkPipeline            m_pipeline;
};
