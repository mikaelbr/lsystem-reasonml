open Batteries;

type lrule = { id: char, out: string };

let is_rule c rule => fst rule == c;
let get_rule c => List.find (is_rule c);
let is_constant (c: char) => List.exists ((==) c);

let create start gens rules constants => {
  let rec new_list st gen =>
    (gen == 0) ? st : (list_char st)
    |> List.map (generate gen)
    |> join
  and generate gen s => {
    if (is_constant s constants) {
      String.make 1 s
    } else {
      let new_string = snd (get_rule s rules);
      new_list new_string (gen - 1);
    }
  };
  new_list start gens |> list_char;
};


let string_of_lsystem =
  List.map (String.make 1)
  >> String.concat "";
