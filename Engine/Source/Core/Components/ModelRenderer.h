#pragma once

#include "Core/Resource/Resource.h"
#include "Scene/BaseComponent.h"

struct ModelRenderer : public ECS::BaseComponent {
	~ModelRenderer() = default;

	ModelRenderer() : Name("Sphere"){
		Renderer = fr::Resource.GetModel(Name);
	}

	ModelRenderer(std::string name): Name(name) {
		Renderer = fr::Resource.GetModel(Name);
	}

	void ReFresh() {
		Renderer = fr::Resource.GetModel(Name);
	}

	std::string Name;
	std::shared_ptr<Model3D> Renderer;
};