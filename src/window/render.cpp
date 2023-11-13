#include "utils.hpp"
#include "window.hpp"

void Window::Render(const RenderStuffs& _render_stuffs) {
  m_window.clear();

  sf::Text sftext;
  sftext.setFont(m_font);


  m_window.setView(_render_stuffs.view);

  {
    for (const auto& value_key_pair : _render_stuffs.quads) {
      // const auto& layer = value_key_pair.first.layer;
      const auto& texture = value_key_pair.first.texture;
      const auto& quads = value_key_pair.second;

      if (texture == "") {
        m_window.draw(quads.data()->arr.data(), quads.size() * 4, sf::Quads);
      } else {
        m_window.draw(quads.data()->arr.data(),
                      quads.size() * 4,
                      sf::Quads,
                      &m_textures[texture]);
      }
    }
  }

  m_window.setView(m_window.getDefaultView());

  {
    sf::Text sf_text;
    sf_text.setFont(m_font);

    for (const auto& text : _render_stuffs.texts) {
      sf_text.setString(text.str);
      sf_text.setPosition(text.pos);
      sf_text.setFillColor(sf::Color::White);
      m_window.draw(sf_text);
    }
  }
  {
    for (const auto& [lat, hearts] : _render_stuffs.heartIcons) {
      auto textureIt = m_textures.find(lat.texture);
      if (textureIt != m_textures.end()) {
        const sf::Texture& texture = textureIt->second;
        for (const auto& heartQuad : hearts) {
          sf::VertexArray heartVertices(sf::Quads, 4);
          for (std::size_t i = 0; i < 4; ++i) {
            heartVertices[i].position = heartQuad.arr[i].position;
            heartVertices[i].texCoords = heartQuad.arr[i].texCoords;
          }
          m_window.draw(heartVertices, &texture);
        }
      } else {
        SPDLOG_ERROR("Heart texture not found: {}", lat.texture);
      }
    }
  }



  {
    float current_time = m_fps_clock.restart().asSeconds();
    float fps = 1.f / current_time;
    m_fps_last = current_time;

    sftext.setString(std::to_string(static_cast<int>(fps)));
    sftext.setPosition(0.f, 0.f);
    m_window.draw(sftext);
  }

  m_window.display();
}