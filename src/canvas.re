type context;

external getContext : Document.element => string => context = "getContext" [@@bs.send];

external strokeStyle : context => string => unit = "strokeStyle" [@@bs.set];
external stroke : context => unit = "stroke" [@@bs.send];
external rotate : context => float => unit = "rotate" [@@bs.send];
external lineTo : context => float => float => unit = "lineTo" [@@bs.send];
external moveTo : context => float => float => unit = "moveTo" [@@bs.send];
external translate : context => float => float => unit = "translate" [@@bs.send];

external save : context => unit = "save" [@@bs.send];
external restore : context => unit = "restore" [@@bs.send];

let createAndGet (w, h) => {
  let canvas = Document.createElement "canvas";
  Document.appendChild canvas;

  let ctxt = getContext canvas "2d";
  Document.setWidth canvas w;
  Document.setHeight canvas h;
  ctxt;
};
