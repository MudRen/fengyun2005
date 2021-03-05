inherit ITEM;

void create()
{
   set_name("土墙", ({ "wall" , "土墙"}) );
   set_weight(500);
   set_max_encumbrance(8000);
   set("no_get", 1);
   set("no_shown", 1);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "on");
      set("unit", "堵");
      set("long", "泥土垒成的墙上挂着一些常用的农具。\n");
      set("value", 1);
   }
    ::init_item();
}

int is_container() { return 1; }


