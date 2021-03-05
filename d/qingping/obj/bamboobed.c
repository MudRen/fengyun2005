inherit ITEM;

void create()
{
   set_name("竹榻", ({ "bamboo bed" , "竹榻", "bamboobed" }) );
   set_weight(500);
   set_max_encumbrance(8000);
   set("no_get", 1);
   set("no_shown", 1);

   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "on");
      set("unit", "张");
      set("long", "这是一张四尺来长的竹榻，似乎是专门给小孩子用的。\n");
      set("value", 1);
   }
}

int is_container() { return 1; }


