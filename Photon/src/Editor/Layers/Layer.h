#pragma once

namespace Photon
{
	/// <summary>
	/// Base class used for constructing and representing the various
	/// layers used throughout the application.
	/// </summary>
	class Layer
	{
	public:
		virtual ~Layer() = default;

		/// <summary>
		/// What to run when the layer is attached.
		/// </summary>
		virtual void OnAttach() {}

		/// <summary>
		/// Defines what to run once the layer is detached.
		/// </summary>
		virtual void OnDetach() {}

		/// <summary>
		/// What to run when the layer is called as part of the update loop.
		/// The layer OnUpdate function will only be called in the update loop
		/// if it attached.
		/// </summary>
		/// <param name="dt">The delta time since the last frame.</param>
		virtual void OnUpdate(float dt) {}

		/// <summary>
		/// What UI elements to render as part of this layer.
		/// </summary>
		virtual void OnUIRender() {}

	protected:
	private:
	};
}
