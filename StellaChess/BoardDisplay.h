#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <string>


const static sf::Color dark_color = sf::Color(112, 81, 56);
const static sf::Color light_color = sf::Color(198, 175, 157);
const static std::vector<std::string> texture_names = { "black_king","white_king","black_queen","white_queen","black_rook","white_rook","black_bishop","white_bishop","black_knight","white_knight","black_pawn","white_pawn" };


class BoardDisplay
{
public:
	void init_textures();

	static void load_texture(sf::Texture texture, std::string file_path) {
		if (!texture.loadFromFile(file_path)) {

			std::ostringstream error_message_stream;
			error_message_stream << "Unable to load file " << file_path << '\n';
			std::string error_message = error_message_stream.str();
			throw std::runtime_error(error_message);
		}
	}

	void init_board();

	std::vector<sf::RectangleShape> get_board();

private:
	std::vector<sf::RectangleShape> board;
	std::vector<sf::Texture> textures;
	std::vector<sf::Sprite> sprites;
};

