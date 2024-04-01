#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using filesystem::path;

path operator""_p(const char* data, std::size_t sz) {
    return path(data, data + sz);
}

// напишите эту функцию
bool Preprocess(const path& in_file, const path& out_file, const vector<path>& include_directories){
    std::regex rf(R"/(\s*#\s*include\s*"([^"]*)"\s*)/");
    std::regex rl(R"/(\s*#\s*include\s*<([^>]*)>\s*)/");
    std::smatch match;
    std::ifstream is(in_file);
    if(!is) return false;
    std::ofstream os(out_file,std::ios::out|std::ios::app);
    int n=0;
    for(std::string w;std::getline(is,w);){
        ++n;
        if(std::regex_match(w,match,rf)){
            path pf =std::string(match[1]); 
            path full=in_file.parent_path()/pf;
            ifstream reader;
            reader.open(full);
            if(reader.is_open()){
                Preprocess(full,out_file,include_directories);
                reader.close();
            }else{
                bool fnd=false;
                for(auto& f:include_directories){
                    if(exists(path(f/pf))){
                        fnd=true;
                        Preprocess(f/pf,out_file,include_directories);
                        break;
                    }
                }
                if(!fnd){
                    std::cout<<"unknown include file "s << pf.filename().string() << " at file "s << in_file.string() << " at line "s << n << endl;
                return false;    
        }
            }
            
        }else if(std::regex_match(w,match,rl)){
            path pf=std::string(match[1]); 
            bool fnd=false;
            for(auto& f:include_directories){
                if(exists(path(f/pf))){
                    fnd=true;
                    Preprocess(f/pf,out_file,include_directories);
                    break;
                }
            }
            if(!fnd){
                std::cout<<"unknown include file "s << pf.filename().string() << " at file "s << in_file.string() << " at line "s << n << endl;
            return false;    
    }
            
            
        }else{
            os<<w<<endl;
        }
        
    }
    return true;
    
}

string GetFileContents(string file) {
    ifstream stream(file);

    // конструируем string по двум итераторам
    return {(istreambuf_iterator<char>(stream)), istreambuf_iterator<char>()};
}

void Test() {
    error_code err;
    filesystem::remove_all("sources"_p, err);
    filesystem::create_directories("sources"_p / "include2"_p / "lib"_p, err);
    filesystem::create_directories("sources"_p / "include1"_p, err);
    filesystem::create_directories("sources"_p / "dir1"_p / "subdir"_p, err);

    {
        ofstream file("sources/a.cpp");
        file << "// this comment before include\n"
                "#include \"dir1/b.h\"\n"
                "// text between b.h and c.h\n"
                "#include \"dir1/d.h\"\n"
                "\n"
                "int SayHello() {\n"
                "    cout << \"hello, world!\" << endl;\n"
                "#   include<dummy.txt>\n"
                "}\n"s;
    }
    {
        ofstream file("sources/dir1/b.h");
        file << "// text from b.h before include\n"
                "#include \"subdir/c.h\"\n"
                "// text from b.h after include"s;
    }
    {
        ofstream file("sources/dir1/subdir/c.h");
        file << "// text from c.h before include\n"
                "#include <std1.h>\n"
                "// text from c.h after include\n"s;
    }
    {
        ofstream file("sources/dir1/d.h");
        file << "// text from d.h before include\n"
                "#include \"lib/std2.h\"\n"
                "// text from d.h after include\n"s;
    }
    {
        ofstream file("sources/include1/std1.h");
        file << "// std1\n"s;
    }
    {
        ofstream file("sources/include2/lib/std2.h");
        file << "// std2\n"s;
    }

    assert((!Preprocess("sources"_p / "a.cpp"_p, "sources"_p / "a.in"_p,
                                  {"sources"_p / "include1"_p,"sources"_p / "include2"_p})));

    ostringstream test_out;
    test_out << "// this comment before include\n"
                "// text from b.h before include\n"
                "// text from c.h before include\n"
                "// std1\n"
                "// text from c.h after include\n"
                "// text from b.h after include\n"
                "// text between b.h and c.h\n"
                "// text from d.h before include\n"
                "// std2\n"
                "// text from d.h after include\n"
                "\n"
                "int SayHello() {\n"
                "    cout << \"hello, world!\" << endl;\n"s;

    assert(GetFileContents("sources/a.in"s) == test_out.str());
}

int main() {
    Test();
}