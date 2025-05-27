#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cctype>

#include <stack>
#include <queue>
#include <deque>

#include <list>
#include <forward_list>

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <tuple>

using namespace std;

class Musica {
    private:

    struct tCancion{
        string artista;
        int duracion;
        tCancion (string a, int d){
            artista = a;
            duracion = d;
        }
    };
    unordered_map<string,pair<tCancion, list<string>::iterator>> canciones;
    pair<list<string>, int> playlist;
    list<string> recientes;

    public:

    Musica() : playlist(list<string>(), 0) {
    }

    void addSong(string can, string au, int dur){
        auto it = canciones.find(can);
        if (it != canciones.end()){
            throw domain_error("addSong");
        }
        else {
            canciones[can] = make_pair(tCancion{au, dur}, list<string>::iterator{});
        }
    }

    void addToPlay(string can){
        auto it = canciones.find(can);
        if (it != canciones.end()){
            throw domain_error("addToPlay");
        }
        else if (it->second.second != list<string>::iterator{}){
            throw domain_error("addToPlay");
        }
        else {
            playlist.first.push_back(can);
            playlist.second += it->second.first.duracion;
            it->second.second = playlist.first.end()--;
        }
    }

    string current(string can){
        if (playlist.first.empty()){
            throw domain_error("current");
        }
        else {
            return playlist.first.back();
        }
    }

    string play(){
        if (playlist.first.empty()){
            return "No hay canciones en la lista";
        }
        else {
            string can = playlist.first.front();
            auto it = canciones.find(can);
            playlist.first.pop_front();
            playlist.second -= it->second.first.duracion;
            it->second.second = list<string>::iterator{};
            recientes.push_front(can);
            return "Sonando " + can;
        }
    }

    string totalTime(){
        return "Tiempo total " + to_string(playlist.second);
    }

    list<string> recent(int n){
        auto it = recientes.begin();
        list<string> dev;
        int cont = 0;
        while (it != recientes.end() && cont < n){
            dev.push_back(*it);
            it++;
            cont++;
        }
        return dev;
    }

    void deleteSong(string can){
        auto it = canciones.find(can);
        if (it == canciones.end()){
            return;
        }
        else {
            if (it->second.second != list<string>::iterator{}){
                playlist.first.erase(it->second.second);
                playlist.second -= it->second.first.duracion;
            }
            canciones.erase(it);
        }
    }

};
