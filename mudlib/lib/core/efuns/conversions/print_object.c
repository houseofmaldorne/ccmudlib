
static string print_object(mixed ob)
{
  write(to_string(ob));

  if (intp(ob)) 
  {
    return "int";
  }
  else if (floatp(ob)) 
  {
    return "float";
  }
  else if (stringp(ob)) 
  {
    return "string";
  }
  else if (objectp(ob)) 
  {
    if (interactive(ob)) 
      return "user object";

    return "object";
  }
  else if (mappingp(ob))
  {
    return "mapping";
  }
  else if (arrayp(ob)) 
  {
    return "array";
  }
  else if (undefinedp(ob))
  {
    return "nil";
  }

  return "oh dear";
}
