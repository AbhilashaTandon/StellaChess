#include "BoardDisplay.h"

void BoardDisplay::init_textures() {
	for (int i = 0; i < texture_names.size(); i++) {
		//init blank textures
		this->textures.push_back(sf::Texture());

	}

	for (int i = 0; i < texture_names.size(); i++) {
		std::ostringstream file_path;
		file_path << "PieceSprites/" << texture_names[i] << ".png";
		load_texture(textures[i], file_path.str());
	}

}

void BoardDisplay::init_board() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			sf::RectangleShape tile(sf::Vector2f(100.f, 100.f));
			if ((i + j) & 1) {
				tile.setFillColor(dark_color);
			}
			else {
				tile.setFillColor(light_color);
			}

			tile.setPosition(i * 100.f, j * 100.f);
			board.push_back(tile);
		}
	}
}

std::vector<sf::RectangleShape> BoardDisplay::get_board() {
	return this->board;
}