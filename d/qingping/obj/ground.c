inherit ITEM;

void create()
{
   set_name("土地", ({ "ground" }) );
   set_weight(500);
   set_max_encumbrance(8000);
   set("no_get", 1);
   set("no_shown", 1);

   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "in");
      set("unit", "块");
      set("long", "靠近芭蕉旁的土地十分的潮湿松软。\n");
      set("value", 1);
   }
}

int is_container() { return 1; }


