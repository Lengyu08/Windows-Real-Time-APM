#include <windows.h>
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

using namespace std;
sf::RenderWindow window;
// 设置桌面的长宽
const int WINDOW_WIDTH = 25, WINDOW_HEIGHT = 35;

inline void display_draw(int n);    // 把传入的整数打印在屏幕上
inline string change(int n);        // 类型转换把整形转化为字符串类型

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    // 创建窗口
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "APM", sf::Style::Titlebar | sf::Style::Close);
    int flag1 = false, flag2 = false, flag3 = false, flag4 = false;
    int n = 0;
    double apm = 0, inc = 1;
    int cnt[2], tmp = 0;

    sf::Clock clock; // 打开时钟

    while (window.isOpen()) {
        sf::Event event;
        sf::Time e = clock.getElapsedTime();
        
        window.pollEvent(event);
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        int num = 0;
        FILE *f;
        f = fopen("key.txt", "r");
        fscanf(f, "%d", &num);
        fclose(f);
        
        if (num == 1) flag1 = true; 
        if (num == 2 && flag1 == true) {
            n ++ ;
            flag1 = false;
        }

        if (num == 3) flag2 = true;
        if (num == 4 && flag2 == true) {
            n ++ ;
            flag2 = false;
        }

        if (num == 5) flag3 = true; 
        if (num == 6 && flag3 == true) {
            n ++;
            flag3 = false;
        }
        
        if (flag4) {
            cnt[tmp ^ 1] = n;
            flag4 = false;
        }
        cnt[tmp] = n;
        if (e.asSeconds() > 2.5) {
            if (cnt[tmp] > cnt[tmp ^ 1]) {
                apm = (cnt[tmp] - cnt[tmp ^ 1]) * 24;
            } else {
                apm = 0;
            }
            clock.restart(); 
            n = 0;
            flag4 = true;
        }
        display_draw((int)apm);
    }
    return EXIT_SUCCESS;
}

inline void display_draw(int n) {
    string str = change(n);
    sf::Font font;
    if (!font.loadFromFile("YaHeiConsolas.ttf")) return;
    sf::Text text(str, font, 25);

    window.clear();
    window.draw(text);
    window.display();
}

inline string change(int n) {
    stringstream ss;
    ss << "APM : " << n;
    string str = ss.str();
    return str;
}