open Batteries;

external pi : float = "Math.PI" [@@bs.val];

let deg_to_rad deg => (float_of_int deg) *. pi /. 180.0;
let rotate ctxt deg  => Canvas.rotate ctxt (deg_to_rad deg);
let push = Canvas.save;
let pop = Canvas.restore;
let drawLine ctxt len => and_fn3 [
  Canvas.lineTo,
  Canvas.translate
] ctxt (float_of_int len) 0.0;
let start = and_fn3 [
  Canvas.lineTo,
  Canvas.translate
];

let lsystem ctxt (w, h) len deg sys => {
  let rot = rotate ctxt;
  let move = drawLine ctxt;
  start ctxt w h;
  let rec next sys => switch sys {
  | [a, ...tl] => {
    switch a {
    | '[' => push ctxt;
    | ']' => pop ctxt;
    | '+' => rot deg;
    | '-' => rot (-deg);
    | _ => move len;
    };
    next tl;
  };
  | [] => Canvas.stroke ctxt;
  };
  next sys;
};
