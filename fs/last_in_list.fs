let last xs = 
   List.rev xs |> List.tryItem 0 
////

let last = List.tryLast

//////

let last xs = 
    match xs with
    | [] -> None
    | _  -> Some (List.last xs)

    