#include <list>
#include <iostream>
#include <string>

using namespace std;
using namespace std::literals;


class Editor {
public:
    Editor()=default;
    // сдвинуть курсор влево
    void Left(){
        if(crs!=0) --crs;
    }
    // сдвинуть курсор вправо 
    void Right(){
        if(crs!=lst.size()) ++crs;
    }
    // вставить символ token
    void Insert(char token){
        lst.insert(next(lst.begin(),crs),token);
        ++crs;
    }
    // вырезать не более tokens символов, начиная с текущей позиции курсора
    void Cut(size_t tokens = 1){
        Copy(tokens);
        lst.erase(next(lst.begin(),crs),next(lst.begin(),std::min(crs+tokens,lst.size())));
    }
    // cкопировать не более tokens символов, начиная с текущей позиции курсора
    void Copy(size_t tokens = 1){
        if(!buf.empty()) buf.clear();
       auto bg=next(lst.begin(),std::min(crs,lst.size()));
        auto ed=next(lst.begin(),std::min(crs+tokens,lst.size())); 
        std::copy(bg,ed,std::back_inserter(buf));
    }
    // вставить содержимое буфера в текущую позицию курсора
    void Paste(){
        for(auto c:buf){
            Insert(c);
        }
    }
    // получить текущее содержимое текстового редактора
    string GetText() const{
        std::string s(lst.begin(),lst.end());
        return s;
    }
private:    
    std::list<char>lst;
    std::list<char>buf;
    size_t crs=0;
};


int main() {
    Editor editor;
    const string text = "hello, world"s;
    for (char c : text) {
        editor.Insert(c);
    }
    // Текущее состояние редактора: `hello, world|`
    for (size_t i = 0; i < text.size(); ++i) {
        editor.Left();
    }
    // Текущее состояние редактора: `|hello, world`
    editor.Cut(7);
    // Текущее состояние редактора: `|world`
    // в буфере обмена находится текст `hello, `
    for (size_t i = 0; i < 5; ++i) {
        editor.Right();
    }
    // Текущее состояние редактора: `world|`
   editor.Insert(',');
    editor.Insert(' ');
    // Текущее состояние редактора: `world, |`
    editor.Paste();
    // Текущее состояние редактора: `world, hello, |`
    editor.Left();
   editor.Left();
    //Текущее состояние редактора: `world, hello|, `
    editor.Cut(3);  // Будут вырезаны 2 символа
    // Текущее состояние редактора: `world, hello|`
    cout << editor.GetText();
    return 0;
}

///////////////////////////
#include <iostream>
#include <list>
#include <string>



using namespace std;

class Editor {
public:
    Editor()
            : pos(text.end()) {
    }

    void Left() {
        pos = Advance(pos, -1);
    }

    void Right() {
        pos = Advance(pos, 1);
    }

    void Insert(char token) {
        text.insert(pos, token);
    }

    void Cut(size_t tokens = 1) {
        auto pos2 = Advance(pos, tokens);
        buffer.assign(pos, pos2);
        pos = text.erase(pos, pos2);
    }

    void Copy(size_t tokens = 1) {
        auto pos2 = Advance(pos, tokens);
        buffer.assign(pos, pos2);
    }

    void Paste() {
        text.insert(pos, buffer.begin(), buffer.end());
    }

    string GetText() const {
        return {text.begin(), text.end()};
    }

private:
    using Iterator = list<char>::iterator;
    list<char> text;
    list<char> buffer;
    Iterator pos;

    Iterator Advance(Iterator it, int steps) const {
        while (steps > 0 && it != text.end()) {
            ++it;
            --steps;
        }
        while (steps < 0 && it != text.begin()) {
            --it;
            ++steps;
        }
        return it;
    }
};