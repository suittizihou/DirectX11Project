struct PS_INPUT
{
	float4 pos : SV_POSITION;
    float4 nor : NORMAL;
	float4 col : COLOR;
    float2 uv : TEXCOORD;
};

cbuffer ConstantBuffer
{
    float4x4 World; // ���[���h�ϊ��s��
    float4x4 View; // �r���[�ϊ��s��
    float4x4 Projection; // �����ˉe�ϊ��s��
    float4 CameraPos; // �J�������W
    float4 LightVector; // ���C�g����
    float4 LightColor; // ���C�g�J���[
    float4 MaterialAmbient; // �A���r�G���g
    float4 MaterialDiffuse; // �f�B�t���[�Y
    float4 MaterialSpecular; // �X�y�L�����[
}

Texture2D Texture : register(t0[0]); // Texture���X���b�g0��0�Ԗڂ̃e�N�X�`�����W�X�^�ɐݒ�
SamplerState Sampler : register(s0[0]); // Sampler���X���b�g0��0�Ԗڂ̃T���v�����W�X�^�ɐݒ�

float4 psMain(PS_INPUT input) : SV_TARGET
{    
    //float4 color = Texture.Sample(Sampler, input.uv)/* * input.col * input.nor*/;
    //color *= input.col;
    
    float4 color = input.col * input.nor;

	return color;
}