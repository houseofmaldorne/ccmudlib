
inherit "/lib/room";

void setup() 
{
  set_light(40);
  set_short(mud_name()+": El Vac�o");
  set_long("�ste es el lugar al que vienes cuando ha habido un fallo "+
          "en el lugar en el que estabas la �ltima vez que jugaste, "+
          "y te quedas sin ning�n lugar al que ir. "+
          "La raz�n se deber� muy probablemente "+
          "a alg�n fallo involuntario de programaci�n o a un error del sistema. "+
          "Utiliza el comando 'emergencia' para avisar de lo que ha pasado "+
          "(indica d�nde te encontrabas la �ltima vez si lo recuerdas) y que as� "+
          "quede constancia de lo que ha sucedido para que se pueda arreglar, "+
          "y luego sal de este lugar utilizando las salidas a tu disposici�n.\n");

  add_exit("ciudad", "/d/ciudad_capital/barrio_antiguo/rooms/calzada02.c", "standard");
}
