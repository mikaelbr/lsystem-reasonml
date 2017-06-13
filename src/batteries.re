let (<|) f x => f(x);
let (>>) f g x => g(f(x));
let join = String.concat "";
let string_of_char = String.make 1;
let and_fn3 fns => fun a b c =>
  List.iter (fun fn => fn a b c) fns;

external pow: float => float => float = "Math.pow" [@@bs.val];

let weighted_length len gens =>
  int_of_float <| len *. (pow 0.5 (float_of_int gens));

let rec list_char str =>
  switch str {
  | "" => []
  | ch =>
    let last_index = String.length ch - 1;
    [ch.[0], ...list_char (String.sub ch 1 last_index)]
  };

