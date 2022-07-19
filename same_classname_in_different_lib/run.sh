rm *.o *.so *.out

g++ -c register.cpp -fPIC -o register.o -std=c++11
g++ -shared -o libregister.so register.o

g++ -c a1.cpp -fPIC -o a1.o -std=c++11
g++ -shared -o a1.so a1.o

g++ -c a2.cpp -fPIC -o a2.o -std=c++11
g++ -shared -o a2.so a2.o

g++ main.cpp -fPIC -o a.out -ldl -L. -lregister -std=c++11

export LD_LIBRARY_PATH=.

echo "----a1, a2----"
./a.out a1.so a2.so

echo ""
echo "----a2, a1----"
./a.out a2.so a1.so
