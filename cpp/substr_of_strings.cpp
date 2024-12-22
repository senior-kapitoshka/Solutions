#include <algorithm>

class WhichAreIn
{
public:
    static std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2)
    {
        std::vector<std::string> results;
        
        std::copy_if( array1.begin( ), array1.end( ), std::back_inserter( results ),
            [&](const std::string &item1) {
                return std::any_of( array2.begin( ), array2.end( ), 
                    [&](const std::string &item2) {
                        return item2.find( item1 ) != std::string::npos;
                    } 
                );
            } 
        );
        
        std::sort( results.begin( ), results.end( ) );
        
        return results;
    }
};/* из первого нужно выбрать слова которые я вляются подстрокой слов из второго массива*/