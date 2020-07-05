open Yojson.Basic.Util;

let url = "https://ipinfo.io/";
let res = Lib.Util.json_get(url);
switch (res) {
| Ok(json) => print_endline(json |> member("ip") |> to_string)
| Error(msg) => print_endline("Error: " ++ msg)
};
