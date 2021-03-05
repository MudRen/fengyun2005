inherit ITEM;

void create()
{
   set_name("野花", ({ "wild flower" , "野花", "flower", "cao"}) );
   set_weight(500);
   set_max_encumbrance(8000);
   set("no_get", 1);
   set("no_shown", 1);

   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "on");
      set("unit", "朵");
      set("long", "不知名的草顽强地从石缝中钻出，并开出了艳丽的花朵。\n");
      set("value", 1);
   }
}

int is_container() { return 1; }


