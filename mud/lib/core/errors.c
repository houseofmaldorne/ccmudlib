
// * void runtime_error(string error, int caught, mixed **trace)
//     A runtime error has occurred.
//
// * void atomic_error(string error, int atom, mixed **trace)
//     A runtime error has occurred in atomic code.
//
// * void compile_error(string file, int line, string error)
//     A compile-time error has occurred.

#include <kernel.h>

nomask string runtime_error(string error, int caught, int ticks)
{
  mixed **trace;
  string progname, objname, function, str;
  string long_err, short_err;
  int i, sz, line, len;
  object player;

  if (caught)
    return nil;

  short_err = error + "\n";
  long_err = error + "\n";

  trace = call_trace();

  if ((sz = sizeof(trace) - 1) != 0)
  {
    for (i = 0; i < sz; i++)
    {
      progname = trace[i][1];
      function = trace[i][2];

      // I'm not sure what this is catching: bad object to call_other maybe?
      // if (progname == AUTO && strlen(function) > 3)
      // {
      //   switch (function[0 .. 2])
      //   {
      //     // case "bad":
      //     //   progname = trace[i - 1][1];
      //     //   function = trace[i - 1][2];
      //     case "_F_":
      //     case "_Q_":
      //       continue;
      //     default:
      //       break;
      //   }
      // }

      objname  = trace[i][0];
      line     = trace[i][3];

      if (line == 0)
        str = "    ";
      else
      {
        str = "    " + line;
        str = str[strlen(str) - 4 ..];
      }

      str += " " + function + " ";
      len = strlen(function);

      if (len < 22)
        str += "                      "[len ..];

      str += " " + progname;

      if (progname != objname)
      {
        len = strlen(progname);
        if (len < strlen(objname) && progname == objname[.. len - 1])
          str += " (" + objname[len ..] + ")";
        else
          str += " (" + objname + ")";
      }

      // call_other is masked ("because of reasons"... shadows)
      // remove those messages from the error trace
      if (function == "call_other" &&
          progname == "/lib/core/auto")
        continue;

      long_err += str+"\n";
    }
  }

  short_err += "" + progname + ", line " +line + ", function "+function+" (object: "+ objname + ")\n";

// Use long or short logs in the driver stderr
#ifdef DRIVER_LONG_LOGS
  return long_err;
#else
  return short_err;
#endif
}

string atomic_error(string error, int atom, mixed **trace)
{
  return "lib > core > handlers > errors :: atomic_error\n";
  // load_object(DRIVER)->driver_message("An atomic error happened!");
}

string compile_error(string file, int line, string error)
{
  return file + ", " + line + ": " + error + "\n";
}




