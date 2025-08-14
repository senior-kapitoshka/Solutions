let geometricSequenceElements (a: int) (r: int) (n: int) =
    [for i in 0 .. n-1 -> (a * pown r i).ToString()]
    |> String.concat ", "

    //////////////
open System
let geometricSequenceElements (a: int) (r: int) (n: int) =
    String.Join(", ", [ for i in 0 .. n - 1 -> a * pown r i ])

/////////////
open System

let geometricSequenceElements (a: int) (r: int) (n: int) =
  [2..n]
  |> List.scan (fun acc _ -> acc * r) a
  |> List.map string
  |> String.concat ", "

  ///////////
      