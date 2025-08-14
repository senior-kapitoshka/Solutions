let swap (s:string) =
  let up (c:char) = 
    match c with
    |'e'|'a'|'u'|'o'|'i' -> System.Char.ToUpper c
    |_-> c 
  s |> Seq.map up |> System.String.Concat 

  /////////////
  let swap = String.map (fun c -> if ['a';'e';'i';'o';'u'] |> List.contains c then (int c) - 32 |> char else c)

  ///////////
  let capitalizeVowel = function
  | 'a' -> 'A'
  | 'e' -> 'E'
  | 'i' -> 'I'
  | 'o' -> 'O'
  | 'u' -> 'U'
  | x -> x

let swap = String.map capitalizeVowel

////////////
let swap =
  String.map (fun c -> if (['a';'e';'i';'o';'u'] |> List.contains c) then c |> System.Char.ToUpper else c)

  ///////////
  let swap (s: string) =
    s 
    |> Seq.map (fun c -> 
        match System.Char.ToLower(c) with
        | 'a' | 'e' | 'i' | 'o' | 'u' -> System.Char.ToUpper(c)
        | _ -> c
    )
    |> System.String.Concat

    ///////////
    let charToCap (c: char) =
  match c with
  | 'a' | 'e' | 'i' | 'o' | 'u' -> System.Char.ToUpper c
  | _ -> c
  
let swap = String.map charToCap