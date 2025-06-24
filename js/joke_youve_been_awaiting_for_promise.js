// Объявляем функцию sayJoke как асинхронную с помощью ключевого слова async
// Это значит, что функция всегда возвращает Promise и внутри неё можно использовать await
async function sayJoke(apiUrl, jokeId) {
  
    // await ставит "пауза" выполнения кода, пока промис справа не выполнится (resolved)
    // Здесь мы сначала ждём ответа от fetch(apiUrl) — это промис, который завершится, когда ответ получен
    // Затем сразу же вызываем .json(), который тоже возвращает промис с распарсенными данными
    // Благодаря await код выглядит синхронным, хотя на самом деле не блокирует основной поток
    const jsonResponse = await (await fetch(apiUrl)).json();
  
    // Проверяем, что в ответе есть ключ 'jokes' (обычно это массив шуток)
    // hasOwnProperty — надёжный способ проверить, что поле существует у объекта
    if (!jsonResponse.hasOwnProperty('jokes')) {
      // Если ключа нет — выбрасываем ошибку, которая попадёт в catch у вызывающего кода
      throw new Error(`No jokes at url: ${apiUrl}`);
    }
  
    // Ищем в массиве шуток элемент, у которого id совпадает с нужным jokeId
    // find возвращает первый подходящий элемент или undefined, если не нашёл
    const joke = jsonResponse.jokes.find(j => j.id === jokeId);
  
    // Если шутка не найдена — выбрасываем ошибку
    if (!joke) throw new Error(`No jokes found id: ${jokeId}`);
  
    // Возвращаем объект с двумя функциями (методами),
    // которые по вызову возвращают тексты шутки и её "панчлайна"
    return {
      saySetup: () => joke.setup,
      sayPunchLine: () => joke.punchLine
    };
  }  
  //////////
  const sayJoke = (apiUrl, jokeId) => {
    // fetch возвращает промис, который разрешится ответом от сервера
    return fetch(apiUrl)
      // когда fetch выполнится, вызывается .then, в котором response преобразуем в JSON
      .then(response => response.json())
      // из результата JSON сразу деструктурируем свойство jokes
      /*Что значит ({jokes})?
        Это деструктуризация объекта — из объекта, который приходит в .then,
         берётся только свойство jokes и оно сразу становится локальной
          переменной jokes.*/
      // проверяем, есть ли jokes — если да, ищем нужную шутку по id
      // если нет — отклоняем промис с ошибкой (Promise.reject)
      .then(({jokes}) => jokes ?
                      jokes.find(joke => joke.id === jokeId) :
                      Promise.reject(new Error(`No jokes at url: ${apiUrl}`)))
      // если шутка найдена — возвращаем объект с методами saySetup и sayPunchLine
      // если нет — снова отклоняем промис с ошибкой
      .then(joke => joke ?
                 {saySetup: () => joke.setup, sayPunchLine: () => joke.punchLine} :
                 Promise.reject(new Error(`No jokes found id: ${jokeId}`)))
  };
  