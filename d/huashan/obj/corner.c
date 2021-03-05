inherit ITEM;

void create()
{
   set_name("墙柱", ({ "corner" , "墙柱", "柱子"}) );
   set_weight(50000);
   set_max_encumbrance(80000);
   set("no_get", 1);
   set("no_shown", 1);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "in");
      set("unit", "个");
      set("long", "庙墙的柱子裂开了。\n");
      set("value", 1);
   }
    ::init_item();
}

int is_container() { return 1; }


