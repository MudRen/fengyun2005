inherit ITEM;

void create()
{
   set_name("墙壁", ({ "wall" }) );
   set_weight(500);
   set_max_encumbrance(8000);
   set("no_get", 1);
   set("no_shown", 1);

   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "on");
      set("unit", "堵");
      set("long", "雪白的墙壁上挂了几幅字画。\n");
      set("value", 1);
   }
}

int is_container() { return 1; }

