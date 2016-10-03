/* *****************************************************************
 *
 *  lpc + exec
 *
 *  - (lpc) original from Jubal E. Harshaw (GumbiMud)
 *  - (exec) original from who knows who, modified by neverbot for RLMud
 *  - (lpc + exec) MudOS version (CcMudlib) by neverbot, 11/2008
 *  - ported to DGD (CcMudlib) by neverbot, 08/2015 
 *
 * ***************************************************************** */

// #include <standard.h>

#include <mud/cmd.h>

inherit CMD_BASE;

#define CODER_DIR "/home/" + (string)this_player()->query_name()
#define CODER_FILE "/home/"+this_player()->query_name()+"/.lpc_exec.c"

private int show, dont_overwrite, dont_remove;
private mixed arg;

private string parse_args(string str);
private void usage();
private string defines();
private string vars();
private string before();
private string after();
private int check_file();
private int check_code(string str);

private int check_file()
{
  string wiz_dir;
  string wiz_file_str;
  object wiz_file_ob;

  wiz_dir = CODER_DIR;
  wiz_file_str = CODER_FILE;

  if (file_size(wiz_dir) != -2) 
  {
      notify_fail("Directorio: '" + wiz_dir + "' no existente.\n");
      return 0;
  }
  
  if (wiz_file_ob = find_object(wiz_file_str)) 
    wiz_file_ob->dest_me();
  
  return 1;  
}

private int check_code(string str)
{
  string file_target;
  // int auxvar = 0;
  object ob;
  ob = nil;
  
  if (!str || (str == ""))
    return 1;
  
  // Aqui metio mano (mucho) Folken 3/2002, para arreglar el capado
  //  del exec que funcionaba mal :)
  if(sizeof(explode(str,"->"))>1)
  {
    // auxvar = sizeof(explode(explode(str,"->")[0]," "));
    // file_target = explode(explode(str,"->")[0]," ")[auxvar?auxvar-1:auxvar];
    file_target = explode(explode(str,"->")[0]," ")[0];
    if (file_target == "return")
      file_target = explode(explode(str,"->")[0]," ")[1];

    // tell_object(this_player(), "Test: '"+file_target+"'\n");                    
    // Si llamamos por ejemplo a load_object("blabla.c")->lala()
    if (sizeof(explode(file_target,"(")) > 1)
    {
      file_target = explode(file_target,"(")[1];
      file_target = explode(file_target,")")[0];
    }
    file_target = replace_string(file_target,"\"","");

    // tell_object(this_player(), "Test: '"+file_target+"'\n");                    
    // Podemos estar haciendo un find_living("blahblah")->algo
    
    if (file_target == "TP")
    {
      file_target = this_player()->query_cap_name();
    }
    else if (file_target == "TO")
    {
      file_target = CODER_FILE;
    }

    ob = find_living(file_target);

    if (ob)
    {
      if (!ob->query_coder())
      {
        tell_object(this_player(), "No esta permitido hacer execs sobre jugadores.\n");
        return 0;
      }
    }
    else
    {
      if ((file_target != CODER_FILE) && (file_size(file_target) < 0))
      {
        tell_object(this_player(), "Exec sobre el archivo: '"+file_target+"' (no existe)\n");          
        return 0;
      }
      tell_object(this_player(), "Exec sobre el archivo: '"+file_target+"'\n");          
      if((int)"/secure/master.c"->valid_read(file_target,this_player())==0)
      {
        log_file("exec_ilegal",ctime(time(),4) + " " + (string)this_player()->query_cap_name()+ " ilegal exec: "+str+"\n");
        tell_object(this_player(), "Tu intento de hacer un exec ilegal ha sido grabado.\n");
        return 0;
      }
    }        
  }  
  return 1;
}

