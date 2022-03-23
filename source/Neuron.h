#pragma once

#include "Object.h"



struct NeuronConnection
{
	uint num;
	float weight;
};


enum NeuronType
{
	basic,
	input,
	output,
	random,
	radialbasis,
	memory
};


struct Neuron
{
	NeuronType type = basic;

	float bias = 0.0f;

	uint numConnections = 0;
	NeuronConnection allConnections[NeuronsInLayer];	


	//Self explanatory
	void AddConnection(uint NUM, float WEIGHT);

	//Sort connections by index
	void SortConnections();

	//Does neuron have a connection
	bool IsConnected(uint index);


	//Set to random
	void SetRandomBias();
	void SetRandomType();
	void SetRandomConnections();

	//Randomize entire neuron
	void SetRandom();

	//Zero connections
	void ClearConnections();
	//Zero bias and connections
	void SetZero();

	//Tunnel neuron - one with no bias and only 1 connection to same neuron in next layer with weight = 1.0f
	void SetTunnel(int num);

	//Change neuron a little
	void SlightlyChange();


	static char* GetTextFromType(NeuronType t)
	{
		switch (t)
		{
		case basic:
			return (char*)"basic";
		case input:
			return (char*)"input";
		case output:
			return (char*)"output";
		case radialbasis:
			return (char*)"radial basis";
		case memory:
			return (char*)"memory";
		case random:
			return (char*)"random";
		default:
			return (char*)"other";
		}
	}
};
