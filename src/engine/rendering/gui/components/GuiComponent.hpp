#pragma once
#include <utility>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace lei3d
{
	class UiMesh;

	class GuiComponent
	{
	public:
		enum Anchor
		{
			TOP_LEFT,
			TOP_RIGHT,
			BOTTOM_LEFT,
			BOTTOM_RIGHT,
			CENTER_TOP,
			CENTER_RIGHT,
			CENTER_BOTTOM,
			CENTER_LEFT,
			CENTER,
			ANCHOR_COUNT
		};

		enum Space
		{
			PIXELS,
			NORMALIZED
		};

		GuiComponent(
			Anchor anchor = CENTER, 
			const std::pair<Space, glm::vec2>& pos = { NORMALIZED, { 0.25, 0.25 } }, 
			const std::pair<Space, glm::vec2>& size = { NORMALIZED, { 0.5, 0.5 } }
		);
		virtual ~GuiComponent();

		void SetPositionNormalized(const glm::vec2& pos);
		void SetPositionPixels(const glm::vec2& pos);

		void SetSizeNormalized(const glm::vec2& size);
		void SetSizePixels(const glm::vec2& size);

	protected:
		friend class GuiManager;

		static unsigned s_nextId;
		unsigned m_id;
		unsigned m_anchor;

		static const glm::vec3 s_anchorPositions[ANCHOR_COUNT];

		std::pair<Space, glm::vec2> m_position; // normalized 0-1
		std::pair<Space, glm::vec2> m_size;	// normalized 0-1
		UiMesh* m_mesh = nullptr;

		virtual void Render(const glm::vec2& screenSize) = 0;
		virtual void Update() = 0;

		glm::vec2 PosNormalized(const glm::vec2& screenSize);
		glm::vec2 SizeNormalized(const glm::vec2& screenSize);
	};
}