static int cmd(string str, object me, string verb)
{
  object ob;
  string file;
  mixed error, ret;
 
  if (!this_player()) 
    return 0;
  if (this_player(1) != this_player()) 
    return 0;
  
  if (!check_file())
    return 1;

  show = 0;
  dont_overwrite = 0;
  dont_remove = 0;
  arg = 0;
  
  if(!str) 
  {
    usage();
    return 1;
  }
    
  str = parse_args(str);
  
  if (!str) 
  {
    write("Abortado.\n");
    return 1;
  }

  // Intento de ejecutar codigo ilegal (solo comprobamos para programadores
  // de bajo nivel)
  if (!"/lib/core/secure/permission"->is_administrator(this_player()->query_name()))
    if (!check_code(str))
      return 1;
        
  if (show) 
    write(before() + str + after());
  
  file = CODER_FILE;
  
  if ((file_size(file) > 0) && dont_overwrite) 
    write("Abortado. El archivo '"+file+"' ya existe (b�rralo antes)\n");
  
  write_file(file, before() + str + after());
  
  if ((ob = find_object(file))) 
    destruct(ob);  /* update */
  
  error = catch(ret = load_object(file)->main(arg));
  
  if (error) 
    write(sprintf("\nHa ocurrido un error: %s\n", error));
  else
    // write(sprintf("\nResultado: %O\n", ret));
    write(to_string(ret));
  
  if (find_object(file)) 
    file->dest_me();
  
  if (!dont_remove)
    rm(file);

  log_file("exec", ctime(time(),4) + " " + (string)this_player()->query_name()+
                   " ejecut� : " + str + "\n");  
  return 1;
}

private string parse_args(string str) 
{
  string pre, rest, flags;

  if(sscanf(str, "%sABORT%s", pre, rest) == 2) 
    return nil;
  if(sscanf(str, "-%s %s", flags, rest) == 2) 
  {
    str = rest;
    if(sscanf(flags, "%ss%s", pre, rest) == 2) 
      show = 1;
    if(sscanf(flags, "%sd%s", pre, rest) == 2) 
      dont_overwrite = 1;
    if(sscanf(flags, "%sp%s", pre, rest) == 2) 
      dont_remove = 1;
    if(sscanf(flags, "%sa", pre) ==1)
    {
      if((sscanf(str, "\"%s\" %s", arg, str) != 2) &&
         (sscanf(str, "%s %s", arg, str) != 2)) 
      {
        usage();
        return nil;
      }
    }
  }
  return str;
}

private void usage() 
{
  write("Sintaxis: exec [-flags] <c�digo>\n");
  write("[Permite probar una �nica l�nea de c�digo LPC]\n\n");
  write("Ejecuta la l�nea de c�digo dentro de la funci�n main()\n");
  write("del archivo: "+CODER_FILE+" (ser� borrado)\n");
  write("flags:  s: muestra el archivo por pantalla tras ser generado\n");
  write("        d: no sobrescribir el archivo si ya existe\n");
  write("        p: no borrar el archivo tras la ejecuci�n\n");
  write("        a <arg>: pasa como argumento 'arg' al llamar a main()\n");
  write("                 (debe ser el �ltimo flag)\n");
  write("\nSe pueden utilizar las siguientes macros: \n"+defines()+"\n");
  // write("These variables are set for you: \n"+vars()+"\n");
  // No veo utilidad en esto
  // write("Adem�s, si \"ABORT\" se encuentra en la l�nea, exec ser� abortado.\n");
  write("Ej: exec object *a=users(); for(int i=0;i<sizeof(a);i++) tell_object(a[i], \"Prueba\");\n");
}

// Codigo a incluir en el archivo generado

private string defines() 
{
  // return INCLUDE;
  return "#define TP this_player()\n#define TO this_object()\n" +
         "#define QN query_name()\n#define QCN query_cap_name()\n";
}

private string vars() 
{
  return "  // int i, j, k, l = 0;             /* initialized to 0 */\n" +
         "  // string str, pre, rest = \"\";     /* initialized to \"\" */\n" +
         "  // object ob, a, b;                /* not initialized */\n";
}

private string before() 
{
  return defines() + 
         "\nvoid create() { seteuid(geteuid(this_player())); }\n" +
         "void dest_me() { destruct(this_object()); }\n\n" +
         "\nmixed main(mixed arg)\n{\n" + vars() +
         "  /* ONE LINE: */\n\n  ";
}

private string after() 
{
  return ";\n\n  /* END ONE LINE */\n"+
        "  write(\"\\nEjecuci�n terminada.\\n\");\n" +
        "  return 1;\n}\n";
}

// string help() { main(); }
                                                                          