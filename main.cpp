#include "Pong.h"
#include "Breakout.h"

int main() {
    Pong pong(1920, 1080, sf::Keyboard::Key::Space);
    pong.run();

    // Breakout breakout(1920, 1080, sf::Keyboard::Key::Space);
    // breakout.run();
}