#include <stdexcept>
#include <optional>
#include <map>
#include <deque>

template <typename Key1, typename Key2, typename Value>
class BiMap {
public:
    // Вставить значение, указав один или оба ключа.
    // Генерирует исключение std::invalid_argument("some text") в случае,
    // если оба ключа пусты, либо один из ключей уже имеется в хранилище.
    void Insert(const std::optional<Key1>& key1, const std::optional<Key2>& key2, const Value& value){
        if(!key1 && !key2){
            throw std::invalid_argument("!key1 && !key2");
        }else if (key1 && mp1.count(*key1)){
            throw std::invalid_argument("mp1.count(*key1)");
        }else if(key2 && mp2.count(*key2)){
            throw std::invalid_argument("mp2.count(*key2)");
        }else{
            if(key1 && !key2){
    
                vc.push_back(value);
                mp1.insert({*key1,&vc.back()});
                
            }else if(key2 && !key1){
    
                vc.push_back(value);
                mp2.insert({*key2,&vc.back()});
            }else if(key1 && key2){
                vc.push_back(value);
                mp2.insert({*key2,&vc.back()});
                mp1.insert({*key1,&vc.back()});
            }
        }
    }

    // Получить значение по ключу первого типа.
    // Генерирует исключение std::out_of_range("some text")
    // в случае отсутствия ключа (как и функция at в std::map).
    Value& GetByPrimaryKey(const Key1& key){
        if(!mp1.count(key))throw std::out_of_range("some text");
        return *mp1.at(key);;
    }
    const Value& GetByPrimaryKey(const Key1& key) const{
        if(!mp1.count(key))throw std::out_of_range("some text");
        return *mp1.at(key);;
    }

    // Аналогичная функция для ключа второго типа.
    Value& GetBySecondaryKey(const Key2& key){
        if(!mp2.count(key))throw std::out_of_range("some text");
        return *mp2.at(key);;
    }
    const Value& GetBySecondaryKey(const Key2& key) const{
        if(!mp2.count(key))throw std::out_of_range("some text");
        return *mp2.at(key);;
    }
private:
    std::map<Key1,Value*>mp1;
    std::map<Key2,Value*>mp2; 
    std::deque<Value>vc;   
};

///////////////////////////////

/*Поэтому нужно, чтобы значения хранились где-то отдельно в одном экземпляре, а отображения 
из ключей ссылались бы на них. Например, можно сохранять значения в контейнере, а ключи отображать
 в индексы:

template <typename Key1, typename Key2, typename Value>
class BiMap {
    std::deque<Value> values;
    std::map<Key1, size_t> map1;
    std::map<Key2, size_t> map2;
};
Индексы можно было бы заменить на итераторы, если выбраны контейнеры deque или list, 
но для контейнера vector итераторы использовать не получится: при добавлении новых элементов
 в вектор может произойти реаллокация, и старые итераторы будут инвалидированы.

Другое решение не использует отдельного хранилища значений. Вместо этого значения создаются 
в динамической памяти. Чтобы не думать о том, кто и в какой момент должен освобождать эту память, 
можно обернуть их в умный указатель. Так как на значение может быть две ссылки, то нужно использовать
 умный указатель shared_ptr. Рассмотрим это решение подробнее.*/


#include <map>
#include <memory>
#include <optional>
#include <stdexcept>

template <typename Key1, typename Key2, typename Value>
class BiMap {
private:
    std::map<Key1, std::shared_ptr<Value>> map1;
    std::map<Key2, std::shared_ptr<Value>> map2;

public:
    void Insert(
        const std::optional<Key1>& key1,
        const std::optional<Key2>& key2,
        const Value& value
    ) {
        if (!key1.has_value() && !key2.has_value()) {
            throw std::invalid_argument("Both keys are empty");
        }

        auto shared = std::make_shared<Value>(value);

        if (key1.has_value() && map1.find(*key1) != map1.end()) {
            throw std::invalid_argument("Key already exists");
        }

        if (key2.has_value() && map2.find(*key2) != map2.end()) {
            throw std::invalid_argument("Key already exists");
        }

        if (key1.has_value()) {
            map1[*key1] = shared;
        }

        if (key2.has_value()) {
            map2[*key2] = shared;
        }
    }

    Value& GetByPrimaryKey(const Key1& key) {
        return *map1.at(key);
    }

    const Value& GetByPrimaryKey(const Key1& key) const {
        return *map1.at(key);
    }

    Value& GetBySecondaryKey(const Key2& key) {
        return *map2.at(key);
    }

    const Value& GetBySecondaryKey(const Key2& key) const {
        return *map2.at(key);
    }
};

/*

#include <stdexcept>
#include <optional>
#include <map>
#include <deque>

template <typename Key1, typename Key2, typename Value>
class BiMap {
public:
    // Вставить значение, указав один или оба ключа.
    // Генерирует исключение std::invalid_argument("some text") в случае,
    // если оба ключа пусты, либо один из ключей уже имеется в хранилище.
    void Insert(const std::optional<Key1>& key1, const std::optional<Key2>& key2, const Value& value){
        if(!key1 && !key2){
            throw std::invalid_argument("!key1 && !key2");
        }else if (key1 && mp1.count(*key1)){
            throw std::invalid_argument("mp1.count(*key1)");
        }else if(key2 && mp2.count(*key2)){
            throw std::invalid_argument("mp2.count(*key2)");
        }else{
            if(key1 && !key2){
    
                vc.push_back(value);
                mp1.insert({*key1,prev(vc.end())});
                
            }else if(key2 && !key1){
    
                vc.push_back(value);
                mp2.insert({*key2,prev(vc.end())});
            }else if(key1 && key2){
                vc.push_back(value);
                mp2.insert({*key2,prev(vc.end())});
                mp1.insert({*key1,prev(vc.end())});
            }
        }
    }

    // Получить значение по ключу первого типа.
    // Генерирует исключение std::out_of_range("some text")
    // в случае отсутствия ключа (как и функция at в std::map).
    Value& GetByPrimaryKey(const Key1& key){
        if(!mp1.count(key))throw std::out_of_range("some text");
        return *mp1.at(key);;
    }
    const Value& GetByPrimaryKey(const Key1& key) const{
        if(!mp1.count(key))throw std::out_of_range("some text");
        return *mp1.at(key);;
    }

    // Аналогичная функция для ключа второго типа.
    Value& GetBySecondaryKey(const Key2& key){
        if(!mp2.count(key))throw std::out_of_range("some text");
        return *mp2.at(key);;
    }
    const Value& GetBySecondaryKey(const Key2& key) const{
        if(!mp2.count(key))throw std::out_of_range("some text");
        return *mp2.at(key);;
    }
private:

//
//ошибка компиляции type/value mismatch at argument 2 in\
 template parameter list for ‘template class std::map’
//не даеь хранить итератор на Value
//

    std::map<Key1,std::deque<Value>::iterator>mp1;
    std::map<Key2,std::deque<Value>::iterator>mp2; 
    std::deque<Value>vc;   
};
*/