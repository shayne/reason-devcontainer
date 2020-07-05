open Lwt;
open Cohttp;
open Cohttp_lwt;
open Cohttp_lwt_unix;

let curl_get = url =>
  Uri.of_string(url)
  |> Client.get(~headers=Header.of_list([("User-Agent", "curl")]));

let resp_status = resp => resp |> Response.status |> Code.code_of_status;

let json_resp = (resp, body) => {
  let code = resp_status(resp);
  switch (code) {
  | 200 => Ok(Yojson.Basic.from_string(body))
  | _ => Error(Printf.sprintf("[%d] %s", code, body))
  };
};

let json_get = url =>
  curl_get(url)
  >>= (
    ((resp, body)) => {
      Body.to_string(body) >|= (body => json_resp(resp, body));
    }
  )
  |> Lwt_main.run;
