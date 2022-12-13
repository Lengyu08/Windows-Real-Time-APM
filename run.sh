# 编译生成WIndow.o文件
g++ -c  main.cpp -I"D:\environment\SFML-2.5.1\include"
# 链接SFML库生成Window.exe文件
g++ main.o -o main -L"D:\environment\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
# 删除生成的对象文件
rm -rf *.o
# 运行Window.exe文件
./main.exe
