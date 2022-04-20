#pragma once

namespace ABC_Name {
	class Layer
	{
	public:
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUIRender() {}

	};
}