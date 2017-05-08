
#include <mud/secure.h>
#include <areas/calendar.h>

static string tmppassword;

void create()
{
}

void account_commands()
{
  add_action("chfn", ({ "datos", "chfn" }));
  // add_action("set_email", "email");
  add_action("change_password", ({ "password" , "passwd", "contrase�a", "contrasenya" }));
}

int change_password2(mixed pass);

int change_password(string str) 
{
  write("Por favor, introduce tu antigua contrase�a: ");
  input_to("change_password2", 1);
  return 1;
}

int change_password2(mixed pass) 
{
  string str;
  string password;
  
  if (!strlen(pass))
  {
    write("Cancelando...\n");
    return 1;
  }
  
  password = this_object()->query_password();
  
  if (password) 
  {
    str = crypt(pass, password);
    if (str != password) 
    {
      write("Contrase�a incorrecta. Cancelando...\n");
      return 1;
    }
  }
  else
  {
    write("Hay alg�n problema con la contrase�a de tu cuenta.\n");
    return 1;
  }

  write("Introduce la nueva contrase�a: ");
  input_to("change_password3",1);
  return 1;
} 

int change_password3(string pass) 
{
  if (strlen(pass) < 6)
  {
    write("La contrase�a debe tener al menos seis caracteres.\nCancelando...\n");
    return 1;
  }
  
  tmppassword = pass;
  write("Por favor, introd�cela de nuevo: ");
  input_to("change_password4",1);
  return 1;
}

int change_password4(string pass) 
{
  if (tmppassword != pass) 
  {
    write("Las contrase�as no coinciden. Cancelando...\n");
    return 1;
  }

  this_object()->set_password( crypt(pass, "") );
  write("Ok.\n");
  return 1;
}

int chfn(string str) 
{
  write("Cambiando los datos personales de tu cuenta.\n");
  write("Si no introduces alg�n dato, se tomar� la opci�n por defecto (entre corchetes).\n");

  write("\nIntroduce tu nombre real ["+this_object()->query_real_name()+"]\n"+
    "('ninguno' para borrarlo): ");
  input_to("real_name");
  return 1;
}

int real_name(string str) 
{
  if (strlen(str))
  {
    if ((str == "none") || (str == "ninguno") || (str == "ninguna"))
    {
      this_object()->set_real_name("");
      write("Ok, nombre real borrado.\n");
    }
    else
    {
      this_object()->set_real_name(str);
      write("Ok, nombre real establecido como "+str+".\n");
    }
  }
  else
  {
    write("Ok, nombre real sin modificar.\n");
  }

  write("\nIntroduce tu lugar de residencia (ej: Madrid, Estocolmo... ) ["+
    this_object()->query_location()+"]\n"+
    "('ninguna' para borrarla): ");
  input_to("get_where");
  return 1;
} /* real_name() */

int get_where(string str) 
{
  if (strlen(str))
  {
    if ((str == "none") || (str == "ninguno") || (str == "ninguna"))
    {
      this_object()->set_location("");
      write("Ok, lugar de residencia borrado.\n");
    }
    else
    {
      this_object()->set_location(str);
      write("Ok, lugar de residencia establecido como "+str+".\n");
    }
  }
  else
  {
    write("Ok, lugar de residencia sin modificar.\n");
  }
  
  write("\nIntroduce tu fecha de cumplea�os (ddmm) ["+this_object()->query_birthday()+"]\n"+
    "('ninguna' para borrarla): ");
  input_to("birthday");
  return 1;
} /* get_where() */

void birthday(string str) 
{
  if (strlen(str))
  {
    if ((str == "none") || (str == "ninguno") || (str == "ninguna"))
    {
      this_object()->set_birthday("");
      write("Ok, fecha de cumplea�os borrada.\n");
    }
    else
    {
      if (!handler(CALENDAR_HANDLER)->valid_birthday(str))
      {
        write("La fecha no es v�lida, vuelve a introducirla (ddmm): ");
        input_to("birthday",1);
        return;
      }
      this_object()->set_birthday(str);
      write("Ok, fecha de cumplea�os establecida como "+str+".\n");
    }
  }
  else
  {
    write("Ok, fecha de cumplea�os sin modificar.\n");
  }

  this_object()->save_me();

  return;

  // remove email change for now, it's set with 
  // the account and cannot be changed

  // write("\nIntroduce tu direcci�n de email ["+this_object()->query_email()+"]\n"+
  //   "('ninguna' para borrarla): ");
    
  // write("\nPuedes anteponer el s�mbolo ':' delante, y as� s�lo los administradores "+
  //     "podr�n verlo.\n");
  // input_to("set_email");

} /* birthday() */

/*
int set_email(string str) 
{
  if (strlen(str))
  {
    if ((str == "none") || (str == "ninguno") || (str == "ninguna"))
    {
      this_object()->set_email("");
      write("Ok, direcci�n de email borrada.\n");
    }
    else
    {
      // hack para evitar un error comun del cliente ZMud
      if (str[1..1] == ":")
        str = str[1..strlen(str)-1];

      if (!SECURE->valid_email(str))
      {
        write("Direcci�n de email inv�lida, se deja sin modificar.\n");
        return 1;
      }
        
      if (str[0..0] == ":")
        write("Tu direcci�n de email s�lo ser� visible por administradores.\n");

      this_object()->set_email(str);
      write("Ok, direcci�n de email establecida como "+str+".\n");
    }
  }
  else
  {
    write("Ok, direcci�n de email sin modificar.\n");
  }
  return 1;
}
*/
  
mixed stats() 
{
  return ({ });
}
            