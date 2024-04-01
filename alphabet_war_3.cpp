#include <string>
#include <vector>

std::string alphabet_war(const std::vector<std::string>& reinforces,
                         const std::vector<std::string>& airstrikes)
{
  //сначала создаем вектор result той же длины, что первая строка reinforces и инициализируем нулями
  //В этом векторе будут храниться индексы выживших воинов после всех авиаударов
std::vector<int> result(reinforces[0].size(), 0);

for (int i = 0; i < airstrikes.size(); ++i) 
{

    std::vector<int> temp = result;

    for (int j = 0; j < airstrikes[i].size(); ++j) 
    {
        if (airstrikes[i][j] == '*') 
        {   // проверяем является ли он символом авиаудара
            //если да, то проверяется что не выходит за границы строки
            if (j > 0) 
            {
                result[j - 1] = temp[j - 1] + 1;
            }
            result[j] = temp[j] + 1; // увеличиваем на 1 для текущей позиции и его соседних позиций 
            if (j < result.size() - 1) 
            {
                result[j + 1] = temp[j + 1] + 1;
            }
        }
    }
}

std::string result_battle = "";//результат битвы
for (int i = 0; i < result.size(); ++i) 
{
    if (result[i] < reinforces.size()) 
    {
        result_battle += reinforces[result[i]][i];
    }
    else 
    {
        result_battle += '_';
    }
}

return result_battle;
}