struct PS_INPUT
{
	float4 Pos : SV_POSITION;
	float4 Col : TEXCOORD;
};

float4 psMain(PS_INPUT input) : SV_TARGET
{
	return input.Col;
}